package round1a;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemB {

	ProblemB() throws IOException {
		
		Scanner reader = new Scanner(new File("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));
		
		int cases = reader.nextInt();
		
		for(int i = 1; i <= cases; i++) {
			
			int N = reader.nextInt();
			
			int[] os = new int[N], ts = new int[N];
			int[] hs = new int[N];
			int count = 0, stars = 0;
			
			for(int j = 0; j < N; j++) {
				os[j] = reader.nextInt();
				ts[j] = reader.nextInt();
			}
			
			for(int j = 0; j < N; j++) {
				for(int k = j+1; k < N; k++) {
					if(ts[j] > ts[k]) {
						int temp = ts[j];
						ts[j] = ts[k];
						ts[k] = temp;
						temp = os[j];
						os[j] = os[k];
						os[k] = temp;
					}
				}
			}
			
			int tsi = 0;
			
			while(stars<2*N) {
				if(ts[tsi]<=stars) {
					stars += 2-hs[tsi];
					count++;
					hs[tsi] = 2;
					tsi++;
				}
				else {
					int t = -1;
					for(int j = N-1; j >= tsi; j--) {
						if(os[j]<=stars&&hs[j]==0) {
							t = j;
							break;
						}
					}
					if(t == -1) break;
					stars++;
					count++;
					hs[t] = 1;
				}
			}
			
			writer.write("Case #"+i+": "+(stars==2*N?count:"Too Bad"));
			writer.newLine();
		}
		
		reader.close();
		writer.close();
	}
	
	public static void main(String[] args) throws IOException {
		new ProblemB();
	}
}
