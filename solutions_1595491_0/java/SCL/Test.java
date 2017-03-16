import java.util.*;
import java.io.*;

public class Test {

	public void doMain() throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
        int n = input.nextInt();
        for(int i = 0 ; i < n ; i++){
            int N = input.nextInt();
            int S = input.nextInt();
            int P = input.nextInt();
            int[] person = new int[N];
            for(int j = 0 ; j < N ; j++){
            	person[j] = input.nextInt();
            }
            pw.println("Case #"+(i+1)+": "+num(N,S,P,person));
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static int num(int N,int S,int P,int[] person){
    	Arrays.sort(person);
    	int mone = 0;
    	//int mtwo = 0;
    	int oks = 0;
    	int preoks = 0;
    	for(int i = 0 ; i < person.length ; i++){
    		if(person[i]/3 == 0){
    			if(P == 2){
    				if(person[i] == 2)mone++;
    			}else if(P == 1){
    				if(person[i] >= 1){
    					preoks++;
    				}
    			}else if(P == 0){
    				preoks++;
    			}
    		}else if(person[i]/3 >= P || (person[i]/3 >= P-1 && person[i] % 3 == 1) || (person[i]/3 >= P-1 && person[i] % 3 == 2)){
    			oks = person.length-i;
    			break;
    		}else if(person[i]/3 >= P-1){
    			mone++;
    		}else if(person[i]/3 >= P-2 && person[i] % 3 == 2){
    			mone++;
    		}
    	}
    	oks += preoks;
    	if(S <= mone){
    		oks += S;
    	}else{
    		oks += mone;
    	}
    	return oks;
    }
	
	public static void main(String[] args) throws Exception{
		(new Test()).doMain();
	}	
	
	
}
