import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
public class C {

	Scanner sc = new Scanner(System.in);
	ArrayList<Long> cands = new ArrayList<Long>();
	void doIt()
	{
		init_small();
		int T = sc.nextInt();
		for(int t = 1; t <= T; t++) {
			int ans = solve_small();
			System.out.print("Case #" + t + ": ");
			System.out.println(ans);
		}
	}
	int solve_small()
	{
		long A = sc.nextLong();
		long B = sc.nextLong();
		int idxa = Collections.binarySearch(cands, A);
		int idxb = Collections.binarySearch(cands, B);
		if(idxa < 0) idxa = - idxa - 1;
		if(idxb < 0) idxb = - idxb - 2;
		int ans = idxb - idxa + 1;
		if(ans < 0) return 0;
		else return ans;
	}
	void init_small()
	{
		//final long LIMIT = 1000;
		final long LIMIT = 100000000000000L; // 10^14
		for(long i = 1; ; i++) {
			if(! par(i)) continue; 
			long sq = i * i;
			if(par(sq)) {
				cands.add(sq);
				if(sq > LIMIT) break;
			}
		}
		//System.out.println(cands);
		for(long i = 1; i <= 20; i++) {
			int idx = Collections.binarySearch(cands, i);
			//System.out.println(i + ":" +  idx);
		}
	}
	boolean par(long n) {
		String a = Long.toString(n) ;
		String b = new StringBuilder(a).reverse().toString();
		return a.equals(b);
	}

	public static void main(String[] args) {
		new C().doIt();

	}

}

