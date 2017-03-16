import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;

public class ProblemB_Round1_2016 {
	public static void main(String[] args) {
		try {
//			quickTest();
			compete();
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static void quickTest() {
		int[][] data = new int[][] {
			{1, 2, 3},
			{2, 3, 5},
			{3, 5, 6},
			{2, 3, 4},
			{1, 2, 3}
		};
		output(1, data);
	}
	
	private static void output(int i, int[][] data) {
		System.out.println("Case #" + i + ": " + getOutput(data));
	}
	
	private static void compete() throws NumberFormatException, IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			int n = Integer.parseInt(br.readLine());
			int n2 = 2*n-1;
			int[][] data = new int[n2][];
			for (int j = 0; j < n2; j++) {
				data[j] = stringToIntArr(br.readLine());
			}
			output(i, data);
		}
		br.close();
	}
	
	private static int[] stringToIntArr(String s) {
		String[] sarr = s.split(" ");
		int[] iarr = new int[sarr.length];
		for (int i = 0; i < iarr.length; i++)
			iarr[i] = Integer.parseInt(sarr[i]);
		return iarr;
	}
	
	private static String getOutput(int[][] data) {
		// its a square when viewed horizontally and vertically
		// given 2n-1 length n samples, reconstruct the n x n square
		// value increases (not equal) left to right and top to bottom
		// the values missing will be the ones not accounted for twice
		HashMap<Integer, Integer> dataCount = new HashMap<Integer, Integer>();
		for (int i = 0; i < data.length; i++) {
			for (int j = 0; j < data[0].length; j++) {
				int val = data[i][j];
				
				if (dataCount.containsKey(val)) {
					int count = dataCount.get(val);
					dataCount.put(val, count+1);
				} else {
					dataCount.put(val, 1);
				}
			}
		}
		int[] missings = new int[data[0].length];
		int j = 0;
		for (Integer key : dataCount.keySet()) {
			int value = dataCount.get(key);
			if (value % 2 == 1) {
				missings[j++] = key;
				if (j == missings.length)
					break;
			}
		}
		
		Arrays.sort(missings);
		
		return intArrToString(missings);
	}
	
	private static String intArrToString(int[] arr) {
		StringBuilder b = new StringBuilder();
		for (int i = 0; i < arr.length; i++){
			b.append(arr[i]).append(" ");
		}
		return b.toString().trim();
	}
}
