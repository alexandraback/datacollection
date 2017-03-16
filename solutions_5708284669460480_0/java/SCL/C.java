import java.io.*;
import java.math.BigDecimal;

public class C {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2015R1C/io/B-small-attempt2.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2015R1C/io/output.txt"));
		
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			String[] s = input.readLine().split(" ");
			int K = Integer.parseInt(s[0]);
			int L = Integer.parseInt(s[1]);
			int S = Integer.parseInt(s[2]);
			String Ks = input.readLine();
			String Ls = input.readLine();
			int[] count = new int[26];
			for(int j = 0 ; j < K ; j++){
				count[Ks.charAt(j) - 65]++;
			}
			double canmake = 1;
			for(int j = 0 ; j < L ; j++){
				canmake *= ((double)count[Ls.charAt(j) - 65] / K);
			}
			if(canmake != 0){
				int bestmake = S / L;
				int max = (int)Math.pow(K, S) - 1;
				double counted = 0;
				for(int j = 0 ; j <= max ; j++){
					String st = Integer.toString(j,K);
					while(st.length() != S){
						st = "0"+st;
					}
					String newst = "";
					for(int k = 0 ; k < S ; k++){
						newst += Ks.charAt(Character.digit(st.charAt(k), 10));
					}
					int length = countStringInString(newst,Ls);
					counted += length;
					//System.out.println(bestmake+","+counted+","+(max + 1));
				}
				BigDecimal bi = new BigDecimal(String.valueOf((bestmake - counted / (max + 1))));
				double k3= bi.setScale(6, BigDecimal.ROUND_HALF_UP).doubleValue();
				pw.println("Case #"+(i+1)+": "+k3);
				
			}else{
				pw.println("Case #"+(i+1)+": "+(0.0));
			}

		}
		pw.flush();
		input.close();
		pw.close();
	}
	
	  public static int countStringInString(String target, String searchWord) {
	        return (target.length() - target.replaceAll(searchWord, "").length()) / searchWord.length();
	  }
}
