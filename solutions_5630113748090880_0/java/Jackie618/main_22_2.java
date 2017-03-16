import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class main_22_2 {
	public String Rank_and_File(int[] array){
		Set<Integer> set = new HashSet<Integer>();
		for(int i = 0; i < array.length; i++){
			if(!set.contains(array[i])){
				set.add(array[i]);
			} else {
				set.remove(array[i]);
			}
		}
		
		int[] ans = new int[set.size()];
		int index = 0;
		for(int i : set){
			ans[index++] = i;
		}
		
		Arrays.sort(ans);
		StringBuffer sb = new StringBuffer();
		for(int i = 0; i < ans.length; ++i){
			sb.append(ans[i]).append(" ");
		}
		return sb.substring(0, sb.length() - 1);
	}

	public static void main(String[] args) {
		main_22_2 m = new main_22_2();
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int t = in.nextInt(); // Scanner has functions to read ints, longs,
								// strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			int times = in.nextInt();
			int total = 2*times*times-times;
			int[] input = new int[total];
			for (int j = 0; j < total; j++) {
				input[j] = in.nextInt();
			}

			String ans = m.Rank_and_File(input);
			System.out.print("Case #" + i + ": " + ans);
			System.out.println();
		}
	}
	
	
}
