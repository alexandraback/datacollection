using System;
using System.IO;
using System.Collections;
using System.Linq;
using System.Collections.Generic;


namespace GoogleJam
{
	/// <summary>
	/// Summary description for Class1.
	/// </summary>
	class ClassProblemSolverQB
	{

		[STAThread]
		static void Main(string[] args)
		{
			string fileName = "b-small";
			if (File.Exists(fileName + ".in"))
				ClassProblemSolverQB.ProcessFile(fileName);
			fileName = "b-large";
			if (File.Exists(fileName + ".in"))
				ClassProblemSolverQB.ProcessFile(fileName);

			
		}

		public static void ProcessFile(string fileName)
		{
			FileStream fileStreamWriter = new FileStream(fileName + ".out",FileMode.Create,FileAccess.Write);
			StreamWriter writer = new StreamWriter(fileStreamWriter);
			FileStream fileStreamReader = new FileStream(fileName + ".in",FileMode.Open,FileAccess.Read);
			StreamReader reader = new StreamReader(fileStreamReader);
			try
			{
				string s = reader.ReadLine();
				int numberOfTests = Convert.ToInt32(s);
				int currentTest = 0;
				while ((s = reader.ReadLine()) != null)
				{					
					currentTest++;
					if (currentTest > numberOfTests) 
						break;
                    writer.WriteLine("Case #{0}: {1}", currentTest, calc(parse(s,reader)));
				}

			}
			finally
			{
				reader.Close();
				fileStreamReader.Close();
				writer.Close();
				fileStreamWriter.Close();
			}

		}

        class ProblemParams
        {
            public int X, Y;
        }


        public class P
        {
            public int x, y;
            public P parent;
            public char c;

            public P(int x, int y, char c, P p)
            {
                this.x = x;
                this.y = y;
                this.parent = p;
                this.c = c;
            }
        }

        static P[] getJump(P p, int l)
        {
            return new P[] {
                new P(p.x + l,p.y,'E', p),
                new P(p.x - l,p.y,'W', p),
                new P(p.x,p.y - l,'S', p),
                new P(p.x,p.y + l,'N', p)
            };
        }
        static string calc(ProblemParams param)
        {
            var map = new P[1000, 1000];
            var st = new List<P>();
            st.Add(new P(0, 0, ' ', null));
            int l = 1;
            while (true)
            {
                var stn = new List<P>();
                foreach (var p in st)
                {
                    foreach (var pt in getJump(p,l))
                        if (map[pt.x + 500, pt.y + 500] == null)
                        {
                            if (pt.x == param.X && pt.y == param.Y)
                            {
                                string result = "";
                                var route = pt;
                                do
                                {
                                    result = route.c + result;
                                    route = route.parent;
                                } while (route != null);
                                return result;
                            }
                            map[pt.x + 500, pt.y + 500] = pt;
                            stn.Add(pt);
                        }                   
                }
                st = stn;
                l++;
            }
        }

        static ProblemParams parse(string s, StreamReader r)
        {
            ProblemParams result = new ProblemParams();
            string[] sp = s.Split(' ');
            result.X = Convert.ToInt32(sp[0]);
            result.Y = Convert.ToInt32(sp[1]);
            return result;                 
        }
    }
}
