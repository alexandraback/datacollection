import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CodeJam {
	 public static void main(String[] args) throws NumberFormatException, IOException {
	     	BufferedReader br = new BufferedReader(new FileReader("in.txt"));
	     	BufferedWriter bw=new BufferedWriter(new FileWriter("lastword.txt"));
	        
	        int T,N=0,k;
	        String s,win;
	        T = Integer.valueOf(br.readLine());
	        for (int i=0;i<T;i++)
	            {
	        	win="";
	            s=br.readLine();
	            win=String.valueOf(s.charAt(0));
	            for(int j=1;j<s.length();j++)
	            	if(s.charAt(j)<win.charAt(0))win=win+String.valueOf(s.charAt(j));
	            	else win=String.valueOf(s.charAt(j))+win;
	           
	            bw.write("Case #"+(i+1)+": "+win);bw.newLine();
	        }
	        br.close();
	        bw.close();
	   }
}
