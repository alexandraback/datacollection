import java.io.*;
import java.text.*;
import java.util.*;

public class Googlerese {
	
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
		String input = "A-small-attempt0.in";
		String output = "A-small.out";
//		String input = "testa.in";
//		String output = "testa.out";
		stdin = new BufferedReader(new FileReader(new File(input)));
		FileWriter frw = new FileWriter(output);
		
		int cases = INT();
		int cc = 1;
		while(cases-->0) {
			frw.write("Case #"+(cc++)+": ");
			frw.write(translate(LINE()));
			frw.write("\n");
		}
		frw.flush();
		frw.close();
		
		
		
	}
	
	public static char[] mapping = new char[] 
	                                	    {'y','h','e','s','o','c','v','x','d','u',
	                                		'i','g','l','b','k','r','z','t','n','w',
	                                		'j','p','f','m','a','q',};
	
	private static String translate(String line) {
		StringBuilder out = new StringBuilder();
		for(char c : line.toCharArray()) {
			if(Character.isWhitespace(c))
				out.append(c);
			else
				out.append(mapping[c-'a']);
		}
		return out.toString();
	}

	public static class State implements Comparable<State> {
		int a, b, seq, time;
		
		State(int a, int b, int seq, int time) {
			this.a = a; 
			this.b = b;
			this.seq = seq;
			this.time = time;
		}
		
		public int compareTo(State s) {
			return this.time-s.time;
		}
	}

}
