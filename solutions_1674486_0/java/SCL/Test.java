import java.util.*;
import java.io.*;
import java.math.BigDecimal;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/A-small-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
        int n = input.nextInt();
        for(int i = 0 ; i < n ; i++){
        	int n2 = input.nextInt();
        	boolean[][] con = new boolean[n2][n2];
        	for(int j = 0 ; j < n2 ; j++){
        		int r = input.nextInt();
        		for(int k = 0 ; k < r ; k++){
        			int l = input.nextInt();
        			con[j][l-1] = true;
        		}
        	}
            pw.println("Case #"+(i+1)+": "+num(n2,con));
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static String num(int n2,boolean[][] con){
    	Queue<Integer> q = new PriorityQueue<Integer>();
    	for(int k = 0 ; k < con.length ; k++){
    		q.add(k);
    		boolean[] isok = new boolean[n2];
    		isok[k] = true;
    		while(!q.isEmpty()){
    			int st = q.poll();
    			for(int i = 0 ; i < con[st].length ; i++){
    				if(con[st][i] == true){
    					if(isok[i] == true){
    						return "Yes";
    					}
    					q.add(i);
    					isok[i] = true;
    				}
    			}
    		}
    	}
    	return "No";
    }
}