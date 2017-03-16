package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;

public class CodeJam3 {

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("C:\\temp\\sums.in"));
		FileOutputStream stream = new FileOutputStream(new File("C:\\temp\\sums.out"));
		int cases = scanner.nextInt();
		scanner.nextLine();
		for (int i = 0; i < cases; i++) {
			String result = solveCase(scanner);
			stream.write(new String("Case #" + (i+1) + ":\r\n" + result + "\r\n").getBytes());
		}
	}

	private static String solveCase(Scanner scanner) {
		int nums = scanner.nextInt();
		Map<Integer, String> map = new HashMap<Integer, String>((int) Math.pow(2, nums));
		for (int i = 0; i < nums; i++) {
			int num = scanner.nextInt();
			if (map.size() == 0) {
				map.put(num, num + "");
			} else {
				for (Integer key : new LinkedList<Integer>(map.keySet())) {
					String numbers = map.get(key);
					if (map.containsKey(key + num)) {
						scanner.nextLine();
						return map.get(key + num) + "\r\n" + numbers + " " + num;
					} else {
						map.put(key + num, numbers + " " + num);
					}
				}
			}
		}
		return "Impossible";
	}
}
