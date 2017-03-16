import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Round1A1 {
	public static void main(String[] args) {
		BufferedReader br = null;
		try {
			// FileWriter fstream = new FileWriter("out.txt");
			// BufferedWriter out = new BufferedWriter(fstream);
			String fileName = "A-small-attempt0";
			PrintWriter pw = new PrintWriter(new FileWriter(
					"C:\\Users\\Arun\\Desktop\\jam\\round1A1\\" + fileName
							+ ".out", false));

			br = new BufferedReader(new FileReader(
					"C:\\Users\\Arun\\Desktop\\jam\\round1A1\\" + fileName
							+ ".in"));
			int numOfCases = Integer.parseInt(br.readLine());
			System.out.println(numOfCases);
			for (int i = 0; i < numOfCases; i++) {
				String line = br.readLine();
				String element[] = line.split(" ");

				long r = Long.parseLong(element[0]);
				long total_paint = Long.parseLong(element[1]);
				Painter painter = new Painter(r, total_paint);
				pw.println("Case #" + (i + 1) + ": "+painter.getCircleNumber());

			}

			br.close();
			pw.close();
		} catch (Exception e) {

			e.printStackTrace();
		}
	}
}

class Painter {
	long r;
	long total_paint;

	Painter(long r, long total_paint) {
		this.r = r;
		this.total_paint = total_paint;
	}

	long getCircleNumber() {
		long nowCircleRadius = 0;
		long noOfBlackCircles = 0;
		boolean blackCircle = true;
		long prevCircleRadius = r;
		while (true) {
			if (blackCircle == false) { // white circle
				blackCircle = true;
				prevCircleRadius++;

			} else { // black circle;
				blackCircle = false;
				nowCircleRadius = prevCircleRadius + 1;
				long areaOfPaint = nowCircleRadius * nowCircleRadius- prevCircleRadius * prevCircleRadius;
				total_paint = total_paint - areaOfPaint;
				prevCircleRadius = nowCircleRadius;
				if (total_paint < 0) {
					break;
				} else {
					noOfBlackCircles++;
				}

			}
		}
		return noOfBlackCircles;
	}

}