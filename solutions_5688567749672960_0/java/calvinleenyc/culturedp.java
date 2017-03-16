import java.util.*;
import java.io.*;
//code by cl3488
public class culturedp {
	public static String reverse(String s){
		return new StringBuilder(s).reverse().toString();
	}
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("culture.in"));
		PrintWriter out = new PrintWriter(new FileWriter("culture2.out"));
		int T = Integer.parseInt(f.readLine());
		for(int tc=1;tc<=T;tc++){
			out.print("Case #" + tc + ": ");
			String s = f.readLine();
			int N = Integer.parseInt(s);
			//BFS
			ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
			HashMap<Integer, Integer> dist = new HashMap<Integer, Integer>();
			Q.add(0);
			dist.put(0, 0);
			while(true){
				int x = Q.removeFirst();
				if(x == N){
					out.println(dist.get(x));
					break;
				}
				int option1 = x+1;
				int option2 = Integer.parseInt(reverse(Integer.toString(x)));
				if(!dist.containsKey(option1) || dist.get(option1) > dist.get(x) + 1){
					dist.put(option1, dist.get(x) + 1);
					Q.addLast(option1);
				}
				if(!dist.containsKey(option2) || dist.get(option2) > dist.get(x) + 1){
					dist.put(option2, dist.get(x) + 1);
					Q.addLast(option2);
				}
			}
		}
		out.close();
	}
}
