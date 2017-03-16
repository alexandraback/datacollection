import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Jam4 {

	
   
  public static void main(String[] args){
	
	
	
	Scanner in=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	
	int t=in.nextInt();
	in.nextLine();
	
	for(int k=1; k<=t;k++){
		
		String n = in.nextLine();
		//in.nextLine();
		String ans=calculate(n);
		System.out.println("Case #"+ k + ": " + ans);
		
	}
    
	in.close();
  }
  
  private static String calculate(String word){
	 String ans=String.valueOf(word.charAt(0));
	 int l=word.length();
	 for(int i=1;i<=l-1;i++){
		 char charWord=word.charAt(i);
		 char charAns=ans.charAt(0);
		 if(charWord>=charAns){
			 ans=charWord+ans;
		 }else{
			 ans=ans+charWord;
		 }
	 }
	 return ans;
  }
  
 
}
