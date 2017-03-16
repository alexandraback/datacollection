import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("B.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("B.out"))));
		
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String[] str = br.readLine().split(" ");
			double C = Double.parseDouble(str[0]);
			double F = Double.parseDouble(str[1]);
			double X = Double.parseDouble(str[2]);
			pw.println("Case #"+(i+1)+": "+analyze(C, F, X));
		}

		pw.close();
		br.close();
	}
	
	private static double analyze(double C, double F, double X) {
		double speed = 2.0;
		double pasttime = 0.0;
		double time1 = X / speed;
		double time2 = C / speed + X / (speed+F);
		double besttime = time1;
		while (time1 > time2) {
			besttime = pasttime + time2;
			pasttime = pasttime + (C / speed);
			speed += F;
			time1 = X / speed;
			time2 = C / speed + X / (speed+F);
		}
		return besttime;
	}
}
