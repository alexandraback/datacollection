import java.util.*;
import java.io.*;

public class Test {

	public void doMain() throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/C-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
        int n = input.nextInt();
        for(int i = 0 ; i < n ; i++){
            int A = input.nextInt();
            int B = input.nextInt();
            boolean[] ispaired = new boolean[B+1];
            pw.println("Case #"+(i+1)+": "+num(A,B,ispaired));
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static int num(int A,int B,boolean[] ispaired){
    	int count = 0;
    	for(int i = A ; i <= B ; i++){
    		StringBuilder sb = new StringBuilder(i+"");
    		boolean same = false;
    		ispaired[i] = true;
    		while(!same){
    			sb.append(sb.charAt(0));
    			sb.deleteCharAt(0);
    			if(Integer.parseInt(sb.toString()) == i){
    				same = true;
    			}else if(A <= Integer.parseInt(sb.toString()) && Integer.parseInt(sb.toString()) <= B && sb.charAt(0) != '0' && !ispaired[Integer.parseInt(sb.toString())]){
    				count++;
    			}
    		}
    	}
    	return count;
    }
	
	public static void main(String[] args) throws Exception{
		(new Test()).doMain();
	}	
	
	
}
