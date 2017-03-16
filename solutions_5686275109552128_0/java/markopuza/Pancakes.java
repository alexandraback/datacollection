import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Pancakes {
	
	public static int findMin(ArrayList<Integer> list) {
		if (list.size() == 0) return 0;
		int min = 10000;
		for (int el : list) {
			if (el < min) min = el;
		}
		return min;
	}
	
	public static boolean isNineThree(int[] p) {
		boolean result = true;
		if (p[9] != 1) result = false;
		if (p[8] != 0) result = false;
		if (p[7] != 0) result = false;
		if (p[6] != 0) result = false;
		if (p[5] != 0) result = false;
		if (p[4] != 0) result = false;
		return result;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new  BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(in.readLine());

		for (int i = 1; i <= t; i++) { 
			int n = Integer.parseInt(in.readLine());
			
			int[] pancakes = new int[1001];
			for (int j = 0; j < 1001; j++) {
				pancakes[j] = 0;
			}
			
			ArrayList<Integer> times = new ArrayList<Integer>();
			for (String pan : in.readLine().split(" ")) {
				pancakes[Integer.parseInt(pan)]++;
			}
			
			
			int[] pancakes2 = pancakes.clone();
	
			int cursor = 1000;
			int count = 0;
			while (cursor > 0) {
				while (cursor > 0 && pancakes[cursor] == 0) cursor--;
				times.add(cursor + count);
					
				pancakes[cursor / 2] += pancakes[cursor];
				pancakes[cursor / 2 + (cursor % 2)] += pancakes[cursor];
					
				count += pancakes[cursor];
				pancakes[cursor] = 0;
			}
			
			cursor = 1000;
			count = 0;
			while (cursor > 0) {
				while (cursor > 0 && pancakes2[cursor] == 0) cursor--;
				times.add(cursor + count);
					
				if (cursor == 9) {
					pancakes2[cursor / 3] += pancakes2[cursor];
					pancakes2[2*cursor / 3] += pancakes2[cursor];
				}
				else {
					pancakes2[cursor / 2] += pancakes2[cursor];
					pancakes2[cursor / 2 + (cursor % 2)] += pancakes2[cursor];
				}	
				
				count += pancakes2[cursor];
				pancakes2[cursor] = 0;
			}
			System.out.println("Case #" + i + ": "+ findMin(times));
		}
	}

}
