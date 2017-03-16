import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author Mostafa
 *
 */
public class TESTME {
	public static String[] tobin(int[] a, int x) {
		int i, j, k;
		String[] back = new String[a.length];
		char[] temp = new char[x];
		for (i = 0; i < x; i++) {
			temp[i] = '0';
		}
		for (i = 0; i < a.length; i++) {
			String tempo = Integer.toBinaryString(a[i]);
			k = x;
			for (j = tempo.length() - 1; j >= 0; j--) {
				temp[k - 1] = tempo.charAt(j);
				k--;
			}
			String temp2 = new String(temp);
			back[i] = temp2;
			for (j = 0; j < x; j++) {
				temp[j] = '0';
			}
		}
		return back;
	}

	public static void main(int[] s, int t, PrintWriter out) throws FileNotFoundException {
		int i, k = 0, j = 0;
		int counter1 = 0;
		int counter2 = 0;
		int[] temp = new int[(int) Math.pow(2, s.length)];
		for (i = 0; i < temp.length; i++) {
			temp[i] = i;
		}
		String[] bintemp = tobin(temp, s.length);
		boolean found = false;
		for (i = 1; i < bintemp.length; i++) {
			for (k = i + 1; k < bintemp.length; k++) {
				counter1 = 0;
				counter2 = 0;
				for (j = 0; j < bintemp[0].length(); j++) {
					if (bintemp[i].charAt(j) == '1') {
						counter1 += s[j];
					}
					if (bintemp[k].charAt(j) == '1') {
						counter2 += s[j];
					}
				}
				if (counter1 == counter2) {
					found = true;
					break;
				}
			}
			if (found == true) {
				break;
			}
		}
		if (found == true) {
			out.printf("Case #%d:\n", t);
			System.out.println(t);
			int[] lastback = new int[s.length];
			int[] lastback2 = new int[s.length];
			int lastcounter1 = 0;
			int lastcounter2 = 0;
			for (j = 0; j < bintemp[0].length(); j++) {
				if (bintemp[i].charAt(j) == '1') {
					lastback[lastcounter1] = s[j];
					lastcounter1++;
				}
				if (bintemp[k].charAt(j) == '1') {
					lastback2[lastcounter2] = s[j];
					lastcounter2++;
				}
			}
			for (i = 0; i < lastcounter1; i++) {
				out.printf("%d ", lastback[i]);
			}
			out.printf("\n");
			for (i = 0; i < lastcounter2; i++) {
				out.printf("%d ", lastback2[i]);
			}
		}
		else {
			out.printf("Case #%d:\nImpossible", t);
		}
		System.out.println("done2");
	}
}
