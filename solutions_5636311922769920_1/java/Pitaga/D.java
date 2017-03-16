import java.util.*;
import java.io.*;

public class D {
	
	public static void main(String[] args) throws IOException {
		
		
		Scanner qwe = new Scanner(new File("D.in"));
		PrintWriter out = new PrintWriter("D.out");
				
		int T = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			
			int K = qwe.nextInt();
			int C = qwe.nextInt();
			int S = qwe.nextInt();
			
			out.print("Case #"+cse+":");
			
			if((K+C-1)/C > S){
				out.println(" IMPOSSIBLE");
			}
			else{
				
				long[] pows = new long[C+1];
				pows[0] = 1;
				for (int i = 1; i < pows.length; i++) {
					pows[i] = pows[i-1]*K;
				}
				
				ArrayDeque<Integer> dq = new ArrayDeque<Integer>();
				for (int i = 0; i < K; i++) {
					dq.add(i);
				}
				
				while(!dq.isEmpty()){
					
					int[] nums = new int[C]; 
					for(int i =0; i < C && !dq.isEmpty(); i++){
						nums[i] = dq.poll();
					}
					
					long toprint = 0;
					for (int i = 0; i < nums.length; i++) {
						
						//System.out.println(pows[i] + " times " + nums[i]);
						
						toprint += pows[i]*nums[i];
					}
					
					//System.out.println();
					
					
					out.print(" "+(toprint+1));
					
				}
				
				
				out.println();
			}
			
						
		}
		
		
		out.close();
		qwe.close();
	}

}
