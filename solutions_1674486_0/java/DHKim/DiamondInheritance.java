import java.io.*;
import java.util.*;

public class DiamondInheritance  {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static StringTokenizer st;

    public static void main ( String [] args ) throws IOException
    {
	int T = Integer.parseInt(br.readLine());

	for(int i = 0;i < T; i++) {
	    System.out.print("Case #" + (i+1) + ": ");
	    new DiamondInheritance().cal();
	}
    }

    private boolean [][] link;
    private int N;

    private void cal() throws IOException 
    {
	boolean ret = false;
	
	N = Integer.parseInt(br.readLine());
	link = new boolean[N+1][N+1];
	
	for(int i = 1; i <= N; i++) {
	    st = new StringTokenizer(br.readLine());

	    int n = Integer.parseInt(st.nextToken());
	    while(st.hasMoreTokens()) {
		int j = Integer.parseInt(st.nextToken());
		link[i][j] = true;
	    }
	}

	for(int i = 1; i <= N; i++)
	    for(int j = 1; j <= N; j++) {
		if ( i == j ) continue;

		if ( func(i, j) >= 2 ) {
		    System.out.println("Yes");
		    return;
		}
	    }
	System.out.println("No");	

    }
    
    private int func(int X, int Y) {
	int ret = 0;
	for(int i = 1; i <= N; i++)  {
	    if ( X == i ) continue;
	    else if ( link[X][i]  && i != Y ) ret += func(i, Y);
	    else if ( link[X][i]  && i == Y ) ret += 1;
	}
	return ret;
    }

}
