import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class Q3RecycledNumbers {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		Scanner scanner = new Scanner(new File("q3.input"));
		
		FileWriter writer = new FileWriter("q3.output");
		
		int cases = scanner.nextInt();
		
		for (int i = 1; i <= cases; i++) {
			
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			
			int n = solve(a, b);
			
			writer.write("Case #" + i + ": " + n + "\n");
		}
		
		writer.close();
	}

	private static int solve(int a, int b) {
		int n = 0;
		
		for (int i = b; i >= a; i--) {
			String strI = String.valueOf(i);
			Set<Integer> mirrorSet = new HashSet<Integer>();
			
			for (int j = 1; j <= strI.length(); j++) {
				String r = strI.substring(j, strI.length()) + strI.substring(0, j);
				int intR = Integer.valueOf(r);
				if (intR < i && intR >= a && !mirrorSet.contains(intR)) {
					mirrorSet.add(intR);
					n++;
				}
			}
		}
		
		return n;
	}
	
}
