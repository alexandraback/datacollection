import java.util.Scanner;


public class Solution {

	
	
	public static void main(String[] args) {

		int N = 0;
		int T = 0;
		Scanner sc = new Scanner(System.in);
		
		T = sc.nextInt();
		
		for(int i = 0; i < T; i++){
			
			N = sc.nextInt();
			
			float points[] = new float[N];
			float X = 0;
			float B = 0;
			float R = 1;
			for(int l = 0; l < N; l++){
				points[l] = sc.nextInt();
				X += points[l];
			}
			B = biggest(points);
			
			float Y[] = new float[N];
			if(2*X/N >= B){
			for(int l = 0; l < N; l++){
				
				
				Y[l] = (B-points[l])/X;
				R -= Y[l];
			}
			}else{
				float sb = secondBiggest(points, B);
				while(2*X/N < sb){
					B = sb;
					sb = secondBiggest(points, B);
				}
				B = sb;
				for(int l = 0; l < N; l++){
					
					if(points[l] < B){
						Y[l] = (B-points[l])/X;
						R -= Y[l];
					}
				}
				
			}
			
			if(R > 0 && 2*X/N >= biggest(points)){
				for(int l = 0; l < N; l++){
					
					Y[l] += R/N;
					
				}
			}else{
				int F = valids(points, B);
					for(int l = 0; l < N; l++){
						if(points[l] <= B)
						Y[l] += R/F;
					
				}
			}
			
			
			
			System.out.print("Case #" + (i+1) + ":");
			for(int l = 0; l < N; l++){
				System.out.print(" " + (Y[l]*100));
			}
			System.out.println();
			
			
		}
		
		
	}
	
	static public float biggest(float point[]){
		float b = 0;
		for(int l = 0; l < point.length; l++){
			if(point[l] > b) b = point[l];
		}
		return b;
	}

	static public float secondBiggest(float point[], float B){
		float b = 0;
		for(int l = 0; l < point.length; l++){
			if(point[l] > b && point[l] < B) b = point[l];
		}
		return b;
	}
	
	static public int valids(float[] points, float B){
		int r = 0;
		for(int i = 0; i < points.length; i++){
			if(points[i] <= B) r = r+1;
		
		}
		return r;
	}
	
}
