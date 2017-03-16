package round1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;

public class ProblemB {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		Locale.setDefault(Locale.US);
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt2.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("B-small-attempt2.out"));

		int t = Integer.parseInt(br.readLine());
		for (int i=1; i<=t; i++){
			int n = Integer.parseInt(br.readLine());
			int levels[] = new int[n*2];
			boolean win[] = new boolean[n*2];
			for (int j=0; j<n; j++){
				int pos = 2*j;
				String linha[] = br.readLine().split(" ");
				levels[pos]   = Integer.parseInt(linha[0]);
				levels[pos+1] = Integer.parseInt(linha[1]);
				win[pos] = win[pos+1] = false;
			}
			
			int nwin = 0;
			int stars = 0;
			int ngames = 0;
			//System.out.println("Case " + i);
			while (nwin < n){
				boolean ok = false;
				for (int j=0; j<n; j++){
					int pos = 2*j+1; 
					if (!win[pos] && levels[pos] <= stars){
						stars += win[pos-1]? 1: 2;
						win[pos] = ok = true;
						nwin++;
						ngames++;
						break;
					}
				}
				if (ok) continue;
				

				for (int j=0; j<n; j++){
					int pos = 2*j; 
					if (!win[pos] && !win[pos+1] && levels[pos] <= stars){
						stars += 1;
						win[pos] = ok = true;
						ngames++;
						break;
					}
				}
				if (!ok) break;
			}
			
			if (nwin < n)
				bw.write(String.format("Case #%d: Too Bad\n", i));
			else
				bw.write(String.format("Case #%d: %d\n", i, ngames));
		}
		
		br.close();
		bw.close();
	}
}
