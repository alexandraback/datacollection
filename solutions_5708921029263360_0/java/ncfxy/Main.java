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

public class Main {

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
		int j = cin.nextInt();
		int p = cin.nextInt();
		int s = cin.nextInt();
		int k = cin.nextInt();
		List<Integer> listJ = new ArrayList<Integer>();
		List<Integer> listP = new ArrayList<Integer>();
		List<Integer> listS = new ArrayList<Integer>();
		for (int indexj = 1; indexj <= j; indexj++) {

			for (int indexp = 1; indexp <= p; indexp++) {
				for (int indexs = 1; indexs <= s; indexs++) {
					listJ.add(indexj);
					listP.add(indexp);
					listS.add(indexs);
				}

			}

		}
		List<Integer> ex = new ArrayList<Integer>();
		for (int i = 0; i < listP.size(); i++) {
			int tmp = 1;
			for (int jj = i + 1; jj < listP.size(); jj++) {
				if (listP.get(i).equals(listP.get(jj))
						&& listS.get(i).equals(listS.get(jj))) {
					tmp++;
					if (tmp > k) {
						ex.add(jj);
					}
				}
			}
		}
		for (int i = 0; i < listP.size(); i++) {
			int tmp = 1;
			for (int jj = i + 1; jj < listP.size(); jj++) {
				if (listJ.get(i).equals(listJ.get(jj))
						&& listS.get(i).equals(listS.get(jj))) {
					tmp++;
					if (tmp > k) {
						ex.add(jj);
					}
				}
			}
		}
		for (int i = 0; i < listP.size(); i++) {
			int tmp = 1;
			for (int jj = i + 1; jj < listP.size(); jj++) {
				if (listP.get(i).equals(listP.get(jj))
						&& listJ.get(i).equals(listJ.get(jj))) {
					tmp++;
					if (tmp > k) {
						ex.add(jj);
					}
				}
			}
		}
		System.out.println("Case #" + index + ": " + listJ.size());
		for (int i = 0; i < listJ.size(); i++) {
			if (ex.contains(new Integer(i))) {
				continue;
			}
			System.out.print(listJ.get(i) + " ");
			System.out.print(listP.get(i) + " ");
			System.out.print(listS.get(i));
			System.out.println();
		}
		for (int i = 0; i < listJ.size(); i++) {

		}
	}

}
