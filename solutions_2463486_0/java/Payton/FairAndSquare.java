import java.io.*;
import java.util.*;

public class FairAndSquare{
	public static void main(String[] args) throws IOException {
		ArrayList<Long> palindromes = new ArrayList<Long>();
		
		for(long a=1; a<=10000000; a++){
			String x = Long.toString(a);
			String y = (new StringBuilder(x)).reverse().toString();
			if(!x.equals(y)) continue;
			
			long sq = a*a;
			String s = Long.toString(sq);
			String r = (new StringBuilder(s)).reverse().toString();
			if(s.equals(r)){
				palindromes.add(sq);
			}
		}
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
		
		int cases = Integer.valueOf(br.readLine().trim());
		for(int ctr=0; ctr<cases; ctr++){
			String[] ss = br.readLine().trim().split("\\s+");
			
			long start = Integer.valueOf(ss[0]);
			long end = Integer.valueOf(ss[1]);
			int count = 0;
			for(int i=0; i<palindromes.size(); i++){
				long n = palindromes.get(i);
				if(start <= n && n <= end){
					count++;
				}
			}
			out.printf("Case #%d: %d\n", ctr+1, count);
		}
		out.flush();
	}
}
