import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

public class ProblemC {
	public static void main(String[] args) throws NumberFormatException, IOException{

		BufferedReader reader=new BufferedReader(new FileReader(new File(args[0])));

		int numTestCases=Integer.parseInt(reader.readLine());

		String[] split;

		for (int testCase=0; testCase<numTestCases; testCase++){
			split=reader.readLine().split("\\s+");
			
			int a=Integer.parseInt(split[0]);
			int b=Integer.parseInt(split[1]);
			
			String stra=String.valueOf(a);
			
			String curr;
			int currVal;
			
			int len=stra.length();
			
			Set<String> iCanHasPair=new HashSet<String>();
			
			int result=0;
			
			for (int i=a; i<=b; i++){
				curr=String.valueOf(i);
								
				boolean inRange;
								
				for (int k=1; k<len; k++){
					currVal=0;
					inRange=true;
					
					for (int j=0; j<len; j++){
						currVal+=((int)Math.pow(10, len-j-1))*(curr.charAt((j+k)%len)-'0');
						
						if (currVal>b){
							inRange=false;
							break;
						}
					}
					
					if (currVal<a)
						continue;
					
					if (!inRange)
						continue;
					
					
					if (i!=currVal){
						String key=i<currVal?i+":"+currVal:currVal+":"+i;
					
						if (!iCanHasPair.contains(key)){
							iCanHasPair.add(key);
							result++;
						}
					}

				}
				
			}
			
			
			System.out.println("Case #"+(testCase+1)+": "+result);
		}		
	}
}
