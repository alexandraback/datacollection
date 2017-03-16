package Y2014.Round1C;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    private static final String fwin = "Fegla Won";
    private static final String newLine = System.getProperty("line.separator");
    int T;
    int copy;
    static private int MOD = 1000000007;
    BufferedWriter bw;
    {
	try {
	    bw = new BufferedWriter(new FileWriter(new File("E:\\out"
		    + System.currentTimeMillis() + ".t")));
	} catch (IOException e) {
	    // TODO Auto-generated catch block
	    e.printStackTrace();
	}
    }

    public static void main(String[] args) throws IOException {
	long b = System.currentTimeMillis();
	B f = new B();
	f.do1();
	long a = System.currentTimeMillis();
	System.out.println(a - b);

    }

    private void do1() throws IOException {
	Scanner sc = new Scanner(new File("E:\\B-small-attempt1.in"));
	// Scanner sc = new Scanner(System.in);
	copy = sc.nextInt();
	int N = 1;
	T = copy;
	while (T-- > 0) {
	    int n = sc.nextInt();
	    String[] ss = new String[n];
	    for (int i = 0; i < n; i++)
		ss[i] = sc.next();
	    solve(N, ss);
	    N++;
	}
	// TODO Auto-generated method stub
	sc.close();
	bw.close();

    }

    private void solve(int N, String[] ss) throws IOException {
	int[] freq = freq(ss);
	int[] curFreq = new int[26];
	Arrays.fill(curFreq, 0);
	long ans = 0;
	for (int i = 0; i < ss.length; i++) {
	    ans += find(ss, new int[] { i }, findFreq(curFreq, ss[i]), curFreq,
		    freq);
	    ans = ans % MOD;
	}
	resultPrint(N, ans);
    }

    private long find(String[] ss, int[] cur, int[] cF, int[] curFreq,
	    int[] freq) {
	if (cur.length == ss.length)
	    return 1;
	long ans = 0;
	for (int i = 0; i < ss.length; i++) {
	    if (!Contain(cur, i)) {
		String last = ss[cur[cur.length - 1]];
		if (last.charAt(last.length() - 1) == ss[i].charAt(0)) {
		    ans += find(ss, add(cur, i), findFreq(cF, ss[i]), curFreq,
			    freq);
		    ans = ans % MOD;
		} else {
		    char lastChar = last.charAt(last.length() - 1);
		    if (allCame(cF, freq, ss[i])) {
			ans += find(ss, add(cur, i), findFreq(cF, ss[i]),
				curFreq, freq);
			ans = ans % MOD;
		    } else
			return 0;
		}
	    }
	}
	return ans % MOD;
    }

    private boolean allCame(int[] cF, int[] freq, String string) {
	for (char c : string.toCharArray())
	    if (cF[c - 'a'] != 0)
		return false;
	return true;
    }

    private int[] add(int[] cur, int i) {
	int[] c = new int[cur.length + 1];
	for (int ii = 0; ii < cur.length; ii++)
	    c[ii] = cur[ii];
	c[cur.length] = i;
	return c;
    }

    private boolean Contain(int[] cur, int i) {
	for (int j : cur)
	    if (j == i)
		return true;
	return false;
    }

    private int[] findFreq(int[] curFreq, String string) {
	int[] cc = new int[26];
	for (int i = 0; i < 26; i++)
	    cc[i] = curFreq[i];
	for (char c : string.toCharArray()) {
	    int index = c - 'a';
	    cc[index]++;
	}
	return cc;
    }

    private int[] freq(String[] ss) {
	int[] freq = new int[26];
	Arrays.fill(freq, 0);
	for (String s : ss)
	    for (char c : s.toCharArray())
		freq[c - 'a']++;
	return freq;
    }

    public void resultPrint(int n, Object res) throws IOException {
	System.out.print("Case #" + n + ": " + res + newLine);

	/*
	 * if (n == copy) // for last output ,we don't need newLine.
	 * bw.write("Case #" + n + ": " + res); else
	 */
	bw.write("Case #" + n + ": " + res + newLine);

    }

}
