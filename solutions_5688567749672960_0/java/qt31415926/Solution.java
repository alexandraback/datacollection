import java.io.*;
import java.util.*;


class Solution{

	public static int reverse(int N){
		String input = Integer.toString(N);
		input = new StringBuilder(input).reverse().toString();
//		System.out.println(input + " " + N);
		return Integer.parseInt(input);
	}

	private static int[] memo = new int[10000000];

	public static int solve(int target){
		for (int N = 1; N <= target; N++){
			if (reverse(N)<N && N==reverse(reverse(N))){
	//		System.out.println(memo[N] + " " + memo[reverse(N)]);
				memo[N] = Math.min(memo[N-1]+1, memo[reverse(N)]+1);
			} else {
	//			System.out.println(N + ": " + memo[N]);
				memo[N] = memo[N-1]+1;
			}
		}
//		System.out.println("Target: " + target + " Answer: " + memo[target]);
		return memo[target];
	}

	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try{
			int Tcases =Integer.parseInt(br.readLine().trim());
			for (int i = 0 ; i < Tcases; i++){
				int N = Integer.parseInt(br.readLine().trim());
				memo = new int[10000000];
				for (int j = 1; j < 21; j++){
					memo[j]=j;
				}
				String answer = Integer.toString(solve(N)); 
				System.out.format("Case #%d" + ": %s\n", i+1, answer);
			}
		}catch (IOException e){
			System.out.println(e.getStackTrace());
		}
	}
}
