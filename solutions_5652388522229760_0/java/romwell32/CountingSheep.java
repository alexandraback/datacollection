import java.util.Scanner;

public class CountingSheep {

	public static boolean is_all_true(boolean[] arr){
		for (boolean b : arr){
			if (!b) { return false;}
		}
		return true;
	}
	
	
	public static long last_num(long n){
		long ans  = 0;
		boolean[] dig = new boolean[10]; 
		boolean found = false;
		long N = 0;
		while (!found){
			ans++;
			N = n * ans;			
			while (N>0){				
				int d = (int) N % 10;				
				dig[d] = true;
				N = N / 10;
			}
			if (is_all_true(dig)){
				found = true;				
			}
		}
		return ans*n;		
	}
	
	
	public static void main(String [] args){		 
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i=0; i<T; i++){
			int n = sc.nextInt();
			System.out.println("Case #" + (i+1) +": " + (n == 0 ? "INSOMNIA" : last_num(n)));
		}
	}
	
	
}
