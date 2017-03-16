import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class B {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		new B().run();
	}

	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		for (int t = 1; t <= tc; t++) {
			double c = Double.parseDouble(sc.next());
			double f = Double.parseDouble(sc.next());
			double x = Double.parseDouble(sc.next());
			double speed = 2;
			double curTime = 0;
			while (true) {
				double s1 = x;
				double time1 = s1 / speed;
				//get farm:
				double s2 = c;
				double time2 = s2 / speed;
				s2 = x;
				double speed2 = speed + f;
				time2 += s2 / speed2;
				if (time1 > time2) {
					curTime += c / speed;
					speed += f;
				} else {
					curTime += time1;
					break;
				}
			}
			pw.printf(Locale.US, "Case #%d: %.7f\n", t, curTime);
		}
		pw.close();
	}

}
