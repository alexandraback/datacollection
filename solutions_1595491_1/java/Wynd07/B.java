import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class B {
	public static void main (String [] args) throws IOException {new B().run();}
	public void run() throws IOException{
		Scanner file = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		int times = Integer.parseInt(file.nextLine());
		for(int asdf = 0; asdf<times; asdf++){
			int n = file.nextInt();
			int s = file.nextInt();
			int p = file.nextInt();
			int[] ar = new int[n];
			for(int i = 0; i<n; i++)
				ar[i] = file.nextInt();
			Arrays.sort(ar);
			int count = 0;
			for(int i = n-1; i>=0; i--){
				int x = ar[i];
				int m1 = pos(x,false);
				int m2 = pos(x,true);
				if( m1 >= p ) count++;
				else if( m2 >= p && s>0 ){
					count++;
					s--;
				}
			}
			out.println ("Case #"+(asdf+1)+": "+count);
		}
		out.close();
		System.exit(0);
	}
	public int pos(int x, boolean s){
		int div = (int)Math.ceil(x/3.);
		int max = 0;
		for(int a = Math.max(0,div-2); a<div+2; a++)
		for(int b = Math.max(0,div-2); b<div+2; b++)
		for(int c = Math.max(0,div-2); c<div+2; c++){
			int dif = Math.max(Math.max(a,b),c)-Math.min(Math.min(a,b),c);
			if( dif >2 || a+b+c!=x || (!s&& dif==2))continue;
			max = Math.max(Math.max(a,b),Math.max(max,c));
		}
		return max;
	}
}