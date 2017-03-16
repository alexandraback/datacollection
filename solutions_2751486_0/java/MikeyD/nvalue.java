import java.io.*;
import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class nvalue {

	public static String vowels = "aeiou";
	
	public static void main(String[] args) throws Exception{
		
		Scanner In = new Scanner(System.in);
		
		int testCases = In.nextInt();
		
		for(int currCase = 1;currCase <= testCases;currCase++){
			
			String name = In.next();
			int nVal = In.nextInt();
			
			int count = 0;
			
			for(int i = 0;i <= name.length()-nVal;i++){
				for(int j = i+nVal;j <= name.length();j++){
				
					if(ValidSubstring(name.substring(i, j), nVal)){
						count++;
						/*
						if(i == 0 && j == name.length()){
							System.out.println("#1");
							count += 1;
						}
						else if(i == 0){
							System.out.println("#2");
							count += name.length()-nVal;
						}
						else if(j == name.length()){
							System.out.println("#3");
							count += i;
						}
						else{
							System.out.println("#4");
							count += (name.length()-j)*i;
						}*/
					}
					
				}
				
			}
			
			System.out.println("Case #"+currCase+": "+count);
			
			
		}
		
	}
	
	public static boolean ValidSubstring(String word, int nVal){
		
		int max = 0, curr = 0;
		
		for(int i = 0;i < word.length();i++)
			if(vowels.indexOf(word.charAt(i)) >= 0){
				max = Math.max(max, curr);
				curr = 0;
			}
			else
				curr++;
				
		max = Math.max(max,  curr);
		
		if(max < nVal)
			return false;
		
		//System.out.println("returned true "+word);
		return true;

	}
	
}
