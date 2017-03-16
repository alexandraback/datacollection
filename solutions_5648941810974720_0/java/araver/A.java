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
	static int[] a,b;
	static boolean debug = false;
	
	
	public static void main(String [ ] args) throws IOException{
		int i,k,l,n;
		
		BufferedReader br = new BufferedReader(new FileReader("A-small.in"));
	    try {

	    	File file = new File("A.out");
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		
	        line = br.readLine();
	        t = Integer.valueOf(line); //1 <= T <= 100
	        
	        for(l=0;l<t;l++){
	        	
	        	a = new int[10];
	        	b = new int[10];
	        	for(i=0;i<9;i++) {a[i]=0;b[i]=0;}
	        	
	        	line = br.readLine(); //S
	        	n = line.length();
	        	
	        	for(i=0;i<n;i++) {
	        		if(line.charAt(i)=='Z') a[0]++;
	        		if(line.charAt(i)=='W') a[2]++;
	        		if(line.charAt(i)=='U') a[4]++;
	        		if(line.charAt(i)=='X') a[6]++;
	        		if(line.charAt(i)=='G') a[8]++;
	        		
	        		if(line.charAt(i)=='H') b[0]++;//0-H
	        		if(line.charAt(i)=='O') b[1]++;//1-O
	        		if(line.charAt(i)=='S') b[2]++;//2-S
	        		if(line.charAt(i)=='V') b[3]++;//3-V
	        		if(line.charAt(i)=='I') b[4]++;//4-I
	        	}

	        	a[1] = b[1]-a[0]-a[2]-a[4];//O
	        	a[3] = b[0]-a[8];//H
	        	a[7] = b[2]-a[6];//S
	        	a[5] = b[3]-a[7];//V 
	        	a[9] = b[4]-a[8]-a[6]-a[5];//I
	        	
	        	
	        	bw.write("Case #"+(l+1)+": ");
	        	for(i=0;i<=9;i++){
	        		for (k=1;k<=a[i];k++) bw.write(""+i);
	        	}
	        	bw.write("\n");	
	        	
	        }
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
}
