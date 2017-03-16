

import java.io.BufferedReader;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;

public class R1B_First {

	static boolean test = true;

	private void solve() throws Throwable {
		int t = iread();
		for (int i = 0; i < t; i++) {
			solveIt(i+1);
		}
	}
	
	private void solveIt(int casenr) throws Throwable {
		
		int n = iread();
		
		int[] scores = new int[n];
		double tot = 0;
		for (int i = 0; i < n; i++) {
			int s = iread();
			scores[i] = s;
			tot += s;
		}
		
		StringBuilder res = new StringBuilder();
		DecimalFormat format = new DecimalFormat("#.######");
		format.setDecimalFormatSymbols(DecimalFormatSymbols.getInstance(new Locale("EN")));
		
		for (int i = 0; i < n; i++) {
			double ans = go(i, tot, scores);
			res.append(format.format(ans));
			if(i < n -1 ){
				res.append(" ");
			}
		}
				
		String answerString = "Case #" + casenr + ": " + res.toString();
		out.write(answerString + "\n");
		System.out.println(answerString);
	}

	private double go(int thisNr, double tot, int[] scores) {
		
		double hi = 1, lo = 0;
		double epsilon = 0.000000000001d;
		
		while (hi - lo > epsilon) {
			double mid = (hi + lo)/2;
			double left = 1.0d - mid;
			double target = scores[thisNr] + mid * tot;
			for (int i = 0; i < scores.length; i++) {
				if(i == thisNr){
					continue;
				}
				double base =  scores[i];
				double needed = (target - base)/tot;
				if(needed > 0){
					left -= needed;
				}
			}
			
			if(left < 0){
				hi = mid;
			} else {
				lo = mid;
			}
		}
		
		return hi * 100;
	}

	public int iread() throws Exception {
		return Integer.parseInt(wread());
	}

	public double dread() throws Exception {
		return Double.parseDouble(wread());
	}

	public long lread() throws Exception {
		return Long.parseLong(wread());
	}

	public String wread() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) throws Throwable {
		new R1B_First().solve();
		out.close();
	}

	public R1B_First() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
			out = new BufferedWriter(new FileWriter(getClass().getCanonicalName() + "-out.txt"));
		} else {
			new BufferedReader(inp);
		}
	}

	static InputStreamReader inp = new InputStreamReader(System.in);
	static BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
//	static BufferedWriter out;// = new BufferedWriter(new FileWriter("out.txt"));

//	static String testDataFile = "testdata.txt";
	static String testDataFile = "A-large.in";
}