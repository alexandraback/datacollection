package leetcode;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;

public class Round1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*String[] test = {"CAB","JAM","CODE","ABAAB","CABCBBABC","ABCABCABC"};
		for(int i = 0;i < test.length;i ++)
			System.out.println(form(test[i]));*/
		    Scanner sc = new Scanner(System.in);
		    int T = sc.nextInt();
		    sc.nextLine();
		    //PrintWriter writer = new PrintWriter("the-file-name.txt", "UTF-8");
		    
		    
		    Writer writer = null;

		    try {
		        writer = new BufferedWriter(new OutputStreamWriter(
		              new FileOutputStream("filename.txt"), "utf-8"));

		        for(int i = 0; i < T; i++){
		        	String N = sc.nextLine();
		          	System.out.println(form(N));
		    		writer.write("Case #" + (i+1) + ": " + form(N)+"\n");
		        }
		    } catch (IOException ex) {
		      // report
		    } finally {
		       try {writer.close();} catch (Exception ex) {/*ignore*/}
		    }
	}
	public static String form(String root){
		if(root == null || root.length() == 0)
			return "";
		StringBuilder sb= new StringBuilder();
		sb.append(root.charAt(0));
		for(int i = 1;i < root.length(); i++){
			if(sb.charAt(0) > root.charAt(i)){
				sb.append(root.charAt(i));
			} else {
				sb.insert(0, root.charAt(i));
			}
		}
		return sb.toString();
	}
}
