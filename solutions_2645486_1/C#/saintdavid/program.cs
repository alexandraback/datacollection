using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class program
    {
        public static void Main()
        {
            //List<string> input_lines = funcs.getInputDocs2(@"input.txt");
            //List<string> input_lines = funcs.getInputDocs2(@"B-small-attempt1.in");            
            List<string> input_lines = funcs.getInputDocs2(@"B-large.in");
            
            int num = int.Parse(input_lines[0]);            
            List<string> outlines = new List<string>();
            int lcount = 1;
            for (int samples = 0; samples < num; samples++)
            {
                string thisline = input_lines[lcount]; lcount++;
                string[] words = thisline.Split(' ');
                int HP = int.Parse(words[0]); int Regain = int.Parse(words[1]); int N = int.Parse(words[2]);
                string[] words_2 = input_lines[lcount].Split(' '); lcount++;

                int[] values = new int[N]; for (int i = 0; i < values.Length; i++) values[i] = int.Parse(words_2[i]);
                int[] hps = new int[N];
                List<string> active = new List<string>();
                for (int i = 0; i < N; i++) active.Add("A");

                long sum = 0;
                int Cur_HP = HP;
                for (int i = 0; i < N; i++)
                {
                    //Find the next bigger one. Otherwise return -1
                    if (active[i].Equals("A"))
                    {
                        int flag = -1, gain = 0;

                        int num_of_regain = (int)Math.Ceiling((double)HP/(double)Regain) - 1;

                        int counter = 0;
                        while ((i + counter + 1 < N) && (counter < num_of_regain))
                        {
                            counter++;
                            if (values[i] < values[i + counter])
                            {
                                int leftnow = HP - Regain * counter; //Expected Lefted Value
                                if (Cur_HP > leftnow) gain = Cur_HP - leftnow;
                                //Freeze guys in the middle
                                for (int j = 1; j < counter; j++)
                                    active[i + j] = "F";
                                flag = 1;
                                break;
                            }
                        }

                        if (flag == -1) hps[i] = Cur_HP;
                        else hps[i] = gain;
                        Cur_HP = Cur_HP - hps[i];

                        sum += (long)hps[i] * (long)values[i];
                    }
                    Cur_HP = Cur_HP + Regain;
                }
                Console.WriteLine(sum);
                outlines.Add("Case #" + (samples + 1).ToString() + ": " + sum);                
            }
            funcs.WriteLines(@"B-large.out", outlines);            
        }
    }
}
