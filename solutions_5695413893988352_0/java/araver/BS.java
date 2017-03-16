import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class BS{
	
	static int t,n,count;
	static String line,str,s,u,v;
	static String[]row;
	static int[] a,b;
	static int max,max1,max2;
	static boolean debug = false;
	
	public static void back(int k, int j){
		if(j==n) {
			int x=0,y=0;
			for (int i = 0; i<n;i++){
				x+=a[i];
				x*=10;
				y+=b[i];
				y*=10;
			}
			x/=10; y/=10;
			int z = Math.abs(x-y);
			
			if(z < max) {max = z; max1 = x; max2 = y;}
			else {
				if(z == max){
					if (x < max1) {max1 = x; max2 = y;}
					else if (x == max1 && y < max2){
						max2 = y;
					}
				}
			}
			return;
		}
		
		if(k<n){
			if(s.charAt(k)=='?'){
				for (int i = 0; i<=9;i++){
					a[k]=i;
					back(k+1,j);
				}
			} else {
				a[k]=s.charAt(k)-'0';
				back(k+1,j);
			}
		} else //k==n
		{
			if(u.charAt(j)=='?'){
				for (int i = 0; i<=9;i++){
					b[j]=i;
					back(k,j+1);
				}
			} else {
				b[j]=u.charAt(j)-'0';
				back(k,j+1);
			}
		}

		return;
	}
	
	public static String print(int i){
		String s = "";
		int r = 0;
		for (int j=0; j<n;j++){
			r = i%10;
			s=""+r+s;
			i/=10;
		}
		return s;
	}
	
	public static void main(String [ ] args) throws IOException{
		int i,k,j;
		
		BufferedReader br = new BufferedReader(new FileReader("B-small.in"));
	    try {
	    	File file = new File("B.out");
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		a = new int[19];
    		b = new int[19];
    		
	        line = br.readLine();
	        t = Integer.valueOf(line); //1 <= T <= 200
	        
	        for(i = 0; i < t; i++){
	        	line = br.readLine();
				row = line.split("\\s");
	        	s = row[0];
	        	u = row[1];
	        	n = s.length();
	        	
	        	for(k = 0; k < n; k++){
	        		a[k]=b[k]='?';
	        	}
	        	int bigger = 0;
	        	int index=-1;
	        	int diff=0;
	        	boolean zeroes=true;
	        	
	        	for(k = 0; k < n; k++){
	        		if(s.charAt(k)!='?' && u.charAt(k)!='0' 
	        				|| s.charAt(k)!='0' && u.charAt(k)!='?'){
	        			zeroes=false;
	        		}
	        		if (s.charAt(k)!='?' && u.charAt(k)!='?')
	        		{
	        			bigger= s.charAt(k)>u.charAt(k)?-1:1;
	        			index = k;
	        			diff = bigger<0?s.charAt(k)-u.charAt(k):u.charAt(k)-s.charAt(k);
	        			k=n;
	        		}
	        	}
	        	
	        	boolean swit=(diff>=5);
	        	
	        	int dif = 0;
	        	
	        	max = 999;
	        	back(0,0);
				
				//output
				bw.write("Case #"+(i+1)+": "+print(max1)+" "+print(max2)+"\n");    			
	        }
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
}
