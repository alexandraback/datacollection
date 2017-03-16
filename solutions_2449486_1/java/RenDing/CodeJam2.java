import java.io.*;
import java.util.*;

public class CodeJam2 {
	
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
	    		String result = "NO";
	    		line = bufreader.readLine();
	    		String[] splitLine = line.split(" ");
    			int n = Integer.parseInt(splitLine[0]);
    			int m = Integer.parseInt(splitLine[1]);
    			
    			//if n or m == 1, result is YES
    			if(n == 1 || m == 1) {
    				result = "YES";
    				for(int pN = 0; pN < n; pN ++) bufreader.readLine();
    			} else {
	    			int [][] arr = new int[n][m];	//height data matrix
	    			boolean[][] bArr = new boolean[n][m];	//can cut or not matrix
	    			for(int p = 0;p < n;p++)
	    				Arrays.fill(bArr[p], false);
	    			
	    			//read data from file, store them into an n*m array
	    			for(int pN = 0; pN < n; pN ++) {
	    				line = bufreader.readLine();
	    				String[] nLine = line.split(" ");
	    				for(int pM = 0; pM < m; pM++) {
	    					arr[pN][pM] = Integer.parseInt(nLine[pM]);
	    					
	    				}
	    			}
	    			
	    			
	    			//horizontal scanning
	    			for(int pN = 0; pN < n; pN ++) {
	    				for(int pM = 0; pM < m; pM++) {
							int tempMax = arr[pN][0];
							for(int k = 0; k < m; k++) {
								if(arr[pN][k] > tempMax) tempMax = arr[pN][k];
							}
							for(int k = 0; k < m; k++) {
								if(tempMax == arr[pN][k])	bArr[pN][k] = true;
							}
	    				}
	    			}
	    			
	    			//vertical scanning
	    			for(int pM = 0; pM < m; pM++) {
	    				for(int pN = 0; pN < n; pN ++) {
	    					int tempMax = arr[0][pM];
	    					for(int k = 0; k < n; k++) {
	    						if(arr[k][pM] > tempMax) tempMax = arr[k][pM];
	    					}
	    					for(int k = 0; k < n; k++) {
	    						if(tempMax == arr[k][pM])	bArr[k][pM] = true;
	    					}
	    				}
	    			}
	    			
	    			//check if it can be cuted
	    			boolean testRes = true;
	    			for(int pN = 0; pN < n; pN ++) {
	    				for(int pM = 0; pM < m; pM++) {
	    					if(testRes) {
	    						if(!bArr[pN][pM]) testRes = false;
	    					}
	    				}
	    			}
	    			
	    			if(testRes == true) result = "YES";
    			}
    			
	    		int printNumCase = i + 1;
	   			System.out.println("Case #"+printNumCase+": " + result);
	    	}
        } catch(IOException e1) {
        	System.out.println("An IO error occurs when read line");
        }
	}
}