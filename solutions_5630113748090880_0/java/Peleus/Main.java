import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		File in = new File("B-small-attempt0.in");
		File out = new File("file.out");
		Scanner scanner = null;
		PrintStream ps = null;
		try {
			scanner = new Scanner(in);
			ps = new PrintStream(out);
			int num = scanner.nextInt();
			for(int i = 1; i <= num; i++) {
				int N = scanner.nextInt();
				List<Integer> arr = new ArrayList<>();
				for(int j = 0; j < (2 * N - 1) * N; j++) {
					arr.add(scanner.nextInt());
				}
				ps.print("Case #" + i + ":");
				for(int n : fun(arr)) {
					ps.print(" " + n);
				}
				ps.println();
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
	
	public static List<Integer> fun(List<Integer> arr) {
		HashSet<Integer> set = new HashSet<>();
		List<Integer> res = new ArrayList<>();
		for(Integer n : arr) {
			if(set.contains(n)) {
				set.remove(n);
			} else {
				set.add(n);
			}
		}
		for(Integer n : set) {
			res.add(n);
		}
		Collections.sort(res);
		return res;
	}
	
}
