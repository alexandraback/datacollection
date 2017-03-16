import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.util.*;
import java.math.BigInteger;
public class a{
	public static int solve( boolean[] c, int n){
		int len = c.length;
		int res = 0;
		
		for ( int i = 0;i < len; i++)
			for ( int j = i; j < len; j++){
				int con = 0;
				for ( int k = i; k <= j; k++){
					if ( c[k] ) con ++ ;
					else con = 0;
					if ( con >= n ) {
						res ++ ;
						break;
					}
				}
			}
		return res;
	}
	static   boolean convert(char c){
		if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return false;
		return true;
	}
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("a.in"));
		FileWriter fw = new FileWriter("a.out");
		int T = sc.nextInt();
		for ( int t = 0 ; t <T ; t++){
			String str = sc.next();
			//int index = str.indexOf(" ");
			int n = sc.nextInt();
			//int n = Integer.valueOf(str.substring(index+1));
			int index = str.length();
			boolean[] c = new boolean[index];
			for ( int i = 0 ;i < index; i++)
				c[i] = convert(str.charAt(i));
			int res = solve(c,n);
			//....Do sth here
			fw.write("Case #" + (t+1) + ": " + res);
			fw.write("\n");
			
		}
		fw.close();
	}
}	
