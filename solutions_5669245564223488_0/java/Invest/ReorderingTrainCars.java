package gcj14;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class ReorderingTrainCars {

	private int res;
	
	private String getAnswer(String[] arr) {
		permutate(arr, 0);
		
		return String.valueOf(res);
	}
	
	public void permutate(String[] arr, int count) {
		if (count == arr.length) {
			
			if (isValid(arr)) res++;
			return;
		}
		
		for (int i = count; i < arr.length; i++) {
			swap(count, i, arr);
			permutate(arr, count + 1);
			swap(count, i, arr);
		}
	}

	private void swap(int x, int y, String[] arr) {
		String temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}
	
	private boolean isValid(String[] arr) {
		boolean[] used = new boolean['z' - 'a' + 1];
		char last = arr[0].charAt(0);
		
		for (String s : arr) {
			for (int j = 0; j < s.length(); j++) {
				if (used[s.charAt(j) - 'a'] && last != s.charAt(j)) return false;
				
				used[s.charAt(j) - 'a'] = true;
				last = s.charAt(j);
			}
		}
		
		return true;
	}
	
	public static final long MOD = 1000000007;
	
	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			in = new Scanner(new File(INPUT_FILE_PATH));
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			int testCount = in.nextInt();

			for (int i = 0; i < testCount; i++) {
				String[] arr = new String[in.nextInt()];
				for (int j = 0; j < arr.length; j++) {
					arr[j] = in.next();
				}

				System.out.println(i);
				writer.println("Case #" + (i + 1) + ": " + new ReorderingTrainCars().getAnswer(arr));
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (in != null) in.close();
			if (writer != null) writer.close();
		}
	}

}
