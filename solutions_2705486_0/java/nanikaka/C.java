package gcj2013.r1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class C {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2013/r1b";
	final String PROBLEM = "C";

	int n, INF = 1<<26;
	char[] s;
	int[][] dp;
	List<String>[] dic;

	int get(int k, int x){
		if(n==k)return 0;
		if(dp[k][x]!=-1)return dp[k][x];
		int min = 1<<25;
		for(int L=1;L<=10 && k+L<=n;L++){
			for(String t:dic[L]){
				int cnt = 0, nx = x;
				boolean f = true;
				for(int i=0;i<L;i++){
					if(t.charAt(i)!=s[k+i]){
						f&=5<=k+i-nx;
						cnt++;
						nx = k+i;
					}
				}
				if(!f)continue;
				min = Math.min(min, cnt+get(k+L, nx));
			}
		}
		return dp[k][x] = min;
	}

	@SuppressWarnings("unchecked")
	void run(){
		Scanner scan = null;
		try {
			scan = new Scanner(new File("./src/"+PACKAGE+"/garbled_email_dictionary.txt"));
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
		dic = new List[11];
		for(int i=0;i<11;i++)dic[i]=new ArrayList<String>();
		while(scan.hasNext()){
			String str = scan.next();
			dic[str.length()].add(str);
		}
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			s = ("aaaaa"+sc.next()).toCharArray();
			n = s.length;
			dp = new int[n][n];
			for(int[]d:dp)Arrays.fill(d, -1);
			System.out.println("Case #"+CASE+": "+get(5, 0));
		}
	}

	void debug(Object...o){
		System.out.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new C().run();
	}
}
