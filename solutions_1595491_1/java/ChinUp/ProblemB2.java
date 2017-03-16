package QualificationB;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;

public class ProblemB2 {
	
	
	
	public static void main(String args[]) throws Exception{
//		System.out.println(args[0]);
		FileReader fr = new FileReader(args[0]);
		BufferedReader br = new BufferedReader(fr);	
		
		int T = Integer.parseInt(br.readLine());
		
//		System.out.println(T);
		for(int t=0;t<T;t++) {
			int result = 0;
			
			String question = br.readLine();
			String[] qarray = question.split(" ");
			int N = Integer.parseInt(qarray[0]);
			int sp = Integer.parseInt(qarray[1]);
			int p = Integer.parseInt(qarray[2]);
			int[] array = new int[N];
			for(int i=0;i<N;i++) {
				array[i] = Integer.parseInt(qarray[i+3]);
			}
			
//			System.out.println("N: " + N);
//			System.out.println("sp: " + sp);
//			System.out.println("p: " + p);
//			System.out.println("Array: " + Arrays.toString(array));
			
			int mintotal = 3 * p - 2;
			int surprisetotal = 3 * p - 4;
			
			for(int i=0; i < N; i++) {
				int total = array[i];
				if(p == 0) {
					result++;
				}else if (total == 0 & p == 1){
					continue;
				} else if(total >= mintotal) { 
					result++;
				} else if (total >= surprisetotal && sp > 0) {
					result++;
					sp--;
				} else {
					continue;
				}
			}
			System.out.println("Case #"+ (t+1) + ": " + result);
//			System.out.println("-----");
		}
	}
}
