import java.util.*;
import java.io.*;
import java.math.BigDecimal;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
        int n = input.nextInt();
        for(int i = 0 ; i < n ; i++){
        	int row = input.nextInt();
        	int col = input.nextInt();
        	int[][] rawn = new int [row][col];
        	for(int j = 0 ; j < row ; j++){
        		for(int k = 0 ; k < col ; k++){
        			rawn[j][k] = input.nextInt();
        		}
        	}
            pw.print("Case #"+(i+1)+": "+win(row,col,rawn));
            pw.println();
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static String win(int row,int col,int[][] rawn){
    	boolean[] isnum = new boolean[100];
    	for(int i = 0 ; i < row ; i++){
    		for(int j = 0 ; j < col ; j++){
    			isnum[rawn[i][j]-1] = true;
    		}
    	}
    	for(int i = 0 ; i < isnum.length ; i++){
    		if(isnum[i]){
    			for(int j = 0 ; j < row ; j++){
    				for(int k = 0 ; k < col ; k++){
    					if(rawn[j][k] == (i+1)){
    						if(!hantei(j,k,rawn,(i+1),row,col))return "NO";
    					}
    				}
    			}
    		}
    	}
    	return "YES";
    }
    
    public static boolean hantei(int j,int k,int[][] rawn,int len,int row,int col){
    	boolean rok = true;
    	boolean cok = true;
    	for(int i = 0 ; i < col ; i++){
    		if(rawn[j][i] > len){
    			rok = false;
    			break;
    		}
    	}
    	
    	for(int i = 0 ; i < row ; i++){
    		if(rawn[i][k] > len){
    			cok = false;
    			break;
    		}
    	}
    	if(rok || cok){
    		return true;
    	}else{
    		return false;
    	}
    }

}