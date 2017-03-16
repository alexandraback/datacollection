import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class FairAndSquare {
	
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "C-large-1.in";
		StringBuilder answer = new StringBuilder();
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFilename));
			String line = br.readLine();
			int testCases = Integer.parseInt(line);
			for (int i=1; i<=testCases; i++) {
				line = br.readLine();
				int indexOfSpace = line.indexOf(" ");
				String aStr = line.substring(0,  indexOfSpace);
				String bStr = line.substring(indexOfSpace+1);
				int ans = getAnswer(Double.parseDouble(aStr), Double.parseDouble(bStr));
				
				answer.append("Case #" + i + ": " + ans + System.lineSeparator());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		writeOutput(answer.toString());
		System.out.println("in " + (System.currentTimeMillis() - start));
	}
	
	private static int getAnswer(double a, double b) {
		int count = 0;
		double aSqrt = Math.ceil(Math.sqrt(a));
		double bSqrt = Math.floor(Math.sqrt(b));
		double currPalindrom = 0;
		for (double i=aSqrt; (currPalindrom == 0) && i<=bSqrt; i++) {
			String iStr = String.format("%.0f", i);
			if (isPalindrom(iStr)) 
				currPalindrom = i;
		}
		while (currPalindrom != 0) {
			if (isSquarePalindrom(currPalindrom))
				count++;
			currPalindrom = nextPalindrom(currPalindrom, bSqrt);
		}
		return count;
	}
	
	private static double nextPalindrom(double currPalindrom, double endOfInterval) {
		String curr = String.format("%.0f", currPalindrom);
		int length = curr.length();
		if (length%2 == 0) { //even  12344321
			for (int i=(length/2)-1; i>=0; i--) {
				int iMirror = length - 1 - i;
				int digit = Integer.parseInt("" + curr.charAt(i)); 
				if (digit < 9) {
					digit++;
					if (i != 0)
						curr = curr.substring(0, i) + digit + curr.substring(i+1, iMirror) + digit + curr.substring(iMirror+1);
					else
						curr = digit + curr.substring(i+1, iMirror) + digit;
					break;
				}
				else {
					if (i != 0)
						curr = curr.substring(0, i) + 0 + curr.substring(i+1, iMirror) + 0 + curr.substring(iMirror+1);
					else { //currPalindrom is from the form 999...999
						curr = String.format("%.0f", currPalindrom+2);
						break;
					}
				}
			}
		}
		else { //odd 123454321
			int digit = Integer.parseInt("" + curr.charAt((length/2)));
			if (digit < 9) {
				digit++;
				if (length != 1)
					curr = curr.substring(0, length/2) + digit + curr.substring((length/2)+1);
				else
					curr = "" + digit;
			}
			else {
				if (length == 1) //currPalindrom is 9
					curr = "11";
				else {
					curr = curr.substring(0, length/2) + 0 + curr.substring((length/2)+1);
					for (int i=(length/2)-1; i>=0; i--) {
						int iMirror = length - 1 - i;
						digit = Integer.parseInt("" + curr.charAt(i)); 
						if (digit < 9) {
							digit++;
							if (i != 0)
								curr = curr.substring(0, i) + digit + curr.substring(i+1, iMirror) + digit + curr.substring(iMirror+1);
							else
								curr = digit + curr.substring(i+1, iMirror) + digit;
							break;
						}
						else {
							if (i != 0)
								curr = curr.substring(0, i) + 0 + curr.substring(i+1, iMirror) + 0 + curr.substring(iMirror+1);
							else { //currPalindrom is from the form 999...999
								curr = String.format("%.0f", currPalindrom+2);
								break;
							}
						}
					}
				}
			}
		}
		double ans = Double.parseDouble(curr);
		if (ans > endOfInterval) {
			ans = 0;
		}
		return ans;
	}

	private static boolean isSquarePalindrom(double number) {
		double square = Math.pow(number, 2);
		String squareStr = String.format("%.0f", square);
		int length = squareStr.length();
		for (int i=0; i<length/2; i++) {
			if (squareStr.charAt(i) != squareStr.charAt(length-1-i))
				return false;
		}
		return true;
	}

	private static boolean isPalindrom(String number) {
		int length = number.length();
		for (int i=0; i<length/2; i++) {
			if (number.charAt(i) != number.charAt(length-1-i))
				return false;
		}
		return true;
	}

	private static void writeOutput(String string) {
		try {
			String outputFilename = "output.txt";
			BufferedWriter bw = new BufferedWriter(new FileWriter(outputFilename));
			bw.write(string);
			bw.close();
			System.out.println("success!");
		} catch (Exception e) {
			System.out.println("error!");
		}
	}

}
