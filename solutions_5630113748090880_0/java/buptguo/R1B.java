package googleCodeJam;

import java.util.Scanner;

public class R1B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int i=1; i<=n; i++){
			int m = in.nextInt();
			int[] ans = new int[m];
			int[] num = new int[2600];
			int tmp;
			for(int j=0; j<2*m-1; j++){
				for(int k=0; k<m; k++){
					tmp = in.nextInt();
					num[tmp]++;
				}
			}
			int nn=0;
			System.out.print("Case #" + i + ": ");
			for(int j=0; j<num.length; j++){
				if(num[j]%2 !=0 && j!=num.length-1) System.out.print(j + " ");
				else if(num[j]%2 !=0 && j!=num.length-1) System.out.print(j);
			}
			System.out.println();
		}
		// TODO Auto-generated method stub

	}

}
