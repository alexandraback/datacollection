package a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import javax.swing.JTree;

public class EjA {
	public static void main(String[] args) {

        ArrayList<String> list = new ArrayList<String>();

        try {

            FileReader fileReader =  new FileReader("A-large.in");

            BufferedReader br = new BufferedReader(fileReader);
            
            int testCases = Integer.valueOf(br.readLine());
            
            for (int i = 1; i <= testCases; i++){
            	String st = br.readLine();
            	list.add(lastWord(st));
            	//System.out.println("TestCase : "+String.valueOf(i)+"  : "+stSplited[0]+" Columns : "+stSplited[1]+" Width : "+stSplited[2]);
            }

            br.close();
            writeFile(list);
        } catch(Exception ex) {
            System.out.println("Error reading file");                  

        }
	}
	
	public static String lastWord(String s) {
		String output = "";
		
		for (int i = 0; i < s.length(); i++){
			if (i == 0) {
				output = output.concat(String.valueOf(s.charAt(i)));
			} else {
				if (((int) output.charAt(0)) > ((int) s.charAt(i))){
					output = output.concat(String.valueOf(s.charAt(i)));
				}else {
					output = String.valueOf(s.charAt(i)).concat(output);
				}
			}
		}
		
		return output;
	}
	
	
	public static void writeFile (ArrayList<String> l){
		try {
			PrintWriter writer = new PrintWriter("output_a_large.txt", "UTF-8");
			for (int i = 0; i < l.size() ; i++ ){
				writer.println("Case #"+String.valueOf(i+1)+": "+l.get(i));
			}
			writer.close();
		} catch (Exception e){
			 System.out.println("Error writing file");
		}
	}


}