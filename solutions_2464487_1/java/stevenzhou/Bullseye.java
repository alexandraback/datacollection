import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;



public class Bullseye {
    private File inFile;
    private File outFile;
    

    BigInteger r,t;
    

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
            String result;
            
            for(i=0;i<totalTestCases;i++) {
            	line = br.readLine().split(" ");
            	r = new BigInteger(line[0]);
            	t = new BigInteger(line[1]);
            	
            	BigInteger a,b,c,d;
            	
            	a = new BigInteger("2");
            	b = r.multiply(a).add(BigInteger.ONE.negate());
            	c = t.negate();
            	
            	d = a.pow(2);
            	
            	
            	
            	
            	
            	result = (sqrt(b.pow(2).add(d.multiply(a).multiply(t))).add(b.negate()).divide(d)).toString();

            	

            	bw.write(String.format("Case #%d: %s\n", i+1, result));
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
    
    BigInteger sqrt(BigInteger n) {
    	  BigInteger a = BigInteger.ONE;
    	  BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
    	  while(b.compareTo(a) >= 0) {
    	    BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
    	    if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
    	    else a = mid.add(BigInteger.ONE);
    	  }
    	  return a.subtract(BigInteger.ONE);
    	}



}
