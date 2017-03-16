import java.io.*;
import java.util.*;

public class PasswordProblem  {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static StringTokenizer st;

    public static void main ( String [] args ) throws IOException
    {
	int T = Integer.parseInt(br.readLine());

	for(int i = 0;i < T; i++) {
	    System.out.print("Case #" + (i+1) + ": ");
	    new PasswordProblem().cal();
	}
    }

 
    private void cal() throws IOException 
    {
	int A, B;
	st = new StringTokenizer(br.readLine());
	A = Integer.parseInt(st.nextToken());
	B = Integer.parseInt(st.nextToken());

	double [] p = new double [A+1];
	double [] Pn = new double[A];

	st = new StringTokenizer(br.readLine());
	for(int i = 1; i <= A; i++)
	    p[i] = Double.parseDouble(st.nextToken());

	Pn[A-1] = p[1];
	for(int i = 1; i < A; i++) {
	    Pn[A-i-1] = Pn[A-i] * p[i+1];
	}

	//	for(double d : Pn)
	    //	    System.out.printf("%.6f\n", d);

	double [] E = new double[A+2];
	for(int i = 0; i < A; i++) 
	    E[i] = 2 * i + ( B - A + 1 ) + ( 1 - Pn[i] ) * ( B+1);
	E[A] = A + B + 1;
	E[A+1] = B + 2;

	Arrays.sort(E);
	
	System.out.printf("%.6f\n", E[0]);
	

    }

}
