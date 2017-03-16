

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

/***/
public class FairSquareMedium {

	/**
	 */
	public static void main(String[] args) {

		try {

			LineNumberReader reader=new LineNumberReader(new FileReader(new File(args[0]))); // InputFile
			PrintStream printer=new PrintStream(new File(args[1])); // OutputFile
			
			/***/
			// long t=System.currentTimeMillis();
			List<Long> list=Collections.synchronizedList(new ArrayList<Long>());
			for(int len=1;len<=8;len++){
				
				// System.err.println(len);
				
				if(len==1){

					for(int i=1;i!=10;i++){
						Long sq=(long) Math.pow(i, 2);
						if(isPalindrome(sq)){
							// System.err.println(i+"=>"+sq);
							list.add(sq);
						}							
					}
					
				}else if((len%2)==0){
					int nStart=(int) Math.pow(10,(len/2)-1);
					int nEnd=(int) nStart*10; // Math.pow(10,(len/2)+1);
					// System.err.println("Start="+nStart+",End="+nEnd);
					for(int i=nStart;i!=nEnd;i++){
						
						String num=String.valueOf(i);
						String rev="";
						for(int c=0;c!=num.length();c++)
							rev+=num.charAt(num.length()-1-c);
						
						Long number=Long.valueOf(num+rev);						
						Long sq=(long) Math.pow(number, 2);
						// System.err.println(number+"=>"+sq);
						if(isPalindrome(sq))
							list.add(sq);							
					}
				}else{
					
					int nStart=(int) Math.pow(10,(len/2)-1);
					int nEnd=(int) nStart*10; // Math.pow(10,(len/2)+1);
					// System.err.println("Start="+nStart+",End="+nEnd);
					for(int i=nStart;i!=nEnd;i++){
						
						String num=String.valueOf(i);
						String rev="";
						for(int c=0;c!=num.length();c++)
							rev+=num.charAt(num.length()-1-c);
						
						for(int m=0;m!=10;m++){

							Long number=Long.valueOf(num+String.valueOf(m)+rev);
							Long sq=(long) Math.pow(number, 2);
							// System.err.println(number+"=>"+sq);
							if(isPalindrome(sq))
								list.add(sq);													
						}
					}
					
				}
				
			}

			Collections.sort(list);
			
			/**
			System.err.println(list);
			System.err.println(list.size()); */
			// System.err.println(System.currentTimeMillis()-t);

			/***/
			int nTestCases=Integer.valueOf(reader.readLine().trim());
			for(int i=0;i!=nTestCases;i++){
				// long tCase=System.currentTimeMillis();
				String s[]=reader.readLine().trim().split(" ", 2);
				Long nMin=Long.valueOf(s[0].trim());
				Long nMax=Long.valueOf(s[1].trim());
				int nCount=0;
								
				Iterator<Long> iter=list.iterator();
				while(iter.hasNext()){
					Long v=iter.next();
					if((v>=nMin)&&(v<=nMax))
						nCount++;
				}
				
				printer.println("Case #"+(i+1)+": "+nCount);
				System.out.println("Case #"+(i+1)+": "+nCount /*+" :"+(System.currentTimeMillis()-tCase)*/);
			}
			
			reader.close();
			printer.close();			
		} catch (FileNotFoundException e) {
			
			e.printStackTrace();
		} catch (IOException e) {
			
			e.printStackTrace();
		} 
		
	}

	/***/
	public static boolean isPalindrome(long n){
		String s=String.valueOf(n);
		int len=s.length();
		if(len==1)
			return true;

		for(int i=0;i!=len/2;i++)
			if(s.charAt(i)!=s.charAt(len-1-i))
				return false;
		
		return true;
	}
	
	
}
