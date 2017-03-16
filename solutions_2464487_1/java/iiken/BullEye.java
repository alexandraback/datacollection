import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.util.*;
public class BullEye{
	public static final double pi = 1;
	public static long solve(long r, long t, long min, long max){
		if ( min >= max)  return min;
		long mid = min + (max-min)/2;
		if ( mid == min ) mid = max;
		double v = (double)mid*(2*r-3) + (double)2*(1+mid)*mid;
		//System.out.println(mid+ " " +max + " " + v);
		if ( (t-v) >= 0 ) 
			return solve(r,t,mid, max);
		else return solve(r,t,min,mid-1);
	}
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("a.in"));
		FileWriter fw = new FileWriter("a.out");
		int T = sc.nextInt();
		for ( int x = 0 ; x < T ; x++){
			long r = sc.nextLong();
			long t = sc.nextLong();
			long right  = (long)( (double)t/pi/(2*r+1));
			long left = 1;
			//....Do sth here	
			long result = solve(r,t,left, right);
			fw.write("Case #" + (x+1) + ": " + result);
			fw.write("\n");
		}
		fw.close();
	}
}	
