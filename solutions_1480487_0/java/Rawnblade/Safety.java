import java.util.*;
import java.io.*;

public class Safety {
	static int BINARY_SEARCH_ITERATIONS = 200;
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(new File("a.in"));
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt();
			double sum = 0;
			double[] p = new double[n];
			
			for(int i = 0; i < n; i++){
				p[i] =  reader.nextDouble();
				sum += p[i];
			}
			
			double[] sol = new double[n];
			Arrays.fill(sol, -1);
			
			for(int i = 0; i < n; i++){
				double low = 0;
				double high = 1;
				for(int j = 0; j < BINARY_SEARCH_ITERATIONS; j++){
					double mid = (low + high)/2;
					boolean f = f(mid, i, sum, p);
					if(f){
						sol[i] = mid;
						high = mid;
					}else{
						low = mid;
					}
				}
			}
			
			System.out.print("Case #"+t+": ");
			for(double x:sol)
				System.out.printf("%.6f ", x*100);
			System.out.println();
		}
	}
	
	public static boolean f(double f, int j, double s, double[] p){
		boolean good = false;
		double v = p[j] + f*s + .00000001;
		double left = (1-f);
		
		for(int i = 0; i < p.length && !good; i++){
			if(i == j) continue;
			double need = (v-p[i])/s;
			good |= need > left;
			left -= Math.max(need, 0);
		}
		
		return good;	
	}
}
