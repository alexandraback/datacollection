using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ2012.R1C
{
    public class ProblemA
    {
        static class Program
        {
            [STAThread]
            static void Main(string[] args)
            {
                string inpFilePath = "input.txt";
                if (args.Length > 0) inpFilePath = args[0];
                ProblemA b = new ProblemA(inpFilePath);
                b.Run();
            }
        }

        StreamReader inputFile;
        StreamWriter outPutFile;

        int totalCases,testCase;
        string fileLine,inputFilePath,outputFilePath;

        Dictionary<int,cls> classes;
        int clsCount;
        public ProblemA(string inputFilePath)
        {
            this.inputFilePath = inputFilePath;
            this.outputFilePath = Path.Combine(Path.GetDirectoryName(Path.GetFullPath(inputFilePath)), "output.txt");
        }

        public void Run()
        {
            this.inputFile = new StreamReader(this.inputFilePath);
            this.outPutFile = new StreamWriter(this.outputFilePath);

            fileLine = this.inputFile.ReadLine();
            totalCases = Convert.ToInt32(fileLine);

            for (testCase = 0; testCase < totalCases; testCase++)
            {
                InitTestCase();
                RunTestCase();
            }

            this.outPutFile.Close();
            this.inputFile.Close();
        }

        private void InitTestCase()
        {
            fileLine = this.inputFile.ReadLine();
            clsCount = Convert.ToInt32(fileLine);
            this.classes = new Dictionary<int,cls>();
            for (int i = 1; i <= clsCount; i++)
            {
                cls c = new cls();
                c.id = i;
                this.classes.Add(i,c);
            }

            for (int i = 1; i <= clsCount; i++)
            {
                fileLine = this.inputFile.ReadLine();
                string[] tmp = fileLine.Split(' ');
                int parentCount = Convert.ToInt32(tmp[0]);
                for (int j = 1; j <= parentCount; j++)
                {
                    int pClsId = Convert.ToInt32(tmp[j]);
                    this.classes[i].parent.Add(this.classes[pClsId]);
                    this.classes[pClsId].child.Add(this.classes[i]);
                }
            }
        }

        private void RunTestCase()
        {
            bool diamondExists = false;
            
            for (int i = 1; i <= this.clsCount&& !diamondExists; i++)
            {
                cls x = this.classes[i];
                if (x.parent.Count == 1)
                {
                    x = x.parent[0];
                }
                else if (x.parent.Count > 1)
                {
                    for (int cId = 1; cId <= this.clsCount && !diamondExists; cId ++)
                    {
                        for (int p = 0; p < x.parent.Count && !diamondExists; p++)
                        {
                            if (x.parent[p].isChildOf(cId) || x.parent[p].id==cId)
                            {
                                for (int k = 0; k < x.parent.Count && !diamondExists; k++)
                                {
                                    if (k != p && (x.parent[k].id == cId || x.parent[k].isChildOf(cId)))
                                    {
                                        Console.WriteLine("Diamond Exists between {0} and {1}", x.id, cId);
                                        diamondExists = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            this.outPutFile.WriteLine(string.Format("Case #{0}: {1}", this.testCase+1,diamondExists?"Yes":"No"));
        }

        class cls
        {
            public int id;
            public List<cls> child;
            public List<cls> parent;

            public cls()
            {
                this.child = new List<cls>();
                this.parent = new List<cls>();
            }
            
            public bool isChildOf(int clsId)
            {
                for (int i = 0; i < parent.Count; i++)
                {
                    if(this.parent[i].id==clsId)
                    {
                        return true;
                    }
                    else if (this.parent[i].isChildOf(clsId))
                    {
                        return true;
                    }
                }
                return false;
            }

            public bool IsParentOf(int clsId)
            {
                for (int i = 0; i < this.child.Count; i++)
                {
                    if (this.child[i].id == clsId)
                    {
                        return true;
                    }
                    else if (this.child[i].IsParentOf(clsId))
                    {
                        return true;
                    }
                }
                return false;
            }

        }
    }
}
