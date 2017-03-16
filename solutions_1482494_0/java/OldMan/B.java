import java.util.Arrays;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		int k = 0;
		while (t > 0) {
			t--;
			k++;
			int n = cin.nextInt();
			Score[] f = new Score[n];
			
			for (int i = 0; i < n; i++) {
				f[i] = new Score(cin.nextInt(), cin.nextInt());
			}
			
			
			int num = 0, race = 0;
			int j = 0,i = 0;
			boolean []vg = new boolean[n];
			boolean []vf = new boolean[n];
			for(i = 0 ; i < n ; i++){
				boolean flag = false;
				for(j = 0 ; j < n ; j++){
					if(!vg[j] && num >= f[j].costB){
						vg[j] = true;
						num += vf[j]?1:2;
						race++;
						flag = true;
						break;
					}					
				}
				if(!flag){
					int tmp = -1, z = 0;
					for(j = 0 ; j < n ; j++){
						if(!vf[j] && !vg[j]){
							if(f[j].costA <= num && f[j].costB >tmp){
								tmp = f[j].costB;
								z = j;
							}
						}
					}
					if(tmp == -1) break;
					vf[z] = true;
					race++;
					num++;
					i--;
				}
			}
			System.out.print("Case #"+k+": ");
			if(i == n)System.out.println(race);
			else System.out.println("Too Bad");
		}
	}

}

class Score {
	public Score(int i, int j) {
		costA = i;
		costB = j;
		
	}

	public int costA;
	public int costB;
}
