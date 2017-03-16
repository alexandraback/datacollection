package recycled;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Main {

	public static void main(String[] args) throws IOException {
		File file = new File("C-small-attempt0.in");
		FileReader fr = new FileReader(file);
		BufferedReader in = new BufferedReader(fr);
		
		String line=in.readLine();
		String[] tokens;
		int num = Integer.parseInt(line);
		int i=1;
		int A,B;
		String str;
		int n,count;
		while(i<=num){
			line=in.readLine();
			tokens = line.split(" ");
			A = Integer.parseInt(tokens[0]);
			B = Integer.parseInt(tokens[1]);
			count = 0;
			for(int m=A;m<B;m++){
				str = Integer.toString(m);
				for(int j=0;j<str.length()-1;j++){
					str = str.substring(1) + str.charAt(0);
					n = Integer.parseInt(str);
					if(n>m && n<=B){
						count++;
					}
					if(n==m){
						break;
					}
				}
			}
			
			System.out.println("Case #"+i+": "+count);
			i++;
		}
	}

}
