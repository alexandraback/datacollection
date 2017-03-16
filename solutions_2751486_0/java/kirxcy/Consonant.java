/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package consonant;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

/**
 *
 * @author rickyjeremiah
 */
public class Consonant {

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		try{

			
			//System.out.println(dcs);
			
			Scanner sc = new Scanner(new File("input.txt"));
			FileWriter fw = new FileWriter("output.txt");

			int t = sc.nextInt();
			
			int l;
			String s;
			
			for(int tc = 1; tc<=t ; tc++){
				sc.nextLine();
				
				s = sc.next();
				
				l = sc.nextInt();
				
				int count = 0;
				int ncount = 0;
				long res = 0;
				int last = 0;
				
				for(int i=0;i<s.length();i++){
					if(isConsonant(s.charAt(i))){
						count ++;
						if(count >= l){
							int ki = i-l+1;
							res += (ki-last+1)*(s.length() - i);
							ncount ++;
							last = i-l+2;
						}
					}else{
						count = 0;
					}
				}
				
				
				System.out.println("Case #"+tc+": "+res);
				fw.write("Case #"+tc+": "+res+"\n");
			}
			
			fw.close();

		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
	
	public static boolean isConsonant(char ch){
		switch(ch){
			case 'a' :
			case 'i' :
			case 'u' :
			case 'e' :
			case 'o' : 
				return false;
		}
		return true;
	}
}


