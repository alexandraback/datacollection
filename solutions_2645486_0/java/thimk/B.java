import java.util.*;

public class B
{
    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);

	int T = in.nextInt();

	int v[] = new int[10000];
	

	for(int caseno = 1; caseno <= T; caseno++){
	    System.out.print("Case #" + caseno + ": ");
	    int E = in.nextInt();
	    int R = in.nextInt();
	    int N = in.nextInt();

	    if(R >= E){
		long tot = 0;
		for(int i = 0; i < N; i++)
		    tot += in.nextInt();
		tot *= E;
		System.out.println(tot);
		continue;
	    }

	    for(int i = 0; i < N; i++)
		v[i] = in.nextInt();
	    
	    int b = 0;
	    int c = N-1;
	    long tot = 0;

	    while(c > 0){
		int s = c - 1;
		int m = s;
		while(s > 0 && v[s] <= v[c] && (c-s+1)*R <= E){
		    s--;
		    if(v[s] >= v[m])
			m = s;
		    
		}
		if(v[s] > v[c]){
		    tot += ((c-s)*R - b)*v[c];
		    b = 0;
		    c = s;
		}
		else{
		    tot += (E-b)*v[c];
		    b = E - (c-m)*R;
		    c = m;
		}
		//System.out.println(" "+ c +", " + s +", " +b);
	    }
	    tot += (E-b)*v[0];

	    System.out.println(tot);

	}
    }

}