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
public class R1ProblemB {
	public static void main (String[] args)throws Exception{
		JFileChooser ourChooser = new JFileChooser(".");
		int retval = ourChooser.showOpenDialog(null);
	    if (retval == JFileChooser.APPROVE_OPTION) {
	        File file = ourChooser.getSelectedFile();
	        Scanner input = new Scanner(file);
	        int testSize = Integer.parseInt(input.nextLine());
	        for(int i=0; i<testSize; i++){
	        	String s0 = input.nextLine();
	        	int num = Integer.parseInt(s0);
	        	String[] infos = new String[num*2-1];
	        	for(int j=0; j<num*2-1; j++){
	        		infos[j] = input.nextLine();
	        	}
	        	System.out.println("Case #"+(i+1)+": "+getResult(num, infos));
	        }
	    }
	}
	
	public static String getResult(int num, String[] infos){
		HashMap<Integer, Integer> map = new HashMap<>();
		//construct number map
		for(String s: infos){
			String[] numbers = s.split(" ");
			for(String str: numbers){
				int n = Integer.parseInt(str);
				if(map.containsKey(n)){
					int count = map.get(n);
					count = count + 1;
					map.put(n, count);
				}
				else{
					map.put(n, 1);
				}
			}
		}
		//find odd frequency
		int[] numResult = new int[num];
		int index = 0;
		for(int key: map.keySet()){
			if(map.get(key)%2 != 0){// frequency is odd
				numResult[index] = key;
				index++;
			}
		}
		Arrays.sort(numResult);
		String result = ""+numResult[0];
		for(int i=1; i<numResult.length; i++){
			result = result + " " + numResult[i];
		}
		return result;
	}
}
