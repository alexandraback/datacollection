import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class ProblemB{
	static int t,t1,t2;
	static int a,b,k,count;
	static BigInteger g;
	static String line;
	static String[] row;
	
	public static void main(String [ ] args) throws IOException{
		int i,j,l;
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
	    try {
	    	File file = new File("aaa.out");
    		
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		
	        line = br.readLine();
	        t = Integer.valueOf(line);
	        
	        for(i = 0; i < t; i++){
	        	line = br.readLine();

	        	row = line.split("\\s");
	        	
	        	a = Integer.valueOf(row[0]);
	        	b = Integer.valueOf(row[1]);
	        	k = Integer.valueOf(row[2]);
	        	
	        	count =0;
	        	for(j=0;j<a;j++){
	        		for (l=0;l<b;l++){
	        			if((j & l) < k){
	        				count++;
	        			}
	        		}
	        	}
		        
    			bw.write("Case #"+(i+1)+": "+count+"\n");
	        }
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
	
}
