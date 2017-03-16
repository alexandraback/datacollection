import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.util.*;
import java.math.BigInteger;
public class FairSquare{
	public static boolean isPal(long num){
		String str = Long.toString(num);
		int i = 0;
		int j = str.length()-1;
		while ( i < j ) {
			if ( str.charAt(i) != str.charAt(j) ) return false;
			i ++;
			j--;
		}
		return true;
	}
	public static long nextPal(long num){
		String str = Long.toString(num);
		int index = str.length() /2;
		boolean flag = true;
		if ( str.length()%2 == 1 )index++;
		else flag = false;
		str = str.substring(0,index);
		long newN = Long.parseLong(str);
		newN ++;
		String strTmp = String.valueOf(newN);
		if ( strTmp.length() > str.length()){
			newN = num + 2;
			return newN;
		}
		str = Long.toString(newN);
		if ( flag ) newN /= 10;
		while ( newN > 0 ){
			str += String.valueOf(newN%10);
			newN /= 10;
		}
		return Long.parseLong(str);
	}
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("a.in"));
		FileWriter fw = new FileWriter("a.out");
		int t = sc.nextInt();
		ArrayList<Long> a = new ArrayList<Long>();
		long upper = (long) 1e14;
		long cur = 1;
		while ( cur*cur < upper ) {
			if ( isPal(cur*cur) ) {
				a.add(cur*cur);
				//System.out.println(cur*cur);
			}
			cur = nextPal(cur);
			//System.out.println(cur);
		}
		for ( int x = 0 ; x < t ; x++){
			long n = sc.nextLong();
			long m = sc.nextLong();
			int res = 0;
			for ( int i = 0 ; i < a.size() ; i++)
				if ( a.get(i) >= n && a.get(i)<=m ) res++;
			//....Do sth here
			fw.write("Case #" + (x+1) + ": " + res);
			fw.write("\n");
			
		}
		fw.close();
	}
}	
