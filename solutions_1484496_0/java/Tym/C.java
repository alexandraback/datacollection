package round1B;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	String solve(Scanner in) throws IOException {
		int n = in.nextInt();
		int[] s = new int[n];
		for(int i = 0; i < n; i++)
			s[i] = in.nextInt();
		
		int[] sum = new int[1<<n];
		for(int i = 0; i < n; i++)
			sum[1<<i] = s[i];
		for(int i = 0; i < 1<<n; i++)
			sum[i] = sum[i&~(i-1)] + sum[i&(i-1)];
		
		int[] possible = new int[4000000];
		Arrays.fill(possible, -1);
		for(int i = 1; i < 1<<n; i++)
			if(possible[sum[i]] != -1) {
				String ans = "";
				for(int j = 0; j < n; j++)
					if((possible[sum[i]] & 1<<j) != 0)
						ans += s[j] + " ";
				ans = ans.trim() + "\n";
				for(int j = 0; j < n; j++)
					if((i & 1<<j) != 0)
						ans += s[j] + " ";
				return ans.trim() + "\n";
			}
			else
				possible[sum[i]] = i;
		
		return "Impossible";
	}
	
/*************************************************************************************************/
	
	public static void main(String[] args) throws IOException {
		for(File f : new File(".").listFiles())
			if(f.isFile() && f.getName().startsWith(C.class.getSimpleName() + "-")
					      && f.getName().endsWith(".in")) {
				
				Scanner in = new Scanner(new FileReader(f));
				PrintWriter out = new PrintWriter(new FileWriter(f.getName() + ".out"));
				
				int cases = in.nextInt(); in.nextLine();
				for(int caseno = 1; caseno <= cases; caseno++)
					out.printf("Case #%d:%n%s", caseno, new C().solve(in));
				
				out.close();
			}
	}
}
