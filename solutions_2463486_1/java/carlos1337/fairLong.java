import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Hashtable;
import java.util.Scanner;


public class fairLong {

	static Hashtable<Integer, Boolean> palyndromes;
	
	static long[] numsFSQR = new long[]{1L,4L,9L,121L,484L,10201L,12321L,14641L,40804L,44944L,1002001L,1234321L,4008004L,100020001L,102030201L,104060401L,121242121L,123454321L,125686521L,400080004L,404090404L,10000200001L,10221412201L,12102420121L,12345654321L,40000800004L,1000002000001L,1002003002001L,1004006004001L,1020304030201L,1022325232201L,1024348434201L,1210024200121L,1212225222121L,1214428244121L,1232346432321L,1234567654321L,4000008000004L,4004009004004L};
	
	public static void main(String[] args) throws Exception{			
		Scanner sc = new Scanner(new File("C-large-1.in"));
		PrintWriter pw = new PrintWriter(new File("fairLong.out"));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			int startIndex = Arrays.binarySearch(numsFSQR,a);			
			int mod = 0;
			if(startIndex< 0){
				startIndex = -startIndex-1;
			}			
			while(startIndex < numsFSQR.length && numsFSQR[startIndex]<=b){
				mod++;
				startIndex++;
			}						
			pw.println("Case #"+i+": "+mod);
		}
		pw.close();
		
	}
	
	static boolean checkFair(long num){
		String s = ""+num;
		boolean v = true;
		for (int i = 0; i < s.length()/2 && v; i++) {
			v = s.charAt(i)==s.charAt(s.length()-1-i);
		}
		return v;					
	}
	
}
