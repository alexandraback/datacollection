import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class WinningWord {
		
		
	public static void main(String[] args){
		
		
		 Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		 
		 int problemcount  = scan.nextInt();
		 int i = 1;
		 
		 while(i <= problemcount)
		 {
			String entry = scan.next();
			
			int index  = 1;
			
			String winningword = "" + entry.charAt(0);
			
			
			while(index < entry.length()){
				
				if(entry.charAt(index)>= winningword.charAt(0))
					winningword = entry.charAt(index) + winningword;
				else
					winningword+= entry.charAt(index);
				
				index++;
				
			}
			
			 System.out.println("Case #" + i + ": " + winningword);
			 
			 i++;
		 }
		
	}

}
