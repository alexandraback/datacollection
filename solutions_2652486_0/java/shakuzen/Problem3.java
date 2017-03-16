package codejam.cj2013.r1a;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Problem3 {

	Scanner scin = new Scanner(System.in);
	
	// variables go here
	int R, N, M, K;
	int[][] k;
	List<Integer> digits;

	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (Problem1.class.getName() + ".in"))));
		} catch (Exception e) {
			//do nothing... use standard System.in
		}
		new Problem3().exec();
	}
	
	void exec() {
		int N = scin.nextInt();
//		scin.nextLine();
		for (int i = 1; i <= N; i++) {
			System.out.printf("Case #%d: ", i);
			read();
			solve1();
		}
	}
	
	void read() {
		R = scin.nextInt();
		N = scin.nextInt();
		M = scin.nextInt();
		K = scin.nextInt();
		
		k = new int[R][K];
		digits = new ArrayList<Integer>(N);
		
		for (int i = 0; i < R; i++)
			for (int j = 0; j < K; j++)
				k[i][j] = scin.nextInt();
			
	}
	
	void solve1() {
		System.out.println();
		
		List<Integer> list = new ArrayList<Integer>(K);
		
		for (int i = 0; i < R; i++) {
			digits.clear();
			list.clear();
			int two = 0;
			int three = 0;
			int four = 0;
			int five = 0;
			// number of digits definitely found
			int def_digits = 0;
			
			for (int temp : k[i])
				list.add(temp);
			
			// gather probabilities / find definites
			for (int I : list) {
				if (def_digits == 3)
					break;
				
				switch(I) {
				case 1:
					break;	//no useful info
				case 2:
					if (def_digits < 3 && !digits.contains(2)) {
						digits.add(2);
						def_digits++;
					}
					two++;
					break;
				case 3:
					if (def_digits < 3 && !digits.contains(3)) {
						digits.add(3);
						def_digits++;
					}
					three++;
					break;
				case 4:
					two += 2;
					four++;
					break;
				case 5:
					if (def_digits < 3 && !digits.contains(5)) {
						digits.add(5);
						def_digits++;
					}
					five++;
					break;
				case 6:
					if (def_digits < 3 && !digits.contains(2)) {
						digits.add(2);
						def_digits++;
					}
					if (def_digits < 3 && !digits.contains(3)) {
						digits.add(3);
						def_digits++;
					}
					two++;
					three++;
					break;
				case 8:
					four++;
					two++;
					break;
				case 9:
					// 3 * 3
					if (def_digits < 3 && !digits.contains(3)) {
						digits.add(3);
						def_digits++;
					}
					three += 2;
					break;
				case 10:
					if (def_digits < 3 && !digits.contains(2)) {
						digits.add(2);
						def_digits++;
					}
					if (def_digits < 3 && !digits.contains(5)) {
						digits.add(5);
						def_digits++;
					}
					five++;
					two++;
				case 12:
					// 2 * 2 * 3; 3 * 4
					three++;
					four++;
					two++;
					if (def_digits < 3 && !digits.contains(3)) {
						digits.add(3);
						def_digits++;
					}
					break;
				case 15:
					// 5 * 3
					five++;
					three++;
					if (def_digits < 3 && !digits.contains(3)) {
						digits.add(3);
						def_digits++;
					}
					if (def_digits < 3 && !digits.contains(5)) {
						digits.add(3);
						def_digits++;
					}
					break;
				case 16:
					// 4 * 4; 2 * 2 * 4
					two += 2;
					four += 2;
					break;
				case 18:
					// 3 * 3 * 2; ONLY POSSIBLE WAY
					def_digits = 3;
					digits.clear();
					digits.add(3);
					digits.add(3);
					digits.add(2);
					break;
				case 20:
					// 5 * 4; 5 * 2 * 2;
					if (def_digits < 3 && !digits.contains(5)) {
						digits.add(5);
						def_digits++;
					}
					two++;
					four++;
					break;
				case 24:
					// 4 * 2 * 3; ONLY POSSIBLE WAY
					def_digits = 3;
					digits.clear();
					digits.add(4);
					digits.add(2);
					digits.add(3);
					break;
				case 25:
					// 5 * 5
					int five_count = 0;
					for (int x : digits)
						if (x == 5)
							five_count++;
					while (five_count++ < 2) {
						digits.add(5);
						def_digits++;
					}
					break;
				case 27:
					// 3 * 3 * 3; ONLY POSSIBLE WAY
					def_digits = 3;
					digits.clear();
					digits.add(3);
					digits.add(3);
					digits.add(3);
					break;
				case 30:
					// 5 * 2 * 3;
					def_digits = 3;
					digits.clear();
					digits.add(5);
					digits.add(2);
					digits.add(3);
					break;
				case 32:
					// 4 * 4 * 2
					def_digits = 3;
					digits.clear();
					digits.add(4);
					digits.add(2);
					digits.add(2);
					break;
				case 36:
					// 3 * 3 * 4
					def_digits = 3;
					digits.clear();
					digits.add(3);
					digits.add(3);
					digits.add(4);
					break;
				case 40:
					// 4 * 5 * 2;
					def_digits = 3;
					digits.clear();
					digits.add(4);
					digits.add(5);
					digits.add(2);
					break;
				case 45:
					// 3 * 3 * 5
					def_digits = 3;
					digits.clear();
					digits.add(3);
					digits.add(3);
					digits.add(5);
					break;
				case 48:
					// 3 * 4 * 4
					def_digits = 3;
					digits.clear();
					digits.add(4);
					digits.add(4);
					digits.add(3);
					break;
				case 50:
					// 5 * 5 * 2
					def_digits = 3;
					digits.clear();
					digits.add(5);
					digits.add(5);
					digits.add(2);
					break;
				case 60:
					// 4 * 3 * 5
					def_digits = 3;
					digits.clear();
					digits.add(4);
					digits.add(5);
					digits.add(3);
					break;
				case 64:
					// 4 * 4 * 4
					def_digits = 3;
					digits.clear();
					digits.add(4);
					digits.add(4);
					digits.add(4);
					break;
				case 75:
					// 3 * 5 * 5
					def_digits = 3;
					digits.clear();
					digits.add(3);
					digits.add(5);
					digits.add(5);
					break;
				case 80:
					// 4 * 5 * 4
					def_digits = 3;
					digits.clear();
					digits.add(4);
					digits.add(5);
					digits.add(4);
					break;
				case 100:
					// 5 * 5 * 4
					def_digits = 3;
					digits.clear();
					digits.add(4);
					digits.add(5);
					digits.add(5);
					break;
				case 125:
					//5 * 5 * 5
					def_digits = 3;
					digits.clear();
					digits.add(5);
					digits.add(5);
					digits.add(5);
					break;
				}
			}
			
			// need to determine based on probability
			while (def_digits++ < 3) {
				List<Integer> temp = new ArrayList<Integer>();
				temp.add(-1);
				temp.add(-1);
				temp.add(two);
				temp.add(three);
				temp.add(four);
				temp.add(five);
				int max_index = 2;
				int max = 0;
				for (int z = 0; z < temp.size(); z++) {
					if (temp.get(z) > max) {
						max = temp.get(z);
						max_index = z;
					}
				}
				digits.add(max_index);
				if (max_index == 2)
					two = 0;
				else if (max_index == 3)
					three = 0;
				else if (max_index == 4)
					four = 0;
				else if (max_index == 5)
					five = 0;
			}
			
			for (int j = 0; j < N; j++)
				System.out.print(digits.get(j));
			System.out.println();
		}
	}
}