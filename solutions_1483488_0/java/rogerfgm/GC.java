import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class GC {
	String s  = null;
	String[] sp = null;
	
	
	
	public void run() throws Exception{
		
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("OUTPUT.txt"));
		s = br.readLine();
		int T = Integer.parseInt(s);
		
		
		int t = 1;
		while(t <= T){
			s = br.readLine();
			sp = s.split(" ");
			int ans = 0;
			int a = Integer.parseInt(sp[0]);
			int b = Integer.parseInt(sp[1]);
			
			if(a < 10){
				a = 10;
			}
			while(a < b){
			
				String sa = Integer.toString(a);
				
				Set<String> set = new HashSet<String>();
				for(int i = 1; i < sa.length(); i++){
					String f = sa.substring(0, i);
					String ba = sa.substring(i);
					String ns = ba + f;
					if(set.contains(ns)){
						continue;
					}
					set.add(ns);
					int nb = Integer.parseInt(ns);
					if(nb > a && nb <= b){
						ans++;
					}
				}

				a++;
			}
			
			bw.write("Case #" + t + ": " + ans +  "\n");

			t++;
		}
		
		bw.close();
	}
	

	
	

	public static void main(String[] args) throws Exception {
		GC b = new GC();
		b.run();
	}

}
