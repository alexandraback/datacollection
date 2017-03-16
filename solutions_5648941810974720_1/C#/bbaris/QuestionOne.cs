using System;
using System.IO;
using System.Collections.Generic;

namespace Round1B
{
	public class QuestionOne
	{	
		public QuestionOne () {}
		
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

			Dictionary<int, int> results = new Dictionary<int, int>(10);
			for (int i = 0; i < 10; i++) {
				results[i] = 0;
			}

			Dictionary<char, int> chars = new Dictionary<char, int>(30);
			string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			foreach (char c in alphabet) {
				chars[c] = 0;
			}
			foreach (char c in line) {
				if (!chars.ContainsKey (c)) {
					chars[c] = 0;
				}
				chars[c]++;
			}

			if (chars.ContainsKey ('Z')) {
				int numZ = chars['Z'];
				chars['Z'] -= numZ;
				chars['E'] -= numZ;
				chars['R'] -= numZ;
				chars['O'] -= numZ;
				results[0] = numZ;
			}
			if (chars.ContainsKey ('W')) {
				int num = chars['W'];
				chars['T'] -= num;
				chars['W'] -= num;
				chars['O'] -= num;
				results[2] = num;
			}
			if (chars.ContainsKey ('U')) {
				int num = chars['U'];
				chars['F'] -= num;
				chars['O'] -= num;
				chars['U'] -= num;
				chars['R'] -= num;
				results[4] = num;
			}
			if (chars.ContainsKey ('X')) {
				int num = chars['X'];
				chars['S'] -= num;
				chars['I'] -= num;
				chars['X'] -= num;
				results[6] = num;
			}
			if (chars.ContainsKey ('G')) {
				int num = chars['G'];
				chars['E'] -= num;
				chars['I'] -= num;
				chars['G'] -= num;
				chars['H'] -= num;
				chars['T'] -= num;
				results[8] = num;
			}
			if (chars.ContainsKey ('O')) {
				int num = chars['O'];
				chars['O'] -= num;
				chars['N'] -= num;
				chars['E'] -= num;
				results[1] = num;
			}
			if (chars.ContainsKey ('R')) {
				int num = chars['R'];
				chars['T'] -= num;
				chars['H'] -= num;
				chars['R'] -= num;
				chars['E'] -= num;
				chars['E'] -= num;
				results[3] = num;
			}
			if (chars.ContainsKey ('S')) {
				int num = chars['S'];
				chars['S'] -= num;
				chars['E'] -= num;
				chars['V'] -= num;
				chars['E'] -= num;
				chars['N'] -= num;
				results[7] = num;
			}
			if (chars.ContainsKey ('V')) {
				int num = chars['V'];
				chars['F'] -= num;
				chars['I'] -= num;
				chars['V'] -= num;
				chars['E'] -= num;
				results[5] = num;
			}
			if (chars.ContainsKey ('I')) {
				int num = chars['I'];
				chars['N'] -= num;
				chars['I'] -= num;
				chars['N'] -= num;
				chars['E'] -= num;
				results[9] = num;
			}

			string ret = "";
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < results[i]; j++) {
					ret += i.ToString ();
				}
			}

			return ret;
		}
	}
}
