import java.io.File;
import java.io.PrintWriter;
import java.util.Hashtable;
import java.util.Scanner;


public class fair {

	static Hashtable<Integer, Boolean> palyndromes;
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new File("fair.out"));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int start= (int)Math.ceil(Math.sqrt(a));
			System.out.println(start+"-"+b);
			int sqr = start*start;
			palyndromes = new Hashtable<Integer, Boolean>();
			int count = 0;
			while(sqr <= b){
				if(checkFair(start)&&checkFair(sqr))
					count++;				
				start++;
				sqr = start*start;
			}
			pw.println("Case #"+i+": "+count);
		}
		pw.close();
	}
	
	static boolean checkFair(int num){
		String s = ""+num;
		boolean v = true;
		for (int i = 0; i < s.length()/2 && v; i++) {
			v = s.charAt(i)==s.charAt(s.length()-1-i);
		}
		return v;					
	}
	
}
