using System;
using System.IO;
using System.Collections.Generic;

namespace Round1B
{
	public class QuestionThree
	{	
		public QuestionThree () {}
		
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
			int N = int.Parse (line);

			List<Tuple<string, string>> topics = new List<Tuple<string, string>> (16);
			for (int i = 0; i < N; i++) {
				line = reader.ReadLine();
				string[] parts = line.Split (new char[] {' '});
				Tuple<string, string> topic = new Tuple<string, string> (parts[0], parts[1]);
				topics.Add (topic);
			}

			int[] digits = new int[N];
			for (int i = 0; i < N; i++) {
				digits[i] = 0;
			}

			Dictionary<string, bool> firstWords = new Dictionary<string, bool> (100);
			Dictionary<string, bool> secondWords = new Dictionary<string, bool> (100);

			bool cont = true;
			int bestFake = 0;
			while (cont) {
				digits[0]++;
				for (int i = 0; i < N-1; i++) {
					if (digits[i] == 2) {	
						digits[i] = 0;
						digits[i+1]++;
					}
				}
				if (digits[N-1] == 2) {
					cont = false;
					break;
				}

				firstWords.Clear ();
				secondWords.Clear ();


				for (int i = 0; i < N; i++) {
					if (digits[i] == 1) {
						firstWords[topics[i].Item1] = true;
						secondWords[topics[i].Item2] = true;
					}
				}
				int currentFake = 0;
				for (int i = 0; i < N; i++) {
					if (digits[i] == 0 && (firstWords.ContainsKey (topics[i].Item1) && secondWords.ContainsKey (topics[i].Item2)))
						currentFake++;
				}
				if (currentFake > bestFake)
					bestFake = currentFake;
			}




			
			/*
			string[] parts = line.Split (new char[] {' '});
			for (int j = 0; j < N; j++) {
				int height = Int32.Parse (parts[j]);
			}
*/
			
			return bestFake.ToString();
		}
	}
}
