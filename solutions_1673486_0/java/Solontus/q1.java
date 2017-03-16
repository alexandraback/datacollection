import java.io.*;
import java.util.*;
public class q1{
    public static void main (String[] args) throws IOException 
    {
	BufferedReader input = new BufferedReader (new FileReader ("A-small-attempt0.txt"));
	PrintWriter output = new PrintWriter (new FileWriter("test1Max.txt"));
	StringTokenizer st;
	
	int numlines = Integer.parseInt(input.readLine());
	for(int i = 0; i < numlines; i++){
	    st = new StringTokenizer(input.readLine());
	    int A = Integer.parseInt(st.nextToken());
	    int B = Integer.parseInt(st.nextToken());
	    st = new StringTokenizer(input.readLine());
	    double[] probs = new double[A];
	    for(int j = 0; j < A; j++){
		probs[j] = Double.parseDouble(st.nextToken());
	    }
	    double tempProb1;
	    tempProb1 = 1;
	    for(int j = 0; j < A; j++){
		tempProb1 *= probs[j];
	    }
	    double S1 = tempProb1 * (double)(B - A + 1) + (1.0 - tempProb1) * (double)(1 + B - A + B + 1);
	    double [] S2Cases = new double[A];
	    for(int j = 1; j < A+1; j++){
		double Q = 1;
		for(int k = 0; k < A-j; k++){
		    Q *= probs[k];
		}
		S2Cases[j-1] = Q * (double)(j + j + B - A + 1) + (1.0 - Q) * (double)(j + j + B - A + 1 + B + 1);
		//output.println(S2Cases[j-1] + " " + Q);
	    }
	    double S2 = S2Cases[0];
	    for(int j = 0; j < A; j++){
		if(S2Cases[j] < S2)
		    S2 = S2Cases[j];
	    }
	    double S3 = B + 2;
	    double best = S1;
	    if(best > S2)
		best = S2;
	    if(best > S3)
		best = S3;
	    //output.println(S1 + " " + S2 + " " + S3);
	    output.println("Case #" + (i + 1) + ": " + best);
	}
	output.close();
    }
}
