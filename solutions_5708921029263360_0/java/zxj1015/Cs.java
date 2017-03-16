import java.util.Arrays;
import java.util.*;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigDecimal;

public class Main {
	
	public static void main(String[] args) {
		init();
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		for (int i = 0; i < cases; ++i) {
			int J, P, S, K;
			J = scanner.nextInt();
			P = scanner.nextInt();
			S = scanner.nextInt();
			K = scanner.nextInt();
			int total = J * P * S;
			//System.out.println(J + " " + P + " " + S + " " + K);
			Suit[] suits = new Suit[J * P * S];
			for (int j = 0; j < J; ++j) {
				for (int p = 0; p < P; ++p) {
					for (int s = 0; s < S; ++s) {
						suits[j * P * S + p * S + s] = new Suit(j, p, s);
					//	System.out.println(j + " " + p + " " + s);
					}
				}
			}
			int maxNum = 0;
			int idx = 0;
			for (int j = 0; j < (1 << total); ++j) {
				int temp = 0;
				for (int k = 0; k < total; ++k) {
					if (((j >> k) & 1) == 1) {
						++temp;
					}
				}
				if (temp <= maxNum) {
					continue;
				}
				//System.out.println(j + " " + total);
				int[] nums = new int[100];
				boolean flag = true;
				int counter = 0;
				
				for (int k = 0; k < total; ++k) {
					if (((j >> k) & 1) == 1) {
						/*if (j == 12) {
							System.out.println(j + "========"+ k);
						}*/
						++counter;
						Suit suit = suits[k];
						int code1 = (suit.A  + 1) * 16 + (suit.B + 1) * 4;
						int code2 = (suit.A  + 1) * 16 + suit.C;
						int code3 = (suit.B + 1) * 4 + suit.C;
						++nums[code1];
						++nums[code2];
						++nums[code3];
						if (nums[code1] > K || nums[code2] > K || nums[code3] > K) {
							flag = false;
							break;
						}
					}
				}
				if (flag && counter > maxNum) {
					maxNum = counter;
					idx = j;
				}
			}
			System.out.printf("Case #%d: %d\n", i + 1, maxNum);
			for (int k = 0; k < suits.length; ++k) {
				if (((idx >> k) & 1) == 1) {
					System.out.printf("%d %d %d\n", suits[k].A + 1, suits[k].B + 1, suits[k].C + 1);
				}	
			}
		}
	}
	
	static void printAll(Suit[] suits, int i) {
		System.out.printf("Case #%d: %d\n", i + 1, suits.length);
		for (int k = 0; k < suits.length; ++k) {
				System.out.printf("%d %d %d\n", suits[k].A + 1, suits[k].B + 1, suits[k].C + 1);
		}
	}

	private static class Suit {
		int A;
		int B;
		int C;
		Suit(int a, int b, int c) {
			A = a;
			B = b;
			C = c;
		}
	}
	
	
	
	
	
	
	
	
	
	public static void init() {
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("/Users/zxj/Documents/workspace/Algorithm/src/test.in");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
        System.setIn(fis); 
	}
}

