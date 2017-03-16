import java.util.Scanner;


public class Main {
	
	public static long pow(long v, long p){
		long result = 1;
		for(long i = 0; i < p; ++i)
			result *= v;
		return result;
	}
	
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		long t = scanner.nextInt();
		for(int i = 1; i <= t; ++i){
			int k = scanner.nextInt();
			int c = scanner.nextInt();
			int s = scanner.nextInt();
			if(s * c < k){
				System.out.println("Case #"+i+": IMPOSSIBLE");
			}
			else{
				if(c >= k){
					long result = 1;
					for(long j = 1; j < k; ++j){
						result += j * pow(k, k - 1 - j);
					}
					System.out.println("Case #"+i+": " + result);
				}
				
				else{
					System.out.print("Case #"+i+":");
					long count = 0, result = 1;
					while(count < k){
						for(long j = 0; j < c && count < k; ++j){
							result += count * pow(k, c - j - 1);
							++count;
						}
						System.out.print(" " + result);
						result = 1;
					}
					System.out.println();
				}
			}
		}
	}
}
