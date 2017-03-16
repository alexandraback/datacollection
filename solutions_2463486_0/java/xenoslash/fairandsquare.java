package qual;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class fairandsquare {
	private static BufferedReader f;
	private static PrintWriter out;
	private static String[] inputLines;
	static int N;
	
	public static void naive(long a, long b){
		for(long i=(long)(Math.sqrt(a)-1);i*i<=b;i++){
			if(i*i<a)continue;
			if(isPal("" + i) && isPal("" + i*i)){
				pals.add(BigInteger.valueOf(i*i));
			}
		}
	}
	
	public static void main(String[] args) throws IOException{	
		//f = new BufferedReader(new InputStreamReader(System.in));
		//out = new PrintWriter(System.out);
		f = new BufferedReader(new FileReader("C-small-attempt0.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("C-small.out")));
		
		N = Integer.parseInt(f.readLine());
		inputLines = new String[N];
		for(int i=0; i<N;i++){
			inputLines[i] = f.readLine();
		}
		
		pals = new ArrayList<BigInteger>();
		naive(1,Long.valueOf("100000000000000"));
		
		
		for(int i=1; i<=N;i++){
			out.write("Case #" + i+": ");
			solve(i);
		}
		out.close();
	}
	
	public static void initPals(){
		hi = BigInteger.valueOf(-1);
		lo = BigInteger.valueOf(10);
		lo = lo.pow(100);
		
		for(int i=0;i<N;i++){
			String[] toks = inputLines[i].split(" ");
			BigInteger curLo = new BigInteger(toks[0]);
			BigInteger curHi = new BigInteger(toks[1]);
			if(curLo.compareTo(lo) < 0){
				lo = curLo;
			}
			
			if(curHi.compareTo(hi) > 0){
				hi = curHi;
			}
		}
		
		int maxPow = hi.toString().length() / 2 +1;
		for(int numDig = 1; numDig<=maxPow;numDig++){
			if(numDig%2 == 0){
				for(int j=1;j<=9;j++){
					dfsEven(numDig/2-1, "" + j);
				}
			}else{
				for(int j=1;j<=9;j++){
					dfsOdd((numDig-1)/2, "" + j);
				}
			}
		}
	}
	
	static BigInteger lo;
	static BigInteger hi;
	static List<BigInteger> pals;
	public static void solve(int caseNum) throws IOException{
		long count = 0;
		String[] toks = inputLines[caseNum-1].split(" ");
		
		lo = new BigInteger(toks[0]);
		hi = new BigInteger(toks[1]);
		
		for(BigInteger s : pals){
			if(s.compareTo(lo) >= 0 && s.compareTo(hi)<=0){
				count++;
			}
		}
		out.write(count +"\n");
	}
	
	public static void check(String sqrt){
		BigInteger x = new BigInteger(sqrt);
		BigInteger y = x.pow(2);
		String yString=  y.toString();
		if(y.compareTo(hi) <=0 && y.compareTo(lo)>=0 && isPal(yString)){
			pals.add(y);
		}
	}
	
	public static boolean isPal(String s){
		for(int i=0; i<s.length()/2; i++){
			if(s.charAt(i) != s.charAt(s.length()-i-1)){
				return false;
			}
		}
		return true;
	}
	
	//numDig = remaining number of digits to fill
	public static void dfsEven(int numDig, String halfFilled){
		if(numDig == 0){
			String otherHalf = reverse(halfFilled.substring(0,halfFilled.length()));
			String complete = halfFilled + otherHalf;
			check(complete);
		}else{
			for(int i=0;i<=9;i++){
				dfsEven(numDig-1, halfFilled + i);
			}
		}
	}
	
	//stores the first half+1 of odd palindrome, starting outside most
	//numDig = how many digs left to fill
	public static void dfsOdd(int numDig, String halfFilled){
		if(numDig == 0){
			String otherHalf = reverse(halfFilled.substring(0,halfFilled.length()-1));
			String complete = halfFilled + otherHalf;
			check(complete);
		}else{
			for(int i=0;i<=9;i++){
				dfsOdd(numDig-1, halfFilled + i);
			}
		}
	}
	
	public static String reverse(String s){
		String rev = "";
		for(int i=0; i<s.length();i++){
			rev+=s.charAt(s.length()-1-i);
		}
		return rev;
	}
	
public static class FastScanner {
	BufferedReader br;
	StringTokenizer st;

	public FastScanner(String s) {
		try {
			br = new BufferedReader(new FileReader(s));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public FastScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String nextToken() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}

}
