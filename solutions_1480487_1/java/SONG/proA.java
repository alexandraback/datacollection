import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class proA {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
    private static Scanner sc = new Scanner(br);

    public static void main ( String [] args ) throws IOException
    {
	int N = Integer.parseInt(br.readLine());

	for(int i = 0;i < N; i++) {
	    System.out.print("Case #" + (i+1) + ":");
	    new proA().cal();
	}
    }



    private void cal() throws IOException 
    {
    	int num = sc.nextInt();
    	
    	int[] pointString = new int[num];
    	int sum = 0;
    	
    	for(int i=0; i< num; i++ ){
    		pointString[i] = sc.nextInt();
    		sum += pointString[i];
    	}
    	
    	double[] x = new double[num];
    	int count = 0;
    	int extraSum = 0;
    	boolean check = false;
    	
        String pattern = "#####.######";

        DecimalFormat dformat = new DecimalFormat( pattern );

    	for(int i=0; i< num ; i++){
    		x[i] = (2/(double)num)*sum-pointString[i];
    		if(x[i]<0){
    			x[i] = 0;
    			check = true;
    		}
    		else {
    			x[i] = (x[i]/sum)*100;
    			extraSum += pointString[i];
    			count++;
    		}	
    	}
    	
    	if (check){
    	for(int i=0; i<num; i++){
    		if(x[i] != 0){
    			x[i] = (1/(double)count)*(sum+extraSum)-pointString[i];
    			x[i] = (x[i]/sum)*100;
    		}
    	}
    	}
    	
    	for(int i=0; i< num; i++){
    		System.out.print(" "+dformat.format(x[i]));
    	}
    	System.out.println();

    }

}


