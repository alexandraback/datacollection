using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleB
{
    class Program
    {
        static void Main(string[] args)
        {
            #region IO
            TextReader reader;
            if (args.Length > 0)
            {
                reader = new StreamReader(args[0]);
            }
            else
            {
                reader = Console.In;
            }

            TextWriter writer;
            if (args.Length > 1)
            {
                writer = new StreamWriter(args[1]);
            }
            else
            {
                writer = Console.Out;
            }
            #endregion

            string str = reader.ReadLine();
            int cases;
            if (int.TryParse(str.Trim(), out cases))
            {
                if (cases <= 0)
                {
                    throw new ApplicationException("Invalid number of cases!!!");
                }

                List<string> caseOutputs = new List<string>(cases);
                for (int i = 0; i < cases; i++)
                {
                    str = reader.ReadLine();
                    int level = int.Parse(str);

                    int star = 0;
                    int count = 0;
                    List<LevelStarReq> allLevelStarReq = new List<LevelStarReq>(level);
                    for (int j = 0; j < level; j++)
                    {
                        str = reader.ReadLine();
                        string[] paras = str.Split(' ');

                        LevelStarReq lsq = new LevelStarReq();
                        lsq.solved = lsq.solvedPartial = false;
                        lsq.oneStarReq = int.Parse(paras[0]);
                        lsq.twoStarReq = int.Parse(paras[1]);

                        allLevelStarReq.Add(lsq);
                    }

                    while (allLevelStarReq.Any(x => !x.solved))
                    {
                        var v = from l in allLevelStarReq
                                where ((l.twoStarReq <= star || l.twoStarReq == 0) && !l.solved)
                                orderby l.twoStarReq
                                select l;

                        LevelStarReq lsq = v.FirstOrDefault();
                        if (lsq != null)
                        {
                            if (lsq.solvedPartial)
                                star++;
                            else
                                star += 2;

                            lsq.solved = lsq.solvedPartial = true;
                            count++;
                            continue;
                        }

                        v = from l in allLevelStarReq
                                where ((l.oneStarReq <= star || l.oneStarReq == 0) && !l.solvedPartial)
                                orderby l.twoStarReq descending
                                select l;

                        lsq = v.FirstOrDefault();
                        if (lsq != null)
                        {
                            lsq.solvedPartial = true;
                            star++;
                            count++;

                            continue;
                        }

                        break;
                    }

                    if (allLevelStarReq.Any(x => !x.solved))
                    {
                        caseOutputs.Add(string.Format("Case #{0}: {1}", i + 1, "Too Bad"));
                    }
                    else
                    {
                        caseOutputs.Add(string.Format("Case #{0}: {1}", i + 1, count));
                    }
                }

                foreach (string s in caseOutputs)
                {
                    writer.WriteLine(s);
                }

                writer.Flush();
            }
            else
            {
                throw new ApplicationException("Invalid number of cases!!!");
            }
        }
    }
}
