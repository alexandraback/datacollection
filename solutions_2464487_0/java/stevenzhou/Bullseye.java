import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;



public class Bullseye {
    private File inFile;
    private File outFile;
    

    int r,t;
    

    /**
     * @param args
     */
    public static void main(String[] args) {
        if(args.length < 2) {
            System.out.println("Usage : java Bullseye <In File> <Out File>");
            return;
        }
        Bullseye b = new Bullseye(args[0], args[1]);
        b.start();
    }
    
    public Bullseye(String inFile, String outFile) {
        this.inFile = new File(inFile);
        this.outFile = new File(outFile);
    }
    
    public void start() {
        BufferedReader br = null;
        BufferedWriter bw = null;
        System.out.println(java.lang.Runtime.getRuntime().maxMemory());
        int i,j,k;
        try {
            br = new BufferedReader(new FileReader(inFile));
            bw = new BufferedWriter(new FileWriter(outFile));
            int totalTestCases = Integer.parseInt(br.readLine());
            
            String[] line;
            int result;
            
            for(i=0;i<totalTestCases;i++) {
            	line = br.readLine().split(" ");
            	r = Integer.parseInt(line[0]);
            	t = Integer.parseInt(line[1]);
            	
            	double a,b,c;
            	
            	a = 2;
            	b = 2*r-1;
            	c = -t;
            	
            	
            	
            	
            	
            	
            	
            	result = (int) ((Math.sqrt(b*b-4*a*c) - b) / 4);

            	

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
    
 	



}
