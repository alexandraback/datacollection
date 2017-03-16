import java.util.Arrays;
import java.util.Scanner;


public class D {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int kases=1;kases<=T;kases++) {
			int N = in.nextInt();
			double [] P1 = new double [N];
			double [] P2 = new double [N];
			for(int i=0;i<N;i++)
				P1[i]=in.nextDouble();
			for(int i=0;i<N;i++)
				P2[i]=in.nextDouble();
			Arrays.sort(P1);
			Arrays.sort(P2);

			/* NORMAL */
			int normgame=0;
			boolean [] used = new boolean[N];
			for(int i=0;i<N;i++) {				
				double min = Double.MAX_VALUE;
				int mini=-1;
				for(int j=0;j<N;j++) {
					if(!used[j] && P2[j] > P1[i] && P2[j] < min) {
						min=P2[j];
						mini=j;
					}
				}
				if(mini>=0) {
					used[mini]=true;
				}
				else {
					normgame++;
					for(int j=0;i<N;j++) {
						if(!used[j]) {
							used[j]=true;
							break;
						}
					}
				}
			}
			
			/* DEVIOUS */
			int devgame=0;
			int minj=0;
			for(int i=0;i<N;i++) {
				if(P1[i]>P2[minj]) {
					devgame++;
					minj++;
				}
			}
			System.out.println("Case #"+kases+": "+devgame+" "+normgame);
		}
	}

}
