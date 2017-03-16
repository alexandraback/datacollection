import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-small-attempt1.in"));//
		PrintWriter out = new PrintWriter("out.txt");
		int T = in.nextInt();
		for(int i=1;i<=T;i++){
			int r = in.nextInt();
			int c = in.nextInt();
			int w = in.nextInt();
			int res = solve(r,c,w);
			out.println("Case #"+i+": "+res);			
		}
		
		out.close();
		in.close();

	}
	
	private static int solve(int r, int c, int w){
		int res = 0;
		if(r==1){
			int p = w;
			while(p<=c){
				res++;
				p+=w;
			}
			res+=w;
			if(p==c+w){
				res--;
			}
		}
		else{
			int p = w;
			while(p<=c){
				res++;
				p+=w;
			}
			res*=r;
			res+=w;
			if(p==c+w){
				res--;
			}
		}
		return res;
	}
}
