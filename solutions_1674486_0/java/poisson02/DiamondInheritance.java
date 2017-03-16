import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormatSymbols;


public class DiamondInheritance {
	 public static void main(String[] args) throws IOException
	 {
		  if(args.length < 2) 
		  {
			  System.err.println("Please enter the Valid I/O Paths in the argument ");
			  System.err.println("First Input , then OutPut ");
			  args = new String[2];
			  args[0] = "C:\\CodeJam\\Test.in";
			  args[1] = "C:\\CodeJam\\Test1.out";
		  }
		  File inFile = new File(args[0]);
		  File outFile = new File(args[1]);
		  BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(inFile)));
		  PrintWriter out = new PrintWriter(new FileOutputStream(outFile));
		  String myLine = in.readLine();
		  int t = Integer.parseInt(myLine);
		  int caseNum = 1;
		  while(t-- > 0)
		  {
			  myLine = in.readLine();
			  int n = Integer.parseInt(myLine);
			
			  boolean[][] graph = new boolean[n][n];
			  int[][] path = new int[n][n];
			  for(int i = 0 ; i < n; i++)
				  {
				  myLine = in.readLine();
				  String[] myChars = myLine.split(" ");
				  int m = Integer.parseInt(myChars[0]);
				  for(int j = 1; j <= m; j++)
				  {
					  path[i][Integer.parseInt(myChars[j])-1] = 1;
				  }
				  }
			 
			  boolean isDiamond = false;
			  for(int i = 0 ; i < n ; i++)
			  {
				  for(int j = 0 ; j < n; j++)
					  
					  for(int k = 0 ; k < n ; k++)
					  {
						  if(path[j][k] > 0 && (path[i][k]) > 0 && path[j][i] > 0)
							  isDiamond = true;
						  else if(path[i][k] > 0 && path[j][i] > 0)
						  path[j][k] = 1;
					  }
			  }
			  String myStr = isDiamond ? "Yes":"No";
			  out.println("Case #"+(caseNum)+": "+myStr);
			  caseNum++;
		  }
		  out.close();
	 }
}
