import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Round1C {

	

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();
	   
	    
	    for (int i = 0; i<t; i++){
	    	int b = in.nextInt();
	    	int m = in.nextInt();
	    	
	    	int[][] problem = new int[b][b];
	    	
	    	if(m<=Math.pow(2, (b-2))){


	    		for (int k = 1, times = 0 ; times < m ; k += 2, times++){
	    			long number = (long) Math.pow(2, b-1) + k;
	    			String sequency = Long.toString(number, 2);
	    			char[] sequencychar = sequency.toCharArray();
	    			int position = 0;
	    			for (int z = 1; z < sequencychar.length; z++){
	    				if(sequencychar[z] == '1'){
	    					problem[position][z] = 1;
	    					position = z;
	    				}
	    			}
	    		}
	    		
	    		System.out.print("Case #" + (i+1) + ": POSSIBLE");
	    		for (int k = 0; k< b ; k++){
	    			System.out.println();
	    			for (int z = 0; z < b; z++){
	    				System.out.print(problem[k][z]);
	    			}
	    		}
	    		System.out.println();
	    		
	    	}else{
	    		System.out.println("Case #" + (i+1) + ": IMPOSSIBLE");
	    	}
	    	
	    	
	
	    }
	}
}
