import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File("A.in")));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("A.out"))));

			int T = Integer.parseInt(br.readLine());
			for (int i = 0; i < T; i++) {
				String[] param = br.readLine().split(" ");
				long r = Long.parseLong(param[0])+1;
				long t = Long.parseLong(param[1]);
				pw.println("Case #"+(i+1)+": "+analyze(r, t));
			}
			
			pw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}
	
	private static long analyze(long r, long t) {
		double a = 2.0;
		double b = 2.0*r+1.0;
		double c = 2.0*r-1.0-t;
		double x = (-b+Math.sqrt(b*b-4*a*c))/(2.0*a);
		long n = (long)Math.max(1.0, (Math.floor(x) - 100.0));
		while (2*n*n+(2*r+1)*n+2*r-1 <= t) n++;
		return n;
	}
}
