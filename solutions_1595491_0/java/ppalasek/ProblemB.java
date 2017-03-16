import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class ProblemB {
	public static void main(String[] args) throws NumberFormatException, IOException{

		BufferedReader reader=new BufferedReader(new FileReader(new File(args[0])));

		int numTestCases=Integer.parseInt(reader.readLine());

		String[] split;

		for (int testCase=0; testCase<numTestCases; testCase++){
			split=reader.readLine().split("\\s+");
			
			int n=Integer.parseInt(split[0]);
			int s=Integer.parseInt(split[1]);
			int p=Integer.parseInt(split[2]);
			
			int a, b;
			int curr;
			
			int res=0;
			
			for (int i=0; i<n; i++){
				curr=Integer.parseInt(split[i+3]);
				
				a=(curr+2)/3;
				
				if (curr<2||curr>28)
					b=-1;
				else
					b=(curr+4)/3;
				
				if (a>=p)
					res++;
				else if (s>0&&b>=p){
					res++;
					s--;
				}
			}
			
			System.out.println("Case #"+(testCase+1)+": "+res);
		}		
	}
}
