using System;
using System.Data;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace Box_Factory
{
    public class Box_Factory
    {
	
		[STAThread]
        static void Main(String[] args)
        {
			if (args.Length == 0)
			{
				Console.WriteLine("Error! No input file.");				
			}
			else
			{
				String inp = args[0];
				Box_Factory bt = new Box_Factory();
				bt.calculate (inp, Path.GetFileNameWithoutExtension(inp)+".out");
			}
            
        }
		
		private void calculate(String infilename, String outfilename)
        {
            System.IO.StreamReader SR;
			StreamWriter sw = new StreamWriter(outfilename);
			String S;

			SR = File.OpenText(infilename);
            S = SR.ReadLine();

            long tests = long.Parse(S);
            
                        long N, M;

            long type, count;

            pair pair = null;

            ArrayList boxes = new ArrayList();
            ArrayList toys = new ArrayList();

            for (long i = 0; i < tests; i++)
            {
                boxes.Clear();
                toys.Clear();

                S = SR.ReadLine();

                N = long.Parse(readWord(S));

                S = removeWord(S);

                M = long.Parse(readWord(S));

                S = SR.ReadLine();

                for (long j = 0; j < N; j++)
                {
                    count = long.Parse(readWord(S));
                    S = removeWord(S);
                    type = long.Parse(readWord(S));
                    S = removeWord(S);
                    pair = new pair(count, type);
                    boxes.Add(pair);
                }

                S = SR.ReadLine();

                for (long j = 0; j < M; j++)
                {
                    count = long.Parse(readWord(S));
                    S = removeWord(S);
                    type = long.Parse(readWord(S));
                    S = removeWord(S);
                    pair = new pair(count, type);
                    toys.Add(pair);
                }

				sw.WriteLine("Case #" + (i + 1) + ": "+ compute(boxes, toys));
            }
            SR.Close();
			sw.Close();
        }
		
		
        private string compute(ArrayList boxes, ArrayList toys)
        {
            long max = 0;

            ArrayList next = new ArrayList();

            ArrayList temp = new ArrayList();

            Case c1 = new Case(boxes, toys, 0);

            next.Add(c1);

            while (next.Count > 0)                
            {
                temp.Clear();

                foreach(Case c in next)
                {
                    temp.AddRange(proceed(c, ref max));
                }

                next.Clear();
                next.AddRange(temp);
            }

            return max+"";
        }

        private ArrayList proceed(Case c, ref long max)
        {
            ArrayList result = new ArrayList();

            if (c.boxes.Count > 0 && c.toys.Count > 0)
            {
                if (((pair)c.boxes[0]).type == ((pair)c.toys[0]).type)
                {
                    Case c2 = new Case(c.boxes, c.toys, c.max);

                    long bc = 0, tc = 0;

                    bc = ((pair)c2.boxes[0]).count - ((pair)c2.toys[0]).count;
                    tc = ((pair)c2.toys[0]).count - ((pair)c2.boxes[0]).count;

                    c2.max += Math.Min(((pair)c2.boxes[0]).count, ((pair)c2.toys[0]).count);

                    if (bc <= 0)
                    {
                        c2.boxes.RemoveAt(0);
                    }
                    else
                    {
                        pair p = new pair(bc, ((pair)c2.boxes[0]).type);
                        c2.boxes[0] = p;
                    }

                    if (tc <= 0)
                    {
                        c2.toys.RemoveAt(0);
                    }
                    else
                    {
                        pair p = new pair(tc, ((pair)c2.toys[0]).type);
                        c2.toys[0] = p;
                    }
                    result.Add(c2);
                }
                else
                {
                    /////case1
                    Case c1 = new Case(c.boxes, c.toys, c.max);

                    while (c1.boxes.Count > 0 && ((pair)c1.boxes[0]).type != ((pair)c1.toys[0]).type)
                    {
                        c1.boxes.RemoveAt(0);
                    }

                    result.Add(c1);

                    /////case2

                    Case c2 = new Case(c.boxes, c.toys, c.max);

                    while (c2.toys.Count > 0 && ((pair)c2.toys[0]).type != ((pair)c2.boxes[0]).type)
                    {
                        c2.toys.RemoveAt(0);
                    }

                    result.Add(c2);
                }
            }
            else
            {
                max = Math.Max(c.max, max);
            }
            return result;
        }

 
 
		public static String readWord(String S)
        {
            if (S.Contains(' '))
            {
                return S.Substring(0, S.IndexOf(' ')).Trim();
            }
            else
            {
                return S;
            }
        }

        public static String removeWord(String S)
        {
            if (S.Contains(' '))
            {
                return S.Substring(S.IndexOf(' ')).Trim();
            }
            else
            {
                return S;
            }
        }         
    }
	
	
    class pair
    {
        public long type, count;


        public pair(long count_2, long type_2)
        {
            this.count = count_2;
            this.type = type_2;
        }
    }

    class Case
    {
        public ArrayList boxes, toys;
        public long max;

        public Case(ArrayList boxes, ArrayList toys, long max)
        {
            this.boxes = new ArrayList();
            this.boxes.AddRange(boxes);

            this.toys = new ArrayList();
            this.toys.AddRange(toys);

            this.max = max;
        }
    }
 
}