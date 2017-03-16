import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;

public class B {

	
	public static void main(String args[]){
		
		try{
		File ifile = new File(args[0]);
		File ofile = new File(args[1]);

		Scanner in = new Scanner(ifile);
		PrintWriter out = new PrintWriter(ofile);
		
		int T = in.nextInt();
	
		for(int ti=0;ti<T;ti++){
			int N = in.nextInt();//no-of-googlers
			int S = in.nextInt();//no-of-surprising cases
			int p= in.nextInt(); //best
			int res=0;
			for(int ni=0; ni<N; ni++){
			
				int total = in.nextInt();
				if( (total+2) >= (p*3)) res++;
				else if( ((total+4) >= (p*3)) && S>0 && total!=0) {res++;S--;}
			}
			
			out.format("Case #%d: %d\n", ti+1, res);
						//out.println("Case #" + (i+1) + ": " + t);

		}
		out.flush();
		in.close();
		out.close();	
		}catch(Exception e){e.printStackTrace();}
	}
}
