package cg.y2012.qual;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class Q1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Map<Character, Character> G = new HashMap<Character, Character>();
		String s1 ="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String s2 ="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
		for(int i=0;i<s1.length();i++){
			G.put(s1.charAt(i), s2.charAt(i));
		}
		G.put('y', 'a');
		G.put('e', 'o');
		G.put('q', 'z');
		G.put('z','q');
		 //'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'.
		BufferedWriter out = null;
		try {
			String newLine = System.getProperty("line.separator");
		    out = new BufferedWriter(new FileWriter(args[0]+".output"));
		    BufferedReader b = new BufferedReader(new FileReader(args[0]));
		    int number_of_test_cases = Integer.parseInt(b.readLine().split(" ")[0]);
		    for( int tc = 0; tc < number_of_test_cases; tc++) {
		    	String si = b.readLine();
			    StringBuilder so = new StringBuilder();
			    for(int i=0;i<si.length();i++){
			    	so.append(G.get(si.charAt(i)));
				}
			    out.write("Case #"+(tc+1)+": "+so.toString()+newLine);
				
			}
		} catch (IOException e) {
			System.out.println("Exception : "+e);
		}
		finally {
			if(out != null){
				try {
					out.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
	
	private static int[] convertToInt(String line, int size){
		int[] rtn = new int[size];
		String data[] = line.split(" ");
		for(int i=0;i< data.length ;i++){
			rtn[i]=Integer.parseInt(data[i].trim());
		}
		return rtn;
	}
	
}
