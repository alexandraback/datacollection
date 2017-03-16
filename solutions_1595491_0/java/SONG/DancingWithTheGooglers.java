import java.io.*;
import java.util.*;

public class DancingWithTheGooglers {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static Scanner sc = new Scanner(br);

    public static void main ( String [] args ) throws IOException
    {
	int N = Integer.parseInt(br.readLine());

	for(int i = 0;i < N; i++) {
	    System.out.print("Case #" + (i+1) + ": ");
	    new DancingWithTheGooglers().cal();
	}
    }



    private void cal() throws IOException 
    {
    	int ret = 0;
    	
    	int number = sc.nextInt();
    	int[] numberArray = new int[number];
    	
    	int surprising = sc.nextInt();
    	int p = sc.nextInt();
    	
    	
    	int sDeadLine = p*3-4;
    	int deadLine = p*3-2;
    	if (p == 0){
    		sDeadLine = 100;
    		deadLine = 0;
    	}
    	if (p == 1){
    		sDeadLine = 100;
    		deadLine = 1;
    	}
    	
    	boolean[] okay = new boolean[number];
    	boolean[] sOkay = new boolean[number];

    	int okayCounter = 0, sOkayCounter = 0;
    	
    	
    	for(int i = 0; i < number; i++){
    		numberArray[i] = sc.nextInt();
    		if (numberArray[i] >= deadLine){
    			okay[i] = true; okayCounter++;
    			sOkay[i] = true; sOkayCounter++;
    		} else if( numberArray[i] >= sDeadLine ){
    			okay[i] = false;
    			sOkay[i] = true; sOkayCounter++;
    		} else {
    			okay[i] = false;	
    			sOkay[i] = false;
    		}
    	}
    	
    	ret = okayCounter;
    	ret += (sOkayCounter - okayCounter) > surprising? surprising : (sOkayCounter - okayCounter);   
    		
    	System.out.println(ret);
    	

    }

}


