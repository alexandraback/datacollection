import java.io.*;
import java.util.*;

public class Cookies {
	static PrintWriter pw = null;
	
	public static void main(String[] args) throws Exception {
	  BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
	  pw = new PrintWriter(new FileWriter("outLarge.txt"));
	  int nrTests = Integer.parseInt(br.readLine());
	  for(int test = 1; test <= nrTests; test++) {
	  	String[] strs = br.readLine().split(" ");
	  	double C = Double.parseDouble(strs[0]);
	  	double F = Double.parseDouble(strs[1]);
	  	double X = Double.parseDouble(strs[2]);
	  	
	  	double k = (X*F - 2 * C) / C / F;
	  	
	  	int ik = (int)(k + 1e-9);
	  	if(ik < 0) {
	  		ik = 0;
	  	}
	  	
	  	double res = 0;
	  	for(int i = 0; i < ik; i++) {
	  		res += C / (2 + i * F);
	  	}
	  	
	  	res += X / (2 + ik * F);
	  	writeOut(test, String.valueOf(res));
	  }
	  
	  pw.close();
  }
	
	static void writeOut(int testNr, String res) {
		pw.println("Case #" + testNr + ": " + res);
	}
}
