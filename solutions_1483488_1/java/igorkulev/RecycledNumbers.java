import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;


public class RecycledNumbers {
	
	public static void main(String[] args) throws Exception {
		int i,j,k;
		int A, B;
		int L;
		String first, second, secondNoLeadingZeros;
		int s;
		HashSet<Integer> hs = new HashSet<Integer>();
		
		BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
		PrintWriter out = new PrintWriter("C-large.out");
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		int res;
		
		for (k=1;k<=T;k++) {
			System.out.println(k+"/"+T);
			st = new StringTokenizer(br.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			L = Integer.toString(A).length();
			res = 0;
			
			for (i=A;i<=B;i++) {
				
				first = Integer.toString(i);
				hs.clear();
				hs.add(i);
				
				for (j=1;j<L;j++) {
					second = first.substring(j)+first.substring(0, j);
					s = Integer.parseInt(second);
					secondNoLeadingZeros = Integer.toString(s);
					if (secondNoLeadingZeros.length() == L) {
						if (( s >= A)&&(s <= B)) {
							if (hs.contains(s) == false) {
								hs.add(s);
								res++;
							}
						}
					}
				}
					
			}
			
			res /= 2;
			out.println("Case #"+k+": "+res);
			
		}
		
		out.close();
		
	}

}
