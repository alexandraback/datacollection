import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class Round1Question3 {
	private static class Car {
		public boolean left;
		public float place, speed;
		public Car(boolean left, float speed, float place) {
			this.left = left;
			this.place = place;
			this.speed = speed;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("r1q3.in")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0;i < T;i++) {
			int N = Integer.parseInt(br.readLine());
			String[] caseArgs = new String[N];
			for (int j = 0;j < N;j++)
			{
				caseArgs[j] = br.readLine();
			}
			doCase(i + 1, caseArgs);
		}
	}
	static float time = 0;
	static void doCase(int caseNum, String[] args) {
		time = 0;
		Car[] cars = new Car[args.length];
		for (int i = 0;i < args.length;i++) {
			String[] ss = args[i].split(" ");
			boolean l = ss[0].equals("L");
			int s = Integer.parseInt(ss[1]);
			int p = Integer.parseInt(ss[2]);
			cars[i] = new Car(l,s,p);
		}
		while (!findCollision(cars) && time != -1);
		if (time == -1) {
			System.out.println("Case #" + caseNum + ": Possible");
		} else
			System.out.println("Case #" + caseNum + ": " + time);
	}
	
	static boolean findCollision(Car[] cars) {
		if (cars.length <= 2) {
			time = -1;
			return false;
		}
		float firstCollision = 0;
		int x = -1, y = -1;
		for (int i = 0;i < cars.length;i++) {
			for (int j = 0;j < cars.length;j++) {
				if (i != j && cars[i].left == cars[j].left && cars[j].speed > cars[i].speed && cars[j].place < cars[i].place) { // If 1 car is in front and slower.
					float collisionTime = (cars[i].place - 5 - cars[j].place) / (cars[j].speed - cars[i].speed);
					if (firstCollision == 0 || collisionTime < firstCollision) {
						firstCollision = collisionTime;
						x = i;y = j;
					}
				}
			}
		}
		if (firstCollision > 0)
			moveCars(cars,firstCollision);
		else {
			time = -1;
			return false;
		}
		time += firstCollision;
		return tryMove(cars);
	}
	
	static void moveCars(Car[] cars, float el) {
		for (int i = 0;i <cars.length;i++) {
			cars[i].place += (el * cars[i].speed);
		}
	}
	
	static boolean colliding(Car c1, Car c2) {
		return c1 != c2 && c1.left == c2.left && Math.abs(c2.place - c1.place) < 5.00005;
	}
	
	static boolean tryMove(Car[] cars) {
		for (int i = 0;i < cars.length;i++) {
			for (int j = 0;j < cars.length;j++) {
				if (i != j && colliding(cars[i],cars[j])) {
					cars[i].left = !cars[i].left;
					for (int k = 0;k < cars.length;k++) {
						if (i != k && j != k && colliding(cars[i],cars[k])) {
							cars[i].left = !cars[i].left;
							cars[j].left = !cars[j].left;
							for (int l = 0;l < cars.length;l++) {
								if (i != l && j != l && colliding(cars[j],cars[l])) {
									cars[j].left = !cars[j].left;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	}
}
