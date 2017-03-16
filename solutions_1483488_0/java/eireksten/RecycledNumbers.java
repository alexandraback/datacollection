import java.io.*;
import java.text.*;
import java.util.*;

public class RecycledNumbers {
	
	static BufferedReader stdin;
	static StringTokenizer st;

	static String LINE() throws Exception { return stdin.readLine(); }
	static String TOKEN() throws Exception {
		while (st == null || !st.hasMoreTokens())st = new StringTokenizer(LINE());
		return st.nextToken();
	}
	static int INT() throws Exception {return Integer.parseInt(TOKEN());}
	static long LONG() throws Exception {return Long.parseLong(TOKEN());}
	static double DOUBLE() throws Exception {return Double.parseDouble(TOKEN());}

	
	static DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	
	
	public static void main(String[] args) throws Exception {
		String input = "C-small-attempt0.in";
		String output = "C-small.out";
//		String input = "testa.in";
//		String output = "testa.out";
		stdin = new BufferedReader(new FileReader(new File(input)));
		FileWriter frw = new FileWriter(output);
		
		int cases = INT();
		int cc = 1;
		while(cases-->0) {
			System.out.println(cc);
			int N = INT(), M = INT();
			int cp = N / 10;
			int factor = 1;
			while(cp>0) {
				factor *= 10;
				cp /= 10;
			}
			int solution = 0;
			for(int i = N; i < M; i++) {
				
				solution += addPairs(i, factor, M);
				
			}
			
			frw.write("Case #"+(cc++)+": ");
			frw.write(""+solution);
			frw.write("\n");
			
		}
		frw.flush();
		frw.close();
		
		
		
	}
	private static int addPairs(int i, int factor, int max) {
		int cnt = 0;
		int num = i;
//		System.out.println(i+" "+factor+" "+max);
		do {
//			System.out.println(num);
			int tmp = num;
			tmp /= 10;
			tmp += factor * (num % 10);
			num = tmp;
			if(num > i && num <= max)cnt++;
		} while (num != i);
		
		return cnt;
	}

}
