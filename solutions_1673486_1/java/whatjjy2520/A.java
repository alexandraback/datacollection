import java.io.*;
import java.util.*;
import java.text.*;
public class A {
  public static void main (String[] args) throws IOException {
    DecimalFormat d = new DecimalFormat("0.000000");
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	int T = Integer.parseInt(in.readLine());
	for (int t = 0; t < T; t++) {
	  StringTokenizer st = new StringTokenizer(in.readLine());
	  int A = Integer.parseInt(st.nextToken());
	  int B = Integer.parseInt(st.nextToken());
	  double[] prob = new double[A];
	  st = new StringTokenizer(in.readLine());
	  for (int i = 0; i < A; i++)
	    prob[i] = Double.parseDouble(st.nextToken());
	  for (int i = 1; i < A; i++)
	    prob[i] = prob[i]*prob[i-1];
	  //for (int i = 0; i < A; i++)
	  //  System.out.println(prob[i]);
	  
	  double best = B+2;
	  for (int i = 0; i < A; i++) {
	    double exp = (A-1-i) + (B-i) + (1-prob[i])*(B+1);
		if (exp < best)
		  best = exp;
	  }
	  System.out.printf("Case #%d: %.6f\n", t+1, best);
	  
	}
	
	in.close();
  }
}