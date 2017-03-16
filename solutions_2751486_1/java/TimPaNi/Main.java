import java.io.*;
import java.util.*;


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader fin = new BufferedReader(new FileReader("a_in.in"));
		BufferedWriter fout = new BufferedWriter(new FileWriter("a_out.out"));
				
		char c[] = {'a', 'e', 'i', 'o', 'u'};
		int T = Integer.parseInt(fin.readLine().trim());

		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(fin.readLine());
			String str = st.nextToken();
			int n = Integer.parseInt(st.nextToken());
			long forwordF = 0;
			long ans = 0;
			for(int i = 0 ; i < str.length(); i++){
				boolean flag = true;
				int j = 0;
				for(j = 0; j < n; j++){
					if( i+j >= str.length() ){
						flag = false;
						i = str.length()+1;
						break;
					}
					
					for(char cc : c)
						if( str.charAt(i+j) == cc )
							flag = false;			
					
					if( !flag )
						break;						
				}
				
				if( flag ){
					long front = i + 1 - forwordF;
					long back = str.length() - (i + n - 1);
					
					ans += front * back;
					forwordF = i+1;
				}
				else{
					i += j;
				}
			}
			
			fout.write("Case #" + t + ": " + ans + "\n");
		}


		// fout.write("Case #" + t + ": " + ansCount + "\n");
		fin.close();
		fout.close();
	}
}