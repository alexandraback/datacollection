import java.util.*;
import java.io.*;
import java.math.BigDecimal;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
		ArrayList<Long> lst = new ArrayList<Long>();
		for(int i = 1 ; i <= 1000 ; i++){
			long lt = i*i;
			String l = String.valueOf(lt);
			String ii = String.valueOf(i);
			StringBuilder lb = new StringBuilder(ii);
			StringBuilder sb = new StringBuilder(l);
			if(sb.reverse().toString().equals(l) && lb.reverse().toString().equals(ii))lst.add(lt);
		}
		
        int n = input.nextInt();
        for(int i = 0 ; i < n ; i++){
        	int A = input.nextInt();
        	int B = input.nextInt();
            pw.print("Case #"+(i+1)+": "+win(A,B,lst));
            pw.println();
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static int win(int A,int B,ArrayList<Long> lst){
    	int sum = 0;
    	for(int i = 0 ; i < lst.size(); i++){
    		if(A <= lst.get(i) && lst.get(i) <= B){
    			sum++;
    		}else{
    			//break;
    		}
    	}
    	return sum;
    }
}