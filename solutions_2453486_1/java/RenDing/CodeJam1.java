import java.io.*;
import java.util.*;

public class CodeJam1 {
	
	public static void main(String[] args) {
		FileReader reader = null;
        try {
        		reader = new FileReader(args[0]);
        } catch (FileNotFoundException fnf) {
        		System.out.println("The input file is not found");
        }
        
        BufferedReader bufreader = new BufferedReader(reader);
        String line = null;		//each line of the data
        
        //read the number of test cases
        try {
			line = bufreader.readLine();
		} catch (IOException e0) {
			System.out.println("An IO error occurs when read the number of test cases");
		}
        
        int numCase = Integer.parseInt(line);
        
        try {
	    	for(int i = 0;i < numCase;i++) {
	    		int resultInt = 4;
	    		boolean emptyCell = false;
	    		int[] arrX = new int[16];	//convert X and T to 1, put them into arrX
	    		int[] arrY = new int[16];	//convert Y and T to 1, put them into arrY
	    		Arrays.fill(arrX, 0);
	    		Arrays.fill(arrY, 0);
	    	
	    		//read data and convert them from char to integer
	    		line = bufreader.readLine();
	    		line += bufreader.readLine();
	    		line += bufreader.readLine();
	    		line += bufreader.readLine();
	    		for(int j = 0; j < 16; j++) {
	    			if(line.substring(j, j+1).equals("X")) arrX[j] = 1;
	    			else if(line.substring(j, j+1).equals("O")) arrY[j] = 1;
	    			else if(line.substring(j, j+1).equals("T")) {
	    				arrX[j] = 1;
	    				arrY[j] = 1;
	    			}

	    			else if(!emptyCell) {
	    				if(line.substring(j, j+1).equals(".")) emptyCell = true;
	    			}
	    		}
	    		
	    		//remove empty line
	    		line = bufreader.readLine();
	    		
	    		//X won
	    		if(arrX[0]+arrX[1]+arrX[2]+arrX[3] == 4
	    			|| arrX[4]+arrX[5]+arrX[6]+arrX[7] == 4
	    			|| arrX[8]+arrX[9]+arrX[10]+arrX[11] == 4
	    			|| arrX[12]+arrX[13]+arrX[14]+arrX[15] == 4
	    			|| arrX[0]+arrX[4]+arrX[8]+arrX[12] == 4
	    			|| arrX[1]+arrX[5]+arrX[9]+arrX[13] == 4
	    			|| arrX[2]+arrX[6]+arrX[10]+arrX[14] == 4
	    			|| arrX[3]+arrX[7]+arrX[11]+arrX[15] == 4
	    			|| arrX[0]+arrX[5]+arrX[10]+arrX[15] == 4
	    			|| arrX[3]+arrX[6]+arrX[9]+arrX[12] == 4
	    			)
	    			resultInt = 1;
	    		//Y won	
	    		else if(arrY[0]+arrY[1]+arrY[2]+arrY[3] == 4
		    			|| arrY[4]+arrY[5]+arrY[6]+arrY[7] == 4
		    			|| arrY[8]+arrY[9]+arrY[10]+arrY[11] == 4
		    			|| arrY[12]+arrY[13]+arrY[14]+arrY[15] == 4
		    			|| arrY[0]+arrY[4]+arrY[8]+arrY[12] == 4
		    			|| arrY[1]+arrY[5]+arrY[9]+arrY[13] == 4
		    			|| arrY[2]+arrY[6]+arrY[10]+arrY[14] == 4
		    			|| arrY[3]+arrY[7]+arrY[11]+arrY[15] == 4
		    			|| arrY[0]+arrY[5]+arrY[10]+arrY[15] == 4
		    			|| arrY[3]+arrY[6]+arrY[9]+arrY[12] == 4
		    			)
		    			resultInt = 2;	
	    		//Draw
	    		else if(!emptyCell) resultInt = 3;
	    		
	    		//display result
	    		int printNumCase = i+1;
	    		String result =  "";
	    		switch(resultInt) {
	    			case 1:
	   					result = "X won";
	   					break;
	   				case 2:
	   					result = "O won";
	   					break;
	   				case 3:
	   					result = "Draw";
	   					break;
	   				case 4:
	    				result = "Game has not completed";
	    				break;
	    		}
	   			System.out.println("Case #"+printNumCase+": " + result);
	    	}
        } catch(IOException e1) {
        	System.out.println("An IO error occurs when read line");
        }
	}
}