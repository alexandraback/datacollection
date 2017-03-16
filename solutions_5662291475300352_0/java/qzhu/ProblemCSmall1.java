/* 
 * Google Code Jam - 2015 - Round 1B - Problem C "Hiking Deer"
 * Solution for small input 1 by Qiyu Zhu
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class ProblemCSmall1 {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %d%n", i + 1, handleCase(in));
	}
	
	
	private static int handleCase(Scanner in) {
		int n = in.nextInt();
		List<Integer> degrees = new ArrayList<Integer>();
		List<Integer> minutes = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			int d = in.nextInt();
			int h = in.nextInt();
			int m = in.nextInt();
			for (int j = 0; j < h; j++) {
				degrees.add(d);
				minutes.add(m + j);
			}
		}
		
		if (degrees.size() < 2)
			return 0;
		if (degrees.size() > 2)
			throw new IllegalArgumentException();
		
		int d0 = degrees.get(0);
		int d1 = degrees.get(1);
		int m0 = minutes.get(0);
		int m1 = minutes.get(1);
		if (m0 == m1)
			return 0;
		if (d1 < d0) {
			int temp = d0;
			d0 = d1;
			d1 = temp;
			temp = m0;
			m0 = m1;
			m1 = temp;
		}
		if (m0 > m1)  // Check whether the fast hiker overtakes the slow hiker before the slow hiker reaches 360 degrees
//			return (long)m0 * m1 * (360 + d0 - d1) <= (long)m0 * (m0 - m1) * (360 - d0) ? 1 : 0;
			return (360.0 + d0 - d1) / (1.0 / m1 - 1.0 / m0) <= (360.0 - d0) * m0 ? 1 : 0;
		else  // Check whether the second time the fast hiker overtakes the slow hiker is before the slow hiker reaches 360 degrees
//			return (long)m1 * m0 * (360 + d1 - d0) <= (long)m1 * (m1 - m0) * (360 - d1) ? 1 : 0;
			return (360.0 + d1 - d0) / (1.0 / m0 - 1.0 / m1) <= (360.0 - d1) * m1 ? 1 : 0;
	}
	
}
