package QualificationB;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;

public class ProblemB {
	
	
	
	public static void main(String args[]) throws Exception{
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
//			System.out.println("-----");
			
			for(int i=0; i < N; i++) {
				int total = array[i];
				
				if(p == 0) { 
					result++;
				}
				
				else if((total/p) >= 3) {
					result++;
				} else if (total < p) {
					continue;
				} else {
					int a = (total - p) / 2;

					int dif = (p - a);
					if(dif > 2) {
						// impossible
					} else if(dif == 2) {
						if(sp > 0) {
							result++;
							sp--;
						}
					} else {
						result++;
					}
				}

			}
			System.out.println("Case #"+ (t+1) + ": " + result);
		}
	}
}
