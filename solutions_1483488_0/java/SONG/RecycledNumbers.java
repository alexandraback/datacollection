import java.io.*;
import java.util.*;

public class RecycledNumbers {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static Scanner sc = new Scanner(br);

    public static void main ( String [] args ) throws IOException
    {
    	int N = Integer.parseInt(br.readLine());

		for(int i = 0;i < N; i++) {
			System.out.print("Case #" + (i+1) + ": ");
			new RecycledNumbers().cal();
		}
    }	



    private void cal() throws IOException 
    {
    	int A = sc.nextInt();
    	int B = sc.nextInt();
    	
    	String aString = Integer.toString(A);
    	int length = aString.length();
    	
    	String testString;
    	String testTemp;
    	int checkingNumber;
    	int counter = 0;
    	boolean check = false;
    	
    	
    	for(checkingNumber = A; checkingNumber < B; checkingNumber++ ){
        	int[] stack = new int[length-1];
    		testString = Integer.toString(checkingNumber);
    		check = true;
    		for(int i = 0; i < length-1; i++ ){
    		
    			testTemp = testString.substring(1, length) + testString.substring(0, 1);
    			testString = testTemp;
    		
    			if( checkingNumber < Integer.parseInt(testString)){
    				if( Integer.parseInt(testString) <= B ){
    					for(int k = 0; k < i; k++)
    						if( stack[k] == Integer.parseInt(testString) ) check = false;
    					if(check){
    						counter++;
    						//System.out.println(checkingNumber + " " + testString+ " "+ counter);
    						stack[i] = Integer.parseInt(testString);
    					}
    				}
    			}
    		}
    		
    		
    	}
    	
    	System.out.println(counter);
    	
    		
    }

}


