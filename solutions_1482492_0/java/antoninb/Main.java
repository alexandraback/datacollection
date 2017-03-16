package B;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class Main {
	
	public static double calc(double a, double v, double d){
		double delta = v * v + 2. * a * d;
		delta = Math.sqrt(delta);
		return (-v + delta) / a;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//String fileName = args[0];
		String fileName = "B-small-attempt0.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		sC.useLocale(Locale.US);
		
		int T = sC.nextInt();
		double D;
		int N, A;
		double[] tO;
		double[] posO;
		double[] AM;
		
		for(int i = 0; i < T; i++){
			D = sC.nextDouble();
			N = sC.nextInt();
			A = sC.nextInt();
			tO = new double[N];
			posO = new double[N];
			AM = new double[A];
			
			for(int j = 0; j < N; j++){
				tO[j] = sC.nextDouble();
				posO[j] = sC.nextDouble();
			}
			
			for(int j = 0; j < A; j++){
				AM[j] = sC.nextDouble();
			}
			
			System.out.println("Case #" + (i + 1) + ":");
			
			double posM, posMprev, v, dt, res;
			
			for(int j = 0; j < A; j++){
				posM = 0;
				posMprev = 0;
				v = 0;
				res = 0;
				
				int k;
				for(k = 0; k < N; k++){
					if(k == 0)
						dt = tO[k];
					else
						dt = tO[k] - tO[k - 1];
					posM += v * dt + 0.5 * AM[j] * dt * dt;
					
					if(posM >= D && posO[k] >= posM){
						res = tO[k - 1] + calc(AM[j], v, D - posMprev);
						break;
					}
					if(posM >= D && posO[k] >= D){
						v = (posO[k] - posO[k - 1]) / dt;
						res = tO[k - 1] + (D - posO[k - 1]) / v;
						break;
					}
					if(posM > posO[k]){
						//v = (posO[k] - posO[k - 1]) / dt;
						v = Math.sqrt(2. * AM[j] * (posO[k] - posO[k - 1]));
						posM = posO[k];
					}
					else{
						v += AM[j] * dt;
					}
					
					posMprev = posM;
				}
				
				if(res == 0){
					res = tO[N - 1] + calc(AM[j], v, D - posM);
				}
				
				System.out.println(res);

			}
		}

	}

}
