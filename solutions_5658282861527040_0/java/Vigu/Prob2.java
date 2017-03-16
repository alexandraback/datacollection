package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.BitSet;

public class Prob2 {
	public static void main(String[] args) throws IOException {
		BufferedReader bi = new BufferedReader(new FileReader("/Users/vigneshiyer/Desktop/a.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("/Users/vigneshiyer/Desktop/op.txt"));
		String line;
		int t = Integer.parseInt(bi.readLine());
		String[] result = new String[t];
		long a,b,k;
		long count=0;
		String[] temp;
		for (int i = 0; i < result.length; i++) {
			line = bi.readLine();
			temp = line.split(" ");
			a = Long.parseLong((temp[0]));
			b = Long.parseLong(temp[1]);
			k = Long.parseLong(temp[2]);
			if(a<=k || b<=k)
			{
				count = a*b;
			}
			else
			{
				count = k*b+k*(a-k);
				for (long j = k; j < a;  j++) {
					for (long j2 = k; j2 < b; j2++) {
						if((j&j2) < k)
							count++;
					}
				}
				
			}
			result[i] = Long.toString(count);
			count=0;
		}
		for (int i = 0; i < result.length; i++) {
			bw.write("Case #"+(i+1)+": "+result[i]);
			bw.newLine();
			bw.flush();
			//System.out.println("Case #"+(i+1)+": "+result[i]);
		}
		
	}
}
