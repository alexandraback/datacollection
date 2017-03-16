import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class InfiniteHouseOfPancakes {
	static Scanner in;
	static PrintStream out;

	static void solve(int caseNb) {
		String pancakes = in.nextLine();
		pancakes = pancakes.replaceAll("[+]*$","").replaceAll("[+]+", "+").replaceAll("[-]+","-");
		out.println(String.format("Case #%d: %d",caseNb+1,pancakes.length()));
	}
	
//	static void solve(int caseNb) {
//		String pancakes = in.nextLine();
//		int end=pancakes.length()-1;
//		int count = 0;
//		while(end>=0){
//		    System.err.println("ori:"+pancakes);
//		    if(pancakes.charAt(end)=='-'){
//			int beg = 0;
//			StringBuilder bul = new StringBuilder();
//			while(pancakes.charAt(beg)=='+'){//build a beginning of - minus
//			    bul.append('-');
//			    beg++;
//			}
//			if(beg>0){
//			    count++;
//			    pancakes = bul.toString()+pancakes.substring(beg, pancakes.length());
//			    System.err.println("mid:"+pancakes);
//			}
//			
//			bul = new StringBuilder();
//			for(int c=0;c<end;c++){
//			    bul.append(pancakes.charAt(c)=='+'?'-':'+');
//			}
//			count++;
//						
//		    }
//		    end--;
//		}
//	}
	

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(new Locale("en", "US"));
		 in = new Scanner(new FileInputStream("inputs/B-small-attempt0.in"));
		 out = new PrintStream("outputs/B-small-attempt0.out");

//		 in = new Scanner(System.in);
//		 out = System.out;

		int cases = in.nextInt();
		in.nextLine();
		for (int i = 0; i < cases; i++)
			solve(i);
	}

}