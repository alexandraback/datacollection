using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class DeceitfulWar
    {
        static StreamReader Input;
        static StreamWriter Output;

        static void Main(string[] args)
        {
            string classname = MethodBase.GetCurrentMethod().DeclaringType.Name;
            string testcase = Console.ReadLine();

            Input = new StreamReader("input/" + classname + "-" + testcase + ".txt");
            Output = new StreamWriter("output/" + classname + "-" + testcase + ".txt");

            int testcases = Convert.ToInt32(Input.ReadLine());

            for (int t = 1; t <= testcases; t++)
            {
                int n = Convert.ToInt32(Input.ReadLine());

                string[] blocksN = Input.ReadLine().Split(' ');
                string[] blocksK = Input.ReadLine().Split(' ');
                
                List<Block> blocks = new List<Block>();
                for (int i = 0; i < n; i++)
                {
                    Block b1 = new Block();
                    b1.Weight = Convert.ToDouble(blocksN[i]);
                    b1.Player = 'N';
                    blocks.Add(b1);

                    Block b2 = new Block();
                    b2.Weight = Convert.ToDouble(blocksK[i]);
                    b2.Player = 'K';
                    blocks.Add(b2);
                }

                blocks = blocks.OrderBy(x => x.Weight).ToList();

                int pointW = 0;
                while (true)
                {
                    Block chooseN = blocks.FirstOrDefault(x => x.Player == 'N');

                    if (chooseN == null)
                        break;

                    Block chooseK = blocks.FirstOrDefault(x => x.Player == 'K' && x.Weight > chooseN.Weight);

                    if (chooseK == null)
                    {
                        ++pointW;
                        chooseK = blocks.FirstOrDefault(x => x.Player == 'K');
                    }

                    chooseN.Player = 'n';
                    chooseK.Player = 'k';
                }

                foreach (Block b in blocks)
                {
                    if (b.Player == 'n')
                        b.Player = 'N';
                    else
                        b.Player = 'K';
                }

                int pointDW = 0;
                while (true)
                {
                    if (isNaomiWinner(blocks))
                    {
                        pointDW += blocks.Count(x => x.Player == 'N');
                        break;
                    }
                    
                    Block chooseN = blocks.FirstOrDefault(x => x.Player == 'N');

                    if (chooseN == null)
                        break;

                    Block chooseK = blocks.LastOrDefault(x => x.Player == 'K' && x.Weight > chooseN.Weight);

                    if (chooseK == null)
                    {
                        ++pointDW;
                        chooseK = blocks.FirstOrDefault(x => x.Player == 'K');
                    }

                    chooseN.Player = 'n';
                    chooseK.Player = 'k';
                }

                Output.WriteLine("Case #{0}: {1} {2}", t, pointDW, pointW);
            }

            Output.Close();
        }

        private static bool isNaomiWinner(List<Block> blocks)
        {
            int superior = 0;
            for (int i = blocks.Count - 1; i >= 0; i--)
            {
                if (superior < 0)
                    return false;
                
                if (blocks[i].Player == 'N')
                {
                    ++superior;
                    continue;
                }
                if (blocks[i].Player == 'K')
                {
                    --superior;
                    continue;
                }
            }

            return true;
        }
    }

    class Block
    {
        public double Weight { get; set; }
        public char Player { get; set; }
    }
}
