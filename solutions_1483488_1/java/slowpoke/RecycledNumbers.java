import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class RecycledNumbers {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("C-large.in"));
		PrintWriter pw = new PrintWriter("C-large.out");
		
		int tc = sc.nextInt();
		for(int t=1; t<=tc; t++){
			int A = sc.nextInt();
			int B = sc.nextInt();
			pw.println("Case #" + t + ": " + count(A,B));
		}
		pw.close();
		sc.close();
	}

	private static long count(int a, int b) {
		boolean[] flag = new boolean[b-a+1];
		long gsum = 0;
		for(int v=Math.max(a, 12); v<b; v++){
			long sum = 1;
			int i = v;
			if(flag[i-a]) continue;
			int exp = 1;
			while(i>0){
				i/=10;
				exp *= 10;
			}
			i = v;
			for(int e=10; e<exp; e*=10){
				int right = i%e;
				if(right < (e/10)) continue;
				int left = i/e;
				int num = right * (exp/e) + left;
				if(num == i) break;
				if(num >= a && num <= b){
					flag[num-a] = true;
					sum++;
				}
			}
			gsum += (sum*(sum-1)/2);
		}
		return gsum;
	}

}
