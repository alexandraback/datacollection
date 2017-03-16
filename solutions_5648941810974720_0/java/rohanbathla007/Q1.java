package Round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Q1 {
	
	String number[];
	int upperAlphabets[];
	String phoneNumber;
	
	public static void main(String args[]) throws FileNotFoundException {
		Q1 obj = new Q1();
		obj.initialize();
		obj.solve();
	}

	private void initialize() {
		number = new String[10];
		number[0] = "ZERO";
		number[1] = "ONE";
		number[2] = "TWO";
		number[3] = "THREE";
		number[4] = "FOUR";
		number[5] = "FIVE";
		number[6] = "SIX";
		number[7] = "SEVEN";
		number[8] = "EIGHT";
		number[9] = "NINE";
	}

	private void solve() throws FileNotFoundException {
		File input = new File("C:\\Users\\rbathla\\Desktop\\input.txt");
		File output = new File("C:\\Users\\rbathla\\Desktop\\output.txt");
		Scanner in = new Scanner(input);
		PrintWriter out = new PrintWriter(output);
		
		int t = in.nextInt();
		int caseNumber = 1;
		
		while ((t--) != 0) {
			String s = in.next();
			generatePhoneNumber(s);
			out.println("Case #" + caseNumber + ": " + phoneNumber);
			++caseNumber;
		}
		in.close();
		out.close();
	}

	private String generatePhoneNumber(String s) {
		phoneNumber = "";
		upperAlphabets = new int[26];
		
		for (int i = 0; i < s.length(); i++) {
			++upperAlphabets[s.charAt(i) - 65];
		}
		int temp[] = upperAlphabets.clone();
		
		for(int i = 0; i <= 9; i++) {
			phoneNumber = "";
			upperAlphabets = temp.clone();
			for (int j = 0, k = i; j <= 9 ; j++, k++) {
				boolean flag = true;
				while (flag) {
					flag = findNumber(number[(k+10)%10], (k+10)%10);
				}
			}
			if (isEmpty()) {
				break;
			}
		}


		int[] ans = new int[10];
		for (int i = 0; i < phoneNumber.length(); i++) {
			++ans[phoneNumber.charAt(i) - 48];
		}
		
		phoneNumber = "";
		for (int i = 0; i < 10; i++) {
			for (int j = 1; j <= ans[i]; j++) {
				phoneNumber += (String.valueOf(i));
			}
		}
		
		return phoneNumber;
	}

	private boolean isEmpty() {
		boolean result = true;
		
		for (int i = 0; i < upperAlphabets.length; i++) {
			if (upperAlphabets[i] != 0) {
				result = false;
				break;
			}
		}
		
		return result;
	}

	private boolean findNumber(String num, int x) {
		
		int temp[] = upperAlphabets.clone();
		boolean flag = true;
		
		for (int i = 0; i < num.length(); i++) {
			if (upperAlphabets[num.charAt(i) - 65] == 0) {
				flag = false;
				break;
			} else {
				--upperAlphabets[num.charAt(i) - 65];
			}
		}
		
		if (!flag) {
			upperAlphabets = temp.clone();
		} else {
			phoneNumber += String.valueOf(x);
		}
		
		return flag;
	}

}
