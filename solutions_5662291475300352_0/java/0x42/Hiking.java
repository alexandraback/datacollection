import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Hiking {

	public static void main(String[] args) throws Exception {

		Hiking object = new Hiking();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();

		for (int tc = 1; tc <= testCases; tc++) {

			int N = scanner.nextInt();

			List<Hiker> hikers = new ArrayList<>();

			for (int i = 0; i < N; i++) {
				double di = scanner.nextDouble();
				int ni = scanner.nextInt();
				double mi = scanner.nextDouble();

				for (int z = 0; z < ni; z++) {
					double start = di;
					double speed = mi + z;

					hikers.add(new Hiker(start, speed));
				}
			}

			int result = object.solve(hikers);

			wr.write("Case #" + tc + ": " + result + "\r\n");
		}

		scanner.close();
		wr.close();
	}

	private int solve(List<Hiker> hikers) {
		if (hikers.size() < 2)
			return 0;

		Hiker fasterHiker = hikers.get(0);
		Hiker slowerHiker = hikers.get(1);

		if (Math.abs(fasterHiker.speed - slowerHiker.speed) < 1e-10) {
			return 0;
		}

		int option1 = 2;

		if (fasterHiker.speed > slowerHiker.speed) {
			Hiker temp = fasterHiker;
			fasterHiker = slowerHiker;
			slowerHiker = temp;
		}

		double SlowFinishPosition = 360.0;

		if (fasterHiker.start > slowerHiker.start || (Math.abs(fasterHiker.start - slowerHiker.start) < 1e-10)) {
			option1 = 1;
			slowerHiker.start += 360.0;
			SlowFinishPosition = 720.0;
		}

		double tReach = (slowerHiker.start - fasterHiker.start) / (360.0 / fasterHiker.speed - 360.0 / slowerHiker.speed);
		double tReach2 = 360.0 / (360.0 / fasterHiker.speed - 360.0 / slowerHiker.speed);

		//double fastFinish = (360.0 - fasterHiker.start) / (360.0 / fasterHiker.speed);
		double slowFinish = (SlowFinishPosition - slowerHiker.start) / (360.0 / slowerHiker.speed);

		
		double req = tReach;
		if (option1 == 2)
			req += tReach2;
		
		if (req < slowFinish || Math.abs(req - slowFinish) < 1e-10) {

			return 1;
		}

		return 0;
	}

}

class Hiker {
	public double start, speed;

	public Hiker(double start, double speed) {
		this.start = start;
		this.speed = speed;
	}

}