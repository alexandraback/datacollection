import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	int solve(int N, int[] shyness)
	{
		int ans = 0;
		int standUppers = 0;
		for( int i=0; i<shyness.length; i++) {
			if (standUppers < i) {
				ans += i - standUppers;
				standUppers = i;
			}
			standUppers += shyness[i];
		}
		return ans;
	}

	public static void main(String[] args) {
		try {
			File fin = new File("A-small-attempt1.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("aout.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				int N = sc.nextInt();
				int[] s = new int[N+1];
				String str = sc.next();
				for (int i=0; i<N+1; i++) {
					s[i] = str.charAt(i)-'0';
				}
				A a = new A();
				pw.write("Case #" + cn + ": " + a.solve(N, s) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
