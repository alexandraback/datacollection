import java.util.*;
import java.io.*;
public class Consonants {
	public static void main(String[] args) {
		String inputfile = args[0];
		BufferedReader input;
		try {
			input = new BufferedReader(new FileReader(inputfile));
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		Scanner s = new Scanner(input);
		int T = s.nextInt();
		for (int x = 1; x <=T; x++) {
			String str = s.next();
			int n = s.nextInt();
			ArrayList<Integer> startindex = new ArrayList<Integer>();
			for (int i = 0; i < str.length() - (n-1); i++) {
				int j;
				for (j = 0; j < n; j++) {
					if (str.charAt(i+j) == 'a' ||
					    str.charAt(i+j) == 'e' ||
					    str.charAt(i+j) == 'i' ||
						str.charAt(i+j) == 'o' ||
						str.charAt(i+j) == 'u') {
						i = i+j;
						break;
					}
				}
				if (j == n) {
					startindex.add(i);
				}
			}

			int count = 0;
			// For a string of size N
			// there are N - (n-1) substrings of size n.
			for (int i = n; i <= str.length(); i++) {
				// j is the starting position.
				for (int j = 0; j < str.length()-i+1; j++) {
					for (Integer start : startindex) {
						if (j <= start && start+n <= j+i) {
							count++;
							break;
						}
					}
				}
			}
			System.out.println("Case #" + x + ": " + count);
		}
	}
}
