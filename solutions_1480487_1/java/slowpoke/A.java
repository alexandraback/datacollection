import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	static int count = 0;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter pw = new PrintWriter("A-large.out");
//		Scanner sc = new Scanner(new File("A-small-attempt1.in"));
//		PrintWriter pw = new PrintWriter("A-small-attempt1.out");
//		Scanner sc = new Scanner(new File("A-small.in"));
//		PrintWriter pw = new PrintWriter("A-small.out");
		
		int tc = sc.nextInt();
		for(int t=1; t<=tc; t++){
			int N = sc.nextInt();
			int[] p = new int[N];
			int sum = 0;
			for(int i=0; i<N; i++){
				p[i] = sc.nextInt();
				sum += p[i];
			}
			double avg = sum*2/(double)N;
			int num = 0;
			int targetSum = 0;
			for(int i=0; i<N; i++){
				if(p[i]<avg){
					num++;
					targetSum += p[i];
				}
			}
			double target = (sum+targetSum)/(double)num;
			
			pw.print("Case #" + t + ": ");
			for(int i=0; i<N; i++){
				if(p[i]>=target){
					pw.print("0");
				}else{
					pw.print((target-p[i])*100/sum);
				}
				if(i<N-1)
					pw.print(" ");
			}
			pw.println();
		}
		
		pw.close();
		sc.close();
	}
		
}
