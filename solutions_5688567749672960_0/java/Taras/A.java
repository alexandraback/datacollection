import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {		
		Scanner in;
		try {
			in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1B/src/A-small-attempt1.in"));
			//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1B/src/a.in"));
			
			int t = in.nextInt();
			
			StringBuilder resultBuilder = new StringBuilder();
			
			for(int i = 0; i < t; i++){
				long x = in.nextLong();
				
				System.out.println("\n\nFind solution:"+x);
				resultBuilder.append("Case #"+(i+1)+": "+findSolution(x,0)+"\n");
			}
			
			
			System.out.println(resultBuilder.toString());
			String content = resultBuilder.toString();
			 
			File file = new File("/home/taras/workspace/GoogleCodeJam_1B/src/a.out");
 
			// if file doesnt exists, then create it
			if (!file.exists()) {
				file.createNewFile();
			}
 
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(content);
			bw.close();
 
			System.out.println("Done");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	
	private static long findSolution(long x, long moves){
		System.out.println("findSolution: x:"+x+"  moves:"+moves);
		/*try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		long dMove = 0;
		

		if(x<=20) return x+moves;
		else{
			List<Long> digits = new ArrayList<Long>();
			List<Long> newDigits = new ArrayList<Long>();
			long copy = x;
			long next = 0;
			long totalDigits = 0;
			long zeroDigits = 0;
			long nonZeroDigits = 0;
			
			
			while(copy>0){
				next = copy%10;
				copy/=10;
				digits.add(next);
				newDigits.add(next);
				totalDigits++;
				if(next==0){
					zeroDigits++;
				}else{
					nonZeroDigits++;
				}
			}
			
			
			
			if(nonZeroDigits==1 || digits.get(0)==0){
				//10000 || 20000
				System.out.println("condition1:");
				return findSolution(x-1, moves+1);
			}if(nonZeroDigits==2 && digits.get(0)==1 && digits.get(digits.size()-1)==1){
				return findSolution(x-1, moves+1);
			}else{
				//543210 -> 100001
				dMove = 0;
				
				
				long part1 = listToLong(digits,true);
				long part2 = listToLong(digits,false);
				System.out.println("part1:"+part1+" part2:"+part2);
				if(part1!=1){
					dMove++;
				}
				dMove+=part2+part1-2;
				
				
				
				for(int i=0; i<digits.size(); i++){
					digits.set(i,new Long(0));
				}
				digits.set(0,new Long(1) );
				digits.set(digits.size()-1,new Long(1));
				
				return findSolution(listToLong(digits), moves+dMove);
			}
			
			//return x;
		}
		
	}
	

	
	private static long listToLong(List<Long> before){
		long res = 0;
		for(int i=before.size()-1;i>=0; i--){
			res*=10;
			res+=before.get(i);
		}
		
		return res;
	}
	
	private static long listToLong(List<Long> before, boolean isReverse){
		long res = 0;
		if(isReverse){
			int shift = before.size()%2;
			
			for(int i=before.size()/2 + shift;i<before.size(); i++){
				res*=10;
				res+=before.get(i);
			}
		}else{
			int shift = before.size()%2;
			for(int i=before.size()/2-1 +shift; i>=0; i--){
				res*=10;
				res+=before.get(i);
			}
		}
		
		return res;
	}
}
