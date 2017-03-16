import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Formatter;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {

	static StringBuilder sb = new StringBuilder();
	static int CA;
	static char[] s, t;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("B.in"));
		System.setOut(new PrintStream("B.out"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		CA = Integer.parseInt(in.readLine());
		StringTokenizer st;
		for (int c = 1; c <= CA; c++) {
			st = new StringTokenizer(in.readLine());
			s = st.nextToken().toCharArray();
			t = st.nextToken().toCharArray();
			sb.append("Case #" + c + ": ");
			solve();
		}
		System.out.print(sb.toString());
	}

	static long[][][][] C = new long[10][10][20][10]; 
	static long[][][][] D = new long[10][10][20][10]; 

	static void solve(){
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) for (int k = 0; k < 20; k++) for (int l = 0; l < 10; l++) C[i][j][k][l] = -1;
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) for (int k = 0; k < 20; k++) for (int l = 0; l < 10; l++) D[i][j][k][l] = -1;

		if (s[0]=='?') {
			if (t[0]=='?') {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						C[i][j][0][0]=i;
						D[i][j][0][0]=j;
					}
				}
			}else{
				for (int i = 0; i < 10; i++) {
					C[i][num(t[0])][0][0] = i;
					D[i][num(t[0])][0][0] = num(t[0]);
				}				
			}
		}else{
			if (t[0]=='?'){
				for (int i = 0; i < 10; i++) {
					C[num(s[0])][i][0][0] = num(s[0]);
					D[num(s[0])][i][0][0] = i;
				}
			}
			else{
				C[num(s[0])][num(t[0])][0][0] = num(s[0]);
				D[num(s[0])][num(t[0])][0][0] = num(t[0]);
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

							if (C[d][e][i-1][0] == -1) continue;

							int X = 0;
							
							while(X < 10 && C[d][e][i-1][X]!=-1) {
								num1 = C[d][e][i-1][X]*10+a;
								num2 = D[d][e][i-1][X]*10+b;

								dist = Math.abs(num1 - num2);

								if (dist<min){
									min=dist;
									C[a][b][i][0] = num1;
									D[a][b][i][0] = num2;
									for (int j = 1; j < 10; j++) {
										C[a][b][i][j] = -1;
										D[a][b][i][j] = -1;

									}
								}else if (dist==min) {
									int W=0;
									while(W<10 && C[a][b][i][W]!=-1) W++;
									if (W<10){
									min=dist;
									C[a][b][i][W] = num1;
									D[a][b][i][W] = num2;
									}
								}
								X++;
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
				 if (C[a][b][s.length-1][0]==-1) continue;
				 
				 int X=0;
				 
				 while (X < 10 && C[a][b][s.length-1][X]!=-1){
					 num1 = C[a][b][s.length-1][X];
					 num2 = D[a][b][s.length-1][X];
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

					 
					 X++;
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


