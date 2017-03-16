import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("A-small-attempt1.in"));
		FileWriter fstream = new FileWriter("A-small-attempt1.out");
		BufferedWriter out = new BufferedWriter(fstream);
		int numCases = in.nextInt();
		in.nextLine();
		for (int i = 0; i < numCases; i++) {
			String nextLine = in.nextLine();
			String[] strs = nextLine.split(" ");
			String str = strs[0]; 
			int n = Integer.valueOf(strs[1]);
			out.write("Case #" + String.valueOf(i + 1) + ": "
					+ String.valueOf(nValue(str, n)) + "\n");
		}
		out.close();
		in.close();
	}
	
	public static int nValue(String str, int n) {
		int count = 0;
		for (int i = 0; i <= str.length(); i++) {
			for (int j = i + n; j <= str.length(); j++) {
				String s = str.substring(i, j);
				if (hasNValue(s, n)) {
					count++;
				}
			}
		}
		return count;
	}
	
	public static boolean hasNValue(String str, int n) {
		//System.out.println(str);
		for (int i = 0; i <= str.length() - n; i++) {
			int count = 0;
			for (int j = i; j < i + n; j++) {
				if (isConsonant(str.charAt(j))) {
					count++;
				} else {
					break;
				}
				if (count == n) {
					return true;
				}
			}
		}
		return false;
	}
	
	public static boolean isConsonant(char ch) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			return false;
		}
		return true;
	}
}


