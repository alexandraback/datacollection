import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class C{
	
	static int t,n,count;
	static String line,str;
	static long[] a;
	static String[] row;
	static boolean debug = false;
		
	private static long findDivisor(long c){
		long i;
		long j = (long) Math.sqrt(c);
		for(i=2;i<=j;i++)
			if(c%i==0) return i;
		return -1;
	}
	
	public static void main(String [ ] args) throws IOException{
		int i,j,k;
		long m,div;
		
		BufferedReader br = new BufferedReader(new FileReader("C-small.in"));
	    try {
	    	File file = new File("C.out");
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		a = new long[9];
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
	        line = br.readLine();
	        t = Integer.valueOf(line); //1==T
	        
	        line = br.readLine();
			row = line.split("\\s");
			n = Integer.valueOf(row[0]);
			j = Integer.valueOf(row[1]);
			
			m=1<<(n-1);
			k=1<<n;
			m+=1;
			
			//output
			bw.write("Case #1:\n");
	        
			//start candidates
			count = 0;
			for(i =0;i<9;i++){
				a[i]=0;
			}
			while(count<j && m<k){
				str = Long.toString(m, 2);
				//System.out.println(str);
				for(i = 2;i<=10;i++){
					//System.out.println(Long.valueOf(str, i));
					div = findDivisor(Long.valueOf(str, i));
					if(div ==-1)//prime
					{
						//System.out.println("abort");
						i=100;
					} else {
						a[i-2]=div;
					}
				}
				
				if(i==11) {
					count++;
					bw.write(str);
					for(i =0;i<9;i++){
						bw.write(" "+a[i]);
					}
					bw.write("\n");
				}
				
				//new candidate
				m+=2;
			}
			
			bw.close();

	    } finally {
	        br.close();
	    }
	}
}
