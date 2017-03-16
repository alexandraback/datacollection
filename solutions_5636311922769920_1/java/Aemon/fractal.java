import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class fractal {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		PrintWriter out = new PrintWriter(new File("fractal.out"));
		
		for(int t=1;t<=T;t++){
			long k = scan.nextLong(), c = scan.nextLong(), s = scan.nextLong();
			
			
			long tile = 0L;
			int idx = 0;
			out.print("Case #"+t+": ");
			if(s*c < k){
				out.println("IMPOSSIBLE");
				continue;
			}
			while(idx<k){
				for(int i=1;i<c;i++){
					idx = Math.min(idx+1, (int)k-1);
					tile*=k;
					tile+=(long)idx;
				}
				
				out.print((tile+1)+" ");
				idx++;
				tile=idx;
			}
			out.println();
		}
		out.close();
	}
}
