import java.io.*;
import java.util.StringTokenizer;

public class RecycledNumbers {
	public static void main(String[] args) {
		try {
			BufferedReader ifStream = new BufferedReader(new FileReader("C-large.in"));
			PrintWriter ofStream = new PrintWriter(new FileWriter("C.out"));
			int numCase;
			String inputCase;

			numCase = Integer.parseInt(ifStream.readLine());
			for (int i=1; i<=numCase; i++) {
				ofStream.println("Case #"+i+": "+recycledNumbers(ifStream.readLine()));
			}

			ifStream.close();
			ofStream.close();
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
	}

	private static int  recycledNumbers(String input) {
		StringTokenizer st = new StringTokenizer(input, " ", false);
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int numDigits = String.valueOf(A).length();
		int[] mArr = new int[numDigits];
		int count, m;
		int result = 0;

		for (int n=A; n<B; n++) {
			count = 0;
			for (int i=1; i<numDigits; i++) {
				m = shiftInt(n, i);
				if (m > n && m <= B) {
					mArr[count++] = m;
				}
			}
			result += count;
			for (int i=0; i<count; i++) {	// redundancy check
				for (int j=i+1; j<count; j++) {
					if (mArr[j] == mArr[i]) {
						result--;
						mArr[j] = 0;
					}
				}
			}
		}

		return result;
	}

	private static int shiftInt(int num, int k) {
		String before = String.valueOf(num);
		String after = before.substring(k, before.length()) + before.substring(0, k);

		return Integer.parseInt(after);
	}
}
