import java.io.*;

public class DSmall {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2016/io/D-large.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2016/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			String[] st = input.readLine().split(" ");
			int K = Integer.parseInt(st[0]);
			int C = Integer.parseInt(st[1]);
			int S = Integer.parseInt(st[2]);
			String s = "";
			for(int j = 1 ; j <= K ; j++){
				if(j != K){
					s += j+" ";
				}else{
					s += j;
				}
			}
			if(S == K){
				pw.println("Case #"+(i+1)+": "+s);
			}else{
				pw.println("Case #"+(i+1)+": IMPOSSIBLE");
			}
		}
		pw.flush();
		input.close();
		pw.close();
	}
}
