import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TaskA {

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	void run() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		String s1 = br.readLine();
		st = new StringTokenizer(s1);
		int t = Integer.parseInt(st.nextToken());
		for (int i1 = 1; i1 <= t; i1++) {
			out.print("Case #" + i1 + ": ");
			s1 = br.readLine();
			st = new StringTokenizer(s1);
			long r = Integer.parseInt(st.nextToken());
			long x = Integer.parseInt(st.nextToken());
			long ans = 0;
			while (x>=2*r+1){
				x = x - 2*r -1;
				ans++;
				r = r+2;
			}
			out.println(ans);
			

		}

		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new TaskA().run();
	}

}