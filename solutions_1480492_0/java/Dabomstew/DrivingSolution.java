import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class DrivingSolution {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String inFilename = "C-small-attempt0.in";
		String outFilename = inFilename.substring(0, inFilename.length() - 3)
				+ ".out";
		try {
			Scanner sc = new Scanner(new File(inFilename));
			PrintStream ps = new PrintStream(new FileOutputStream(outFilename));
			int testCases = Integer.parseInt(sc.nextLine());
			for (int i = 1; i <= testCases; i++) {
				// logic
				if (i >= 1) {
					ps.println();
				}
				int cars = Integer.parseInt(sc.nextLine());
				List<Car> leftLane = new ArrayList<Car>();
				List<Car> rightLane = new ArrayList<Car>();
				for (int car = 0; car < cars; car++) {
					String data = sc.nextLine();
					String[] parts = data.split(" ");
					double speed = Double.parseDouble(parts[1]);
					double position = Double.parseDouble(parts[2]);
					Car c = new Car();
					c.speed = speed;
					c.position = position;
					if (parts[0].equals("L")) {
						leftLane.add(c);
					} else {
						rightLane.add(c);
					}
				}
				double totalTime = 0;
				boolean canGoUnlimited = false;
				while (true) {
					boolean collisionFound = false;
					double collisionTime = 99999999;
					// Collisions, left lane
					for (int f = 0; f < leftLane.size(); f++) {
						Car first = leftLane.get(f);
						for (int s = 0; s < leftLane.size(); s++) {
							if (s == f) {
								continue;
							}
							// they can collide if s is behind f and going
							// faster than it
							Car second = leftLane.get(s);
							if (second.speed > first.speed
									&& second.position < first.position) {
								// does it
								collisionFound = true;
								double thisCollision = (first.position
										- second.position - 5)
										/ (second.speed - first.speed);
								if (thisCollision < collisionTime) {
									collisionTime = thisCollision;
								}
							}
						}
					}
					for (int f = 0; f < rightLane.size(); f++) {
						Car first = rightLane.get(f);
						for (int s = 0; s < rightLane.size(); s++) {
							if (s == f) {
								continue;
							}
							// they can collide if s is behind f and going
							// faster than it
							Car second = rightLane.get(s);
							if (second.speed > first.speed
									&& second.position < first.position) {
								// does it
								collisionFound = true;
								double thisCollision = (first.position
										- second.position - 5)
										/ (second.speed - first.speed);
								if (thisCollision < collisionTime) {
									collisionTime = thisCollision;
								}
							}
						}
					}
					if (!collisionFound) {
						canGoUnlimited = true;
						break;
					}
					totalTime += collisionTime;
					// Advance the cars
					for (Car c : leftLane) {
						c.position += collisionTime * c.speed;
					}
					for (Car c : rightLane) {
						c.position += collisionTime * c.speed;
					}

					// Find which cars are touching
					List<Collision> colls = new ArrayList<Collision>();
					for (int f = 0; f < leftLane.size(); f++) {
						Car first = leftLane.get(f);
						for (int s = f + 1; s < leftLane.size(); s++) {
							Car second = leftLane.get(s);
							if (first.position < second.position
									&& first.speed > second.speed) {
								double posDiff = second.position
										- first.position - 5;
								if (Math.abs(posDiff) < 0.00001) {
									// collision
									colls.add(new Collision('L', first, second));
								}
							} else if (first.position > second.position
									&& first.speed < second.speed) {
								double posDiff = first.position
										- second.position - 5;
								if (Math.abs(posDiff) < 0.00001) {
									// collision
									colls.add(new Collision('L', first, second));
								}
							}
						}
					}
					for (int f = 0; f < rightLane.size(); f++) {
						Car first = rightLane.get(f);
						for (int s = f + 1; s < rightLane.size(); s++) {
							Car second = rightLane.get(s);
							if (first.position < second.position
									&& first.speed > second.speed) {
								double posDiff = second.position
										- first.position - 5;
								if (Math.abs(posDiff) < 0.00001) {
									// collision
									colls.add(new Collision('R', first, second));
								}
							} else if (first.position > second.position
									&& first.speed < second.speed) {
								double posDiff = first.position
										- second.position - 5;
								if (Math.abs(posDiff) < 0.00001) {
									// collision
									colls.add(new Collision('R', first, second));
								}
							}
						}
					}
					Set<Car> toMoveToLeft = new HashSet<Car>();
					Set<Car> toMoveToRight = new HashSet<Car>();
					boolean notResolved = false;
					for (Collision c : colls) {
						if (c.lane == 'L') {
							if (canMoveTo(rightLane, c.first)) {
								toMoveToRight.add(c.first);
							} else if (canMoveTo(rightLane, c.second)) {
								toMoveToRight.add(c.second);
							} else {
								notResolved = true;
								break;
							}
						} else if (c.lane == 'R') {
							if (canMoveTo(leftLane, c.first)) {
								toMoveToLeft.add(c.first);
							} else if (canMoveTo(leftLane, c.second)) {
								toMoveToLeft.add(c.second);
							} else {
								notResolved = true;
								break;
							}
						}
					}
					if (notResolved) {
						break;
					}
					leftLane.removeAll(toMoveToRight);
					rightLane.removeAll(toMoveToLeft);
					leftLane.addAll(toMoveToLeft);
					rightLane.addAll(toMoveToRight);
				}
				if (canGoUnlimited) {
					System.out.println("Case #" + i + ": Possible");
					ps.print("Case #" + i + ": Possible");
				} else {
					String ttPrint = "" + totalTime;
					if ((double) ((int) totalTime) == totalTime) {
						ttPrint = "" + ((int) totalTime);
					}
					System.out.println("Case #" + i + ": " + ttPrint);
					ps.print("Case #" + i + ": " + ttPrint);
				}
			}
			sc.close();
			ps.close();
		} catch (Exception ex) {
			ex.printStackTrace();
		}

	}

	public static boolean canMoveTo(List<Car> lane, Car moving) {
		boolean canMove = true;
		for (Car c : lane) {
			if (Math.abs(c.position - moving.position) < 5.00001) {
				canMove = false;
				break;
			}
		}
		return canMove;
	}

	public static class Car {
		public double position;
		public double speed;
		private int id;
		private static int IDCOUNTER = 0;

		public Car() {
			id = ++IDCOUNTER;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + id;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Car other = (Car) obj;
			if (id != other.id)
				return false;
			return true;
		}
	}

	public static class Collision {
		public char lane;
		public Car first;
		public Car second;

		public Collision(char lane, Car one, Car two) {
			this.lane = lane;
			this.first = one;
			this.second = two;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((first == null) ? 0 : first.hashCode());
			result = prime * result
					+ ((second == null) ? 0 : second.hashCode());
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Collision other = (Collision) obj;
			if (first == null) {
				if (other.first != null)
					return false;
			} else if (!first.equals(other.first))
				return false;
			if (second == null) {
				if (other.second != null)
					return false;
			} else if (!second.equals(other.second))
				return false;
			return true;
		}
	}

}
