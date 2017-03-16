import java.io.*;

public class ProblemC {

    public static boolean checkPalindrome(long k)
    {
	String s = Long.toString(k);
	int n = s.length();
	for (int i = 0; i < n; ++i) {
	    if (s.charAt(i) != s.charAt(n-i-1)) return false;
	}
	return true;
    }

    public static long countFairSquare(long a, long b)
    {
	long sa = (long) Math.ceil(Math.sqrt(a));
	long sb = (long) Math.floor(Math.sqrt(b));
	long nfs = 0;
	for (long i = sa; i <= sb; ++i) {
	    if (checkPalindrome(i) && checkPalindrome(i*i)) nfs++;
	}
	return nfs;
    }

    public static void main(String[] args)
	throws IOException
    {
	BufferedReader fin = new BufferedReader(new FileReader(args[0]));
	int T = Integer.parseInt(fin.readLine());

	for (int t = 1; t <= T; ++t) {
	    String[] line = fin.readLine().split(" ");
	    long a = Long.parseLong(line[0]);
	    long b = Long.parseLong(line[1]);

	    System.out.print("Case #" + t + ": ");
	    System.out.println(countFairSquare(a, b));
	}
    }


}