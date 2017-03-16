import java.io.*;
import java.util.*;

public class Dijkstra {
	public static final char[][] resultsM = {{'1','k','j'},{'k','1','i'},{'j','i','1'}};
	public static final char[][] resultsD = {{'1','k','j'},{'k','1','i'},{'j','i','1'}};
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/C-small.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int l = sc.nextInt();
			int x = sc.nextInt();
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
			for (int a = 0; a < l*x-2; a++) {
				if (sFirst[a] == 'i' && !negFirst[a]) {
					char m = '1';
					boolean mn = false;
					for (int b = a+1; b < l*x-1; b++) {
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
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/C-small.out"), "utf-8"));
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
	
	public static char div(char a, char b) {
		if (a=='1')
			return b;
		else if (b=='1')
			return a;
		else
			return resultsD[a-'i'][b-'i'];
	}
	
	public static boolean isNegDiv(char a, char b) {
		if (b=='1')
			return false;
		else if (a=='1')
			return true;
		else
			return (b-a+3)%3==1;
	}
}