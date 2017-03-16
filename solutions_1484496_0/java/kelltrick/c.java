import java.io.*;
import java.util.*;
public class c{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int nc = sc.nextInt();
		for(int tc = 1; tc <= nc; tc++){
			int n = sc.nextInt();
			int[] ary = new int[n];
			int sum = 0;
			for(int i = 0; i < n; i++){
				ary[i] = sc.nextInt();
				sum += ary[i];
			}
			int[] access = new int[sum+1];
			int end = 1<<n;
			System.out.println("Case #" + tc + ":");
			boolean done = false;
			for(int i = 0; i < end; i++){
				int ssum = 0;
				for(int j = 0; j < 20; j++){
					if((i&(1<<j)) > 0) ssum += ary[j];
				}
				if(access[ssum] != 0){
					print(access[ssum], ary);
					print(i, ary);
					done = true;
					break;
				}
				else{
					access[ssum] = i;
				}
			}
			if(!done){
				System.out.println("Impossible");
			}
		}
	}
	public static void print(int i, int[] ary){
		for(int j = 0; j < ary.length; j++){
			if((i&(1<<j)) > 0){
				System.out.print(ary[j] + " ");
			}
		}
		System.out.println();
	}
}

//n** {{2 20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600}}

//n** {{1 3 1 2 4}}
