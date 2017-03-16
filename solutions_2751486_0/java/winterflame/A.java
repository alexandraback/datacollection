import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(System.in);
		s = new Scanner(new File("A-small-attempt0.in"));
//		s = new Scanner(new File("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(new File("a.txt")));
		int c = s.nextInt();
		for(int t=1;t<=c;t++){
			String z = s.next();
			int n = s.nextInt();
			long res = d(z,n);
			System.out.printf("Case #%d: ", t);
			pw.print("Case #" + t + ": ");
			System.out.println(res);
			pw.println(res);
			}
			pw.flush();
		}
	
	
	static int d(String s, int n){
		int r = 0;
		for(int i=0;i<s.length();i++){
			for(int j=i+1;j<=s.length();j++){
				String t = s.substring(i,j);
				if(o(t,n)) ++r;
			}
		}
		return r;
	}
	
	static boolean o(String t, int n){
		int r = 0;
		int tm = 0;
		for(int i=0;i<t.length();i++){
			char ch = t.charAt(i);
			if(v(ch)) {
				tm = 0;
				r = Math.max(r, tm);
			} else {
				tm ++;
			}
			r = Math.max(r, tm);
		}
		r = Math.max(r, tm);
		return r >= n;
	}
	
	static boolean v(char c){
		return "aeiou".indexOf(c) >= 0;
	}

}
