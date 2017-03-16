package cn.zhoushuyan.codejam._2013.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

public class C {
	
	public static void main(String[] args) throws Exception {
		// TODO input file path
		String filePath = "/Users/Alen/Documents/CodeJam/2013/Qualification/C-Large-1.in";

		BufferedReader br = new BufferedReader(new FileReader(filePath));
		String outFile = filePath.substring(0, filePath.lastIndexOf('.'))
				+ ".out";
		BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
		
		final int MAX_POWER = 16;
		
		int[] palindrome = new int[MAX_POWER / 2];
		Integer[] palindromeSquarePalindrome = new Integer[MAX_POWER];
		List<Integer[]> pspList = new ArrayList<Integer[]>();
		
		for (int i = 1; i <= palindrome.length; i++) {
			for (int i2 = 0; i2 < palindrome.length; i2++) {
				palindrome[i2] = 0;
			}
			for (int i3 = 0; i3 < palindromeSquarePalindrome.length; i3++) {
				palindromeSquarePalindrome[i3] = 0;
			}
			palindromeSquarePalindrome[palindromeSquarePalindrome.length - 1] = 2 * i - 1;
			
			int j = 0;
			while (j >= 0 && j <= i / 2) {
				if (palindrome[j] == 0) {
					if (j == 0 || j >= (i - 1) / 2 ) palindrome[j] = palindrome[i - j - 1] = 1;
					else {
						j++;
						continue;
					}
				}
				
				boolean isPalindrome = true;
k:				for (int k = 0; k < i; k++) {
					int palindromeSquare = 0;
					for (int l = 0; l <= k; l++) {
						palindromeSquare += palindrome[l] * palindrome[k - l];
						if (palindromeSquare > 9) {
							isPalindrome = false;
							break k;
						}
					}
					palindromeSquarePalindrome[k] = palindromeSquare;
					palindromeSquarePalindrome[2 * i - 2 - k] = palindromeSquare;
				}
				
				if (isPalindrome) {
					pspList.add(palindromeSquarePalindrome.clone());
					if (j < (i - 1) / 2 || palindrome[j] == 9) {
						j++;
						continue;
					}
				} else {
					palindrome[j] = 0;
					palindrome[i - j - 1] = 0;
					j--;
				}
				if (j >= 0) {
					int newValue = palindrome[j] + 1;
					//newValue %= 10;
					if (j == 0 && newValue == 0) {
						newValue = 1;
					}
					palindrome[j] = newValue;
					palindrome[i - j - 1] = newValue;
				}

			}
		}
		
		String line = br.readLine();
		int t = Integer.valueOf(line);
		for (int i = 0; i < t; i++) {
			// TODO main logical
			// ...
			line = br.readLine();
			String[] strs = line.split(" ");
			Integer[] a = new Integer[MAX_POWER];
			Integer[] b = new Integer[MAX_POWER];
			a[a.length - 1] = strs[0].length();
			for (int k = 0; k < strs[0].length(); k++) {
				a[k] = strs[0].charAt(k) - 0x30;
			}
			b[b.length - 1] = strs[1].length();
			for (int k = 0; k < strs[1].length(); k++) {
				b[k] = strs[1].charAt(k) - 0x30;
			}
			
			int start = 0;
			for (int k = 0; k < pspList.size(); k++) {
				if (compare(a, pspList.get(k)) <= 0) {
					start = k;
					break;
				}
			}
			int end = pspList.size();
			for (int k = start; k < pspList.size(); k++) {
				if (compare(b, pspList.get(k)) < 0) {
					end = k;
					break;
				}
			}
			
			// TODO output
			bw.write(String.format("Case #%d: %d\r\n", i + 1, end - start));
		}

		bw.flush();
		bw.close();
		br.close();

	}
	
	public static int compare(Integer[] num1, Integer[] num2) {
		if (num1[num1.length - 1] < num2[num2.length - 1]) {
			return -1;
		} else if (num1[num1.length - 1] > num2[num2.length - 1]) {
			return 1;
		} else {
			for (int i = 0; i < num1[num1.length - 1]; i++) {
				if (num1[i] < num2[i]) {
					return -1;
				} else if (num1[i] > num2[i]) {
					return 1;
				} else {
					continue;
				}
			}
		}
		
		return 0;
	}

}
