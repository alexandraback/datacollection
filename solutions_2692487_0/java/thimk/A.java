import java.util.*;

public class A
{
    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);

	int T = in.nextInt();

	for(int caseno = 1; caseno <= T; caseno++){
	    System.out.print("Case #" + caseno + ": ");

	    long A;
	    long cur;

	    int m[];
	    int N;


	    A = in.nextInt();
	    N = in.nextInt();
	    
	    m = new int[N];
	    for(int i = 0; i < N; i++)
		m[i] = in.nextInt();

	    Arrays.sort(m);

	    int best = N;
	    if(A == 1){
		System.out.println(N);
		continue;
	    }
	    for(int i = 1; i <= N; i++){
		cur = A;
		int nextM = 0;
		int added = 0;
		while(nextM < i){
		    while(cur <= m[nextM]){
			cur *= 2;
			cur--;
			added++;
		    }
		    cur += m[nextM];
		    nextM++;
		}

		if(best > added + (N - i))
		    best = added + (N-i);
	    }

	    System.out.println(best);
	}
    }

}