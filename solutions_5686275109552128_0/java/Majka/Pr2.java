import java.util.Scanner;


public class Pr2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T, D, max, min, temp;
		int[] P;
		Scanner s = new Scanner(System.in);
		T = s.nextInt();
		for(int t=1; t<=T; t++){
			D = s.nextInt();
			P = new int[D];
			max=0;
			for(int i=0; i<D; i++){
				P[i] = s.nextInt();
				if(max<P[i]) max=P[i];
				
			}
			
			min=max;
			for(int e=1; e<=max; e++){
				temp = e;
				for(int i=0; i<D; i++){
					temp += P[i]/e;
					if(P[i]%e == 0) temp -=1;
				}
				if(temp<min) min=temp;
			}
			System.out.println("Case #"+t+": "+min);
		}
	}

}
