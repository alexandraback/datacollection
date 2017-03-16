import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class C_RecycledNumbers {
	static int a;
	static int b;
	static HashSet<String> set;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("Cin.txt"));
		PrintWriter writer = new PrintWriter(new File("Cout.txt"));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			int count = 0;
			set = new HashSet<String>();
			for (int j = a; j <= b; j++) {
				count += get(j);
			}
			writer.println("Case #" + i + ": " + count / 2);
			
		}
		
		writer.close();
	}

	private static int get(int j) {
		String s = j + "";
		int n = s.length();
		int count = 0;
		HashSet<Integer> set1 = new HashSet<Integer>();
		for (int i = 0; i < n - 1; i++) {
			String ss = s.substring(1) + s.charAt(0) + "";
			s = ss;
			int x = Integer.parseInt(ss);

			if (x >= a && x <= b && s.charAt(0) != '0' && !set1.contains(x)) {
				if (j != x) {
					set1.add(x);
					count++;
				}
			}
		}
		return count;
	}
}
