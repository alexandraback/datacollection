import java.io.*;
import java.util.*;

public class C {

	public static void main(String[] args) throws Exception{
		Scanner input = new Scanner(new File(new File("").getAbsolutePath() + "/input.in"));
		input.useLocale(Locale.US);
		PrintWriter output = new PrintWriter(new File("").getAbsolutePath() + "/output.out", "UTF-8");
		int T = input.nextInt() + 1;
		
		for( int i = 1; i < T; i++ ) {
			output.print("Case #" + i + ": ");
			solve(input, output);
		}
		
		output.flush();
		output.close();
		input.close();
	}
	
	public static void solve(Scanner input, PrintWriter output){
		int N = input.nextInt();
		String[] n = new String[N];
		String[] c = new String[N];
		for(int i = 0; i < N; i++){
			n[i] = input.next();
			c[i] = input.next();
		}
		
		output.println(exp(new ArrayList<String>(), new ArrayList<String>(), new ArrayList<String>(), new ArrayList<String>(),n,c,0));
	}
	public static int exp(ArrayList<String> nc, ArrayList<String> cc, ArrayList<String> no, ArrayList<String> co, String[] n, String[] c,int i){
		if ( i == n.length ) {
			boolean che = true;
			for( int j = 0; j < nc.size(); j++){
				che = false;
				for( int x = 0; x < no.size(); x++){
					if (nc.get(j).equals(no.get(x))){
						che = true;
						break;
					}
				}
				if (!che ) return 0;
			}
			for( int j = 0; j < cc.size(); j++){
				che = false;
				for( int x = 0; x < co.size(); x++){
					if (cc.get(j).equals(co.get(x))){
						che = true;
						break;
					}
				}
				if (!che ) return 0;
			}
			return nc.size();
		}
		nc.add(n[i]);
		cc.add(c[i]);
		int r1 = exp(nc, cc, no, co, n, c, i+1);
		nc.remove(n[i]);
		cc.remove(c[i]);
		no.add(n[i]);
		co.add(c[i]);
		int r2 = exp(nc, cc, no, co, n, c, i+1);
		no.remove(n[i]);
		co.remove(c[i]);
		return Math.max(r1, r2);
	}
}

