import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;


public class DWTG {

	static void log(String fs, Object... args) {
		System.err.println(String.format(fs, args));
	}

	public static void main(String[] args) throws FileNotFoundException {
		String filename = "src/data/B-small-attempt0.in";
		Scanner sc = 
				new Scanner(
						new FileInputStream(
								new File(filename)));
		PrintWriter pw = 
				new PrintWriter(
						new FileOutputStream(
								new File(filename + ".result")));

		int[] usually = new int[31];
		int[] surprise = new int[31];
		
		for (int a = 0; a <= 10; a++) {
			for (int b = 0; b <= 10; b++) {
				for (int c = 0; c <= 10; c++) {
					int sum = a+b+c;
					int m = Math.max(c, Math.max(a, b));
					if (Math.abs(a-b) <= 1 && Math.abs(b-c) <= 1 && Math.abs(a-c) <= 1) {
						usually[sum] = Math.max(usually[sum], m); 
					} else if (Math.abs(a-b) <= 2 && Math.abs(b-c) <= 2 && Math.abs(a-c) <= 2) {
						surprise[sum] = Math.max(surprise[sum], m); 
					}
				}
			}
		}
		
		int T = sc.nextInt();
		sc.nextLine();
		for (int task = 1; task <= T; task++) {
			
			int N = sc.nextInt();
			int S = sc.nextInt();
			int p = sc.nextInt();
			
			int count_usually = 0;
			int count_surprise = 0;
			for (int i=0; i<N; i++) {
				int d = sc.nextInt();
				
				if (usually[d] >= p)
					count_usually++;
				else if (surprise[d] >= p)
					count_surprise++;
			}
			
			int result = count_usually + Math.min(S, count_surprise);
			pw.println(String.format("Case #%d: %d", task, result));
			log("Case #%d: %d", task, result);
		}
		pw.close();
	}
}
