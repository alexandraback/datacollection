using System;
using System.IO;


namespace Round1B
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			FileInfo[] allFiles = new DirectoryInfo ("/Users/baris/Desktop/CodeJam_INPUT").GetFiles();
			FileInfo[] files = Array.FindAll (allFiles, file => ((file.Attributes & FileAttributes.Hidden) != FileAttributes.Hidden));
			
			if (files.Length != 1) {
				Console.Write ("Wrong number of files in CodeJamInput!");
				return;
			}
			
			FileInfo fi = files[0];
			StreamReader reader = fi.OpenText();
			
			QuestionOne one = new QuestionOne();
			string output = one.Solve (reader);
			
			File.WriteAllText ("/Users/baris/Desktop/CodeJam_OUTPUT/output.txt", output);
			reader.Close();
			
			return;
		}
	}
}
