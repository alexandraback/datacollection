import java.io.*;
import java.util.*;

public class Dijkstra_large {
	public static final char[][] resultsM = {{'1','k','j'},{'k','1','i'},{'j','i','1'}};
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/C-large.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int l = sc.nextInt();
			long xLong = sc.nextLong();
			int x = -1;
			if (xLong>=12)
				x = (int)(xLong%4+8);
			else
				x = (int)xLong;
			char[] s = sc.next().toCharArray();
			char[] sFirst = new char[l*x];
			char[] sLast = new char[l*x];
			boolean[] negFirst = new boolean[l*x];
			boolean[] negLast = new boolean[l*x];
			sFirst[0] = s[0];
			sLast[l*x-1] = s[l-1];
			for (int a = 1; a < l*x; a++) {
				sFirst[a] = mult(sFirst[a-1], s[a%l]);
				sLast[l*x-a-1] = mult(s[l-a%l-1], sLast[l*x-a]);
				negFirst[a] = negFirst[a-1] ^ isNegMult(sFirst[a-1], s[a%l]);
				negLast[l*x-a-1] = negLast[l*x-a] ^ isNegMult(s[l-a%l-1], sLast[l*x-a]);
			}
			boolean isPossible = false;
			for (int a = 0; a < l*x-2 && a < l*4; a++) {
				if (sFirst[a] == 'i' && !negFirst[a]) {
					char m = '1';
					boolean mn = false;
					for (int b = a+1; b < l*x-1 && b < a+l*4; b++) {
						char tempM = m;
						m = mult(m, s[b%l]);
						mn ^= isNegMult(tempM, s[b%l]);
						if (m=='j' && !mn) {
							if (sLast[b+1] == 'k' && !negLast[b+1]) {
								isPossible = true;
							}
						}
					}
				}
			}
			
			output += "Case #" + i + ": " + (isPossible?"YES":"NO") + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/C-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
	
	public static char mult(char a, char b) {
		if (a=='1')
			return b;
		else if (b=='1')
			return a;
		else
			return resultsM[a-'i'][b-'i'];
	}
	
	public static boolean isNegMult(char a, char b) {
		if (a=='1' || b=='1')
			return false;
		return (b-a+3)%3!=1;
	}
}