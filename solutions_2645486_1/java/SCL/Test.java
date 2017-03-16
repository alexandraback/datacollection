import java.util.*;
import java.io.*;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/B-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
		int num = input.nextInt();
		for(int i = 0 ; i < num ; i++){
			int E = input.nextInt();
			int R = input.nextInt();
			int N = input.nextInt();
			int[] vi = new int[N];
			for(int j = 0 ; j < N ; j++){
				vi[j] = input.nextInt();
			}
	        pw.print("Case #"+(i+1)+": "+radius(E,R,N,vi));
	        pw.println();
			pw.flush();
		}
		input.close();
		pw.close();
	}
	    	
    public static long radius(int E,int R,int N,int[] vi){
    	if(R >= E){
    		long sum = 0;
    		for(int i = 0 ; i < vi.length ; i++){
    			sum += vi[i];
    		}
    		return sum * E;
    	}else{
    		long sum = 0;
    		int ME = E;
    		for(int i = 0 ; i < vi.length ; i++){
    			int vnum = vi[i];
    			long count = E;
    			boolean last = true;
    			for(int j = i+1 ; j < vi.length ; j++){
    				count += R;
    				if(count >= ME*2 || vnum < vi[j]){
    					last = false;
    					break;
    				}
    			}
    			if(count >= ME*2 || last){
    				sum += (long)E*vnum;
    				E = 0;
    			}else if(count > ME){
    				sum += (long)(count-ME)*vnum;
    				E -= (count-ME);
    			}
    			E += R;
    		}
    		return sum;
    	}
    }
}