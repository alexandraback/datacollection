import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class B{
	
	static int t,n,count;
	static String line,str;
	static int[] a;
	static boolean debug = false;
	
	private static void flip (int f, int l){
		int i,j,k;
		for(i=f,j=l;i<j;i++,j--){
			k = a[i];
			a[i]=1-a[j];
			a[j]=1-k;
		}
		if(i==j) a[i]=1-a[i];
	}
	
	private static void prettyPrint(){
		int i;
		for(i=0;i<n;i++)
			System.out.print(""+(a[i]==0?"-":"+"));
		System.out.println();
	}
	
	private static int findLastHappy(){
		int i;
		for(i=n-1;i>=0 && a[i]==1;i--);
		return i;
	}
	
	private static int findFirstUnHappy(){
		int i;
		for(i=0;i<n && a[i]==0;i++);
		return i;
	}
	
	private static int findFirstHappy(){
		int i;
		for(i=0;i<n && a[i]==1;i++);
		return i;
	}
	
	public static void main(String [ ] args) throws IOException{
		int i,j,k,l,m;
		
		BufferedReader br = new BufferedReader(new FileReader("B-small.in"));
	    try {
	    	File file = new File("B.out");
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		a = new int[100];
	        line = br.readLine();
	        t = Integer.valueOf(line); //1 <= T <= 100
	        boolean loop;
	        for(i = 0; i < t; i++){
	        	for(j = 0; j < 100; j++) a[j]=0;
	        	
				line = br.readLine();
				n = line.length();
				
				for(j = 0; j < n; j++){
					a[j]=line.charAt(j)=='-'?0:1;
				}
				
				loop = true;
				count = 0;
				prettyPrint();
				while(loop){
					k = findLastHappy();
					l = findFirstUnHappy();
					
					if(k==-1) {//all are Happy
						break;
					}
					System.out.println(""+k+" "+l);
					if(l==k+1){//starting string is UnHappy, one flip wins
						count++;
						break;
					} else{//l<k
						if(l > 0) //starts with unhappy
						{
							//flip stack from 0 to k
							flip(0,k);
							prettyPrint();
							count++;
						} else //l==0 starts with happy, need to flip those happy bunch first
						{
							m = findFirstHappy();
							flip(0,m-1);
							prettyPrint();
							count++;
						}
					}
				}
				
				//output
				bw.write("Case #"+(i+1)+": "+count+"\n");    			
	        }
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
}
