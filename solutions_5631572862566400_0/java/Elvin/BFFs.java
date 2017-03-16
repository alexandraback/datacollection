import java.io.*;
import java.util.*;

public class BFFs {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(args[0]));
		PrintWriter pw = new PrintWriter(new FileWriter(args[0]+".out.txt"));

		int numOfCase = sc.nextInt();

		for (int i = 0; i < numOfCase; i++) {
			int size = sc.nextInt();

			int[] bffs = new int[size];
			for (int j = 0; j < size; j++) {
				bffs[j] = sc.nextInt() - 1;
			}
			//printArray("bffs", bffs);

			int[] count = new int[size];
			for (int j = 0; j < size; j++) {
				if (count[j] != 0) continue;
				union(bffs, count, j, 0, new int[size]);
			}

			int max = 0;
			for (int j = 0; j < size; j++) {
				int tmp = count[j];
				if (tmp < 0) {
					tmp = -tmp;
				} else if (bffs[bffs[j]] == j) {
					tmp += count[bffs[j]];
				}

				max = Math.max(max, tmp);
			}

			pw.println("Case #" + (i + 1) + ": " + max);
		}

		pw.flush();
		pw.close();
		sc.close();
	}
	private static void printArray(String prefix, int[] arr) {
		System.out.print(prefix + ": ");
		for (int i = 0; i < arr.length; i++) {
			System.out.print("[" + i + "]->" + arr[i] + ", ");
		}
		System.out.println();
	}

	private static void markCycle(int[] bffs, int[] count, int index, int num) {
		if(count[index] != num) {
			count[index] = num;
			markCycle(bffs, count, bffs[index], num);
		} else {
			return;
		}
	}

	private static void union(int[] bffs, int[] count, int index, int preCount, int[] marker) {
		//printArray("union(index: " + index + ", preCount: " + preCount + ")", count);

		if (marker[index] == 1) {
			markCycle(bffs, count, index, count[index] - preCount - 1);
			Arrays.fill(marker, 0);
			return;
		}

		if (bffs[bffs[index]] == index) {
			count[index] = preCount + 1;
			Arrays.fill(marker, 0);
			return;
		}

		if (count[index] >= 0 && (count[index] < preCount + 1)) {
			count[index] = preCount + 1;
			marker[index] = 1;
			union(bffs, count, bffs[index], count[index], marker);
		}

		Arrays.fill(marker, 0);
		return;
	}
}