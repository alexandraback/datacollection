package Y2014.Round1C;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {
    private static final String fwin = "Fegla Won";
    private static final String newLine = System.getProperty("line.separator");
    int T;
    int copy;
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
	A f = new A();
	f.do1();
	long a = System.currentTimeMillis();
	System.out.println(a - b);

    }

    private void do1() throws IOException {
	Scanner sc = new Scanner(new File("E:\\A-small-attempt1.in"));
	// Scanner sc = new Scanner(System.in);
	copy = sc.nextInt();
	int N = 1;
	T = copy;
	while (T-- > 0) {
	    String s = sc.next();
	    long p = new Integer(s.split("/")[0]);
	    long q = new Integer(s.split("/")[1]);
	    solve(N, p, q);
	    N++;
	}
	// TODO Auto-generated method stub
	sc.close();
	bw.close();

    }

    private void solve(int N, long p, long q) throws IOException {
	int ans = sol(p, q, 0);

	resultPrint(N, ans == -1 ? "impossible" : ans);
    }

    private int sol(long p, long q, int hierarchy) {
	while (hierarchy < 40 && p < q) {
	    if (q % 2 == 0)
		q = q / 2;
	    else
		p = p * 2;
	    hierarchy++;
	}
	if (hierarchy == 40)
	    return -1;
	else if (p == q)
	    return hierarchy;
	else {
	    int ans = hierarchy;
	    if (sol(p - q, q, hierarchy) != -1)
		return ans;
	    else
		return -1;
	}
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
