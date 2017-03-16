import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {


	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner=new Scanner(new File("E:\\B-small-attempt0.in"));
		PrintWriter printWriter=new PrintWriter(new File("E:\\B.txt"));
		int T=scanner.nextInt();
		for (int i = 1; i <= T; i++) {	
			int A=scanner.nextInt();
			int B=scanner.nextInt();
			int K=scanner.nextInt();
			int min=Math.min(A, B);
			int max=Math.max(A, B);
			long res=0;
			for (int j = 0; j < A; j++) {
				for (int j2 = 0; j2 < B; j2++) {
					if((j&j2)<K){
						res++;
					}
				}
			}
			printWriter.println("Case #"+i+": "+res);
		}
		scanner.close();
		printWriter.close();
	}

}
