import java.io.*;
import java.util.*;

public class KingdomRush  {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static StringTokenizer st;

    public static void main ( String [] args ) throws IOException
    {
	int T = Integer.parseInt(br.readLine());

	for(int i = 0;i < T; i++) {
	    System.out.print("Case #" + (i+1) + ": ");
	    new KingdomRush().cal();
	}
    }

 
    private void cal() throws IOException 
    {
	int N = Integer.parseInt(br.readLine());
	int [] a = new int[N];
	int [] b = new int[N];
	int [] s = new int[N];
	int star = 0;
	int t = 0;

	for(int i = 0; i < N; i++){
	    st = new StringTokenizer(br.readLine());
	    a[i] = Integer.parseInt(st.nextToken());
	    b[i] = Integer.parseInt(st.nextToken());
	}

	while(!isDone(s)) {
	    boolean f = false;
	    for(int i = 0; i < N; i++)
		if ( s[i] != 2 &&  star >= b[i] ) {
		    s[i] = 2;
		    t++;
		    f = true;
		    break;
		}

	    if ( !f ) {
		for(int i = 0; i < N; i++)
		    if ( s[i] != 1 && s[i] != 2 && star >= a[i] ) {
			s[i] = 1;
			t++;
			f = true;
			break;
		    }
	    }

	    if ( !f ) {
		System.out.println("Too Bad");
		return;
	    }

	    star = 0;
	    for(int i : s )  
		star += i;
	    /*
	    for(int i = 0; i < N; i++)
		System.out.printf("[%d] a: %d b: %d s: %d star: %d t: %d\n", i, a[i], b[i], s[i], star, t);
	    */


	    
	}
	    
	System.out.println(t);

    }

    private boolean isDone(int [] n) {
	for(int i : n )
	    if ( i != 2 ) return false;

	return true;
    }

}
