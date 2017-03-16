import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Fractiles {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("D-small.in"));
		PrintWriter pw = new PrintWriter("D-small.out");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 1; test <= t; test++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int k = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());

			pw.printf("Case #%d: ", test);
			
			for (int i = 1; i <= s; i++) {
				pw.print(i + " ");
			}
			pw.println();
		}
		
		br.close();
		pw.close();
	}
}
