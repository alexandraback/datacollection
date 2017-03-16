using System;
using System.IO;
using System.Collections.Generic; 

namespace Round1B
{
	public class QuestionTwo
	{	
		public QuestionTwo () {}
		
		int[] digits = new int[10];
		
		public string Solve (StreamReader reader) {
			string ret = "";
			
			string line = reader.ReadLine ();
			
			int numCases = Int32.Parse (line);
			
			for (int caseNumber = 1; caseNumber <= numCases; caseNumber++) {
				Console.Write ("Case#: " + caseNumber);
				
				for (int i = 0; i < 10; i++) {
					digits[i] = 0;
				}
				
				string solution = SolveSingleCase (reader);
				ret += "Case #" + caseNumber + ": " + solution + "\n"; 
			}
			
			return ret;
		}
		
		public string SolveSingleCase (StreamReader reader) {
			string line = reader.ReadLine();

			string[] parts = line.Split (new char[] {' '});
			string coders = parts[0];
			string jammers = parts[1];

			int[] coderDigits = new int[3];
			int[] jammerDigits = new int[3];
			int numCQ = 0;
			int numJQ = 0;
			List<int> cMissingDigits = new List<int> ();
			List<int> jMissingDigits = new List<int> ();
			for (int i = 0; i < coders.Length; i++) {
				if (coders[i] == '?') {
					coderDigits[i] = -1;
					cMissingDigits.Add (i);
					numCQ++;
				}
				else
					coderDigits[i] = (int)Char.GetNumericValue (coders[i]);

				if (jammers[i] == '?') {
					jammerDigits[i] = -1;
					jMissingDigits.Add (i);
					numJQ++;
				}
				else
					jammerDigits[i] = (int)Char.GetNumericValue (jammers[i]);
			}

			int numDigits = coders.Length;

			int[] codersResult = new int[numDigits];
			int[] jammersResult = new int[numDigits];

			int[] codersTmp = new int[numDigits];
			int[] jammersTmp = new int[numDigits];
			for (int i = 0; i < numDigits; i++) {
				codersTmp[i] = Math.Max (coderDigits[i], 0);
				jammersTmp[i] = Math.Max (jammerDigits[i], 0);
			}

			int maxCTry = (int)Math.Pow (10, numCQ + 1) - 1;
			int maxJTry = (int)Math.Pow (10, numJQ + 1) - 1;

			int optC = -1, optJ = -1;
			int minDiff = int.MaxValue;
			for (int i = 0; i < maxCTry; i++) {
				int currentC = 0, currentJ = 0;
				for (int j = 0; j < maxJTry; j++) {
					for (int k = 0; k < cMissingDigits.Count; k++) {
						codersTmp[cMissingDigits[k]] = nthDigit (i, cMissingDigits.Count - k);
					}
					for (int k = 0; k < jMissingDigits.Count; k++) {
						jammersTmp[jMissingDigits[k]] = nthDigit (j, jMissingDigits.Count - k);
					}

					currentC = 0;
					currentJ = 0;
					int currentMult = 1;

					for (int k = numDigits - 1; k >= 0; k--) {
						currentC += codersTmp[k] * currentMult;
						currentJ += jammersTmp[k] * currentMult;
					
						currentMult *= 10;
					}

					if (Math.Abs (currentC - currentJ) < minDiff) {
						optC = currentC;
						optJ = currentJ;
						minDiff = Math.Abs (currentC - currentJ);
					}
				}
				//Console.Write (currentC.ToString () + "\n");

			}

			
			return optC.ToString().PadLeft (numDigits, '0') + " " + optJ.ToString().PadLeft (numDigits, '0');
		}

		public static int nthDigit( int value , int n )
		{
			if ( n < 0 ) throw new ArgumentException();
			if ( value < 0 ) throw new ArgumentException() ;
			
			while ( n-- > 0 )
			{
				value /= 10 ;
			}
			
			int digit = value % 10 ;
			return digit ;
		}
	}
}
