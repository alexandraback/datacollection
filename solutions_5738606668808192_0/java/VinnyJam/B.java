import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	
	

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("B-small.in"));
		PrintWriter out = new PrintWriter(new File("B_small.txt"));
		int T = in.nextInt();
		for (int t =0; t<T; t++){
			int n = in.nextInt();
			int J = in.nextInt();
			out.println("Case #"+(t+1)+": ");
			if (n==16){
				for (int i=0; i<J; i++){
					boolean[] s = new boolean[16];				
					int gap=8;
					s[0]=true;
					s[gap-1]=true;
					s[gap]=true;
					s[n-1]=true;
					int ii =i;
					for (int k=1; k<7; k++){
						if (ii%2==1){
							s[k]=true;
							s[k+gap]=true;
						}
						ii=ii/2;
					}
					for (boolean q: s){
						if (q) {
							out.print("1"); 
						}
						else out.print("0");
					}
					out.println(" 257 2 65537 2 17 2 97 2 17");
					
				}
				
			}
			if (n==32){
				
				for (int i=0; i<J; i++){
					boolean[] s = new boolean[32];				
					int gap=16;
					s[0]=true;
					s[gap-1]=true;
					s[gap]=true;
					s[n-1]=true;
					int ii =i;
					for (int k=1; k<16; k++){
						if (ii%2==1){
							s[k]=true;
							s[k+gap]=true;
						}
						ii=ii/2;
					}
					for (boolean q: s){
						if (q) {
							out.print("1"); 
						}
						else out.print("0");
					}
					out.println(" 65537 2 641 2 353 2 193 2 353");
					
				}
			}
			out.close();
			
		}

	}

}
