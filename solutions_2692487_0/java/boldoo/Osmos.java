import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Osmos {

	/**
	 * @param args
	 */
	
	
	public static int solve(int[] a, int me) {
		if (me == 1) return 1000;
		int res = 0;
		for (int i = 0; i < a.length; i++) {
			while (me <= a[i]) {
				me += me - 1;
				res++;
			}
			
			me += a[i];
		}
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(new File("output.txt"));
		
		int T = s.nextInt();
		int it=0;
		while(T-- > 0){
			it++;
			
			int A = s.nextInt();
			int N = s.nextInt();
			
			int[] motes = new int[N];
			int total = 0;
			
			for(int i=0; i<N; i++){
				motes[i] = s.nextInt();
			}
			
			Arrays.sort(motes);
			
/*			total = N;
			for (int i = N; i >= 1; i--) {
				int[] a = new int[i - 1];
				for (int j = 0; j < i - 1; j++)
					a[j] = motes[j];
				total = Math.min(total, solve(a, A) + N - i);
				if (total == 0) {
					pw.println("DEBUG " + i);
				}
			}*/
			
			total = 0;
			
			int i=0;
			for(; i<N; i++){
				if(motes[i] < A){
					A += motes[i];
				}else{
					break;
				}
			}		
			
			if(i != N){
				
				if(A == 1){
					total = N-i;
				}else{
					for(int j=0; j<=N-i; j++){
						int tmpA = A;
						int tmpTotal = j;
						for(int k=i; k<N-j; k++){
							while(motes[k] >= tmpA){
								tmpTotal++;
								tmpA += (tmpA - 1);
							}
							tmpA += motes[k];
						}
						if(j == 0 || tmpTotal < total){
							total = tmpTotal;
						}
					}
				}
				
				
			}
			
			pw.printf("Case #%d: %d\n", it, total);
			
		}
		
		pw.close();
	}

}
