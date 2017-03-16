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

    private static long getResultSlow(long[] range) {
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
	    System.out.println((root * root) + "L,");
	    count++;
	}
	return count;
    }

    private static long getResult(long[] range) {
	int count = 0;
	for (int i = 0; i < LONG_CACHE.length; i++) {
	    if (LONG_CACHE[i] > LONG_CACHE_MAX) {
		break;
	    }
	    if ((LONG_CACHE[i] >= range[0]) && (LONG_CACHE[i] <= range[1])) {
		count++;
	    }
	}
	if (range[1] > LONG_CACHE_MAX) {
	    long min = Math.max(LONG_CACHE_MAX + 1, range[0]);
	    count += getResultSlow(new long[] { min, range[1] });
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

    private static long LONG_CACHE_MAX = 200000000000000L;
    private static long[] LONG_CACHE = {
	1L,
	4L,
	9L,
	121L,
	484L,
	10201L,
	12321L,
	14641L,
	40804L,
	44944L,
	1002001L,
	1234321L,
	4008004L,
	100020001L,
	102030201L,
	104060401L,
	121242121L,
	123454321L,
	125686521L,
	400080004L,
	404090404L,
	10000200001L,
	10221412201L,
	12102420121L,
	12345654321L,
	40000800004L,
	1000002000001L,
	1002003002001L,
	1004006004001L,
	1020304030201L,
	1022325232201L,
	1024348434201L,
	1210024200121L,
	1212225222121L,
	1214428244121L,
	1232346432321L,
	1234567654321L,
	4000008000004L,
	4004009004004L,
	100000020000001L,
	100220141022001L,
	102012040210201L,
	102234363432201L,
	121000242000121L,
	121242363242121L,
	123212464212321L,
	123456787654321L
    };
}
