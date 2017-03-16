import java.io.*;
import java.util.*;

public class RecycledNumbers  {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static StringTokenizer st;

    public static void main ( String [] args ) throws IOException
    {
	int T = Integer.parseInt(br.readLine());

	for(int i = 0;i < T; i++) {
	    System.out.print("Case #" + (i+1) + ": ");
	    new RecycledNumbers().cal();
	}
    }

 
    private void cal() throws IOException 
    {
	int A, B;
	st = new StringTokenizer(br.readLine());
	A = Integer.parseInt(st.nextToken());
	B = Integer.parseInt(st.nextToken());

	int len = Integer.toString(A).length();
	//	if ( len == 1 ) System.out.println("0");


	int num = 0;
	for(int n = A; n < B; n++) {
	    HashSet<Integer> s = new HashSet<Integer>();
	    for(int i = 1; i < len; i++) {
		int m = getRecycledNumbers(n, i);
		if ( n < m && m <= B && !s.contains(m)) {
		    //		    System.out.println("[" + num + "] (n,m) = (" + n + "," + m + ")");
		    s.add(m);
		    num++;
		}
	    }
	}

	System.out.println(num);

    }

    private int getRecycledNumbers(int n, int i) {
	String target = Integer.toString(n);
	String compared = target.substring(i) + target.substring(0, i);
	return Integer.parseInt(compared);
    }

}
