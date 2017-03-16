import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class LastWord {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new File("largeout.txt"));
		int t = Integer.parseInt(in.readLine());
		for(int i = 0;i<t;i++){
			out.println("Case #" + String.valueOf(i+1)+": " + solve(in.readLine()));
		}
		out.close();
	}
	
	static String solve(String s){
		if(s.length()==1){
			return s;
		}
		String n = solve(s.substring(0,s.length()-1));
		String m = s.substring(s.length()-1,s.length());
		String p = n.concat(m);
		String q = m.concat(n);
		if(p.compareTo(q)>0){
			return p;
		}else{
			return q;
		}
	}
}
