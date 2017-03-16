/**
 * File Name: Main.java
 * Package Name: com.ncfxy.MyAlgorithm
 * Description： TODO 
 *
 *   ver					date			author
 * ──────────────────────────────────
 *   1.0-SNAPSHOT			2016年4月9日			Administrator
 *
 * Copyright (c) 2016, ncfxy All Rights Reserved.
 */

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * ClassName: Main<br/>
 * Description: TODO ADD Description
 *
 * @author Administrator
 * @version 1.0-SNAPSHOT
 * @Date 2016 2016年4月9日 上午9:45:38
 */

public class Main1 {

	public static void main(String[] args) {

		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int t = cin.nextInt();
			for (int i = 0; i < t; i++) {
				sol(cin, i + 1);
			}
		}

	}

	public static void sol(Scanner cin, int index) {
		long b = cin.nextLong();
		long m = cin.nextLong();
		long temp = 1;
		temp = temp << (b-2);
		if (m > temp) {
			System.out.println("Case #" + index + ": IMPOSSIBLE");
		} else {
			System.out.println("Case #" + index + ": POSSIBLE");
			buildMatrix(b, m);
		}
	}

	public static void buildMatrix(long b, long m) {
		long tmpM = m - 1;
		long index = 2;
		List<Long> list = new ArrayList<Long>();
		while (tmpM > 0) {
			if ((tmpM & 1) > 0) {
				list.add(index);
			}
			tmpM = tmpM >> 1;
			index++;
		}
		int matrix[][] = new int[60][60];
		for (int i = 1; i <= b; i++) {
			for (int j = 1; j < b; j++) {
				if (i < j) {
					matrix[i][j] = 1;
				} else {
					matrix[i][j] = 0;
				}
			}
		}
		for (int i = 1; i <= b; i++) {
			matrix[i][(int) b] = 0;
		}
		for (int i = 0; i < list.size(); i++) {
			long tmp = list.get(i);
			matrix[(int) tmp][(int) b] = 1;
		}
		matrix[1][(int)b] = 1;
		for (int i = 1; i <= b; i++) {
			for (int j = 1; j <= b; j++) {
				if (j == b) {
					System.out.println(matrix[i][j]);
				} else {
					System.out.print(matrix[i][j]);
				}
			}
		}

	}

}
