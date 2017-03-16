import java.util.*;
import java.io.*;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/C-small-1-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
		int T = input.nextInt();
		int R = input.nextInt();
		int N = input.nextInt();
		int M = input.nextInt();
		int K = input.nextInt();
        pw.println("Case #1:");
		for(int i = 0 ; i < R ; i++){
			int[] vi = new int[K];
			for(int j = 0 ; j < vi.length ; j++){
				vi[j] = input.nextInt();
			}
			pw.println(radius(N,M,K,vi));
			pw.flush();
		}
		input.close();
		pw.close();
	}
	    	
    public static String radius(int N,int M,int K,int[] vi){
    	int[] counter = new int[4];//2 3 4 5
    	for(int i = 0 ; i < vi.length ; i++){
    		int ni = 0;
    		int san = 0;
    		int yon = 0;
    		int go = 0;
    		while(vi[i] != 1){
    			if(vi[i] % 4 == 0){
    				yon++;
    				vi[i] /= 4;
    			}else if(vi[i] % 3 == 0){
    				san++;
    				vi[i] /= 3;
    			}else if(vi[i] % 5 == 0){
    				go++;
    				vi[i] /= 5;
    			}else if(vi[i] % 2 == 0){
    				ni++;
    				vi[i] /= 2;
    			}
    		}
    		if(ni > counter[0])counter[0] = ni;
    		if(san > counter[1])counter[1] = san;
    		if(yon > counter[2])counter[2] = yon;
    		if(go > counter[3])counter[3] = go;
    	}
    	String st = "";
    	while(counter[0] != 0){
    		st += "2";
    		counter[0]--;
    	}
    	while(counter[1] != 0){
    		st += "3";
    		counter[1]--;
    	}
    	while(counter[2] != 0){
    		st += "4";
    		counter[2]--;
    	}
    	while(counter[3] != 0){
    		st += "5";
    		counter[3]--;
    	}
    	if(st.length() == N){
    		return st;
    	}else{
    		for(int i = st.length(); i < N ; i++){
    			st += "2";
    		}
    		return st;
    	}
    }
}