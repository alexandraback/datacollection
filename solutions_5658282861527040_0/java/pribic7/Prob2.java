package Y2014.Round1B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Prob2 {

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
	Prob2 f = new Prob2();
	f.do1();
	long a = System.currentTimeMillis();
	System.out.println(a - b);

    }

    private void do1() throws IOException {
	Scanner sc = new Scanner(new File("E:\\B-small-attempt0.in"));
	copy = sc.nextInt();
	int N = 1;
	T = copy;
	while (T-- > 0) {
	    int a = sc.nextInt();
	    int b = sc.nextInt();
	    int k = sc.nextInt();
	    solve(N, a, b, k);
	    N++;
	}
	// TODO Auto-generated method stub
	sc.close();
	bw.close();

    }

    private void solve(int N, int a, int b, int k) throws IOException {
	int ans = 0;
	for (int i = 0; i < a; i++) {
	    for (int j = 0; j < b; j++) {
		if ((i & j) < k) {
		    ans++;
		    // System.out.println(i + " " + j);
		}
	    }
	}
	resultPrint(N, ans);
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
