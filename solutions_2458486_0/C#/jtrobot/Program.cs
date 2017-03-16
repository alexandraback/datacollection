using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace QualA
{
    class Chest
    {
        public Chest(int chestNum)
        {
            chestNumber = chestNum;
            keysInside = new List<int>();
            opened = false;
        }
        public int chestNumber { get ; set; }
        public int keyType { get; set; }
        public List<int> keysInside { get; set; }
        public bool opened { get; set; }
    }

    class Program
    {
        static List<int> OpenChests(List<Chest> chests, List<int> keys, List<int> answer)
        {
            bool madeProgress = false;
            bool anyClosedChests = false;
            List<int> a = new List<int>(answer);
            foreach (Chest chest in chests)
            {
                List<int> testKeys = new List<int>(keys);
                if (chest.opened == false)
                {
                    anyClosedChests = true;
                
                    //do we have a key?
                    if (testKeys.Contains(chest.keyType))
                    {
                        madeProgress = true;
                        //open chest
                        chest.opened = true;
                        //lose key
                        testKeys.Remove(chest.keyType);
                        //gather new keys
                        testKeys.AddRange(chest.keysInside);
                        //recursive
                        answer.Add(chest.chestNumber);
                        //Console.Write(chest.chestNumber + " ");
                        //System.Threading.Thread.Sleep(100);
                        a = OpenChests(chests, testKeys, answer);
                        if (a.Count == chests.Count)
                            return a;
                        if (a.Count == 0)
                        {
                            //Close last chest
                            chests[answer.Last()-1].opened = false;
                            answer.Remove(chests[answer.Last()-1].chestNumber);
                            break;
                            
                        }
                    }
                }
            }
            if (madeProgress == true || anyClosedChests == false)
                return a;
            else
            {
                return new List<int>();
            }
            
        }
        
        
        static void Main(string[] args)
        {
            string fileIn = "..\\..\\..\\D-small-attempt1.in";
            string fileOut = "..\\..\\..\\fileOut.txt";
            using (StreamReader sr = new StreamReader(fileIn))
            using (StreamWriter sw = new StreamWriter(fileOut))
            {

                int cases = int.Parse(sr.ReadLine());


                for (int i = 1; i <= cases; i++)
                {
                    string lineIn = sr.ReadLine();
                    int keysCount = Convert.ToInt32(lineIn.Split(' ').ElementAt(0));
                    int chestCount = Convert.ToInt32(lineIn.Split(' ').ElementAt(1));

                    //KEYS
                    List<int> keys = new List<int>();
                    string keyList = sr.ReadLine();
                    for (int k = 0; k < keysCount; k++)
                        keys.Add(Convert.ToInt32(keyList.Split(' ').ElementAt(k)));
                    Console.WriteLine("WE HAVE KEYS: " + string.Join(" ", keys));

                    //CHESTS
                    List<Chest> chests = new List<Chest>();
                    for (int k = 0; k < chestCount; k++)
                    {
                        lineIn = sr.ReadLine();
                        Chest chest = new Chest(k+1);
                        //KEY TYPE
                        chest.keyType = Convert.ToInt32(lineIn.Split(' ').ElementAt(0));
                        
                        //KEYS INSIDE
                        int numKeysInChest = Convert.ToInt32(lineIn.Split(' ').ElementAt(1));
                        for (int e = 2; e < numKeysInChest + 2; e++)
                            chest.keysInside.Add(Convert.ToInt32(lineIn.Split(' ').ElementAt(e)));
                        chests.Add(chest);
                        Console.WriteLine("CHEST " + chest.chestNumber + " (TAKES KEY " + chest.keyType + "), CONTENTS: " + string.Join(" ", chest.keysInside));
                    }


                    //Let's open some chests!
                    List<int> theAnswer = OpenChests(chests, keys, new List<int>());
                    string answer = "";
                    if (theAnswer.Count == 0)
                        answer = "Case #" + i + ": " + "IMPOSSIBLE";
                    else
                        answer = "Case #" + i + ": " + string.Join(" ", theAnswer).Trim();
                    
                    sw.WriteLine(answer);
                    Console.WriteLine(answer);
                }
            }
            Console.ReadLine();
        }
        
    
    }
}
