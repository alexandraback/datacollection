import java.io.*;
import java.util.*;

public class proA {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static Scanner sc = new Scanner(br);

    public static void main ( String [] args ) throws IOException
    {
	int N = Integer.parseInt(br.readLine());

	for(int i = 0;i < N; i++) {
	    System.out.print("Case #" + (i+1) + ": ");
	    new proA().cal();
	}
    }


    int classes;
	
	int[][] paths;
	int[] inherits;
	
	boolean[] ends;
	boolean yes;
	
    private void cal() throws IOException 
    {
    	classes = sc.nextInt();
    	
    	paths = new int[classes][];
    	inherits = new int[classes];
    	
    	for(int i=0; i < classes; i++){
    		inherits[i] = sc.nextInt(); //개
			paths[i] = new int[inherits[i]];
    		for(int j=0; j<inherits[i]; j++){
    			paths[i][j] = sc.nextInt()-1;
    		}
    	}
    	
    	
    	for(int i=0; i <classes; i++){
    		if(yes){
    			break;
    		}
    		ends = new boolean[classes];
    		next(i);
    	}
    	
    	if(yes){
    		System.out.println("Yes");
    	}
    	else{
    		System.out.println("No");
    	}

    }
    
    private void next(int sp) {
    	if(inherits[sp] == 0){
    		if(ends[sp]){
    			yes = true;
    		}
    		ends[sp]=true;
    		return; 
    	}
    	else{
    		for(int j=0; j < inherits[sp]; j++){
    			next(paths[sp][j]);
    		}
    	}
    }

}


