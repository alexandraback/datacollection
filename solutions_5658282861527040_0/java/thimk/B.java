import java.util.*;

public class B
{
    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();

	for(int caseno = 1; caseno <= T; caseno++){
	    int A = in.nextInt();
	    int B = in.nextInt();
	    int K = in.nextInt();
	    
	    int ans = 0;
	    for(int a = 0; a < A; a++)
		for(int b = 0; b < B; b++)
		    if((a&b) < K) ans++;

	    System.out.println("Case #" + caseno + ": " + ans);

	}

    }

}
