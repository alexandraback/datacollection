import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class GB {
	String s  = null;
	String[] sp = null;
	
	
	
	public void run() throws Exception{
		
		BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("OUTPUT.txt"));
		s = br.readLine();
		int T = Integer.parseInt(s);
		
		
		int t = 1;
		while(t <= T){
			s = br.readLine();
			sp = s.split(" ");
			int N = Integer.parseInt(sp[0]);
			int S = Integer.parseInt(sp[1]);
			int p = Integer.parseInt(sp[2]);
			
			int[] sco = new int[N];
			for(int i = 0; i < N; i++){
				sco[i] = Integer.parseInt(sp[i+3]);
			}
			
			int ans = 0;
			
			if(p == 0){
				ans = N;
			}
			else if(p == 1){
				for(int i = 0; i < sco.length; i++){
					if(sco[i] > 0){
						ans++;
					}
				}
			}
			else{
				
				int ut = p * 3 - 2;
				int bt = p * 3 - 4;
				int bn = 0;
				for(int i = 0; i < sco.length; i++){
					if(sco[i] >= ut){
						ans++;
					}
					else if(sco[i] >= bt){
						bn++;
					}
				}
				ans += Math.min(S, bn);
			}
			
			bw.write("Case #" + t + ": " + ans +  "\n");

			t++;
		}
		
		bw.close();
	}
	

	
	

	public static void main(String[] args) throws Exception {
		GB b = new GB();
		b.run();
	}

}
