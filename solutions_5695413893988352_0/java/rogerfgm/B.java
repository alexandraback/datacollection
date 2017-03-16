

import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.Integer.*;

public class B {
	static Scanner sc = null;
	static BufferedReader br = null;
	static PrintWriter out = null;
	static PrintStream sysout = System.out;
	static Random rnd = new Random();
	
	int INF = Integer.MAX_VALUE / 10;
	double DF = 0.0000000001;
	
	long b = 1;
	int N = 0;
	int M = 0;
	

	
	public void solve() throws Exception{
		String s = br.readLine();
		
		String[] sp = s.split(" ");
		String C = sp[0];
		String J = sp[1];
		char[] cs = C.toCharArray();
		char[] js = J.toCharArray();
		int diff = Integer.MAX_VALUE;
		int ca = Integer.MAX_VALUE;
		int ja = Integer.MAX_VALUE;
		
				
		for(int i = 0; i < 1000; i++){
			if(i == 23){
				print("");
			}
			if(match(cs, i)){
				for(int j = 0; j < 1000; j++){
					if(i == 23&& j == 23){
						print("");
					}
					if(match(js, j)){
						int df = Math.abs(i-j);
						if(df < diff){
							diff = df;
							ca = i;
							ja = j;
						}
					}
				}
			}
		}
		String cans = Integer.toString(ca);
		String jans = Integer.toString(ja);
		while(cans.length() < C.length()){
			cans = "0" + cans;
		}
		while(jans.length() < C.length()){
			jans = "0" + jans;
		}
		println(cans + " " + jans);
	}
	
	boolean match(char[] t, int c){
		if(t.length == 2 &&  c >= 100){
			return false;
		}
		else if(t.length == 1 && c >= 10){
			return false;
		}
		
		if(t.length == 1){
			return check2(t[0], c);
		}
		else if(t.length == 2){
			if(!check2(t[0], c / 10)){
				return false;
			}
			return check2(t[1], c % 10);
		}
		else if(t.length == 3){
			if(!check2(t[0], c / 100)){
				return false;
			}
			if(!check2(t[1], (c / 10) % 10)){
				return false;
			}
			return check2(t[2], c % 10);
		}
		return false;
	}
	
	boolean check2(char c, int ck){
		if(c == '?'){
			return true;
		}
		else if(c - '0' == ck){
			return true;
		}
		return false;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		File file = new File("B-small-attempt0.in");
		if(file.exists()){
			System.setIn(new BufferedInputStream(new FileInputStream(file)));
		}
		else{
			throw new Exception("can't find a input file : " + file.getAbsolutePath());
		}
		//sc =  new Scanner(System.in);
		br = new BufferedReader(new InputStreamReader(System.in));
		FileWriter fw = new FileWriter(new File("output.txt"));
		out = new PrintWriter(fw);
		
		B b = new B();
		int T = 0;
		if(sc != null){
			T = sc.nextInt();
		}
		else{
			T = parseInt(br.readLine());
		}
		int t = 1;
		while(t <= T){
			out.print("Case #" + t + ": ");
			System.out.print("Case #" + t + ": ");
			b.solve();
			t++;
		}
		out.close();
		fw.close();
	}
	
	void print(int i){
		out.print(i + "");
		System.out.print(i);
	}
	void println(int i){
		out.println(i + "");
		System.out.println(i);
	}
	void print(String s){
		out.print(s);
		System.out.print(s);
	}
	void println(String s){
		out.println(s);
		System.out.println(s);
	}
	void print(long i){
		out.print(i + "");
		System.out.print(i);
	}
	void println(long i){
		out.println(i + "");
		System.out.println(i);
	}
}
