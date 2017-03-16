import java.util.*;
public class a{
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int cases = br.nextInt();
		for(int c = 0;c<cases;c++){
			int n = br.nextInt();
			int[] points = new int[n];
			int x = 0;
			for(int i = 0;i<n;i++){
				points[i] = br.nextInt();
				x+=points[i];
			}
			double[] need = new double[n];
			for(int i = 0;i<n;i++){
				double low = 0;
				double high = 100;
				while(Math.abs(low-high) > 1e-9){
					double mid = (low+high)/2.0;
					mid/=100;
					double mypoints = points[i]+x*mid;
					double left = 1-mid;
					for(int j = 0;j<n;j++){
						if(j == i){
							continue;
						}
						if(points[j] > mypoints){
							continue;
						}
						double needp = ((mypoints+.00000001)-points[j])/(x*1.0);
						left-=needp;
					}
					mid*=100;
					if(left > 0){
						low = mid+.0000000001;
					}
					else{
						high = mid;
					}
				}
				need[i] = (low+high)/2.0;
			}
			System.out.print("Case #"+(c+1)+":");
			for(int i = 0;i<n;i++){
				System.out.printf(" %.6f",need[i]);
			}
			System.out.println();
		}
	}
}