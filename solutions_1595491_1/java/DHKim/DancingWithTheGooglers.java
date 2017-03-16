import java.io.*;
import java.util.*;

public class DancingWithTheGooglers {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static StringTokenizer st;

    public static void main ( String [] args ) throws IOException
    {
	int T = Integer.parseInt(br.readLine());

	for(int i = 0;i < T; i++) {
	    System.out.print("Case #" + (i+1) + ": ");
	    new DancingWithTheGooglers().cal();
	}
    }

 
    private void cal() throws IOException 
    {
	int N, S, p;
	
	st = new StringTokenizer(br.readLine());
	N = Integer.parseInt(st.nextToken());
	S = Integer.parseInt(st.nextToken());
	p = Integer.parseInt(st.nextToken());

	int [] t = new int [N];
	for(int i = 0; st.hasMoreTokens(); i++) 
	    t[i] = Integer.parseInt(st.nextToken());

	/*
	for(int i : t)
	    System.out.println(i);
	*/

	int num = 0;
	for(int n : t) {
	    int q = n / 3;
	    int r = n % 3;

	    //	    System.out.println(q + " " + r);

	  
	    if ( r == 0 && q >= p) {
		num++;
	    } else if ( r == 0 && q != 10 && q != 0 && q + 1 >= p && S > 0 ) {
		num++; S--;
	    }
	    else if ( r == 1 && q + 1 >= p) {
		num++;
	    } else if ( r == 2 && q + 1 >= p) {
		num++;
	    } else if ( r == 2 && q + 2 >= p && S > 0) {
		num++; S--;
	    }

	}

	System.out.println(num);
	
    }

}
