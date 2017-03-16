import java.util.*;
import java.io.*;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/C-small-attempt.in"));
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
    	int num = 1;
    	ArrayList<Integer> list = new ArrayList<Integer>();
    	while(!Integer.toBinaryString(num).equals("100000000000000000000")){
    		String s = Integer.toBinaryString(num);
    		if(s.length() != 20){
    			int zerolen = 20-s.length();
    			String zero = "";
    			for(int i = 0 ; i < zerolen ; i++){
    				zero += "0";
    			}
        		s = zero+s;
    		}
    		//System.out.println(s);
    		int sum = 0;
        	ArrayList<Integer> prelist = new ArrayList<Integer>();
    		for(int i = 0 ; i < s.length(); i++){
    			if(s.charAt(i) == '1'){
    				sum+=number[i];
    				prelist.add(number[i]);
    				//System.out.println(sum+"sum"+i);
    			}
    		}
    		if(!list.contains(sum)){
    			list.add(sum);
    		}else{
    			for(int i = 0 ; i < list.size(); i++){
    				if(list.get(i) == sum){
    					String nums = Integer.toBinaryString(i+1);
    		    		if(nums.length() != 20){
    		    			int zerolen = 20-nums.length();
    		    			String zero = "";
    		    			for(int j = 0 ; j < zerolen ; j++){
    		    				zero += "0";
    		    			}
    		        		nums = zero+nums;
    		    		}
    			    	ArrayList<Integer> kakolist = new ArrayList<Integer>();
    					for(int j = 0 ; j < nums.length() ; j++){
    						if(nums.charAt(j) == '1'){
    							kakolist.add(number[j]);
    						}
    					}
    					for(int j = 0 ; j < prelist.size(); j++){
    						if(j != prelist.size()-1){
    							pw.print(prelist.get(j)+" ");
    						}else{
    							pw.println(prelist.get(j));
    						}
    					}
    					for(int j = 0 ; j < kakolist.size(); j++){
    						if(j != kakolist.size()-1){
    							pw.print(kakolist.get(j)+" ");
    						}else{
    							pw.println(kakolist.get(j));
    						}
    					}
    					break;
    				}
    			}
    			break;
    		}
    		num++;
    	}
    }
}
