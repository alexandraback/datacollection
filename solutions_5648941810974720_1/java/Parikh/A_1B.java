package coding;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class A_1B {
	
	public static void main(String args[]) throws IOException {
		FileReader fileReader = new FileReader(
				"/home/parikh/Downloads/A-large(2).in");
		BufferedReader obj = new BufferedReader(fileReader);
		PrintWriter write = new PrintWriter(new File("/home/parikh/output.txt"));
		String l = obj.readLine();
		int t = Integer.parseInt(l);
		for (int k = 1; k <= t; k++) {
			String inp = obj.readLine();
			int arr[] = new int[10];
			int a[] = new int[26];
			for (int  i = 0;i<inp.length();i++){
				char c = inp.charAt(i);
				a[c-'A']++;
			}
			
			if (a['Z' - 'A']!=0){
				int  v = a['Z'-'A'];
				arr[0] = v;
				a['Z' - 'A'] -=v;
				a['E' - 'A'] -=v;
				a['R' - 'A'] -=v;
				a['O' - 'A'] -=v;
			}
			
			if (a['U' - 'A']!=0){
				int  v = a['U'-'A'];
				arr[4] = v;
				a['F' - 'A'] -=v;
				a['O' - 'A'] -=v;
				a['U' - 'A'] -=v;
				a['R' - 'A'] -=v;
			}
			
			if (a['W' - 'A']!=0){
				int  v = a['W'-'A'];
				arr[2] = v;
				a['T' - 'A'] -=v;
				a['W' - 'A'] -=v;
				a['O' - 'A'] -=v;
				
			}
			
			if (a['X' - 'A']!=0){
				int  v = a['X'-'A'];
				arr[6] = v;
				a['S' - 'A'] -=v;
				a['I' - 'A'] -=v;
				a['X' - 'A'] -=v;
				
			}
			
			if (a['G' - 'A']!=0){
				int  v = a['G'-'A'];
				arr[8] = v;
				a['E' - 'A'] -=v;
				a['I' - 'A'] -=v;
				a['G' - 'A'] -=v;
				a['H' - 'A'] -=v;
				a['T' - 'A'] -=v;
				
			}
			
			if (a['F' - 'A']!=0){
				int  v = a['F'-'A'];
				arr[5] = v;
				a['F' - 'A'] -=v;
				a['I' - 'A'] -=v;
				a['V' - 'A'] -=v;
				a['E' - 'A'] -=v;
				
			}
			
			if (a['V' - 'A']!=0){
				int  v = a['V'-'A'];
				arr[7] = v;
				a['S' - 'A'] -=v;
				a['E' - 'A'] -=v;
				a['V' - 'A'] -=v;
				a['E' - 'A'] -=v;
				a['N' - 'A'] -=v;
				
			}
			
			if (a['T' - 'A']!=0){
				int  v = a['T'-'A'];
				arr[3] = v;
				a['T' - 'A'] -=v;
				a['H' - 'A'] -=v;
				a['R' - 'A'] -=v;
				a['E' - 'A'] -=v;
				a['E' - 'A'] -=v;
				
			}
			
			if (a['O' - 'A']!=0){
				int  v = a['O'-'A'];
				arr[1] = v;
				a['O' - 'A'] -=v;
				a['N' - 'A'] -=v;
				a['E' - 'A'] -=v;
				
				
			}
			
			if (a['N' - 'A']!=0){
				int  v = a['E'-'A'];
				arr[9] = v;
				a['N' - 'A'] -=v;
				a['I' - 'A'] -=v;
				a['N' - 'A'] -=v;
				a['E' - 'A'] -=v;
				
				
			}
			StringBuilder builder = new StringBuilder("");
			for (int i=0;i<10;i++){
				for (int j=1;j<=arr[i];j++)
					builder.append(i);
			}
			String ans  = builder.toString();
			
			write.println("Case #" + k + ": " + ans );
		}
		
		write.close();
	}

}
