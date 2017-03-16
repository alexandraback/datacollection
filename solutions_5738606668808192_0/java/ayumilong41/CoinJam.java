/**
 * File Name: CoinJam.java
 * Package Name: yz.google.codejam
 * Project Name: Algorithm
 * Purpose:
 * Created Time: 7:03:03 PM Apr 8, 2016
 * Author: Yaolin Zhang
 */

import java.util.*;

/**
 * @author Yaolin Zhang
 * @time 7:03:03 PM Apr 8, 2016
 */
public class CoinJam {
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		int N = scan.nextInt();
		int J = scan.nextInt();
		
		String[] jamcoins = new String[J];
		int index = 0;
		
		int start = (1 << (N - 1)) + 1;
		int end = (1 << N) - 1;
		List<List<Long>> divisors = new ArrayList<>();
		for(int i = start; i <= end; i += 2){
			String s = Long.toString(i, 2);
			List<Long> temp = new ArrayList<>();
			boolean isJamCoin = true;
			for(int j = 2; j <= 10; ++j){
				long div = findDivisor(Long.parseLong(s, j));
				if(div == -1L){
					isJamCoin = false;
					break;
				}
				temp.add(div);
			}
			if(isJamCoin){
				jamcoins[index++] = s;
				divisors.add(temp);
				if(index == J){
					break;
				}
			}
		}
		System.out.printf("Case #%d:\n", T);
		for(int i = 0; i < J; ++i){
			System.out.print(jamcoins[i] + " ");
			for(Long n : divisors.get(i)){
				System.out.print(n + " ");
			}
			System.out.println();
		}
		
		scan.close();
	}
	
	public static long findDivisor(long n){
		long i = 2;
		for(; i < Math.sqrt(n); ++i){
			if(n % i == 0){
				return i;
			}
		}
		
		return -1L;
	}
}
