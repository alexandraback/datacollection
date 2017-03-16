import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("D-small.in"));
		PrintWriter out = new PrintWriter(new File("D_small.txt"));
		int T = in.nextInt();
		
		for (int t =0; t<T; t++){
			int k = in.nextInt();
			int d = in.nextInt();
			int s = in.nextInt();
			if (k>(d*s)){
				out.println("Case #"+(t+1)+": "+"IMPOSSIBLE");
			} else{
				int n = (k-1)/d+1; 
				
				out.print("Case #"+(t+1)+":");
				for (int i=0; i<n; i++){
					long p = i*d+1;
					int st = Math.min(d, k-i*d);
					for (int j=2; j<=st; j++){
						p=(p-1)*k+(i*d+j);
					}
					for (int j=0; j<d-st; j++){
						p = p*k;
					}
					out.print(" "+p);
				}
				out.println();
			}
		}
		out.close();

	}

}
