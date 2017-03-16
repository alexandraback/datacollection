import java.util.*;
import java.io.*;

public class RankFile {
	public static void main (String[] args) {		
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = Integer.parseInt(in.nextLine());  // Scanner has functions to read ints, longs, strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			int n = Integer.parseInt(in.nextLine()); 
			String[] list = new String[2*n-1];
			for (int j = 0; j < 2*n-1; j++) {
				list[j] = in.nextLine();
			}
			System.out.println("Case #" + i + ": " + findRankFile(list));
		}
	}
	
	private static String findRankFile (String[] list) {
		HashSet<Integer> set = new HashSet<>();
		for (int i = 0; i < list.length; i++) {
			String[] listElement = list[i].split(" ");
			for (int j = 0; j < listElement.length; j++) {
				Integer element = Integer.valueOf(listElement[j]);
				if (set.contains(element)) {
					set.remove(element);
				} else {
					set.add(element);
				}
			}
		}
		Integer[] elements = set.toArray(new Integer[]{});
		Arrays.sort(elements);
		String result= "";
		for (int i = 0 ; i < elements.length ; i++) {
			result += (elements[i] + " ");
		}
		return result;
	}
}