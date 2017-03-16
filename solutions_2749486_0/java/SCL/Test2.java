import java.util.*;
import java.io.*;

public class Test2 {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
		int num = input.nextInt();
		for(int i = 0 ; i < num ; i++){
			int x = input.nextInt();
			int y = input.nextInt();
			//System.out.println(s);
	        pw.print("Case #"+(i+1)+": "+radius(x,y));
	        pw.println();
			pw.flush();
		}
		input.close();
		pw.close();
	}
	    	
    public static String radius(int x,int y){
    	StringBuilder sb = new StringBuilder();
    	int stx = 0;
    	int sty = 0;
    	int index = 1;
    	boolean ms = false;
    	if(x < 0){
    		ms = true;
    	}
    	while(x != stx){
    		if(ms){
    			if(index % 2 == 1){
    				stx += index;
    				sb.append("E");
    			}else{
    				stx -= index;
    				sb.append("W");
    			}
    		}else{
    			if(index % 2 == 1){
    				stx -= index;
    				sb.append("W");
    			}else{
    				stx += index;
    				sb.append("E");
    			}
    		}
    		index++;
    	}
    	ms = false;
    	if(y < 0){
    		ms = true;
    	}
    	while(y != sty){
    		if(ms){
    			if(index % 2 == 1){
    				sty += index;
    				sb.append("N");
    			}else{
    				sty -= index;
    				sb.append("S");
    			}
    		}else{
    			if(index % 2 == 1){
    				sty -= index;
    				sb.append("S");
    			}else{
    				sty += index;
    				sb.append("N");
    			}
    		}
    		index++;
    	}
    	return sb.toString();
    }
}