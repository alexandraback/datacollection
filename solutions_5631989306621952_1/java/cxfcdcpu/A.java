import java.io.*;
import java.util.*;

public class A{
	
  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt();
	
    for (int i = 1; i <= t; ++i) {
		String n = in.next();
		int length=n.length();
		char first=n.charAt(0);
		String result=""+first;
		int firstLarge=0;
		int run=1;
		System.out.print("Case #" + i + ": ");
		for(int j=1;j<length;j++){
			if(n.charAt(j)>=first){
				result=n.charAt(j)+result;
				first=n.charAt(j);
			}
			else{
				result=result+n.charAt(j);
			}
		}
		System.out.println(result);
		
		
		
	}
	
	
  }
  
}