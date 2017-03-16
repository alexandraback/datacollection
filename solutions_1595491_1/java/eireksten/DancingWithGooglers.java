import java.io.*;
import java.text.*;
import java.util.*;

public class DancingWithGooglers {
	
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
	
	public static int score(int total) {
		return (total + 2) / 3;
	}
	public static int surpriseScore(int total) {
		if(total == 0)return 0;
		if(total == 1)return 1;
		return 2 + (total-2)/3;
	}
	
	public static void main(String[] args) throws Exception {
		String input = "B-large.in";
		String output = "B-large.out";
//		String input = "testa.in";
//		String output = "testa.out";
		stdin = new BufferedReader(new FileReader(new File(input)));
		FileWriter frw = new FileWriter(output);
		
		int cases = INT();
		int cc = 1;
		while(cases-->0) {
			System.out.println(cc);
			int N = INT();
			int S = INT();
			int p = INT();
			
			int[] scores = new int[N];
			for(int i = 0; i < N; i++) {
				scores[i] = INT();
			}
			Arrays.sort(scores);
			int solution = 0;
			for(int i = scores.length - 1; i>=0; i--) {
				if(score(scores[i]) >= p) {
					solution++;
				} else if(S > 0 && surpriseScore(scores[i]) >= p) {
					S--;
					solution++;
				}
			}
			
			frw.write("Case #"+(cc++)+": ");
			frw.write(""+solution);
			frw.write("\n");
			
		}
		frw.flush();
		frw.close();
		
		
		
	}

}
