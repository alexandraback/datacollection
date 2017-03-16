import java.util.*;
import java.io.*;

public class A2012 {

	String s  = null;
	String[] sp = null;
	
	
	
	public void run() throws Exception{
		
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("OUTPUT.txt"));
		s = br.readLine();
		int T = Integer.parseInt(s);
		
	
		
		
		
		int t = 1;
		while(t <= T){
			s = br.readLine();
			String[] ss = s.split(" ");
			int A = Integer.parseInt(ss[0]);
			int B = Integer.parseInt(ss[1]);
			s = br.readLine();
			ss = s.split(" ");
			double[] p = new double[A];
			for(int i = 0; i < A; i++){
				p[i] = Double.parseDouble(ss[i]);
			}
			
			
		
			
			double rem = 1.0;
			double[] m = new double[A+1];
			for(int i = 0; i <= A; i++){
				double mati = 0;
				if(i == A){
					mati = rem;
				}
				else{
					mati = rem * (1-p[i]);
				}
				m[A-i] = mati;
				if(i == A){
					break;
				}
				rem*= p[i];
			}
			
			double[] ret = new double[A+2];
			for(int i = 0; i <= A; i++){
				double kaku = m[i];
				for(int j = 0; j <= A+1; j++){
					if(j == A+1){
						int kai = 1 + B + 1;
						ret[j] += kai * kaku;
					}
					else{
						int kai = 0;
						kai += j;
						kai += (B - (A - j));
						kai += 1;
						if(j < i){
							kai += B + 1;
						}
						
						ret[j] += kaku * kai;
					}
				}
			}
			double ans = 1000000000;
			for(int i =0; i < ret.length; i++){
				ans = Math.min(ans, ret[i]);
			}
			
			
			bw.write("Case #" + t + ": " + ans + "\n");
			
			t++;
		}
		
		bw.close();
	}
	

	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		A2012 b = new A2012();
		b.run();

		
	}
	
	

}