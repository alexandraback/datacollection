import java.io.*;
import java.util.*;

public class B {

	public static void main(String[] args) throws Exception{
		Scanner input = new Scanner(new File(new File("").getAbsolutePath() + "/input.in"));
		input.useLocale(Locale.US);
		PrintWriter output = new PrintWriter(new File("").getAbsolutePath() + "/output.out", "UTF-8");
		int T = input.nextInt() + 1;
		
		for( int i = 1; i < T; i++ ) {
			output.print("Case #" + i + ": ");
			solve(input, output);
		}
		
		output.flush();
		output.close();
		input.close();
	}
	
	public static void solve(Scanner input, PrintWriter output){
		String s1 = input.next();
		String s2 = input.next();
		
		Pair<Long, Pair<String, String>> ans = dfs(0, s1, s2, "", "", 0);
		output.println(ans.second.first + " " + ans.second.second);
	}
	
	static Pair< Long, Pair<String,String>> dfs (int state, String s1, String s2, String o1, String o2,int i){
		
		if ( i == s1.length() ){
			long d = Long.parseLong(o1) - Long.parseLong(o2);
			if ( d < 0 ) d = -d;
			return new Pair<Long, Pair<String, String>>(d, new Pair<String, String>(o1,o2));
		}
		
		if ( s1.charAt(i) != '?' && s2.charAt(i) != '?') {
			if ( state != 0 || s1.charAt(i) == s2.charAt(i))
				return dfs(state, s1, s2, o1+s1.charAt(i), o2+s2.charAt(i), i+1);
			if ((int)s1.charAt(i) > (int)s2.charAt(i))
				return dfs(1, s1, s2, o1+s1.charAt(i), o2+s2.charAt(i), i+1);
			else return dfs(-1, s1, s2, o1+s1.charAt(i), o2+s2.charAt(i), i+1);
		}
		
		
		if ( s1.charAt(i) == '?' && s2.charAt(i) == '?') {
			if ( state == 1 ){
				return dfs(state, s1, s2, o1+'0', o2+'9', i+1);
			}
			if ( state == -1 ){
				return dfs(state, s1, s2, o1+'9', o2+'0', i+1);
			}
			
			Pair<Long, Pair<String, String>> p = dfs(state, s1, s2, o1 + '0', o2 + '0', i+ 1);
			Pair<Long, Pair<String, String>> p1 = dfs(1, s1, s2, o1 + '1', o2 + '0', i+ 1);
			Pair<Long, Pair<String, String>> p2 = dfs(-1, s1, s2, o1 + '0', o2 + '1', i+ 1);
			
			if ( p.first <= p1.first && p.first <= p2.first) return p;
			if ( p2.first <= p1.first) return p2;
			return p1;
		}
		

		if ( s1.charAt(i) == '?' && s2.charAt(i) != '?') {
			if ( state == 1 ){
				return dfs(state, s1, s2, o1+'0', o2+s2.charAt(i), i+1);
			}
			if ( state == -1 ){
				return dfs(state, s1, s2, o1+'9', o2+s2.charAt(i), i+1);
			}
			
			Pair<Long, Pair<String, String>> p = dfs(state, s1, s2, o1 + s2.charAt(i), o2 + s2.charAt(i), i+ 1);
			Pair<Long, Pair<String, String>> p1 = new Pair<Long, Pair<String, String>>(Long.MAX_VALUE, new Pair<String, String>(null,null));
			Pair<Long, Pair<String, String>> p2 = new Pair<Long, Pair<String, String>>(Long.MAX_VALUE, new Pair<String, String>(null,null));

			if ( s2.charAt(i) != '9' )
			{
				p1 = dfs(1, s1, s2, o1 + (char)((int)s2.charAt(i) + 1), o2 + s2.charAt(i), i+ 1);
			}
			if ( s2.charAt(i) != '0'){
				p2 = dfs(-1, s1, s2, o1 + (char)((int)s2.charAt(i) - 1), o2 + s2.charAt(i), i+ 1);
			}
			if ( p2.first <= p1.first && p2.first <= p.first) return p2;
			if ( p.first <= p1.first) return p;
			return p1;
		}
		
		if ( s1.charAt(i) != '?' && s2.charAt(i) == '?') {
			if ( state == 1 ){
				return dfs(state, s1, s2, o1+s1.charAt(i), o2+'9', i+1);
			}
			if ( state == -1 ){
				return dfs(state, s1, s2, o1+s1.charAt(i), o2+'0', i+1);
			}
			
			Pair<Long, Pair<String, String>> p = dfs(state, s1, s2, o1 + s1.charAt(i), o2 + s1.charAt(i), i+ 1);
			Pair<Long, Pair<String, String>> p1 = new Pair<Long, Pair<String, String>>(Long.MAX_VALUE, new Pair<String, String>(null,null));
			Pair<Long, Pair<String, String>> p2 = new Pair<Long, Pair<String, String>>(Long.MAX_VALUE, new Pair<String, String>(null,null));

			if ( s1.charAt(i) != '0' )
			{
				p1 = dfs(1, s1, s2, o1 + s1.charAt(i), o2 + (char)((int)s1.charAt(i) - 1), i+ 1);
			}
			if ( s1.charAt(i) != '9'){
				p2 = dfs(-1, s1, s2, o1 + s1.charAt(i), o2 + (char)((int)s1.charAt(i) + 1), i+ 1);
			}
			if ( p1.first <= p2.first && p1.first <= p.first) return p1;
			if ( p.first <= p2.first) return p;
			return p2;
		}
		return null;
	}
}

class Pair<A, B> {
    public A first;
    public B second;

    public Pair(A first, B second) {
    	this.first = first;
    	this.second = second;
    }
}
