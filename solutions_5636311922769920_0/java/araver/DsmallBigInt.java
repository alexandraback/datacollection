import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class DsmallBigInt{
	
	static int t,k,c,s;
	static String line;
	static String[] row;
		
	
	public static void main(String [ ] args) throws IOException{
		int i,j;
		
		BufferedReader br = new BufferedReader(new FileReader("D-small.in"));
	    try {
	    	File file = new File("D.out");
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
	        line = br.readLine();
	        t = Integer.valueOf(line); //1<=T<=100
	        
	        for(j = 0; j<t; j++){
	        
		        line = br.readLine();
				row = line.split("\\s");
				k = Integer.valueOf(row[0]);
				c = Integer.valueOf(row[1]);
				s = Integer.valueOf(row[2]);
				
				//output
				bw.write("Case #"+(j+1)+":");

				System.out.println("----------");
				if(k==1) {
					bw.write(" 1");
					System.out.println("1");
				}
				else {
					for(i=0;i<k;i++){
						BigInteger mm = BigInteger.valueOf(i).multiply(BigInteger.valueOf(k).pow(c).subtract(BigInteger.ONE)).divide(BigInteger.valueOf(k-1)).add(BigInteger.ONE);
						System.out.print("-"+mm.toString());
						bw.write(" "+mm.toString());
					}
					System.out.println();
				}
				bw.write("\n");
	    	}
			
			bw.close();

	    } finally {
	        br.close();
	    }
	}
}
