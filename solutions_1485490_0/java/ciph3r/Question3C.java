import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;


public class Question3C {
	//final static String FNAME = "C:\\CodeJam\\BoxFactory";
	//final static String FNAME = "C:\\CodeJam\\A-large";
	final static String FNAME = "C:\\CodeJam\\C-small-attempt1";
    public static Scanner in;
    public static PrintWriter out;

    static void open() throws IOException {
        Locale.setDefault( Locale.US );
        in = new Scanner( new File( FNAME + ".in" ) );
        out = new PrintWriter( new File( FNAME + ".out" ) );
    }

    static void close() throws IOException {
        out.close();
    }
    
    public static long matches(long[] boxs, long[] toys){
    	
    	if(boxs==null || boxs.length==0)
    		return 0;
    	if(toys==null || toys.length ==0)
    		return 0;
    	
    	if(boxs[1]==toys[1]){//type check
    		if(boxs[0]==toys[0]){
    			
    			//create 2 new arrays and pass
    			long[] boxNew = new long[boxs.length-2];
    			long[] toyNew = new long[toys.length-2];
    			System.arraycopy(boxs, 2, boxNew, 0, boxs.length-2);
    			System.arraycopy(toys, 2, toyNew, 0, toys.length-2);
    			long retVal = matches(boxNew, toyNew);
    			return boxs[0] + retVal;
    		}
    		else{
    			long goodsCreated = Math.min(boxs[0], toys[0]);
    			
    			if(boxs[0]<toys[0]){
    				long diff = toys[0]-boxs[0];
    				long[] boxNew = new long[boxs.length-2];
    				long[] toyNew = new long[toys.length];
        			System.arraycopy(boxs, 2, boxNew, 0, boxs.length-2);
        			System.arraycopy(toys, 0, toyNew, 0, toys.length);
        			toyNew[0]=diff;
        			long retVal = matches(boxNew, toyNew);
        			return goodsCreated + retVal;
    			}else{
    				long diff = boxs[0]-toys[0];
    				long[] boxNew = new long[boxs.length];
    				long[] toyNew = new long[toys.length-2];
        			System.arraycopy(boxs, 0, boxNew, 0, boxs.length);
        			System.arraycopy(toys, 2, toyNew, 0, toys.length-2);
        			boxNew[0]=diff;
        			long retVal = matches(boxNew, toyNew);
        			return goodsCreated + retVal;
    			}
    			
    		}
    	}else{//Types are different
    		//we can either drop the toys or drop the boxes
    		
    		//1st case : drop boxes
    		long[] boxNew = new long[boxs.length-2];
    		long[] toyNew = new long[toys.length];
			System.arraycopy(boxs, 2, boxNew, 0, boxs.length-2);
			System.arraycopy(toys, 0, toyNew, 0, toys.length);
			long retVal1 = matches(boxNew, toyNew);
			
			//2nd case drop toy boxes
			long[] boxNew2 = new long[boxs.length];
			long[] toyNew2 = new long[toys.length-2];
			System.arraycopy(boxs, 0, boxNew2, 0, boxs.length);
			System.arraycopy(toys, 2, toyNew2, 0, toys.length-2);
			long retVal2 = matches(boxNew2, toyNew2);
			
			return Math.max(retVal1, retVal2);
    		
    	}   	
    	
    	
    }
    
	public static void main(String[] args)throws IOException {
		open();
        int T = in.nextInt();
        //int T = Integer.parseInt(in.nextLine());
        /*    -------- Main code ----------  */
        
        for(int i = 0 ; i < T ; i++){
        	int boxesN = in.nextInt();
        	int toysM = in.nextInt();
        	
        	long[] boxList = new long[boxesN*2];
        	long[] toyList = new long[toysM*2];
        	
        	for(int j = 0 ; j < 2*boxesN ; j++)
        		boxList[j]=in.nextLong();
        	for(int k = 0 ; k < 2*toysM ; k++)
        		toyList[k]=in.nextLong();
        	
        	long matches = matches(boxList, toyList);
        	
        	out.println( "Case #" + (i+1) + ": " + matches);
        }
        	
        	//out.println( "Case #" + (i+1) + ": " + "No");
        	close(); 

        }
        

}

