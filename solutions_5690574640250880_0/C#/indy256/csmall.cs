using System;
using System.IO;

public class Template {

	public static void Main() {
		string name = "C-small-attempt0";
		string path = "";
		
		TextReader reader = new StreamReader(path + name + ".in");
		TextWriter writer = new StreamWriter(path + name + ".out");
		
//		TextReader reader = System.Console.In;
//		TextWriter writer = System.Console.Out;

		int testCases = int.Parse(reader.ReadLine());

		for (int testCase = 1; testCase <= testCases; testCase++) {			
			string[] line = reader.ReadLine().Split(' ');
			int R = int.Parse(line[0]);
			int C = int.Parse(line[1]);
			int M = int.Parse(line[2]);
			
			writer.WriteLine("Case #{0}:", testCase);

			for (int rows = 1; rows <= R; rows++) {
				for (int cols = 1; cols <= C; cols++) {
					for (int r = 0; r <= rows; r++) {
						for (int c = 0; c <= cols; c++) {
							if (rows * cols + r + c != R * C - M)
								continue;
						    if (rows == R && c > 0 || cols == C && r > 0)
						    	continue;
						    if (r == 1 || c == 1)
						    	continue;
						    if (rows * cols != 1 && (rows == 1 && R > 1 || cols == 1 && C > 1))
						    	continue;
						    	
						    for (int i = 0; i < R; i++) {
						    	for (int j = 0; j < C; j++) {
						    		if (i == 0 && j == 0)
   								    	writer.Write("c");
						    		else if (i < rows && j < cols || i == rows && j < c || j == cols && i < r)
   								    	writer.Write(".");
						    		else
   								    	writer.Write("*");   								    	
						    	}
						    	writer.WriteLine("");
						    }
						    goto m1;
						}
					}					
				}
			}
 
			writer.WriteLine("Impossible");
			m1:
			writer.Flush();
		}

		writer.Close();
		reader.Close();
	}
}
