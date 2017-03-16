import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List; 

public class solver{
 
	public static void main (String args[]) {
	try{
		BufferedReader br = 
                      new BufferedReader(new InputStreamReader(System.in));
 
		String input;
		int T = 0;
		int index = 0;
		while((input=br.readLine())!=null){
			if(T == 0){
				T = Integer.parseInt(input);
			}else{
				String[] problemVars = input.split(" ");
				int X = Integer.parseInt(problemVars[0]);
				int R = Integer.parseInt(problemVars[1]);
				int C = Integer.parseInt(problemVars[2]);

			    Boolean res = true;
			    
			    if(X >= 7){
			    	res = false;
			    }else if(X > R && X > C){
			    	res = false;
			    }else if(R * C % X != 0){
			    	res = false;
			    }else if ((X + 1) / 2 > Math.min(R,C)){ // 2 > min(R, C):
			    	res = false;
			    }else if(Arrays.asList(new int[]{1,2,3}).contains(X)){
			    	res = true;
			    }else if(X == 4){
			    	res = Math.min(R, C) > 2;
			    }else if(X == 5){
			    	res = !(Math.min(R, C) == 3 && Math.max(R, C) == 5);
			    }else if(X == 6){
			    	res = Math.min(R, C) > 3;
			    }

			    System.out.println("Case #" + (index + 1)+": "+(res?"GABRIEL":"RICHARD"));
			    index++;
			}
			
		}
 
	}catch(IOException io){
		io.printStackTrace();
	}	
  }
}