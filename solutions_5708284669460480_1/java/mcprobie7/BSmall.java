import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class BSmall {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new File("outputBLarge.txt"));
		int t = in.nextInt();
		for (int testn = 1; testn <= t; testn++) {
			int K = in.nextInt();
			int L = in.nextInt();
			int S = in.nextInt();
			String KB = in.next();
			System.out.println(KB);
			int [] C = new int[26];
			for (int i = 0; i < KB.length(); i++)
			{
				char c = KB.charAt(i);
				if ('A' <= c && c <= 'Z') C[c - 'A']++;
			}
			String Target = in.next();
			System.out.println(Target);
			int shift;
			for (shift = 1; shift < Target.length(); shift++)
			{
				boolean w = false;
				for (int i = shift; i < Target.length(); i++)
					if (Target.charAt(i) != Target.charAt(i - shift))
					{
						w = true;
						break;
					}
				if (!w) break;
			}
			
			
			int MAX = (S - L + 1) / shift;
			if ((S - L + 1) % shift != 0) MAX++;
			System.out.println(MAX);
			double PR = 1.0;
		//	System.out.println(Target);
			for (int i = 0; i < Target.length(); i++)
				PR *= ((double) C[Target.charAt(i) - 'A']) / K;
			double ans = 0.0;
			System.out.println(PR);
			if (PR > 0)
			{
				ans = MAX - PR * (S - L + 1);
			}
			
			out.print("Case #" + testn + ": ");
			out.printf("%7f", ans);
			out.println("");
			
		}
		in.close();
		out.close();
	}
	
}
