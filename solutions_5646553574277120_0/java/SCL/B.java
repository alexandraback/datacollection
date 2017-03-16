import java.io.*;

public class B {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2015R1C/io/C-small-attempt4.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2015R1C/io/output.txt"));
		
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			String[] s = input.readLine().split(" ");
			int C = Integer.parseInt(s[0]);
			int D = Integer.parseInt(s[1]);
			int V = Integer.parseInt(s[2]);
			String[] str = input.readLine().split(" ");
			int[] crs = new int[D];
			for(int j = 0 ; j < D ; j++){
				crs[j] = Integer.parseInt(str[j]);
			}
			int count = 0;
			int now = 0;
			for(int j = 0 ; j < D ; j++){
				if(now >= V)break;
				System.out.println(now+","+j+","+crs[j]);
				if(crs[j] - 1 > now){
					now = now * 2 + 1;
					count++;
					j--;
				}else{
					now += crs[j];
				}
			}
			while(now < V){
				now = now * 2 + 1;
				count++;
			}
			
			pw.println("Case #"+(i+1)+": "+(count));
		}
		pw.flush();
		input.close();
		pw.close();
	}
}