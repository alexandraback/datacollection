package fractiles;

import java.util.*;

public class LargeSolution {

	public static void getTileIndices(int K, int C, int S){
				
		int minNum = (int)(Math.ceil(K*1.0/C));
		if(S<minNum){
			System.out.println(" IMPOSSIBLE");
			return;
		}
		
		for(int index=1;index<=K;index = index+C){
			int endIndex = index+C-1;
			if(endIndex>K){
				endIndex = K;
			}
			long tileIndex = getTileIndex(K, C, index, endIndex);
			System.out.printf(" %d", tileIndex);
		}		
		System.out.println();
		return;
	}
	
	public static long getTileIndex(int K, int C, int start, int end){
		long maxLength = (long)(Math.pow(K, C));		
		long tileIndex = 1;
		
		long multiple = maxLength/K;
		int index = start;
		for(int i=start;i<start+C;i++){
			if(i<=end){
				index = i;
			}
			tileIndex += (index-1)*multiple;
			multiple = multiple/K;
		}
		
		return tileIndex;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		int K = 2;
		int C = 3;
		int start = 1;
		int end = 2;
		long tileIndex = LargeSolution.getTileIndex(K, C, start, end);
		System.out.println(tileIndex);
		*/
				
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			int K = scan.nextInt();
			int C = scan.nextInt();
			int S = scan.nextInt();
			System.out.printf("Case #%d:", i);
			LargeSolution.getTileIndices(K, C, S);
			
		}
		
		scan.close();
		
	}

}
