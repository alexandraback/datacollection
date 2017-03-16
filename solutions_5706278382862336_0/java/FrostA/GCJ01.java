import java.io.*;
import java.util.*;


public class GCJ01 {
	public static PrintStream out;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s = new Scanner(new File("GCJ01.txt"));
		out = new PrintStream(new File("GCJ01.out.txt"));
		int t = s.nextInt();
		for(int i=0;i<t;i++){
			out.print("Case #");
			out.print(i+1);
			out.print(": ");
			String st=s.next();
			Scanner ss = new Scanner(st.substring(0, st.indexOf('/')));
			int p = ss.nextInt();
			ss = new Scanner(st.substring(st.indexOf('/')+1));
			int q=ss.nextInt();
			if(!power(q)){
				out.println("impossible");
				continue;
			}
			out.println(get(q)-get(p));
		}
	}
	public static int get(int x){
		int i=1;
		int r=0;
		while(i<x){
			r++;
			i*=2;
		}
		if(i>x)r--;
		return r;
	}
	public static boolean power(int x){
		if((x==0)||(x==2))return true;
		if((x%2)==1)return false;
		return power(x/2);
	}
}
