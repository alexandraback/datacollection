import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A{
	
	static int t;
	static String line,str;
	static String[] row;
	static int[] a;
	static boolean debug = false;
	
	private static boolean check(){
		for(int i=0;i<10;i++) if(a[i]==0) return false;
		return true;
	}
	
	private static void digit(long c){
		while(c>0){
			a[(int) (c%10)]|=1;
			c=c/10;
		}
	}
	
	public static void main(String [ ] args) throws IOException{
		int i,k,l;
		long j;
		
		BufferedReader br = new BufferedReader(new FileReader("A-small.in"));
	    try {

	        a = new int[10];
	        for(i=0;i<10;i++) a[i]=0;
	    	File file = new File("A.out");
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		
	        line = br.readLine();
	        k = Integer.valueOf(line); //1 <= T <= 200
	        
	        for(l=0;l<k;l++){
	        	line = br.readLine();
		        t = Integer.valueOf(line); //1 <= T <= 200
		        boolean loop=true;
		        j=t;
		        
		        if(j==0){
		        	bw.write("Case #"+(l+1)+": INSOMNIA\n");
		        } else {
					while(loop){
						digit(j);
						if(check()) break;
						j+=t;
					}					
					//output
					bw.write("Case #"+(l+1)+": "+j+"\n");
		        }
		        for(i=0;i<10;i++) a[i]=0;
	        }
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
}
