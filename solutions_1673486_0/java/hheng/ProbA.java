import java.util.*;
import java.io.*;
import java.lang.*;

class ProbA { 
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = Integer.parseInt(sc.nextLine());
    
    for (int c=0; c<T; c++) {
    	int A = sc.nextInt(); // typed
    	int B = sc.nextInt(); // total number
    	double[] prob = new double[A];
    	for (int i=0; i<A; i++) prob[i] = sc.nextDouble();
    	double[] allR = new double[A];
    	allR[0] = prob[0];
    	for (int i=1; i<A; i++) allR[i] = allR[i-1] * prob[i];
    	
    	// how many wrong?
    	double minStroke = Double.MAX_VALUE;
    	for (int i=0; i<=A; i++) {
    		double d = 0.0;
    		if (A-i-1 >= 0) d = allR[A-i-1]; // A-i-1 correct
    		else d = 0.0;
    		//System.out.println(d);
    		double strokes = 0.0;
    		strokes += d * (double)(B-A+2*i+1);
    		//System.out.println(B-A-i+1);
    		if (A-i-1 >= 0) strokes += (1-d) * (double)(B-A+2*i+1+B+1);
    		else strokes += (1-d) * (double)(B-A+2*i+1);
    		//System.out.println(strokes);
    		minStroke = Math.min(minStroke, strokes);
    	}
    	minStroke = Math.min(minStroke, 1+B+1);
    	
    	System.out.println("Case #" + (c+1) + ": " + minStroke);
    }
  }
}


