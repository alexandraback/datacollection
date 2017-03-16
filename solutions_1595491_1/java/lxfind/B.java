import java.util.*;
public class B {

	/**
	 * @param args
	 */
	private static boolean sup(int i,int j,int k) {
		return (Math.abs(i-j)==2 || Math.abs(i-k)==2 || Math.abs(j-k)==2);
	}
	
	private static boolean[] analyze(int x, int p) {
		int i,j,k;
		boolean ret[] = new boolean[4];
		for (i=0;i<=10;i++) {
			for (j=0;j<=10;j++) {
				if (Math.abs(i-j)<=2) {
					k = x-i-j;
					if (k>=0 && k<=10 && Math.abs(k-i)<=2 && Math.abs(k-j)<=2) {
						if (i>=p || j>=p || k>=p) {
							if (sup(i,j,k)) {
								ret[0] = true;
							} else {
								ret[1] = true;
							}
						} else if (sup(i,j,k)) {
							ret[2] = true;
						} else {
							ret[3] = true;
						}
					}
				}
			}
		}
		return ret;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int i,j;
		for (i=1;i<=T;i++) {
			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();
			int overp = 0;			
			int condp = 0;
			int result;
			for (j=0;j<N;j++) {
				int x = in.nextInt();
				if (x>(p-1)*3) {
					overp++;					
				} else if (x<3*p-4 || p==1) {					
				} else {
					condp++; 
				}
			}
			result = Math.min(S, condp) + overp;
			System.out.println("Case #"+i+": "+result);
		}
	}

}
