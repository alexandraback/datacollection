using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace ProblemD
{
    class chestinfo
    {
        public int chestindex;
        public int openkeytype;
        public List<int> keysinside = new List<int>();

        public chestinfo(int ind, string inputline)
        {
            this.chestindex = ind; //+1 while input
            string[] words = inputline.Split(' ');
            this.openkeytype = int.Parse(words[0]);
            for (int t = 2; t < words.Length; t++)
                this.keysinside.Add(int.Parse(words[t]));
        }        
    }

    class program
    {
        public static void Main()
        {
            List<string> inputlines = funcs.getInputDocs2(@"D-small-attempt1.in");
            int num_of_samples = int.Parse(inputlines[0]);
            int count = 1;
            List<string> outlines = new List<string>();
            for (int t = 0; t < num_of_samples; t++)
            {
                string[] words = inputlines[count].Split(' '); count++;
                Console.WriteLine(inputlines[count - 1]);
                int key_num = int.Parse(words[0]);
                int chest_num = int.Parse(words[1]);
                int[] KeyTypeArray = new int[1000];

                words = inputlines[count].Split(' '); count++; //Starting keys
                for (int k = 0; k < words.Length; k++)
                    KeyTypeArray[int.Parse(words[k])]++;

                List<chestinfo> chests = new List<chestinfo>();
                
                for (int k = 0; k < chest_num; k++)
                {
                    chestinfo new_chest = new chestinfo(k + 1, inputlines[count]);
                    count++;
                    chests.Add(new_chest);
                }
                Stopwatch sw = new Stopwatch();
                sw.Start();

                //Sort the chests
                /*
                for (int i = 0; i < chest_num; i++)
                    for (int j = i + 1; j < chest_num; j++)
                        if (chests[i].keysinside.Count < chests[j].keysinside.Count)
                        {
                            chestinfo ttt = chests[i]; chests[i] = chests[j]; chests[j] = ttt;
                        }*/

                //Start Manipulating. Using DFS
                List<int> stack = new List<int>(); int[] b = new int[1000];
                int cur_num = 0, cur_iter = -1;
                bool flag = true, pass = false;
                string real_content = "";

                while (flag && (!pass) &&(sw.ElapsedMilliseconds<20000))
                {
                    cur_iter++;
                    if (cur_iter >= chest_num)
                    {
                        if (cur_num == 0)
                            flag = false;
                        else
                        {
                            cur_iter = stack[stack.Count - 1]; stack.RemoveAt(stack.Count - 1);
                            for (int i = 0; i < chests[cur_iter].keysinside.Count; i++)
                                KeyTypeArray[chests[cur_iter].keysinside[i]]--;
                            KeyTypeArray[chests[cur_iter].openkeytype]++;
                            b[cur_iter] = 0;
                            cur_num--;
                        }
                    }
                    else
                    {
                        if ((b[cur_iter] == 0) && (KeyTypeArray[chests[cur_iter].openkeytype] > 0)) //Can be opened
                        {
                            //Proceed                        
                            stack.Add(cur_iter);
                            KeyTypeArray[chests[cur_iter].openkeytype]--;
                            for (int i = 0; i < chests[cur_iter].keysinside.Count; i++)
                                KeyTypeArray[chests[cur_iter].keysinside[i]]++;
                            b[cur_iter] = 1;
                            cur_num++; cur_iter = -1;                            
                            if (cur_num == chest_num)
                            {
                                real_content = chests[stack[0]].chestindex.ToString();
                                for (int i = 1; i < stack.Count; i++)
                                    real_content = real_content + " " + chests[stack[i]].chestindex;
                                pass = true;
                            }
                        }
                    }
                }

                if (pass == false)
                    real_content = "IMPOSSIBLE";
                outlines.Add("Case #" + (1 + t).ToString() + ": " + real_content);
                Console.WriteLine(real_content);
                Console.WriteLine(sw.ElapsedMilliseconds);
            }
            funcs.WriteLines(@"small.txt", outlines);
        }
    }
}
