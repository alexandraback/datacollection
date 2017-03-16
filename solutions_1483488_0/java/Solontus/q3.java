import java.io.*;
import java.util.*;
public class q3{
    
    public static int fact(int t){
	int result = 1;
	if(t < 1)
	    return 0;
	for(int i = 1; i <= t; i++){
	    result *= i;
	}
	return result;
    }
	    
    
    public static int choose(int n, int m){
	if(m > n)
	    return 0;
	if(m == n)
	    return 1;
	int result = fact(n)/(fact(m) * fact(n-m));
	return result;
    }
	
    
    public static int shift(int num){
	String intNum = Integer.toString(num);
	String shifted = intNum.substring(1) + intNum.substring(0,1);
	int shiftedNum = Integer.parseInt(shifted);
	return shiftedNum;
    }
    
    public static String shiftS(String num){
	String shifted = num.substring(1) + num.substring(0,1);
	return shifted;
    }
    
    
    public static void main (String[] args) throws IOException 
    {
	BufferedReader input = new BufferedReader (new FileReader ("C-small-attempt0.txt"));
	PrintWriter output = new PrintWriter (new FileWriter("test3Done.out"));
	StringTokenizer st;
	
	int numLines = Integer.parseInt(input.readLine());
	for(int i = 0; i < numLines; i++){
	    st = new StringTokenizer(input.readLine());
	    int A = Integer.parseInt(st.nextToken());
	    int B = Integer.parseInt(st.nextToken());
	    int counter = 0;
	    
	    boolean [] numbers = new boolean[B+1];
	    
	    for(int j = 0; j < B+1; j++){
		numbers[j] = true;
	    }
	    
	    for(int j = A ; j < B + 1; j++){
		int uniqueR = 0;
		if(numbers[j]){
		    String currNumS = Integer.toString(j);
		    int currNum = j;
		    numbers[j] = false;
		    for(int k = 0; k < Integer.toString(j).length() - 1; k++){
			if(Integer.parseInt(shiftS(currNumS)) <= B && Integer.parseInt(shiftS(currNumS)) >= A && shiftS(currNumS).charAt(0) != '0'){
			    if(numbers[Integer.parseInt(shiftS(currNumS))]){
				uniqueR ++;
				numbers[Integer.parseInt(shiftS(currNumS))] = false;
			     }
			}
			currNumS = shiftS(currNumS);
		    }
		    counter += choose(uniqueR+1,2);
		}
	    }
	    
	    output.println("Case #" + (i+1) + ": " + counter);
	}
	output.close();
    }
}
			     
			    
			
	    
	    
	    
	    
