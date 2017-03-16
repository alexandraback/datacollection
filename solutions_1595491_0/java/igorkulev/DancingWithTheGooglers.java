import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class DancingWithTheGooglers {
	
	static int N,S,p;
	static int t[];
	
	static int solve() {
		int i,j,k;
		int a,b,c;
		
		int opt[][] = new int[N+1][S+1];
		boolean canMakeOne, goodScoreCaseOneBigger, goodScoreCaseOneSmaller;
		boolean canMakeTwo, goodScoreCaseTwoBigger, goodScoreCaseTwoSmaller;
		
		for (i=1;i<=N;i++) {
			
			// we need to get t[i]
			canMakeOne = false;
			goodScoreCaseOneBigger = false;
			goodScoreCaseOneSmaller = false;
			canMakeTwo = false;
			goodScoreCaseTwoBigger = false;
			goodScoreCaseTwoSmaller = false;

			for (a=0;a<=10;a++) {
				for (b=a;(b<=a+2)&&(b<=10);b++) {
					for (c=b;(c<=a+2)&&(c<=10);c++) {
						if ((a+b+c) == t[i]) {
							if ((c-a) <= 1) {
								canMakeOne = true;
								if (c >= p)
									goodScoreCaseOneBigger = true;
								else
									goodScoreCaseOneSmaller = true;
							} else {
								canMakeTwo = true;
								if (c >= p)
									goodScoreCaseTwoBigger = true;
								else
									goodScoreCaseTwoSmaller = true;
							}
						}
					}
				}
			}
			
			if (canMakeOne == true) {
				
				if (goodScoreCaseOneBigger == true) {
					for (j=0;j<=S;j++) {
						opt[i][j] = Math.max(opt[i][j], opt[i-1][j]+1);
					}
				}
				
				if (goodScoreCaseOneSmaller == true) {
					for (j=0;j<=S;j++) {
						opt[i][j] = Math.max(opt[i][j], opt[i-1][j]);
					}
				}
				
			}
			
			if (canMakeTwo == true) {
				
				if (goodScoreCaseTwoBigger == true) {
					for (j=1;j<=S;j++) {
						opt[i][j] = Math.max(opt[i][j], opt[i-1][j-1]+1);
					}
				}
				
				if (goodScoreCaseTwoSmaller == true) {
					for (j=1;j<=S;j++) {
						opt[i][j] = Math.max(opt[i][j], opt[i-1][j-1]);
					}
				}
				
			}
			
		}
		
		return opt[N][S];
	}
	
	public static void main(String[] args) throws Exception {
		int i,j,k;
		
		BufferedReader br = new BufferedReader(new FileReader("B-small.in"));
		PrintWriter out = new PrintWriter("B-small.out");
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for (k=1;k<=T;k++) {
			
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			S = Integer.parseInt(st.nextToken());
			p = Integer.parseInt(st.nextToken());
			t = new int[N+1];
			
			for (i=1;i<=N;i++)
				t[i] = Integer.parseInt(st.nextToken());
			
			out.println("Case #"+k+": "+solve());
			
		}
		
		out.close();
		
	}

}
