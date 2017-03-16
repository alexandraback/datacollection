import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class GoodLuck {

	public static  int factor(int x, int y){
		int num = 0;
		while(x % y == 0){
			num ++;
			x = x / y;
		}
		return num;
	}
	
	public static int[] test(int[] guess , int N , int M , int K){
		Arrays.sort(guess);
		int max2 = 0 , max3 = 0, max5 = 0;
		for(int num : guess){
			int f2 = factor(num , 2);
			int f3 = factor(num , 3);
			int f5 = factor(num , 5);
			max2 = f2 > max2 ? f2 : max2;
			max3 = f3 > max3 ? f3 : max3;
			max5 = f5 > max5 ? f5 : max5;
		}
		
		int[] results = new int[N];
		
		if(max5 + max3 > 3){
			for(int i = 0 ; i < N ; i ++){
				results[i] = 3;
			}
			return results;
		}
		else{
			
			int i = 0;
			for(; i < max5 ; i ++){
				results[i] = 5;
			}
			for(; i < max5 + max3 ; i ++){
				results[i] = 3;
			}
			
			int left = N - max5 - max3;
			for(; i < max5 + max3 + max2 - left ; i ++){
				results[i] = 4;
			}
			
			for(; i < N ; i ++){
				results[i] = 2;
			}
			
			return results;
		}
		
		
	}
	
	public static String toString(int[] r){
		StringBuilder sb = new StringBuilder();
		for(int v : r){
			sb.append(String.valueOf(v));
		}
		return sb.toString();
	}
	public static void main(String args[]) throws IOException{
		Scanner s = new Scanner(new FileInputStream("C-small-1-attempt0.in"));
		PrintWriter writer = new PrintWriter(new FileOutputStream("output.txt"));
		int T = s.nextInt();
		for(int i = 0 ; i < T ; i ++){
			int R = s.nextInt();
			int N = s.nextInt();
			int M = s.nextInt();
			int K = s.nextInt();
			
			writer.println("Case #" + (i + 1) + ": " );
			for(int j = 0 ; j < R ; j ++){
				int[] guess = new int[K];
				for(int k = 0 ; k < K ; k ++){
					guess[k] = s.nextInt();
				}
				int[] result = test(guess , N , M , K);
				writer.println(toString(result));
			}
			
		}
		s.close();
		writer.close();
	}

}
