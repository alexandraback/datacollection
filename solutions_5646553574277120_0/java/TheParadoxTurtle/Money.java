import java.util.Scanner;


public class Money {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t = 1; t <= T; t++) {
			int C = scan.nextInt();
			int D = scan.nextInt();
			int V = scan.nextInt();
			int[] denoms = new int[D];
			for(int i = 0; i < D; i++)
				denoms[i] = scan.nextInt();
			int low = C;
			int extra = 0;
			int index = 1;
			if(denoms[0] != 1) {
				extra++;
				index--;
			}
			while(index < D && low < V) {
				if(denoms[index] > low+1) {
					extra++;
					low += C*(low+1);
				}
				else {
					low += C*denoms[index];
					index++;
				}
			}
			while(low < V) {
				extra++;
				low += C*(low+1);
			}
			
			System.out.println("Case #" + t + ": " + extra);
		}
	}
}
