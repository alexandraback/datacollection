import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File("C.in")));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("C.out"))));

			long[] table = new long[100];
			int tablenum = 0;
			for (int i = 1; i < 100000000; i++) {
				if (check(i)) {
					table[tablenum++] = (long)i*i;
					System.out.println(""+i+" "+((long)i*i));
				}
			}
			
			int T = Integer.parseInt(br.readLine());
			for (int i = 0; i < T; i++) {
				String[] param = br.readLine().split(" ");
				long A = Long.parseLong(param[0]);
				long B = Long.parseLong(param[1]);
				int ai = Arrays.binarySearch(table, 0, tablenum, A);
				int bi = Arrays.binarySearch(table, 0, tablenum, B);
				if (ai >= 0) ai++;
				if (bi >= 0) bi++;
				int answer = Math.abs(bi) - Math.abs(ai);
				if (bi > 0) answer++;
				pw.println("Case #" + (i+1) + ": " + answer);
			}
			
			pw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}
	
	private static boolean check(int n) {
		String str = Long.toString(n);
		int len = str.length();
		for (int i = 0; i < len/2; i++) {
			if (str.charAt(i) != str.charAt(len-1-i)) return false;
		}
		str = Long.toString((long)n*n);
		len = str.length();
		for (int i = 0; i < len/2; i++) {
			if (str.charAt(i) != str.charAt(len-1-i)) return false;
		}
		return true;
	}
}
