import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class CodeJam {

	/**
	 * @param args
	 */
	
	static File in=new File("C:/Users/SHANTANU/Documents/codejam/inp.in");
	static File out=new File("C:/Users/SHANTANU/Documents/codejam/output.txt");
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedWriter bw=new BufferedWriter(new FileWriter(out));
		Scanner sc=new Scanner(in);
		
		int count=sc.nextInt();
		for(int i=1; i<=count; i++){
			long e=sc.nextLong(), r=sc.nextLong(); int n=sc.nextInt();
			long v[]=new long[n];
			long vm=-1;
			for(int x=0; x<n; x++){
				v[x]=sc.nextLong();
				if(v[x]>vm)
					vm=v[x];
			}
			
			long gain=(e+r*(n-1))*vm;
			for(int x1=0; x1<n; x1++){
				gain=gain-(vm-v[x1])*r;
			}
			bw.write("Case #"+i+": "+gain);
			
			if(i!=count)
				bw.newLine();
		}
		bw.close();
		sc.close();
	}

}
