import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CodeJam {
	 public static void main(String[] args) throws NumberFormatException, IOException {
	     	BufferedReader br = new BufferedReader(new FileReader("in.txt"));
	     	BufferedWriter bw=new BufferedWriter(new FileWriter("soldiers.txt"));
	        
	        int T,N=0;
	        String l;
	       	T = Integer.valueOf(br.readLine());
	        for (int i=0;i<T;i++)
	            {
	        	int max=0;
	        	int m;
	        	int c=0;
	        		N = Integer.valueOf(br.readLine());
	        		int [] S = new int [N];
	        		int [] loop = new int[N];
	        		l=br.readLine();
	        		for(int k=0;k<N;k++)
	        			{S[k]=Integer.valueOf(l.split(" ")[k]);loop[k]=0;}
	        	
	        	for(int j=0;j<N;j++)
	        		{
	        		c=0;
	        		m=S[j]-1;
	        		while(loop[m]==0)
	        		{//System.out.print(S[m]+" ");
	        		loop[m]=1;m=S[m]-1;c++;}
	        		
	        		//System.out.println();
	        		if(c>max)max=c;
	        		for(int k=0;k<N;k++)loop[k]=0;
	        		}
	        	System.out.println(max);
	            bw.write("Case #"+(i+1)+": "+max);bw.newLine();
	        }
	        br.close();
	        bw.close();
	   }
}
