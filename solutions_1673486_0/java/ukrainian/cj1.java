import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class cj1 {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(new File("input.in"));
		int T = s.nextInt();
		s.nextLine();
		for (int i=1; i<=T;i++) {
			System.out.print("Case #" +i+": ");
			int A = s.nextInt();
			int B = s.nextInt();
			double [] y = new double[A+2];
			double [] p = new double[A];
			for(int j=0; j<A;j++) {
				p[j] = s.nextDouble();
			}
			for(int j=0; j<=A;j++) {
				double p_no_er = 1;
				//System.out.println("reducing by "+j);
				for(int no_er_i = 0; no_er_i < p.length-j; no_er_i++) {
					//System.out.print("no_er in "+no_er_i + "th :" + p[no_er_i] + "; ");
					p_no_er*=p[no_er_i];
					//System.out.println("p_no_er after mult: "+p_no_er);
				}
				y[j]=p_no_er*(2*j + B - A + 1) + (1 - p_no_er)*(2*j + 2*B - A + 2);
				//System.out.println("p_0er: "+p_no_er + " B A "+ B + " " + A);
				//System.out.println("cost: "+y[j]);
			}
			y[A+1]=B+2;
			
			double min = y[0];  
		    for (int m=0; m<y.length; m++) {
		        if (y[m] < min) {
		            min = y[m];  
		        }
		    }
		    System.out.println(min);
		}
	}
}


