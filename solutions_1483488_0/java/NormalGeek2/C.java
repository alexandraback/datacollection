import java.io.*;
import java.util.*;

public class C{
	public static void main(String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("C.txt"));
		PrintWriter fout = new PrintWriter(new FileWriter("Cout.txt"));

		String s = fin.readLine();
		int t = Integer.parseInt(s);
		s = fin.readLine();
		for(int i = 0; i < t; i++){
			String[] sp = s.split(" ");
			int a = Integer.parseInt(sp[0]);
			int b = Integer.parseInt(sp[1]);

			int count = 0;
			System.out.println(a + " " + b);
			ArrayList<Integer> visited = new ArrayList<Integer>();
			for(int n = a; n <= b; n++){
				String ns = "" + n;
				
				for(int j = 1; j <= ns.length() - 1; j++){
					int m = (int)((n % Math.pow(10, ns.length() - j)) * Math.pow(10, j)) + (n / (int)Math.pow(10, ns.length() - j));
					if(!visited.contains(m) && m > n && m >= a && m <= b){
						count++;
						visited.add(m);
						//System.out.println(n + " " + m);
					}
					
				}
				visited.clear();
			}

			//count /= 2;

			fout.println("Case #" + (i + 1) + ": " + count);
			fout.flush();
			s = fin.readLine();
		}
	}
}