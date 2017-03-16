import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ConsonantsLarge {
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
		int numconsonants;
		int start[];

		for (k = 0; k < T; k++) {
			input = br.readLine().split(" ");
			str = input[0];
			n = Integer.parseInt(input[1]);
			len = str.length();

			nvalue = 0;
			temp = 0;
			numconsonants = 0;
			for (i = 0; i < len; i++) {
				if (str.charAt(i) != 'a' && str.charAt(i) != 'e'
						&& str.charAt(i) != 'i' && str.charAt(i) != 'o'
						&& str.charAt(i) != 'u') {
					temp++;
				} else {
					if (temp >= n) {
						numconsonants += (temp - n + 1);
					}
					temp = 0;
				}
			}
			if (temp >= n) {
				numconsonants += (temp - n + 1);
			}

			// System.out.println("numconsonants=" + numconsonants);
			start = new int[numconsonants];

			temp = 0;
			l = 0;
			for (i = 0; i < len; i++) {
				if (str.charAt(i) != 'a' && str.charAt(i) != 'e'
						&& str.charAt(i) != 'i' && str.charAt(i) != 'o'
						&& str.charAt(i) != 'u') {
					temp++;
				} else {
					if (temp >= n) {
						for (j = temp - n; j >= 0; j--) {
							start[l++] = i - n - j;
						}
					}
					temp = 0;
				}
			}
			if (temp >= n) {
				for (j = temp - n; j >= 0; j--) {
					start[l++] = i - n - j;
				}
			}

			// System.out.println("start[i]=" + start[0]);
			// System.out.println("nvalue=" + (start[0] + 1)
			// * (len - n - start[0] + 1));
			if (numconsonants > 0)
				nvalue += (start[0] + 1) * (len - n - start[0] + 1);
			for (i = 1; i < numconsonants; i++) {
				// System.out.println("start[i]=" + start[i]);
				// System.out.println("nvalue=" + (start[i] - start[i - 1])
				// * (len - n - start[i] + 1));
				nvalue += (start[i] - start[i - 1]) * (len - n - start[i] + 1);
			}
			System.out.println("Case #" + (k + 1) + ": " + nvalue);
		}
	}
}
