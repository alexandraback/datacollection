using System;
using System.IO;
using System.Collections;
using System.Linq;


namespace GoogleJam
{
	/// <summary>
	/// Summary description for Class1.
	/// </summary>
	class ClassProblemSolverQA
	{

		[STAThread]
		static void Main(string[] args)
		{
			string fileName = "a-small";
			if (File.Exists(fileName + ".in"))
				ClassProblemSolverQA.ProcessFile(fileName);
			fileName = "a-large";
			if (File.Exists(fileName + ".in"))
				ClassProblemSolverQA.ProcessFile(fileName);

			
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
            public int N;
            public bool[] B;
        }

        static int calc(ProblemParams param)
        {
            int result = 0;
            int l = param.N;
            int n = param.B.Length;
            int lastP = 0;
            for (int i = 0; i < n; i++)
            {
                if (param.B[i])
                    continue;
                int p = 1;
                int k = i+1;
                for (; k < n; k++)
                    if (p == l || param.B[k])
                        break;
                    else
                        p++;
                if (p == l)
                {
                    int x = i - lastP;
                    int y = n - k;
                    result += (1 + x + y + x * y);
                    lastP = i+1;
                }         
            }
            return result;
        }

        static ProblemParams parse(string s, StreamReader r)
        {
            ProblemParams result = new ProblemParams();
            string[] sp = s.Split(' ');
            int n = Convert.ToInt32(sp[1]);
            result.N = n;
            result.B = new bool[sp[0].Length];
            int i = 0;
            foreach (char c in sp[0])
                result.B[i++] = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            return result;                 
        }
    }
}
