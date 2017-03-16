import java.math.*;
import java.util.*;

public class Main {
	static int n;
	static int num = 0;
	static BigInteger b[][] = new BigInteger [40][40];
	static int a[] = new int [40];
	static BigInteger ans[] = new BigInteger [40];
	static int m;
	public static void main(String [] args){
		Scanner cin = new Scanner(System.in);
		int casei = cin.nextInt();
		System.out.println("Case #1:");
		n = cin.nextInt(); m = cin.nextInt();
		for(int i = 2; i <= 10; i ++){
			b[i][0] = BigInteger.valueOf(1);
			for(int j = 1; j <= 32; j ++){
				BigInteger tmp = BigInteger.valueOf(i);
				b[i][j] = b[i][j - 1].multiply(tmp);
			}
		}
		num = 0; a[0] = 1; a[n - 1] = 1;
		dfs(1);
		System.out.println(num);
	}
	static void dfs(int step){
		if(num == m) return;
		if(step == n - 1){
			int i;
			for(i = 2; i <= 10; i ++){
				BigInteger tmp = BigInteger.valueOf(0);
				for(int j = 0; j < 32; j ++){
					if(a[j] == 1) tmp = tmp.add(b[i][j]);
				}
				int flag = 0;
				BigInteger j = BigInteger.valueOf(2);
				BigInteger one = BigInteger.valueOf(1);
				BigInteger zero = BigInteger.valueOf(0);
				BigInteger INF = BigInteger.valueOf(10000);
				for(; j.multiply(j).compareTo(tmp) <= 0 && j.compareTo(INF) <= 0; j = j.add(one)){
					if(tmp.mod(j).compareTo(zero) == 0){
						ans[i] = j;
						flag = 1;
						break;
					}
				}
				if(flag == 0) break;
			}
			if(i == 11){
				num ++;
				for(int j = 31; j >= 0; j --) System.out.print(a[j]);
				for(int j = 2; j <= 10; j ++) System.out.print(" " + ans[j]);
				System.out.println();
			}
			return;
		}
		a[step] = 0;
		dfs(step + 1);
		a[step] = 1;
		dfs(step + 1);
	}
}

/* 这里本来想要用程序写来计算置换群中循环个数的，但是有点麻烦，可以直接手工计算。－ －
 * 喔...
 * 题目中还有说到反射。再讨论一下。
 */

