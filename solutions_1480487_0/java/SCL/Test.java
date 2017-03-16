import java.util.*;
import java.io.*;
import java.math.BigDecimal;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/A-small-attempt6.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
        int n = input.nextInt();
        for(int i = 0 ; i < n ; i++){
        	int n2 = input.nextInt();
        	int[] number = new int[n2];
        	for(int j = 0 ; j < number.length ; j++){
        		number[j] = input.nextInt();
        	}
            pw.println("Case #"+(i+1)+":");
            num(n2,number,pw);
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static void num(int n,int[] number,PrintWriter pw){
    	double sum = 0;
    	double max = 0;
    	double min = 9999999;
    	int minindex = -1;
    	double minnext = 9999999;
    	for(int i = 0 ; i < number.length ; i++){
    		sum += number[i];
    		max = Math.max(max, number[i]);
    		if(min >= number[i]){
    			if(min != 9999999){
    				minnext = min;
    			}
    			min = number[i];
    			minindex = i;
    		}
    	}
    	double need = (double)sum*2/(double)number.length;
    	if(need >= max){
    	for(int i = 0 ; i < number.length ; i++){
    		if(i != number.length-1){
    			if((double)(need-number[i])*100/sum >= 0){
    				BigDecimal bd = new BigDecimal((double)(need-number[i])*100/sum);
    				BigDecimal bd4 = bd.setScale(6, BigDecimal.ROUND_HALF_UP);
    				pw.print(bd4+" ");
    			}else{
    				pw.print("0.000000"+" ");
    			}
    		}else{
    			if((double)(need-number[i])*100/sum >= 0){
    				BigDecimal bd = new BigDecimal((double)(need-number[i])*100/sum);
              	    BigDecimal bd4 = bd.setScale(6, BigDecimal.ROUND_HALF_UP);
        			pw.println(bd4);
    			}else{
    				pw.println("0.000000");
    			}
    		}
    	}
    	}else{
    		double kahan = sum/(number.length-1);
        	for(int i = 0 ; i < number.length ; i++){
    		if(i != number.length-1){
    			if(number[i] < kahan){
    				BigDecimal bd = new BigDecimal((double)(kahan-number[i])*100/sum);
    				BigDecimal bd4 = bd.setScale(6, BigDecimal.ROUND_HALF_UP);
    				pw.print(bd4+" ");
    			}else{
    				pw.print("0.000000"+" ");
    			}
    		}else{
    			if(number[i] < kahan){
    				BigDecimal bd = new BigDecimal((double)(kahan-number[i])*100/sum);
              	    BigDecimal bd4 = bd.setScale(6, BigDecimal.ROUND_HALF_UP);
        			pw.println(bd4);
    			}else{
    				pw.println("0.000000");
    			}
    		}
        	}
    	}
    }
}