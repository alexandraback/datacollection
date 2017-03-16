package gcj2013R1B;

import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run(new Scanner(System.in));
	}
	int[] list = new int[708];

	void run(Scanner sc) {

		for(int i = 1, j = 0, k = 0; j < 708;j++, k+=2) {
//			System.out.println(j+" "+i);
			list[j] = i;
			i += (k + 2) * 2 + 1;
		}
		
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void solve(Scanner sc, int case_num) {
		int n = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		if(n == 1) {
			if(x == 0 && y == 0) System.out.printf("Case #%d: 1.0\n", case_num);
			else System.out.printf("Case #%d: 0.0\n", case_num);
			return;
		}
		
		int index = 0;
		if(n != 1)
		for(int i = 1; i < 708; i++) {
			if(list[i - 1] < n && n <= list[i]) {
				index = i; break;
			}
		}
//		System.out.println(index);
		if((index - 1) * 2 >= Math.abs(x) + y) {
			System.out.printf("Case #%d: 1.0\n", case_num);
			return;
		} else if(index * 2 < Math.abs(x) + y) {
			System.out.printf("Case #%d: 0.0\n", case_num);
			return;
		} else if(x == 0) {
			if(list[index] == n) {
				System.out.printf("Case #%d: 1.0\n", case_num);
			} else {
				System.out.printf("Case #%d: 0.0\n", case_num);
			}
			return;
		}
		int diamonds = n - list[index - 1];
//		System.out.println(diamonds);
		
		if((list[index] - list[index - 1]) / 2 + y + 1 <= diamonds) {
			System.out.printf("Case #%d: 1.0\n", case_num);
			return;
		}
		int a = 0, b = 0;
		for(int j = 0; j < (1 << diamonds); j++) {
			if(Integer.bitCount(j) >= (y + 1)) a++;
			b++;
		}
//		System.out.println("#"+xy_val);
//		if(x + y <= xy_val) {
//			System.out.printf("Case #%d: 1.0\n", case_num);
//			return;
//		} else if(x + y + 2 >= xy_val) {
//			System.out.printf("Case #%d: 0.0\n", case_num);
//			return;
//		}
		System.out.printf("Case #%d: ", case_num);
		System.out.println((double)a / b);
	}
}
