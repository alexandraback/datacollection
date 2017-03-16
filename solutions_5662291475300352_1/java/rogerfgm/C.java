

import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.Integer.*;

public class C {
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
		N  = Integer.parseInt(s);
		
		
		int[][] d = new int[N][3];
		boolean f = false;
		int cnt = 0;
		for(int i = 0; i < N; i++){
			s = br.readLine();
			String[] sp = s.split(" ");
			for(int j = 0; j < 3; j++){
				d[i][j] = Integer.parseInt(sp[j]);
			}
			cnt += d[i][1];
		}
		if(N == 1 && d[0][1] == 1){
			println(0);
			return;
		}
		
		double[] first = new double[cnt];
		double[] second = new double[cnt];
		int idx = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < d[i][1]; j++){
				int m = d[i][1] + j;
				first[idx] = m * (360.0-d[i][0]) / 360;
				second[idx] = m * (360.0-d[i][0] + 360) / 360;
				idx++;
			}
		}
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < cnt; i++){
			int a = 0;
			for(int j = 0; j < cnt; j++){
				if(j == i) continue;
				if(first[j] < first[i] - DF){
					a++;
				}
				if(second[j] < first[i] - DF){
					a++;
				}
			}
			ans = Math.min(a, ans);
		}
		
		
		println(ans);
		return;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		File file = new File("C-small-2-attempt1.in");
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
		
		C b = new C();
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
