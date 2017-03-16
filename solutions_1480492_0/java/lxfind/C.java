import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;


public class C {
	static String path = "D:\\Personal\\Dropbox\\Programming\\Google CodeJam 2012\\Round1A\\test\\";
	static String inputfilename = "C-small-attempt0.in";
	static BufferedReader reader;
	static BufferedWriter writer;
	static double eps = 0.0000001;
	
	static int nextInt() throws Exception {
		return Integer.parseInt(reader.readLine());
	}
	
	static String nextLine() throws Exception {
		return reader.readLine();
	}
	
	static void print(String line) throws Exception {
		writer.write(line);
	}
	
	static void println(String line) throws Exception {
		print(line);
		writer.newLine();
	}
	
	public static void main(String args[]) throws Exception {
		reader = new BufferedReader(new FileReader(path + inputfilename));
		writer = new BufferedWriter(new FileWriter(path + inputfilename + ".out"));
		solve();
		reader.close();
		writer.close();
	}
	
	static boolean isinf(ArrayList<Car> cars) {
		int i;
		Collections.sort(cars);
		for (i=0;i<cars.size()-1;i++)
			if (cars.get(i).s>cars.get(i+1).s)
				return false;
		return true;
	}
	
	static double getminHitTime(ArrayList<Car> cars) {
		double min = Double.MAX_VALUE;
		int i;
		for (i=0;i<cars.size()-1;i++)
			if (cars.get(i).s>cars.get(i+1).s)
				min = Math.min(min, (cars.get(i+1).p - cars.get(i).p - 5)/(cars.get(i).s - cars.get(i+1).s));
		return min;
	}
	
	static void move(ArrayList<Car> cars, double time) {
		int i;
		for (i=0;i<cars.size();i++) {
			cars.get(i).p += cars.get(i).s*time;
		}
	}
	
	static boolean dangeTouch(Car c1, Car c2) {
		if (c2.p > c1.p + 5 + eps) {			
			return false;
		} else if (c2.p - c1.p - 5 < eps && c2.s < c1.s) {
			return true;
		} else {
			return false;
		}
	}
	
	static boolean canputin(Car c, ArrayList<Car> cars) {
		int i = 0;
		int s = cars.size();
		if (s==0) {
			cars.add(c);
			return true;
		}
		while (i<s && c.p+eps>cars.get(i).p+5) i++;
		if (i==s) {
			Car last = cars.get(s-1);
			if (dangeTouch(last,c)) {
				return false;
			} else {
				cars.add(c);
				return true;
			}
		}
		Car t = cars.get(i);
		if (c.p>=t.p && c.p + eps < t.p+5)
			return false;
		if (t.p>=c.p && t.p + eps < c.p+5)
			return false;
		if (dangeTouch(c,t)) {
			return false;
		}
		if (i>0 && dangeTouch(cars.get(i-1),c))
			return false;
		cars.add(i, c);
		return true;
	}
	
	static boolean isMovable(ArrayList<Car> left, ArrayList<Car> right) {
		int i;
		for (i=0;i<left.size()-1;i++) {
			Car c1 = left.get(i);
			Car c2 = left.get(i+1);
			if (c2.p - c1.p - 5 < eps) {
				if (canputin(c1, right)) {
					left.remove(c1);
				} else if (canputin(c2, right)) {
					left.remove(c2);
				} else
					return false;
			}
		}
		return true;
	}
	
	static void solve() throws Exception {
		int t = nextInt();
		int i,j;		
		for (i = 1; i <= t; i++) {
			int n = nextInt();
			ArrayList<Car> left = new ArrayList<Car>();
			ArrayList<Car> right = new ArrayList<Car>();
			for (j=0;j<n;j++) {
				String line[] = nextLine().split(" ");
				Car c = new Car(line[0].charAt(0),Double.parseDouble(line[1]),Double.parseDouble(line[2]));
				if (c.left)
					left.add(c);
				else
					right.add(c);
			}
			boolean inf;
			double total = 0;
			while (true) {
				inf = true;
				if (isinf(left) && isinf(right)) {
					break;
				}
				inf = false;
				double min = Math.min(getminHitTime(left), getminHitTime(right));
				if (min<eps) {
					if (!isMovable(left, right) || !isMovable(right, left))
						break;
				} else {
					move(left, min);
					move(right, min);
					total += min;
				}
			}
			if (inf) {
				println("Case #"+i+": Possible");
			} else {
				println("Case #"+i+": "+total);
			}
		}		
	}
}

class Car implements Comparable<Car> {
	boolean left;
	double p, s;
	public Car(char lr, double s, double p) {
		if (lr=='L')
			this.left = true;
		else
			this.left = false;
		this.p = p;
		this.s = s;
	}
	public int compareTo(Car c) {
		if (this.p<c.p)
			return -1;
		else
			return 1;
	}
	
	public String toString() {
		return (left?"L":"R")+" "+this.p + " " + this.s;
	}
}