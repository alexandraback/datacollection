

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.PrintStream;

/***/
public class FairSquareSmall {

	/**
	 */
	public static void main(String[] args) {

		try {

			LineNumberReader reader=new LineNumberReader(new FileReader(new File(args[0]))); // InputFile
			PrintStream printer=new PrintStream(new File(args[1])); // OutputFile
			
			int nTestCases=Integer.valueOf(reader.readLine().trim());
			for(int i=0;i!=nTestCases;i++){
				String s[]=reader.readLine().trim().split(" ", 2);
				int nMin=Integer.valueOf(s[0].trim());
				int nMax=Integer.valueOf(s[1].trim());
				
				int nCount=0;
				int sqMin=(int) Math.sqrt((double)nMin);
				if(Math.pow(sqMin, 2)<nMin)
					sqMin++;
				int sqMax=(int)Math.sqrt((double)nMax);
				// System.out.println(sqMin+"=>"+sqMax);
				for(int n=sqMin; n<=sqMax;n++){
					int sq=(int) Math.pow(n, 2);
					if(isPalindrome(n)&&isPalindrome(sq)){
						// System.out.println(n+"::=>"+sq);
						nCount++;
					}
				}
				
				System.out.println("Case #"+(i+1)+": "+nCount);
				printer.println("Case #"+(i+1)+": "+nCount);
			}
			
			reader.close();
			printer.close();			
		} catch (FileNotFoundException e) {
			
			e.printStackTrace();
		} catch (IOException e) {
			
			e.printStackTrace();
		} 
		
	}

	public static boolean isPalindrome(int n){
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
