import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Random;


public class Main {
	
	public static boolean check(int [] a, int [] products){
		for (int i = 0;i<7;i++){
			boolean flag = false;
			for (int j=0;j<8;j++){
				if (a[i]==products[j]){
					flag = true;
				}
			}
			
			if (flag==false){
				return false;
			}
		}
		
		return true;
	}
	
	public static boolean guess(int [] a,int K){
		Random rand = new Random();
		int [] guess = new int [3];
		int [] products = new int [8];
		
		for (int k=0;k<100;k++){
			guess[0] = Math.abs(rand.nextInt()) % 4 + 2;
			guess[1] = Math.abs(rand.nextInt()) % 4 + 2;
			guess[2] = Math.abs(rand.nextInt()) % 4 + 2;
			
			products[0] = 1;
			products[1] = guess[0];
			products[2] = guess[1];
			products[3] = guess[2];
			products[4] = guess[0]*guess[1];
			products[5] = guess[0]*guess[2];
			products[6] = guess[1]*guess[2];
			products[7] = guess[0]*guess[1]*guess[2];
			
			if (check(a,products)==true){
				System.out.print(guess[0]);
				System.out.print(guess[1]);
				System.out.print(guess[2]);
				System.out.println();
				return true;
			}
		}
		
		
		return false;
	}
	
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		int R = in.nextInt();
		int N = in.nextInt();
		int M = in.nextInt();
		int K = in.nextInt();
		
		System.out.println("Case #1"  + ":");
		int i = 1;
			
		// R = 100, N = 3, M = 5, K = 7
		while( i <= R)
		{
			int [] a = new int [K];
			
			for(int j=0;j<K;j++){
				a[j] = in.nextInt();
			}
			
			if (guess(a,K)){
				;
			}
			else{
				System.out.println(222);
			}
			
			i++;
		}
		
		
	}
	
}

