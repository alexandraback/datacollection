import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class C {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner=new Scanner(new File("E:\\C-small-attempt2.in"));
		PrintWriter printWriter=new PrintWriter(new File("E:\\C.txt"));
		int T=scanner.nextInt();
		for (int test = 1; test <= T; test++) {	
			int N=scanner.nextInt();
			int M=scanner.nextInt();
			int K=scanner.nextInt();
			if(N<=2 || M<=2 || K<=4){
				printWriter.println("Case #"+test+": "+K);
				continue;
			}
			int res=K;
			
			for (int i = 1; i <=K; i++) {
				int min=Math.min(N, M)-2;
				int j=Math.min((int)Math.sqrt(i),min);
				while( j >0) {
					if(i%j==0) break;
					else {
						j--;
					}
				}
				int k=i/j;
				if(k>Math.max(N, M)-2) continue;
				if(i+2*(j+k)>=K){
					res=Math.min(2*(j+k), res);
					
				}
				else {
					if(res>2*(j+k)+K-i-2*(j+k)){
						res=2*(j+k)+K-i-2*(j+k);
					}
				
				}
				
			}
			
			printWriter.println("Case #"+test+": "+res);
		}
		
		scanner.close();
		printWriter.close();
	}

	
	
}
