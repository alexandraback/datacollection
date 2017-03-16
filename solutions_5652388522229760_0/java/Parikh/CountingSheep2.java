package coding;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class CountingSheep2 {
	public static void main(String args[]) throws IOException {
		FileReader fileReader = new FileReader(
				"/home/parikh/Downloads/A-small-attempt0.in");
		BufferedReader obj = new BufferedReader(fileReader);
		String l = obj.readLine();
		int t = Integer.parseInt(l);
		System.out.println(t);
		PrintWriter write = new PrintWriter(new File("/home/parikh/output.txt"));
		for (int k = 1; k <= t; k++) {
			l = obj.readLine();
			long num = Long.parseLong(l);
			if (num == 0) {
				write.println("Case #" + k + ": " + "INSOMNIA");
				continue;
			}
			boolean val = false;
			int arr[] = new int[10];
			long ans = num;
			for (int i = 2; i <= 100000; i++) {
				setArray(ans, arr);
				if (isAllOne(arr)) {
					val = true;
					write.println("Case #" + k + ": " + ans);
					break;
				}
				ans = num * i;
			}
			if (!val)
				write.println("Case #" + k + ": " + "INSOMNIA");

		}
		obj.close();
		write.close();

	}

	public static boolean isAllOne(int arr[]) {
		for (int i = 0; i < arr.length; i++)
			if (arr[i] == 0)
				return false;
		return true;
	}

	public static void setArray(long num, int arr[]) {

		long val = num;
		if (num == 0)
			arr[0] = 1;
		while (val != 0) {
			int x = (int) val % 10;
			arr[x] = 1;
			val = val / 10;
		}
	}
}
