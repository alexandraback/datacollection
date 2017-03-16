import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.io.File;
import java.io.PrintWriter;

public class C {

	
	public static void main(String args[]){
		
		try{
		File ifile = new File(args[0]);
		File ofile = new File(args[1]);

		//Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(ifile);
		PrintWriter out = new PrintWriter(ofile);
		
		int T = in.nextInt();
		Set<Integer> set = null; 
		for(int ti=0;ti<T;ti++){
			int A = in.nextInt();
			int B = in.nextInt();
			
			int no_of_digits =0,counter=0 ;
			int a= A;
			while(a>0){
				no_of_digits++;
				counter++;
				a=a/10;
			}
			
			int res=0;
			int n= A;
			int m=0;
			
			while(n<=B){
				counter = no_of_digits-1;
				m=n;
				set = new HashSet<Integer>();
				while(counter>0){
					m = (int) ((m%10)*Math.pow(10,no_of_digits-1) + (m/10));
					if(A<=n && n<m && m <=B) {
						if(set.add(m)){
							res++;
							//out.println(n+":"+m + " Set:"+set);
						}
					}	
					counter--;//
				}
				set = null;
				n++; //increment n
			}
			
			out.format("Case #%d: %d\n", ti+1, res);

		}
		out.flush();
		in.close();
		out.close();	
		}catch(Exception e){e.printStackTrace();}
	}
}
