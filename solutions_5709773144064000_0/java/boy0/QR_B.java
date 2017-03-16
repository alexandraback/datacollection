package boy0;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class QR_B {
	public static void main(String[] args) throws IOException {
		String strLine;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		QR_B me = new QR_B();

		// me.init();

		strLine = br.readLine();
		int T = Integer.parseInt(strLine);
		String[] as;
		double c, f, g;
		double y;
		for (int x = 1; x <= T; x++) {
			strLine = br.readLine();
			as = strLine.split(" ");
			c = Double.parseDouble(as[0]);
			f = Double.parseDouble(as[1]);
			g = Double.parseDouble(as[2]);
			y = me.exec1(c, f, g);
			System.out.println("Case #" + x + ": " + y);
		}
	}

	private double c;
	private double f;
	private double g;
	private HashMap<Integer, Double> cache_time;
	private HashMap<Integer, Double> cache_plant_time;

	public void init() {

	}

	public double exec1(double c_, double f_, double g_) {
		double y = 0;

		c = c_;
		f = f_;
		g = g_;
		int step_size = (int) Math.ceil(g / (f * c));
		cache_time = new HashMap<Integer, Double>(step_size);
		cache_plant_time = new HashMap<Integer, Double>(step_size);
//		System.out.println("* step_size = " + step_size);

		int old_count, l_count, r_count;
		double old_time, l_time, r_time;

		// 초기
		old_count = 0;
		old_time = g / 2;
		l_count = r_count = 0;

		while (true) {
			l_count = old_count - step_size;
			r_count = old_count + step_size;
			// new_time 계산.
			l_time = calc_time(l_count);
			r_time = calc_time(r_count);
//			System.out.println("count=" + old_count + ",\tstep = " + step_size
//					+ ",\tl = " + l_time + "\t,o = " + old_time + ",\tr = "
//					+ r_time);
			if (old_time <= l_time && old_time <= r_time) {
				if (step_size == 1) {
					y = old_time;
					break;
				} else {
					// step을 절반으로 줄여서 다시 시도.
					step_size /= 2;
				}
			} else if (l_time < old_time) {
				old_count = l_count;
				old_time = l_time;
			} else { // if (r_time < old_time) {
				old_count = r_count;
				old_time = r_time;
			}
		}

		cache_time.clear();
		cache_plant_time.clear();
		return y;
	}

	private double calc_time(int plant_count) {
		double value = 0;
		// count 가 0 보다 작으면 max 리턴
		if (plant_count < 0) {
			return Double.MAX_VALUE;
		}
		// cache 사용.
		if (cache_time.containsKey(plant_count)) {
			value = cache_time.get(plant_count);
			return value;
		}
		
		// plant time
		if (cache_plant_time.containsKey(plant_count)) {
			value = cache_plant_time.get(plant_count);
		} else {
			int i = plant_count;
			for (; i > 0; i--) {
				if (cache_plant_time.containsKey(i)) {
					value = cache_plant_time.get(i);
					break;
				}
			}
			for (int j = i; j < plant_count; j++) {
				value += c / (2 + j * f);
			}
			cache_plant_time.put(plant_count, value);
		}
		
		// + produce time
		value = g / (2 + plant_count * f) + value;
		cache_time.put(plant_count, value);
		return value;
	}

}
