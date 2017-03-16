
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class DancingWithGooglers {
    private Scanner in;
    private PrintWriter out;
    public long output;
    public int N;
    public int S;
    public int p;
    public List<Integer> t = new ArrayList<Integer>();
    /**
     * main method
     */
    public static void main(String args[]){
        new DancingWithGooglers("B-small-attempt1.in");
    }
    
    /**
     * constructor
     */
    public DancingWithGooglers(String filename){
        initIO(filename);
        
        int n = in.nextInt();
        
        for(int i=1;i<=n;i++){
            N = in.nextInt();
            S = in.nextInt();
            p = in.nextInt();
            output = 0;
            t.clear();
            for(int xx=0;xx<N;xx++){
            	t.add(in.nextInt());
            }
            Collections.sort(t);
            output=solve();
            out.println("Case #"+i+": "+output);
        }
        
       closeIO();
    }
    public int solve(){
    	int op=0;
    	for(int i=t.size()-1;i>=0;i--){
    		int elem = t.get(i);
    		if(elem==30 || elem==29 || elem==28){
    			if(10>=p) op++;
    		}
    		else if(elem==0){
    			if(0>=p) op++;
    		}
    		else{
    			if(elem%3==0){
    				//normal case
    				if(elem/3 >= p){
    					op++;
    				}
    				else if((elem/3)+1 >= p){
    					if(S>0){
    						op++;
    						S--;
    					}
    				}
    			}
    			else if(elem%3==1){
    				//normal case
    				if((elem/3)+1 >= p){
    					op++;
    				}
    				else if((elem/3)+1 >= p){
    					if(S>0){
    						op++;
    						S--;
    					}
    				}
    			}
    			else if(elem%3==2){
    				//normal case
    				if((elem/3)+1 >= p){
    					op++;
    				}
    				else if((elem/3)+2 >= p){
    					if(S>0){
    						op++;
    						S--;
    					}
    				}
    			}
    		}
    	}
    	return op;
    }
    
    /**
     * Set up devices to do I/O
     */
    public void initIO(String filename){
        try {
            in = new Scanner(new FileReader(filename));
            out = new PrintWriter(new FileWriter(filename+".out"));
        }catch (IOException except) {
            System.err.println("File is missing!");
        }
    }
    
    /**
     * Free memory used for I/O
     */
    public void closeIO(){
        in.close();
        out.close();
    }

   
}
