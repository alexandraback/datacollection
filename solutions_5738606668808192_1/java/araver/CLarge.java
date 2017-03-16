import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.math.RoundingMode;

public class CLarge{
	
	static int t,count,n;
	static String line,str;
	static BigInteger[] a;
	static String[] row;
	static boolean debug = false;
	

	private static BigInteger findDivisor(BigInteger c){
		BigInteger i = BigInteger.valueOf(2);
		
		if(c.mod(i).compareTo(BigInteger.ZERO)==0) return i;
		
		i = BigInteger.valueOf(3);
		//while(i.multiply(i).compareTo(c)<0){
		while(i.compareTo(BigInteger.valueOf(20))<0){
			if(c.mod(i).compareTo(BigInteger.ZERO)==0)
				return i;
			i = i.add(BigInteger.valueOf(2));
		}
		
		return BigInteger.ONE;
	}
	
	public static void main(String [ ] args) throws IOException{
		int i,j;
		BigInteger m,k,div;
		
		BufferedReader br = new BufferedReader(new FileReader("C-small.in"));
	    try {
	    	File file = new File("C.out");
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		a = new BigInteger[9];
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
	        line = br.readLine();
	        t = Integer.valueOf(line); //1==T
	        
	        line = br.readLine();
			row = line.split("\\s");
			n = Integer.valueOf(row[0]);
			j = Integer.valueOf(row[1]);
			
			m=BigInteger.valueOf(1l<<(n-1));
			k=BigInteger.valueOf(1l<<n);
			m = m.add(BigInteger.ONE);
			
			//output
			bw.write("Case #1:\n");
	        
			//start candidates
			count = 0;
			for(i =0;i<9;i++){
				a[i]=BigInteger.ZERO;
			}
			while(count<j && m.compareTo(k)<0){
				str = m.toString(2);
				//System.out.println("-----------------");
				//System.out.println(str);
				for(i = 2;i<=10;i++){
					//System.out.println(new BigInteger(str, i));
					div = findDivisor(new BigInteger(str, i));
					if(div == BigInteger.ONE)//prime
					{
						//System.out.println("abort:"+div);
						i=100;
					} else {
						a[i-2]=div;
					}
				}
				
				if(i==11) {
					count++;
					bw.write(str);
					for(i=0;i<9;i++){
						bw.write(" "+a[i]);
					}
					bw.write("\n");
					System.out.println(""+count+" - "+str);
				}
				
				//new candidate
				m = m.add(BigInteger.valueOf(2));
			}
			bw.close();

	    } finally {
	        br.close();
	    }
	}
}

