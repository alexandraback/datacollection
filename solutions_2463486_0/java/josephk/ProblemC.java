import java.io.*;
import java.math.*;
import java.util.*;

public class ProblemC {

    private static boolean isPalindrome(long n) {
	char[] str = ("" + n).toCharArray();
	for (int i = 0; i < str.length; i++) {
	    if (str[i] != str[str.length - i - 1]) {
		return false;
	    }
	}
	return true;
    }

    private static long getResult(long[] range) {
	long start = (long) Math.sqrt(range[0]);
	while (start * start > range[0]) {
	    start = start / 2;
	}
	long end = (long) Math.sqrt(range[1]);
	while (end * end < range[1]) {
	    end = end * 2;
	}
	long count = 0;
	for (long root = start; root <= end; root++) {
	    if (root * root < range[0]) {
		continue;
	    } else if (root * root > range[1]) {
		break;
	    }
	    if (!isPalindrome(root) || !isPalindrome(root * root)) {
		continue;
	    }
	    count++;
	}
	return count;
    }

    public static void main(String[] args) throws Exception {
	Scanner input = new Scanner(System.in);
	int cases = Integer.parseInt(input.nextLine().trim());
	for (int c = 0; c < cases; c++) {
	    String[] rangeStr = input.nextLine().split(" ");
	    long[] range = new long[] { Long.parseLong(rangeStr[0]),
					Long.parseLong(rangeStr[1]) };

	    System.out.println("Case #" + (c+1) + ": " + getResult(range));
	}
    }
}
