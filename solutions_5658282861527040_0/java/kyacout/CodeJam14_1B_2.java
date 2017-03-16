import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class CodeJam14_1B_2 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("output"));
		int t = in.nextInt();
		
		for (int tc = 1; tc <= t; tc++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int k = in.nextInt();
			
			int counter = 0;
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; j++)
					if ((i & j) < k)
						counter++;
			out.print("Case #" + tc + ": ");
			out.println(counter);
		}
		in.close();
		out.close();
	}
}
