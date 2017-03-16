import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class B2013 {

	/**
	 * @param args
	 */
	public static void main(String args[]){
		Scanner scn = new Scanner(System.in);
		int T = scn.nextInt();
		int M = 0;
		int N = 0;
		for(int t = 1;t<=T;t++){
			M = scn.nextInt();
			N = scn.nextInt();
			
			Set<Integer> numbers = new HashSet<Integer>();
			
			int lawn[][] = new int[M][N];
			
			for(int i=0;i<M;i++){
				for(int j=0;j<N;j++){
					lawn[i][j] = scn.nextInt();
					numbers.add(lawn[i][j]);
				}
			}
			
			List<Integer> numList = new ArrayList<Integer>();
			numList.addAll(numbers);
			
			Collections.sort(numList);
			
			
			boolean valid = true;
			outerloop:
			for(int z = numList.size()-2;z>=0;z--){
				int val = numList.get(z);
				
				for(int i=0;i<M;i++){
					for(int j=0;j<N;j++){
						if(lawn[i][j]==val){
							boolean row = true;
							boolean column = true;
							for(int k=0;k<N;k++){
								if(lawn[i][k]>val)
									row = false;
							}
							
							for(int k=0;k<M;k++){
								if(lawn[k][j]>val)
									column = false;
							}
							
							if(row == false && column == false){
								valid = false;
								break outerloop;
							}
						}
					}
				}
				
			}
			
			if(valid)
				System.out.println("Case #" + t +": YES");
			else
				System.out.println("Case #" + t +": NO");

		}
	}

}
