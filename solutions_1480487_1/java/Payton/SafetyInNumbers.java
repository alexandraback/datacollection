import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class SafetyInNumbers {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
		int cases = sc.nextInt();
		for(int ctr=0; ctr<cases; ctr++){
			int n = sc.nextInt();
			int sum = 0;
			int[] arr = new int[n];
			for(int i=0; i<n; i++){
				arr[i] = sc.nextInt();
				sum += arr[i];
			}
			double nrec = 1.0/n;
			boolean[] shoe = new boolean[n];
			for(int i=0; i<n; i++){
				if(arr[i]/(2.0*sum) >= nrec){
					shoe[i] = true;
				}
			}
			int m = 0;
			int losersum = 0;
			for(int i=0; i<n; i++){
				if(!shoe[i]){
					losersum += arr[i];
					m++;
				}
			}
			double pointpool = losersum/(2.0*sum) + 0.5;
			double mrec = 1.0/m;
			double minpts = pointpool*mrec;
			
			out.printf("Case #%d:", ctr+1);
			for(int i=0; i<n; i++){
				if(shoe[i]){
					out.printf(" %.5f", 0.0);
				}else{
					double currpts = arr[i]/((double)sum);
					out.printf(" %.5f", 100*(2*minpts - currpts));
				}
			}
			out.println();
		}
		out.flush();
	}
}
