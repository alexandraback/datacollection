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
		long max=0;
		for(int i=1; i<=count; i++){
			max=0;
			long r=sc.nextLong(), t=sc.nextLong();
			long diff=1;
			while(diff>=0){
				long ar=2*r+1;
				diff=t-ar;
				t=diff;
				if(diff>=0)
					max++;
				r=r+2;
			}
			bw.write("Case #"+i+": "+max);
			
			if(i!=count)
				bw.newLine();
		}
		bw.close();
		sc.close();
	}
}
