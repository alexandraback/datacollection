package fractiles;

import java.util.*;

public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			int K = scan.nextInt();
			int C = scan.nextInt();
			int S = scan.nextInt();
			System.out.printf("Case #%d:", i);
			if(S<K){
				System.out.println(" IMPOSSIBLE");
			}
			else{
				for(int j=1;j<=S;j++){
					System.out.printf(" %d", j);
				}
				System.out.println();
			}
		}
		scan.close();

	}

}
