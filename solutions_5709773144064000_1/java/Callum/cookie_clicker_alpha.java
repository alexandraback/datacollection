import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class cookie_clicker_alpha {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
		PrintWriter pw = new PrintWriter("B-large.out", "UTF-8");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 0; test < t; test++) {
			pw.print("Case #" + (test + 1) + ": ");
			StringTokenizer st = new StringTokenizer(br.readLine());
			double c = Double.parseDouble(st.nextToken());
			double f = Double.parseDouble(st.nextToken());
			double x = Double.parseDouble(st.nextToken());
			
			double previous = Double.POSITIVE_INFINITY;
			int n = 0;
			while (true) {
				double temp = seconds(c, f, x, n);
				if (temp < previous) {
					previous = temp; 
					n++;
				} else {
					break;
				}
			}
			pw.println(previous);
		}
		
		br.close();
		pw.close();
	}
	
	public static double seconds(double c, double f, double x, int n) {
		double seconds = 0;
		double cps = 2;
		for (int i = 0; i < n; i++) {
			seconds += c / cps;
			cps += f;
		}
		seconds += x / cps;
		return seconds;
	}
}