import java.io.*;
import java.util.List;
import java.util.ArrayList;

public class ProblemC {

    static List<Long> listFairSquare = new ArrayList<Long>();

    public static boolean checkPalindrome(long k)
    {
	String s = Long.toString(k);
	int n = s.length();
	for (int i = 0; i < n; ++i) {
	    if (s.charAt(i) != s.charAt(n-i-1)) return false;
	}
	return true;
    }

    static final long MAX_FS = 10000000;
    public static void enumerateFairSquare()
    {
	for (long i = 0; i <= MAX_FS; ++i) {
	    if (checkPalindrome(i) && checkPalindrome(i*i)) {
		listFairSquare.add(i*i);
	    }
	}
    }
    
    public static int countFairSquare(long a, long b)
    {
	int nfs = 0;
	for (long i : listFairSquare) {
	    if (i >= a && i <= b) nfs++;
	}
	return nfs;
    }

    public static void main(String[] args)
	throws IOException
    {
	BufferedReader fin = new BufferedReader(new FileReader(args[0]));
	int T = Integer.parseInt(fin.readLine());

	enumerateFairSquare();

	for (int t = 1; t <= T; ++t) {
	    String[] line = fin.readLine().split(" ");
	    long a = Long.parseLong(line[0]);
	    long b = Long.parseLong(line[1]);

	    System.out.print("Case #" + t + ": ");
	    System.out.println(countFairSquare(a, b));
	}
    }


}