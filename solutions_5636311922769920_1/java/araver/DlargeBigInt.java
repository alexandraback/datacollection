import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class DlargeBigInt{
	
	static int t,k,c,s;
	static String line;
	static String[] row;
		
	
	public static void main(String [ ] args) throws IOException{
		int i,j;
		
		BufferedReader br = new BufferedReader(new FileReader("D-large.in"));
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
				} else if((k%2==0 && s<k/2) ||(k%2==1 && s<=k/2)){
					bw.write(" IMPOSSIBLE");
					System.out.println("IMPOSSIBLE");
				} else if ((k%2==0 && s>=k/2) ||(k%2==1 && s>k/2)){
					if(c==1 && s<k)//cannot see all tiles
					{
						bw.write(" IMPOSSIBLE");
						System.out.println("IMPOSSIBLE");
					} else if(c==1 && s==k)//must see all tiles
					{
						for(i=0;i<k;i++){
							bw.write(" "+(i+1));
							System.out.print(" "+(i+1));
						}
						System.out.println();
					} else{//s>=k/2, c>=2
						for(i=0;i<k;i+=2){
							BigInteger mm = BigInteger.valueOf(i).multiply(BigInteger.valueOf(k).pow(c).subtract(BigInteger.ONE)).divide(BigInteger.valueOf(k-1)).add(BigInteger.ONE).add(BigInteger.ONE);
							System.out.print("-"+mm.toString());
							bw.write(" "+mm.toString());
						}
						System.out.println();
					}
				} 
				/*else if (s==k) {
					for(i=0;i<k;i++){
						BigInteger mm = BigInteger.valueOf(i).multiply(BigInteger.valueOf(k).pow(c).subtract(BigInteger.ONE)).divide(BigInteger.valueOf(k-1)).add(BigInteger.ONE);
						System.out.print("-"+mm.toString());
						bw.write(" "+mm.toString());
					}
					System.out.println();
				} */
				bw.write("\n");
	    	}
			
			bw.close();

	    } finally {
	        br.close();
	    }
	}
}
