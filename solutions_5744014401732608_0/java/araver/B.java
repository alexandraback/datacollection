import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class B{
	static final String inFile="B-small.in";
	static final String outFile="B.out";
	
	static int t,n,count;
	static long m, rem;
	static String line,str,s,u;
	static String[]row;
	static int[][]a;
	static boolean debug = false;
	
	public static void main(String [ ] args) throws IOException{
		new B().run();
	}
	
	private void solve(){
		int i,j,k;
		a[0][n-1]=1;
		rem = m;
		int pow = 0;
		for(; rem>0; ){
			rem/=2;pow++;
		}
		rem = (long) Math.pow(2, pow-1);

		//System.out.println("AC"+rem);
		//create pow matrix
		for(i = 1; i <pow; i++){
			for(j = i; j <pow; j++){
					if(i<j) a[i][j]=1;
					if(j<n-1) a[j][n-1]=1;
					a[0][j]=1;
			}
		}
		
		//last 2^pow-2^pow elements
		rem = m - (long) Math.pow(2, pow-1);
		if(rem>0){
			//connect i = pow
			a[0][pow]=1;
			a[pow][n-1]=1;
			rem--;//1 done
			//add a[pow][j] iff 1 is in j position in binary representation
			//System.out.println("AB"+(rem));
			//System.out.println("AA"+pow);
				
			for(int step=1;rem>0;step++){
				System.out.print(rem%2);
				if(rem%2==1) {
					a[pow][pow-step]=1;
					//System.out.println("A["+(pow-step));
				}
				rem/=2;
			}
			//System.out.println("AA");
		}
	}
	
	private void run() throws IOException{
		int i,j,k,l;
		
		BufferedReader br = new BufferedReader(new FileReader(inFile));
	    try {
	    	File file = new File(outFile);
    		if (!file.exists()) {file.createNewFile();}
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		
	        line = br.readLine();
	        t = Integer.valueOf(line); //1 <= T <= 200

			a = new int[50][50];
	        for(l = 0; l < t; l++){
	        	line = br.readLine();
				row = line.split("\\s");
				n = Integer.valueOf(row[0]);
				m = Long.valueOf(row[1]);
				for(i = 0; i < n; i++){
					Arrays.fill(a[i], 0);
				}
				
				//m
				bw.write("Case #"+(l+1)+": ");
				if(m > Math.pow(2,n-2)){
					bw.write("IMPOSSIBLE\n");
				} else {
					if (m>0) solve();
					//output
					bw.write("POSSIBLE\n");
					for(i = 0; i < n; i++){
						for(j = 0; j < n; j++){
							bw.write(""+a[i][j]);
						}
						bw.write("\n");
					}
				}
	        }
			bw.close();
	    } finally {br.close();}
	}
}
