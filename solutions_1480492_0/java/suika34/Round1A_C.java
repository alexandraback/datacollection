import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;


public class Round1A_C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Round1A_C main = new Round1A_C();
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String line = bf.readLine();
			int T = Integer.parseInt(line);
			for (int testcaseIndex=0; testcaseIndex<T; testcaseIndex++) {
				String aaa = bf.readLine();
				int N = Integer.parseInt(aaa);
				Car[] cars = new Car[N]; 
				for (int i=0; i<N; i++) {
					String testCase = bf.readLine();
					String[] array = testCase.split(" ");
					char l = array[0].charAt(0);
					int s = Integer.parseInt(array[1]);
					int p = Integer.parseInt(array[2]);
					cars[i] = new Car(l, s, p);
				}
						
				double out = main.solve(N, cars);
				if (out >= 0.0) {
					System.out.print("Case #"+(testcaseIndex+1)+": ");
					System.out.println(out);
				} else {
					System.out.println("Case #"+(testcaseIndex+1)+": Possible");
				}
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public double solve(int N, Car[] cars) {
		double ret = 0.0;
		while(true) {
			//System.out.println(Arrays.toString(cars));
			double time = -1;
			int back = -1;
			int front = -1;
			for (int i=0; i<N; i++) {
				for (int j=0; j<N; j++) {
					if (cars[i].speed > cars[j].speed && cars[i].pos < cars[j].pos && cars[i].lane == cars[j].lane) {
						double temp = (double)(cars[j].pos - cars[i].pos - 5)/(cars[i].speed - cars[j].speed);
						//System.out.println(temp);
						if (time > temp || time < 0) {
							time = temp;
							back = i;
							front = j;
						}
					}
					
				}
			}
			//System.out.println(time);
			if (time <= 0) {
				return -1;
			}
			for (int i=0; i<N; i++) {
				cars[i].pos += cars[i].speed * time;
			}
			ret += time;
			
			for (int i=0; i<N; i++) {
				if (i != back) {
					if (cars[i].lane != cars[back].lane) {
						if (cars[back].pos < cars[i].pos + 5 && cars[i].pos < cars[back].pos + 5) {
							return ret;
						}
					}
				}
			}
			if (cars[back].lane == 'L') {
				cars[back].lane = 'R';
			} else {
				cars[back].lane = 'L';
			}
		}

	}
	
	static class Car {
		char lane;
		int speed;
		int pos;
		
		public Car(char l, int s, int p) {
			lane = l;
			speed = s;
			pos = p;
		}
		@Override
		public String toString() {
			return ""+lane+" "+speed+" "+pos;
		}
	}

}
