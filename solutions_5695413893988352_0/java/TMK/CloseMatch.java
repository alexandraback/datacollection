package codejam2016.round1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

class Answer {
	long first;
	long second;
	long min;
	public Answer(long first, long second) {
		this.first = first;
		this.second = second;
		this.min = Math.abs(first - second);
	}
}

public class CloseMatch {	
	public void run() throws IOException {
		BufferedReader fin = new BufferedReader(new FileReader(new File("in.txt")));
		PrintWriter fout = new PrintWriter(new File("out.txt"));
		int numCases = Integer.parseInt(fin.readLine());
		for (int cases = 0; cases < numCases; cases++) {
			String[] str = fin.readLine().split(" ");
			Answer ans = new Answer(0, 0);
			ans.min = Long.MAX_VALUE;
			diff(str[0].toCharArray(), str[1].toCharArray(), 0, 0, 0, ans);
			
			System.out.format("Case #%d: %0" + str[0].length() +"d %0" + str[0].length() + "d\n", cases+1, ans.first, ans.second);
			fout.format("Case #%d: %0" + str[0].length() +"d %0" + str[0].length() + "d\n", cases+1, ans.first, ans.second);
		}
		fin.close();
		fout.close();
	}
	
	public void diff(char[] first, char[] second, int pos, long firstNum, long secondNum, Answer ans) {
		if (pos == first.length) {
			long min = Math.abs(firstNum - secondNum);
			if (min < ans.min) {
				ans.first = firstNum;
				ans.second = secondNum;
				ans.min = min;
			} else if (min == ans.min) {
				if (firstNum < ans.first) {
					ans.first = firstNum;
					ans.second = secondNum;
					ans.min = min;	
				} else if (secondNum < ans.second) {
					ans.first = firstNum;
					ans.second = secondNum;
					ans.min = min;
				}
			}
			return;
		}
		long firstDigit = first[pos] - '0';
		long secondDigit = second[pos] - '0';

		if (firstNum == secondNum) {
			if (first[pos] == '?' && second[pos] == '?') {
				diff(first, second, pos+1, firstNum * 10, secondNum * 10, ans);
				diff(first, second, pos+1, firstNum * 10+1, secondNum * 10, ans);
				diff(first, second, pos+1, firstNum * 10, secondNum * 10+1, ans);
			} else if (first[pos] == '?') {
				diff(first, second, pos+1, firstNum * 10 + secondDigit, secondNum * 10 + secondDigit, ans);
				diff(first, second, pos+1, firstNum * 10 + (secondDigit+1)%10, secondNum * 10 + secondDigit, ans);
				diff(first, second, pos+1, firstNum * 10 + (secondDigit+9)%10, secondNum * 10 + secondDigit, ans);
			} else if (second[pos] == '?') {
				diff(first, second, pos+1, firstNum * 10 + firstDigit, secondNum * 10 + firstDigit, ans);
				diff(first, second, pos+1, firstNum * 10 + firstDigit, secondNum * 10 + (firstDigit+1)%10, ans);
				diff(first, second, pos+1, firstNum * 10 + firstDigit, secondNum * 10 + (firstDigit+9)%10, ans);
			} else {

				diff(first, second, pos+1, firstNum * 10 + firstDigit, secondNum * 10 + secondDigit, ans);
			}
		} else if (firstNum != secondNum) {
			if (first[pos] == '?') {
				firstDigit = firstNum > secondNum ? 0 : 9;
			}
			if (second[pos] == '?') {
				secondDigit = firstNum > secondNum ? 9 : 0;
			}
			diff(first, second, pos+1, firstNum*10+firstDigit, secondNum*10 + secondDigit, ans);
		}
	}

	public static void main(String[] args) throws IOException {
		CloseMatch test = new CloseMatch();
		test.run();
	}
}
