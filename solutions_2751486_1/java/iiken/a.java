import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.util.*;
import java.math.BigInteger;
public class a{
	public static long solve( boolean[] c, int n){
		int len = c.length;
		long res = 0;
		Stack<Long> s = new Stack<Long>();
		int con = 0;
		for ( int i = len-1; i >=0 ; i--){
			if ( c[i] ) {
				con ++;
				if ( con >= n ) s.push((long)i);
			}else{
				con = 0;
			}
		}
		for ( int i = 0; i < len; i++){
			if ( s.size() == 0 ) break;
			long nPos = s.peek();
			res += ((long)len-((long)n+nPos-1));
			if ( nPos == i ) s.pop();
		}
		return res;
	}
	static   boolean convert(char c){
		if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return false;
		return true;
	}
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("a2.in"));
		FileWriter fw = new FileWriter("a2.out");
		int T = sc.nextInt();
		for ( int t = 0 ; t <T ; t++){
			String str = sc.next();
			int n = sc.nextInt();
			int index = str.length();
			boolean[] c = new boolean[index];
			for ( int i = 0 ;i < index; i++)
				c[i] = convert(str.charAt(i));
			long res = solve(c,n);
			//....Do sth here
			fw.write("Case #" + (t+1) + ": " + res);
			fw.write("\n");
			
		}
		fw.close();
	}
}	
