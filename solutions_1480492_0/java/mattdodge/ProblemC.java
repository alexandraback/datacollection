package round1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class ProblemC {

	public ProblemC() {
		try {
			FileReader fr = new FileReader("C-small.in");
			BufferedReader br = new BufferedReader(fr);
			
			FileWriter fw = new FileWriter("C-small.out");
			BufferedWriter bw = new BufferedWriter(fw);
			
			int numCases = Integer.parseInt(br.readLine());
			System.out.println(numCases);
			String line = br.readLine();
			int caseNum = 1;
			while(line != null) {
				
				int numCars = Integer.parseInt(line);
				
				ArrayList<Car> cars = new ArrayList<Car>();
				
				for (int i=0; i<numCars; i++) {
					Car c = new Car();
					String[] dets = br.readLine().split(" ");
					
					c.leftLane = dets[0].equals("L");
					c.speed = Integer.parseInt(dets[1]);
					c.pos = Double.parseDouble(dets[2]);
					
					cars.add(c);
				}
				
				String outStr = "";
				
				double maxColTime = manipulateCars(cars, 1);
				
				if (maxColTime == -1) {
					outStr = "Possible";
				} else {
					DecimalFormat df = new DecimalFormat("#.#");
					outStr = df.format(maxColTime);
				}
				
				String output = "Case #"+caseNum + ": "+outStr;
				
				System.out.println(output);
				
				bw.append(output);
				if (caseNum != numCases)
					bw.newLine();
				
				line = br.readLine();
				caseNum++;
			}
			
			bw.flush();
			bw.close();
			br.close();
			
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	private double manipulateCars(ArrayList<Car> cars, int level) {
		if (level > cars.size()) {
			return 0; // call it a collision now
		}
		
		if (indefinite((ArrayList<Car>) (cars.clone()))) {
//			System.out.println("INDEFINITE DETECTED:" + cars.toString());
			return -1;
		}
		
		double maxCollisionTime = getNextCollisionTime(cars);
//		System.out.println("starting out with " + maxCollisionTime);
		for (Car c : cars) {
			if (canSwitch(c, cars)) {
//				System.out.println("switching "+c.toString());
				ArrayList<Car> newCars = new ArrayList<Car>(cars);
				newCars.remove(c);
				c.leftLane = !c.leftLane;
				newCars.add(c);
				
				double newCollisionTime = manipulateCars(newCars, level + 1);
//				System.out.println("and now we have "+newCollisionTime);
				if (newCollisionTime == -1) {
					return -1;
				}
				
				maxCollisionTime = Math.max(maxCollisionTime, newCollisionTime);
			}
		}
		
		if (maxCollisionTime == getNextCollisionTime(cars)) {
			ArrayList<Car> newCars = new ArrayList<Car>();
			for (Car c : cars) {
				c.pos += c.speed * maxCollisionTime;
				newCars.add(c);
			}
			
			double newCollisionTime = manipulateCars(newCars, level + 1);
//			System.out.println("and now we have "+newCollisionTime);
			if (newCollisionTime == -1) {
				return -1;
			}
			
			maxCollisionTime = Math.max(maxCollisionTime, newCollisionTime);
		}
		return maxCollisionTime;
	}
	
	private boolean canSwitch(Car car, ArrayList<Car> cars) {
		for (Car c : cars) {
			if (c.leftLane == car.leftLane) {
				continue;
			}
			
			if (car.pos <= c.pos + 5 && car.pos >= c.pos ||
				car.pos + 5 >= c.pos && car.pos + 5 <= c.pos + 5) {
				return false;
			}
		}
		return true;
	}
	
	private double getNextCollisionTime(ArrayList<Car> cars) {
		ArrayList<CarCollision> collisions = new ArrayList<CarCollision>();
		
		ArrayList<Car> cars1 = new ArrayList<Car>(cars);
		ArrayList<Car> cars2 = new ArrayList<Car>(cars);
		
		for (Car car1 : cars1) {
			for(Car car2 : cars2) {
				if (car1 == car2 || car1.leftLane != car2.leftLane) {
					// same car or different lane
					continue;
				}
				
				CarCollision col = new CarCollision();
				
				if (car1.pos < car2.pos) {
					col.car1 = car1;
					col.car2 = car2;
				} else {
					col.car1 = car2;
					col.car2 = car1;
				}
				
//				System.out.println("colliding "+col.car1+" and "+col.car2);
				col.timeToCollide = (col.car1.pos - col.car2.pos + 5.0) / (col.car2.speed - col.car1.speed);
//				System.out.println("and its happening in "+col.timeToCollide);
				if (col.timeToCollide > 0) {
					collisions.add(col);
				}
			}
		}
		
		Collections.sort(collisions, new CollideTimeComparator());
//		System.out.println(collisions);
		if (collisions.size() == 0) {
			return 0;
		}
		
		return collisions.get(0).timeToCollide;
	}
	
	private boolean indefinite(ArrayList<Car> cars) {
		int leftLaneSpeed = Integer.MAX_VALUE, rightLaneSpeed = Integer.MAX_VALUE;
		
		Collections.sort(cars, new CarPosComparator());
		
//		System.out.println(cars);
		
		for (Car c : cars) {
			if (c.leftLane && c.speed > leftLaneSpeed) {
				// car behind is going faster
				return false;
			} else if (!c.leftLane && c.speed > rightLaneSpeed) {
				return false;
			}
			
			if (c.leftLane) {
				leftLaneSpeed = c.speed;
			} else {
				rightLaneSpeed = c.speed;
			}
		}
		
		return true;
	}
	
	class Car {
		int speed;
		double pos;
		boolean leftLane;
		
		public String toString() {
			return "<Car in " + (leftLane ? "left" : "right") + " lane at "+pos+" going "+speed+">";
		}
		
		public boolean equals(Object o) {
			return this.equals((Car) o);
		}
		
		public boolean equals(Car c) {
			return c.speed == this.speed && c.pos == this.pos && c.leftLane == this.leftLane;
		}
	}
	
	class CarPosComparator implements Comparator<Car> {

		// cars farthest away first
		public int compare(Car c1, Car c2) {
			if (c2.pos > c1.pos) {
				return 1;
			} else if (c2.pos < c1.pos) {
				return -1;
			}
			return 0;
		}
	}
	
	class CarCollision {
		Car car1, car2;
		// assume car1 is behind always
		double timeToCollide;
	}
	
	class CollideTimeComparator implements Comparator<CarCollision> {

		// most imminent collision first
		public int compare(CarCollision c1, CarCollision c2) {
			if (c2.timeToCollide > c1.timeToCollide) {
				return -1;
			} else if (c2.timeToCollide < c1.timeToCollide) {
				return 1;
			}
			return 0;
		}
	}
	
	public static void main(String[] args) {
		new ProblemC();
	}

}
