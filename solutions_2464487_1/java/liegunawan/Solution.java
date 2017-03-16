import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.math.*;

public class Solution {
  public void writeOutputToFile(String output, String filepath) throws IOException {
    FileWriter fstream = new FileWriter(filepath);
    BufferedWriter out = new BufferedWriter(fstream);
    out.write(output);
    out.flush();
    out.close();
  }
  
  public BigInteger docase(String []s) {
  	BigInteger r = new BigInteger(s[0]);
  	BigInteger t = new BigInteger(s[1]);

	BigInteger a = r.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(1));
	BigInteger b;
	BigInteger low = BigInteger.valueOf(0);
	BigInteger mid;
	BigInteger high = t;
	BigInteger maxn = BigInteger.valueOf(0);
	BigInteger sum;
	
	while (low.compareTo(high) <= 0) {
		mid = low.add(high);
		mid = mid.divide(BigInteger.valueOf(2));
		
		b = mid.subtract(BigInteger.valueOf(1)).multiply(BigInteger.valueOf(4));
		b = b.add(a);
		sum = a.add(b).multiply(mid).divide(BigInteger.valueOf(2));
		
		if (sum.compareTo(t) <= 0) {
			low = mid.add(BigInteger.valueOf(1));
			if (maxn.compareTo(mid) < 0)
				maxn = mid;
		} else {
			high = mid.subtract(BigInteger.valueOf(1));
		}
	}
	
  	return maxn;
  }

  public static void main(String[] args) {
    if (args.length < 2) {
      System.out.println("Not enough command line arguments specified. Need 2 (Input and output file paths)");
      return;
    }

    String inputFilePath = args[0];
    try {
      // String buffer for storing the output
      StringBuffer output = new StringBuffer();

      // Instantiate object to use non static methods
      Solution kr = new Solution();

      // read and parse input file
      FileInputStream fstream = new FileInputStream(inputFilePath);
      DataInputStream in = new DataInputStream(fstream);
      BufferedReader br = new BufferedReader(new InputStreamReader(in));
      String s;

      int t = -1;
      int activeTestCaseNumber = 0;
      int noOfLevelsInTestCase = -1;
      int levelNumberInTestCase = -1;

		s = br.readLine();
		t = Integer.parseInt(s);
		
		for (int i=0; i<t; i++) {
			s = br.readLine();
			BigInteger res = kr.docase(s.split(" "));
	      output.append("Case #" + (i+1) + ": " + res + "\n");
		}

      in.close();

      // Pass output string to method to write to file
      kr.writeOutputToFile(output.toString(), args[1]);
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
    finally
    {
      // File read cleanup
    }
  }
}