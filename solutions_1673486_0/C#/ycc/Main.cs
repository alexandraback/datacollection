using System;
using System.IO;

namespace GCJ
{
	class MainClass
	{
		public static void Main ()
		{
			StreamReader SR = new StreamReader("A-small-attempt1.in");
			StreamWriter SW = new StreamWriter("a.out");
		
			int T = int.Parse(SR.ReadLine());
			for(int tcase = 1; tcase <= T; tcase++)
			{
				string[] args = SR.ReadLine().Split(' ');
				int A = int.Parse(args[0]);
				int B = int.Parse(args[1]);
				B -= A;
				double[] Pa = new double[A];
				args = SR.ReadLine().Split(' ');
				for(int i = 0; i < A; i++)
					Pa[i] = double.Parse(args[i]);
				
				//option 1
				double correct = 1;
				foreach(double x in Pa)
					correct *= x;
				double rt = (B + 1) + (1 - correct) * (A + B + 1);
				
				//option 3
				rt = Math.Min (rt, 1 + A + B + 1);
				
				//optin 2
				correct = 1;
				for(int i = 1; i <= A; i++)
				{
					correct *= Pa[i - 1];
					rt = Math.Min(rt, correct * (A - i + A - i + B + 1) + (1 - correct) * (A - i + A - i + B + 1 + A + B + 1));
				}
				SW.WriteLine("Case #{0}: {1:N10}", tcase, rt);
			}
			SW.Close();
		}
	}
}
