/**
 * 
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * @author rohit
 *
 */
public class QR16_D {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader(new File("/home/rohit/Desktop/codejam/d/small.in"));
		BufferedReader br = new BufferedReader(fr);
		
		FileWriter fw = new FileWriter(new File("/home/rohit/Desktop/codejam/d/small.out"));
		BufferedWriter bw = new BufferedWriter(fw);
		
		int tc = Integer.valueOf(br.readLine().trim());
		for(int i=0;i<tc;i++){
			String s[] = br.readLine().trim().split(" ");
			
			int k = Integer.valueOf(s[0].trim());
			int c = Integer.valueOf(s[1].trim());
			int ss = Integer.valueOf(s[2].trim());
			
			bw.write("Case #" + (i+1) + ":");
			for(int j=1;j<=k;j++){
				bw.write(" " + j);
			}
			bw.write("\n");

		}
		
		bw.close();
		br.close();
		fw.close();
		fr.close();
	}

	
	private static String getNext(String s) {

		int i=s.length()-1;
		StringBuffer sb = new StringBuffer();
		for(;i>=0;i--){
			if(s.charAt(i)=='0')
				break;
		}
		for(int j=0;j<i;j++){
			sb.append(s.charAt(j));
		}
		sb.append("1");
		for(int j=i+1;j<s.length();j++){
			sb.append("0");
		}
		return sb.toString();
	}
}
