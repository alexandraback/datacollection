import java.text.DecimalFormat;
import java.util.*; 
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
//SRM525
public class round1CA {
	
	public static String solve(int N, int[][] store){
		int[] stack = new int[10000];
		boolean[] route = new boolean[N];
		
		for(int l = 0; l < N; l++){
			int counter = 0;
			if(store[l][0] >= 2){
				for(int p = 0; p < N; p++){
					route[p] = false;
				}
				route[l] = true;
				for(int s = 1; s <= store[l][0]; s++){
					stack[counter] = store[l][s];
					route[stack[counter] - 1] = true;
					counter++;
				}
				while(counter >= 0){
					counter--;
					if(counter < 0)
						continue;
					//route[stack[counter] - 1] = true;
					int temp = stack[counter];
					for(int s = 1; s <= store[temp - 1][0]; s++){
						//‚È[‚ñ‚à‚È‚¢
						stack[counter] = store[temp - 1][s];
						if(!route[stack[counter] - 1])
							route[stack[counter] - 1] = true;
						else return "Yes";
						counter++;
					}
				}
			}
		}
		return "No";
	}
	
	public static void main(String[] args) throws FileNotFoundException { 
		
		//double answer = 1;
		Scanner scan = new Scanner(System.in);
		int max = scan.nextInt();
		
		for(int i = 1; i <= max; i++){
			int N = scan.nextInt();
			int store[][] = new int[N][11];
			for(int l = 0; l < N; l++){
				int Mj = scan.nextInt();
				store[l][0] = Mj;
				for(int j = 1; j <= Mj; j++){
					store[l][j] = scan.nextInt();
				}		
			}
			System.out.println("Case #" + i + ": " + solve(N, store)); 
		}
	} 
}
