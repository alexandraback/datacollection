import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Consonants {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input[];
		int T = Integer.parseInt(br.readLine());
		int i, j, k, l;
		int n;
		String str;
		long nvalue = 0;
		int len;
		int max;
		int temp;

		for (k = 0; k < T; k++) {
			input = br.readLine().split(" ");
			str = input[0];
			n = Integer.parseInt(input[1]);
			len = str.length();

			nvalue = 0;
			for (i = 0; i < len; i++) {
				for (j = i; j < len; j++) {
					max = 0;
					temp = 0;
					for (l = i; l <= j; l++) {
						if (str.charAt(l) != 'a' && str.charAt(l) != 'e'
								&& str.charAt(l) != 'i' && str.charAt(l) != 'o'
								&& str.charAt(l) != 'u') {
							temp++;
						} else {
							if (temp > max) {
								max = temp;
							}
							temp = 0;
						}
					}
					if (temp > max) {
						max = temp;
					}
					if (max >= n) {
						nvalue++;
					}
				}
			}

			System.out.println("Case #" + (k + 1) + ": " + nvalue);
		}
	}
}
