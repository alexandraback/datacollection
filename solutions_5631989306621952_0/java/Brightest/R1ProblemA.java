/*
 * @author Mingxuan Zha
 * @date April 2016, created
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

import javax.swing.JFileChooser;

public class R1ProblemA {
	public static void main (String[] args)throws Exception{
		JFileChooser ourChooser = new JFileChooser(".");
		int retval = ourChooser.showOpenDialog(null);
	    if (retval == JFileChooser.APPROVE_OPTION) {
	        File file = ourChooser.getSelectedFile();
	        Scanner input = new Scanner(file);
	        int testSize = Integer.parseInt(input.nextLine());
	        for(int i=0; i<testSize; i++){
	        	String s = input.nextLine();
	        	System.out.println("Case #"+(i+1)+": "+getResult(s));
	        }
	    }
	}
	
	public static String getResult(String s){
		String result = ""+s.charAt(0);
		for(int i=1; i<s.length(); i++){
			if(s.charAt(i) >= result.charAt(0)){
				result = s.charAt(i) + result;
			}
			else{
				result = result + s.charAt(i);
			}
		}
		return result;
	}
}
