/// <summary>
/// Solution for Code Jam Problem - Treasure
/// Author - JSSVPrasad Buddha
/// </summary>
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;
using System.Text;
using System.Linq;

namespace CodeJam2013
{
    [TestClass]
    public class Treasure
    {
        [TestMethod]
        public void TreasureSolver()
        {
            int lineCount = lines.Length;
            for (int line = 1, tc = 1; line < lineCount;  tc++)
            {

                int[] temp = lines[line++].Split(' ').Select(x => int.Parse(x)).ToArray();
                int k = temp[0];
                int n = temp[1];
                keys = new Key[41];
                Chest[] chests = new Chest[n+1];
                chestsToBeOpened = n;
                foreach(int key in lines[line++].Split(' ').Select(x => int.Parse(x)))
                {
                    if (keys[key] == null)
                        keys[key] = new Key(key);
                    keys[key].count++;
                }

                for (int i = 1; i <= n; i++)
                {
                    chests[i] = new Chest(i);
                    chests[i].ProcessChestLine(lines[line++]);
                }

                int tobeOpenedBefore;
                bool impossible = false;
                while (chestsToBeOpened > 0)
                {
                    tobeOpenedBefore = chestsToBeOpened;
                    foreach (int type in keys.Where(x=>x!=null).Select(x=>x.type)
                                            .Where(x=>(keys[x].count>0)).OrderBy(x=>keys[x].count))
                    {
                        
                        foreach (Chest chest in chests.Where(x=>(x!=null) && (x.opened==false) && (x.requiredKey == type))
                                                      .OrderByDescending(x => x.containedKeys.Length))
                        {
                            if (chest.Open(keys) == true)
                            {
                                chestsToBeOpened--;
                                chest.openingOrder = n - chestsToBeOpened;
                            }
                        }
                    }
                    if (tobeOpenedBefore == chestsToBeOpened)
                    {
                        impossible = true;
                        break;
                    }
                }
                string result = "IMPOSSIBLE";
                if (!impossible)
                {
                    result = "";
                    foreach (Chest chest in chests.Where(x=>x!=null).OrderBy(x => x.openingOrder))
                    {
                        result = result + chest.num + " ";
                    }
                    result = result.Trim();
                }

                solution.AppendLine("Case #" + tc + ": " + result);
            }

            File.WriteAllText(outputfile, solution.ToString());
            return;
        }

        //private bool Solve(Chest[] chests, int[] keys)
        //{
        //    int[] tempKeys = new int[keys.Length]; 
        //    keys.CopyTo(tempKeys,1);
        //    Chest[] tempChest

        //}

        public Key[] keys;
        public int[] keyrequirement;
        public int chestsToBeOpened;

        public class Key
        {
            public int type { get; private set; }
            public int count;
            public Key(int typeofkey)
            {
                type = typeofkey;
            }
        }

        public class Chest 
        {
            public bool opened { get; private set; }
            public int requiredKey { get; private set; }
            public int[] containedKeys;
            public int openingOrder;
            public int num;
            public Chest(int chestnum)
            {
                num = chestnum;
            }
            public void ProcessChestLine(string line)
            {
                int[] temp = line.Split(' ').Select(x => int.Parse(x)).ToArray();
                requiredKey = temp[0];
                int len = temp.Length;
                containedKeys = new int[len - 1];
                for (int i = 1; i < len; i++)
                {
                    containedKeys[i - 1] = temp[i];
                }
            }

            public bool Open(Key[] keys)
            {
                
                if (keys[requiredKey].count >= 1)
                {
                    opened = true;
                    keys[requiredKey].count--;
                    foreach (int key in containedKeys.Where(x=>x>0))
                    {
                        if (keys[key] == null)
                            keys[key] = new Key(key);
                        keys[key].count++;
                    }
                    return true;
                }
                else
                {
                    return false;
                }
            }

        }        

        [TestCleanup]
        public void CleanUp()
        {
            // This method Sets the test output to a text file rather than Standard Output for seeing the output without indentation issues
            // To disable redirecting output to text file, comment next line
            Console.SetOut(tmp);
            sw.Close();
        }

        [TestInitialize]
        public void Initialize()
        {
            Console.SetOut(sw);
        }

        static string inputfile = @"C:\Documents\Dropbox\Code\BitBucket\Temp\CodeJam\IO\Treasure-small.in";
        static string outputfile = @"C:\Documents\Dropbox\Code\BitBucket\Temp\CodeJam\IO\Treasure-small.out";
        static StringBuilder solution = new StringBuilder();
        static string[] lines = File.ReadAllLines(inputfile);

        static FileStream fs = new FileStream(@"C:\Documents\Dropbox\Code\BitBucket\Temp\CodeJam\IO\Global.out", FileMode.Create);
        static StreamWriter sw = new StreamWriter(fs);
        static TextWriter tmp = Console.Out;
    }


}
