import java.util.*;
import java.io.*;

public class Test2 {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/A-small-attempt3.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
		int num = input.nextInt();
		for(int i = 0 ; i < num ; i++){
			String s = input.next();
			int n = input.nextInt();
			//System.out.println(s);
	        pw.print("Case #"+(i+1)+": "+radius(s,n));
	        pw.println();
			pw.flush();
		}
		input.close();
		pw.close();
	}
	    	
    public static long radius(String s,int n){
    	long sum = 0;
    	int stindex = 0;
    	int enindex = 0;
    	int st2index = 0;
    	int en2index = 0;
    	int stlength = s.length();
    	while(true){
    		boolean isok = false;
	    	for(int i = stindex ; i < s.length() ; i++){
	    		//System.out.println(i);
	    		if(s.charAt(i) == 'a' || s.charAt(i) == 'i' || s.charAt(i) == 'u' || s.charAt(i) == 'e' || s.charAt(i) == 'o'){
	    			stindex = -1;
	    			enindex = -1;
	    		}else{
	    			if(stindex == -1){
	    				stindex = i;
	    				enindex = i;
	    			}else{
	    				enindex = i;
	    			}
	    		}
	    		if(stindex != -1 && enindex != -1 && enindex-stindex+1 == n){
	    			isok = true;
	    			break;
	    		}
	    	}
	    	
	    	if(!isok)break;
	    	st2index = stindex+1;
	    	boolean last = true;
	    	for(int i = st2index ; i < s.length() ; i++){
	    		if(s.charAt(i) == 'a' || s.charAt(i) == 'i' || s.charAt(i) == 'u' || s.charAt(i) == 'e' || s.charAt(i) == 'o'){
	    			st2index = -1;
	    			en2index = -1;
	    		}else{
	    			if(st2index == -1){
	    				st2index = i;
	    				en2index = i;
	    			}else{
	    				en2index = i;
	    			}
	    		}
	    		if(st2index != -1 && en2index != -1 && en2index-st2index+1 == n){
	    			last = false;
	    			break;
	    		}
	    	}
	    	
	    	if(!last){
	    		sum += (stindex+1)*(en2index-enindex);
		    	//System.out.println(stindex+","+enindex+","+st2index+","+en2index+","+sum);
		    	stindex++;
	    	}else{
	    		sum += (stindex+1)*(stlength-enindex);
	    		//System.out.println(stindex+","+enindex+","+st2index+","+en2index+","+sum);
	    		break;
	    	}
    	}
    	return sum;
    }
}