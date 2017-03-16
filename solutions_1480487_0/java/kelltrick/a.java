import java.io.*;
import java.util.*;
public class a{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int nc = sc.nextInt();
		for(int tc = 1; tc <= nc; tc++){
			int n = sc.nextInt();
			int[] points = new int[n];
			int sum = 0;
			for(int i = 0; i < n; i++){
				points[i] = sc.nextInt();
				sum += points[i];
			}
			System.out.print("Case #" + tc + ":");
			for(int i = 0; i < n; i++){			
				double low = 0, high = 1;
				for(int j = 0; j < 5000; j++){
					double mid = (low+high)/2.0;
					boolean isSafe = test(sum,points,mid,i);
					if(isSafe) high = mid + 1e-10;
					else low = mid - 1e-10;
				}
				System.out.printf(" %.6f",(low+high)*50.0);
			}
			System.out.println();
		}
	}
	public static boolean test(int sum, int[] points, double mid, int m){
		double myScore = points[m] + sum*mid;
		double totalNeed = 0;
		for(int i = 0; i < points.length; i++){
			if(points[i] < myScore)
				totalNeed += (myScore - points[i])/sum;
		}
		return (totalNeed >= 1.0);
	}
}
//n** {{1 2 20 10}}
//n** {{1 2 10 0}}
//n** {{1 4 25 25 25 25}}
//n** {{1 3 24 30 21}}
//n** {{1 3 0 30 0}}

//n** {{4 2 20 10 2 10 0 4 25 25 25 25 3 24 30 21}}
