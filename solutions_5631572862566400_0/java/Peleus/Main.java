import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		File in = new File("C-small-attempt1.in");
		File out = new File("file.out");
		Scanner scanner = null;
		PrintStream ps = null;
		try {
			scanner = new Scanner(in);
			ps = new PrintStream(out);
			int num = scanner.nextInt();
			for(int i = 1; i <= num; i++) {
				ps.print("Case #" + i + ": ");
				int N = scanner.nextInt();
				int[] arr = new int[N + 1];
				for(int j = 1; j <= N; j++) {
					arr[j] = scanner.nextInt();
				}
				ps.println(fun(arr));
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} finally {
			if(scanner != null) {
				scanner.close();
			}
			if(ps != null) {
				ps.close();
			}
		}
	}
	
	public static int fun(int[] arr) {
		int n = arr.length;
		int[] lens = new int[n];
		int[] lastNums = new int[n];
		int[] cycLens = new int[n];
		for(int i = 1; i < n; i++) {
			boolean[] flag = new boolean[n];
			lens[i] = search(arr, i, flag);
			lastNums[i] = lastNumber;
			if(arr[lastNumber] == i) {
				cycLens[i] = lens[i];
			}
		}
		
//		for(int ss: cycLens) {
//			System.out.print(ss + " ");
//		}
//		System.out.println();
		
		for(int i = 1; i < n; i++) {
			if(arr[arr[lastNums[i]]] == lastNums[i]) {
				int count = 0;
				for(int a : arr) {
					if(a == lastNums[i]) {
						count++;
					}
				}
				int len = lens[i] + (count > 1 ? 1 : 0);
				cycLens[i] = Math.max(cycLens[i], len);
			}
		}
		
		int maxLen = 0;
		for(int i = 1; i < n; i++) {
			if(maxLen < cycLens[i]) {
				maxLen = cycLens[i];
			}
		}
		int dCount = 0;
		HashSet<Integer> set = new HashSet<>();
		for(int i = 1; i < n; i++) {
			if(i == arr[arr[i]]) {
				dCount++;
				set.add(i);
			}
		}
		boolean[] light = new boolean[n];
		for(int i = 1; i < n; i++) {
			if(!set.contains(i) && set.contains(arr[i])) {
				light[arr[i]] = true;
			}
		}
		for(int i = 1; i < n; i++) {
			if(light[i]) {
				dCount++;
			}
		}
		return Math.max(maxLen, dCount);
	}
	
	private static int lastNumber = 0;
	
	public static int search(int[] arr, int s, boolean[] flag) {
		if(flag[s] == true) {
			return 0;
		}
		
		lastNumber = s;
		flag[s] = true;
		return search(arr, arr[s], flag) + 1;
	}

}
