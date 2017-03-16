import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class Main {
	/*
	public static int calc(int [] v, int [] a, int E, int R, int N){
		int value = 0;
		int energy = E;
		
		for (int j = 0; j<N ; j++){
			// check if valid move
			if (energy < a[j])
				return -1;
			
			energy -= a[j];
			value +=  (a[j]*v[j]);
			energy += R;
			
			if (energy > E)
				energy = E;
		}
		
		return value;
	}
	
	
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int i = 1;
		
		
		while( i <= T)
		{
			int E = in.nextInt();
			int R = in.nextInt();
			int N = in.nextInt();
			
			int [] v = new int [N];
			
			for (int j = 0;j<N ; j++){
				v[j] = in.nextInt();
			}
			
			int max = 0;
			
			for (int k=0; k< Math.pow(E+1,N); k++){
				int [] a = new int [N];
				int tmp = k;
				for (int j = 0; j<N ; j++){
					a[j] = tmp % (E+1);
					tmp = tmp / (E+1);
				}
				
				int current = calc(v, a,E, R, N);
				if (current > max){
					max = current;
				}
			}
			
			System.out.println("Case #" + i + ": " + max);
			
			i++;
		}
		
		
	}*/
	
	public static int calc(int [] v, int [] a, int E, int R, int N){
		int value = 0;
		int energy = E;
		
		for (int j = 0; j<N-1 ; j++){
			// check if valid move
			if (energy < a[j])
				return -1;
			
			energy -= a[j];
			value +=  (a[j]*v[j]);
			energy += R;
			
			if (energy > E)
				energy = E;
		}
		
		value +=  (energy*v[N-1]);
		
		return value;
	}
	
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int i = 1;
		
		
		while( i <= T)
		{
			int E = in.nextInt();
			int R = in.nextInt();
			int N = in.nextInt();
			
			int [] v = new int [N];
			
			for (int j = 0;j<N ; j++){
				v[j] = in.nextInt();
			}
			
			int max = 0;
			
			for (int k=0; k< Math.pow(E+1,N-1); k++){
				int [] a = new int [N];
				int tmp = k;
				for (int j = 0; j<N-1 ; j++){
					a[j] = tmp % (E+1);
					tmp = tmp / (E+1);
				}
				
				int current = calc(v, a,E, R, N);
				if (current > max){
					max = current;
				}
			}
			
			System.out.println("Case #" + i + ": " + max);
			
			i++;
		}
		
		
	}
	
}

