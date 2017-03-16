package Q1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class A {
	public static void main(String[] args) throws Exception {	
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new FileWriter("C:\\A-large.out"));
		int cases = Integer.valueOf(in.readLine());
		boolean X[] = new boolean[16];
		boolean O[] = new boolean[16];
		String search = "XTO";
		for ( int caseN=0 ; caseN<cases ; caseN++ ) {
			int count = 0;
			for ( int l=0 ; l<4 ; l++ ) {
				char[] columns = in.readLine().toCharArray();
				for ( int c=0 ; c<4 ; c++ ) {
					int index = search.indexOf(columns[c]);
					X[l*4 + c] = index==0 || index==1;
					O[l*4 + c] = index==1 || index==2;
					count += index>=0?1:0;
				}
			}
			out.append("Case #").append(String.valueOf(caseN+1)).append(": ");
			if ( isWinner(X) ) {
				out.append("X won");
			} else if ( isWinner(O) ) {
				out.append("O won");
			} else if ( isDraw(count) ) {
				out.append("Draw");
			} else {
				out.append("Game has not completed");
			}
			out.newLine();
			in.readLine();
		}
		out.close();
		in.close();
	}
	
	private static boolean isDraw(int count) {
		return count == 16;
	}
	
	private static boolean isWinner(boolean[] t) {
		return (t[0] && t[1] && t[2] && t[3]) ||
				(t[0] && t[5] && t[10] && t[15]) ||
				(t[0] && t[4] && t[8] && t[12]) ||
				(t[1] && t[5] && t[9] && t[13]) ||
				(t[2] && t[6] && t[10] && t[14]) ||
				(t[3] && t[7] && t[11] && t[15]) ||
				(t[3] && t[6] && t[9] && t[12]) ||
				(t[4] && t[5] && t[6] && t[7]) ||
				(t[8] && t[9] && t[10] && t[11]) ||
				(t[12] && t[13] && t[14] && t[15]);
	}
}
