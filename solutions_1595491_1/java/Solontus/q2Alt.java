import java.io.*;
import java.util.*;
public class q2Alt{
public static void main (String[] args) throws IOException 
    {
	BufferedReader input = new BufferedReader (new FileReader ("B-large.txt"));
	PrintWriter output = new PrintWriter (new FileWriter("test2DoneAlt.out"));
	StringTokenizer st;
	
	int numOfLine = Integer.parseInt(input.readLine());
	for(int i = 0; i < numOfLine; i++){
	    st = new StringTokenizer(input.readLine());
	    int N = Integer.parseInt(st.nextToken());
	    int S = Integer.parseInt(st.nextToken());
	    int P = Integer.parseInt(st.nextToken());
	    int better = 0;
	    int[] scores = new int [N];
	    
	    for(int j = 0; j < N; j++){
		scores[j] = Integer.parseInt(st.nextToken());
	    }
	    
	    for(int j = 0; j < N; j++){
		int reduction = scores[j] - P;
		if(reduction < 0){}
		else if(reduction >= 2*(P - 1)){
		    better ++;
		}
		else if(reduction >= 2*(P-2) && S > 0){
		    better ++;
		    S --;
		}
	    }
	    
	    output.println("Case #" + (i+1) + ": " + better);
	}
	output.close();
    }
}          
