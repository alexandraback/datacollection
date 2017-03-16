//package codeC;

import java.util.Scanner;

public class first {
	 public static void main(String[] args) {
	        Scanner sin = new Scanner(System.in);
	        int testNum = sin.nextInt();
	        for(int i = 1; i <= testNum; i++){
	            int R = sin.nextInt();
	            int C = sin.nextInt();
	            int W = sin.nextInt();
	            
	            //int x = getGaruntee(R, W, C);
	            int x1 = R * (C/W);
		         if(C % W > 0){
		             x1 = x1 + W;
		         }else{
		             x1= x1 + W - 1;
		         }
	            System.out.println("Case #"+i+": "+x1);
	            
	            
	        }
	    }
	     
	   
	 
	     
}
