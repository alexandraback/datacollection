package Round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class Q3 {
	public static void main(String args[]) throws FileNotFoundException {
		Q3 obj = new Q3();
		obj.solve();
	}
	
	private void solve() throws FileNotFoundException {
		File input = new File("C:\\Users\\rbathla\\Desktop\\input.txt");
		File output = new File("C:\\Users\\rbathla\\Desktop\\output.txt");
		Scanner in = new Scanner(input);
		PrintWriter out = new PrintWriter(output);
		
		int t = in.nextInt();
		int caseNumber = 1;
		
		while ((t--) != 0) {
			out.print("Case #" + caseNumber + ": ");
			++caseNumber;
			int n = in.nextInt();
			String a[] = new String[n];
			String b[] = new String[n];
			
			HashMap<String, Integer> mapA = new HashMap<String, Integer>();
			HashMap<String, Integer> mapB = new HashMap<String, Integer>();
			
			for (int i = 0; i < n; i++) {
				a[i] = in.next();
				b[i] = in.next();
				
				/*if (mapA.containsKey(a[i])) {
					int x = mapA.get(a[i]);
					++x;
					mapA.put(a[i], x);
				} else {
					mapA.put(a[i], 1);
				}
				
				if (mapB.containsKey(b[i])) {
					int x = mapB.get(b[i]);
					++x;
					mapB.put(b[i], x);
				} else {
					mapB.put(b[i], 1);
				}*/
				
				mapA.put(a[i], 1);
				mapB.put(b[i], 1);
			}
			int sizeA = mapA.size();
			int sizeB = mapB.size();
			
			int ans = (n - sizeA) < (n - sizeB) ? (n - sizeA) : (n - sizeB);
			
			out.println(ans);
			
		}
		in.close();
		out.close();
	}
	
}
