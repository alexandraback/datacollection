package y2012;

import java.io.*;
import java.util.Arrays;

public class Glob {

  /**
  * Fetch the entire contents of a text file, and return it in a String.
  * This style of implementation does not throw Exceptions to the caller.
  *
  * @param aFile is a file which already exists and can be read.
  */
  static public void IOwork() {
    //...checks on aFile are elided
    try {
      //use buffering, reading one line at a time
      //FileReader always assumes default encoding is OK!
      BufferedReader input =  new BufferedReader(new FileReader(new File("F:\\file.in")));
      Writer output = new BufferedWriter(new FileWriter(new File("F:\\file.out")));
      try {
        String line = null; //not declared within while loop
        /*
        * readLine is a bit quirky :
        * it returns the content of a line MINUS the newline.
        * it returns null only for the END of the stream.
        * it returns an empty String if two newlines appear in a row.
        */
        line = input.readLine();
        int NoOfCases = Integer.parseInt(line);
        for (int i = 0; i < NoOfCases; i++) {
        	line = input.readLine();
        	int NoNum = Integer.parseInt(line)+1;
        	boolean diamond = true;
        	int[][] relations = new int[NoNum][NoNum];
        	for (int j = 0; j < NoNum; j++) {
        		for (int k = 0; k < NoNum; k++) {
        			relations[j][k] = 0;
        		}
        	}
        	for (int j = 1; j < NoNum; j++) {
        		line = input.readLine();
        		String[] temp = line.split(" ");
        		System.out.println(temp.length);
        		for (int k = 1; k < temp.length; k++) {
        			int tmp = Integer.parseInt(temp[k]);
        			//System.out.println(tmp);
        			relations[tmp][j] = 1;
        		}
        	}
        	for (int j = 0; j < NoNum; j++) {
        		int[] visit = new int[NoNum];
        		int[] q = new int[50000];
        		q[0] = j;
        		int qr = 0; int qw = 1;
        		while (qr != qw) {
        			for (int k = 0; k < NoNum; k++) {
        				if (relations[q[qr]][k] > 0) {
        					q[qw] = k;
        					qw++;
        					visit[k]++;
        				}
        			}
        			qr++;
        		}
        		for (int k = 0; k < NoNum; k++) {
        			if (visit[k] > 1) diamond = false; 
        		}
        	}
        	if (diamond) output.write("Case #"+(i+1)+": No\n");
        	else output.write("Case #"+(i+1)+": Yes\n");
        }
      }
      finally {
        input.close();
        output.close();
      }
    }
    catch (IOException ex){
      ex.printStackTrace();
    }
  }
  
  private static int rope(int[][] lines) {
	  int ans = 0;
	  for (int i = 0; i < lines.length-1; i++){
		  for (int j = i+1; j < lines.length; j++) {
			  if ((lines[i][0] > lines[j][0] && lines[i][1] < lines[j][1])||(lines[i][0] < lines[j][0] && lines[i][1] > lines[j][1]))
				  ans++;
		  }
	  }
	return ans;
  }
  
  public static void main (String[] aArguments) throws IOException {
	  IOwork();
	  }
}