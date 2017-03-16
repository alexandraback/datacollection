import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.Locale;
import java.util.StringTokenizer;

public class B2 {

	static StringBuilder sb = new StringBuilder();
	static int CA;
	static char[] s, t;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("B.in"));
		System.setOut(new PrintStream("B2.out"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		CA = Integer.parseInt(in.readLine());
		StringTokenizer st;
		for (int c = 1; c <= CA; c++) {
			st = new StringTokenizer(in.readLine());
			s = st.nextToken().toCharArray();
			t = st.nextToken().toCharArray();
			sb.append("Case #" + c + ": ");
			solve2();
		}
		System.out.print(sb.toString());
	}
	
	static void solve2(){
		int L = s.length;
		int pot = 1;
		for (int i = 0; i < L; i++) {
			pot*=10;
		}
		ArrayList<Integer> A = new ArrayList<>();
		ArrayList<Integer> B = new ArrayList<>();
		
		for (int i = 0; i < pot; i++) {
			int n1 = i;
			if (match(n1, s)) A.add(n1);
			if (match(n1, t)) B.add(n1);
		}
	
		int min = Integer.MAX_VALUE;
		int c=-1, j =-1;
		int dist;
		for (Integer x : A) {
			for (Integer y : B) {
				dist = Math.abs(x-y);
				if (dist < min){
					min=dist;
					c=x;
					j=y;
				}
				else if (dist == min && x<c){
					min=dist;
					c=x;
					j=y;
				}
				else if (dist == min && x==c && y<j){
					min=dist;
					c=x;
					j=y;
				}
				
			}
		}
		
		sb.append(form(c) + " " + form(j)+"\n");
		
	}
	
	static boolean match(int n, char[] S){
		String SS = ""+n;
		while(SS.length()<S.length) SS='0'+SS;
		char[] T = SS.toCharArray();
		for (int i = 0; i < S.length; i++) {
			if (S[i]!='?' && S[i]!=T[i]) return false;
		}
		return true;
	}
	
	static long[][][] C = new long[10][10][20]; 
	static long[][][] D = new long[10][10][20]; 

	static void solve(){
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) for (int k = 0; k < 20; k++) C[i][j][k] = -1;
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) for (int k = 0; k < 20; k++) D[i][j][k] = -1;

		if (s[0]=='?') {
			if (t[0]=='?') {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						C[i][j][0]=i;
						D[i][j][0]=j;
					}
				}
			}else{
				for (int i = 0; i < 10; i++) {
					C[i][num(t[0])][0] = i;
					D[i][num(t[0])][0] = num(t[0]);
				}				
			}
		}else{
			if (t[0]=='?'){
				for (int i = 0; i < 10; i++) {
					C[num(s[0])][i][0] = num(s[0]);
					D[num(s[0])][i][0] = i;
				}
			}
			else{
				C[num(s[0])][num(t[0])][0] = num(s[0]);
				D[num(s[0])][num(t[0])][0] = num(t[0]);
			}
		}

		long num1, num2, dist;
		long min;

		for (int i = 1; i < s.length; i++) {

			int LA, LB, HA, HB;
			
			if (s[i]=='?'){
				LA=0; HA=9; 
			}else{
				LA=num(s[i]); HA=LA;
			}
			
			if (t[i]=='?'){
				LB=0; HB=9; 
			}else{
				LB=num(t[i]); HB=LB;
			}
			
			for (int a = LA; a <=HA; a++) {
				for (int b = LB; b <=HB; b++) {
					min = Long.MAX_VALUE;
					for (int d = 0; d < 10; d++) {
						for (int e = 0; e < 10; e++) {

							if (C[d][e][i-1] == -1) continue;

							num1 = C[d][e][i-1]*10+a;
							num2 = D[d][e][i-1]*10+b;

							dist = Math.abs(num1 - num2);

							if (dist<min){
								min=dist;
								C[a][b][i] = num1;
								D[a][b][i] = num2;
							}else if (dist==min && C[a][b][i] > num1) {
								min=dist;
								C[a][b][i] = num1;
								D[a][b][i] = num2;
							}else if (dist==min && C[a][b][i] == num1 && D[a][b][i] > num2) {
								min=dist;
								C[a][b][i] = num1;
								D[a][b][i] = num2;
							}
						}
					}
				}
			}
		}
		min = Long.MAX_VALUE;
		long c=-1, d=-1;
		for (int a = 0; a <= 9; a++) {
			for (int b = 0; b <= 9; b++) {
				 if (C[a][b][s.length-1]==-1) continue;
				 num1 = C[a][b][s.length-1];
				 num2 = D[a][b][s.length-1];
				 dist = Math.abs(num1-num2);
				 if (dist<min){
					 min=dist;
					 c = num1;
					 d = num2;
				 }else if (dist==min && c > num1){
					 min = dist;
					 c = num1;
					 d = num2;
				 }else if (dist==min && c == num1 && d > num2){
					 min = dist;
					 c = num1;
					 d = num2;
				 }
			}
		}

		sb.append(form(c) + " " + form(d) +"\n");
	}
	static String form(long x){
		String sss = ""+x;
		while(sss.length()<s.length) sss = '0' + sss;
		return sss;
	}
	static int num(char c){
		return c-'0';

	}
}


