
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class RecycledNumbers {
    private Scanner in;
    private PrintWriter out;
    public long output;
    public int A;
    public int B;
    /**
     * main method
     */
    public static void main(String args[]){
        new RecycledNumbers("C-large.in");
    }
    
    /**
     * constructor
     */
    public RecycledNumbers(String filename){
        initIO(filename);
        
        int n = in.nextInt();
//    	long tmStart = System.currentTimeMillis();
        
        for(int i=1;i<=n;i++){
            A = in.nextInt();
            B = in.nextInt();
            output = 0;
            output=solve();
            out.println("Case #"+i+": "+output);
        }
//        System.out.println(System.currentTimeMillis() - tmStart);
        
       closeIO();
    }
    public long solve(){
    	long op=0;
		Set<Integer> s = new HashSet<Integer>();
    	for(int i=A;i<=B;i++){
    		String stringI = Integer.toString(i);
    		s.clear();
    		for(int ind=stringI.length()-1;ind>0;ind--){
    			if(stringI.substring(ind).charAt(0)!= '0'){
    				String stringTemp = stringI.substring(ind) + stringI.substring(0, ind);
    				if(Integer.parseInt(stringTemp) > i && Integer.parseInt(stringTemp)<=B){
//    					System.out.println(stringI + "  "+Integer.parseInt(stringTemp));
    					s.add(Integer.parseInt(stringTemp));
//    					op++;
    				}
    			}
    		}
    		op+=s.size();
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
