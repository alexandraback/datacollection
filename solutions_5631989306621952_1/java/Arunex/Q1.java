package round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Q1 {
	public static void main(String[] args) throws IOException {
		FileInputStream in = null;
		in = new FileInputStream("input.in");
		DataInputStream input = new DataInputStream(in);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		String line = "";
		line = br.readLine();
		int numberOfCases = Integer.parseInt(line);
		FileOutputStream out = null;
		out = new FileOutputStream("out.txt");
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));
		
		for(int i =0;i<numberOfCases;i++){
			line = br.readLine();
			
			char[] lineChar = line.toCharArray();
			char first = lineChar[0];
			String answer = lineChar[0]+"";
			for(int j=1;j<lineChar.length;j++){
				if(lineChar[j]>=first){
					first = lineChar[j];
					answer = lineChar[j] + answer;
				} else{
					answer = answer + lineChar[j];
				}
			}
			bw.write("Case #"+(i+1)+": "+answer+"\n");
		}
		br.close();
		bw.close();
	}
}
