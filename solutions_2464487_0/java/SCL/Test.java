import java.util.*;
import java.io.*;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
		int num = input.nextInt();
		for(int i = 0 ; i < num ; i++){
			long r = input.nextLong();
			long t = input.nextLong();
	        pw.print("Case #"+(i+1)+": "+radius(r,t));
	        pw.println();
		}
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static long radius(long r,long t){
    	long nowp = r*r;
    	long nowr = r;
    	long count = 0;
    	while(t > 0){
    		long req = (nowr+1)*(nowr+1)-nowp;
    		if(req > t)break;
    		t -= req;
    		count++;
    		nowr += 2;
    		nowp = nowr*nowr;
    	}
    	return count;
    }
}