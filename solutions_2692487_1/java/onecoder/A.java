import java.util.*;


public class A {
	static Scanner sc = new Scanner(System.in);
	
	private static void solve() {

		int T = sc.nextInt();
		for(int test =  1 ; test <= T; test++){
			int A = sc.nextInt();
			int N = sc.nextInt();
			int[] ar = new int[N];
			for (int i = 0; i < N; i++) {
				ar[i] = sc.nextInt();
			}
			Arrays.sort(ar);
			boolean fl  = false;
			int ans = 0;
			int crt = A;
			int thisans  = 0;
			if(A==1){
				System.out.println("Case #"+test+": "+N);
				continue;
			}
			for (int i = 0; i < ar.length; i++) {
				if(crt >10000002)break;
				int th = crt;
				if(ar[i]<crt)crt+=ar[i];
				else{
					thisans  = 0;
					while(ar[i]>=th){
						th = th + th - 1;
						thisans++;
					}
					if( thisans > N-i) {
						thisans =  N-i;
						fl = true;
					}
				
				
				if(!fl){
					ans += thisans;
					crt = th+ar[i];
					//System.out.println(i +"  "+crt  +"  " +ans);
				}
					else {
						ans += thisans;
						break;
					}
				}
			}
			if(ans > N)ans = N;;
			System.out.println("Case #"+test+": "+ans);
		}
	}
	
	public static void main(String[] args) {
		solve();
	}
	
}
