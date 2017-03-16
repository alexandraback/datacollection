import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Count {
	public static void main(String[] args) throws FileNotFoundException {
		 Scanner in = new Scanner(new File("s1.in"));
		//Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int caseNo = 1; caseNo <= cases; caseNo++) {
			int val = in.nextInt();
			int count = 0;
			while (val > 20) {
				String sVal = "" + val;
				// char first = sVal.charAt(0);
				char last = sVal.charAt(sVal.length() - 1);
				if (last != '1') {
					val--;
					count++;
				} else
				// We know the last digit is 1
				if (val < 1000) {

					int rev = reverse(val);
					if (rev < val)
						val = rev;
					else
						val--;
					count++;
				} else {
					char second = sVal.charAt(sVal.length() - 2);
					if (second != '0') {
						val--;
						count++;
					} // The last 2 digits are 01
					else if (val < 100000) {

						int rev = reverse(val);
						if (rev < val)
							val = rev;
						else
							val--;
						count++;
					} else {
						char third = sVal.charAt(sVal.length() - 3);
						if (third != '0') {
							val--;
							count++;
						} // The last 3 digits are 001
						else if (val < 10000000) {

							int rev = reverse(val);
							if (rev < val)
								val = rev;
							else
								val--;
							count++;
						}

					}

				}
			}
			count += val;

			System.out.println("Case #" + caseNo + ": " + count);

		}
	}

	private static int reverse(int i) {
		int result = 0;
		// System.err.print("reverse of " + i + " is ");
		while (i > 0) {
			result = result * 10 + i % 10;
			i /= 10;
		}
		// System.err.println(result);
		return result;
	}

}
