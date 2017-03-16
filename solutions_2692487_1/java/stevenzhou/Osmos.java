import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;



public class Osmos {
    private File inFile;
    private File outFile;
    

    int A,N;
    ArrayList<Integer> level = null;

    /**
     * @param args
     */
    public static void main(String[] args) {
        if(args.length < 2) {
            System.out.println("Usage : java Osmos <In File> <Out File>");
            return;
        }
        Osmos o = new Osmos(args[0], args[1]);
        o.start();
    }
    
    public Osmos(String inFile, String outFile) {
        this.inFile = new File(inFile);
        this.outFile = new File(outFile);
    }
    
    public void start() {
        BufferedReader br = null;
        BufferedWriter bw = null;
        System.out.println(java.lang.Runtime.getRuntime().maxMemory());
        int i,j;
        try {
            br = new BufferedReader(new FileReader(inFile));
            bw = new BufferedWriter(new FileWriter(outFile));
            int totalTestCases = Integer.parseInt(br.readLine());
            
            String[] line;
            int result;
            
            for(i=0;i<totalTestCases;i++) {
            	line = br.readLine().split(" ");
            	A = Integer.parseInt(line[0]);
            	N = Integer.parseInt(line[1]);
            	
            	level = new ArrayList<Integer>(N);
            	result = 0;
            	
            	line = br.readLine().split(" ");
            	
            	for(j=0;j<N;j++) {
            		level.add(j, Integer.parseInt(line[j]));
            	}
            	
            	Collections.sort(level);
            	
            	result = solve(A,0);
            	

            	System.out.print(String.format("Case #%d: %d\n", i+1, result));
            	bw.write(String.format("Case #%d: %d\n", i+1, result));
            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            if(bw != null) {
                try {
                    bw.close();
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        }         
    }

	private int solve(int mote, int lo) {
		int result = 0;
    	for(int i=lo; i<level.size();i++) {
    		if (mote > level.get(i)) {
    			mote += level.get(i);
    		} else {
    			int count = 0;
    			int m = mote;
    			if(mote == 1 || level.get(i) == 1) {
    				return level.size() - i;
    			}
    			while(m <= level.get(i)) {
    				count++;
    				m += m-1;
    			}
    			m += level.get(i);
    			return Math.min(1+solve(mote,i+1), count+solve(m,i+1));    			
    		}
    	}
    	
		return result;
	}
}
