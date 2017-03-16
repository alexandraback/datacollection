//Program by Matthew Savage
//With help from the TJHSST SCT Grader Example Class

import java.io.*;
import java.util.*;

public class names{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("names.out")));
		
		int testCases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= testCases; t++){
			pw.print("Case #" + t + ": ");
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			String name = st.nextToken();
			int n = Integer.parseInt(st.nextToken());
			
			int cnt = 0;
			int ans = 0;
			int last = -1;
			for(int i = 0; i < name.length(); i++){
				char c = name.charAt(i);
				if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
					cnt = 0;
				} else {
					cnt++;
					if(cnt == n){
						ans += (name.length() - i) * (i - last - n + 1);
						last = i-n+1;
						cnt--;
					}
				}
			}
			
			pw.println(ans);
		}
		
		br.close();
		pw.close();
	}
}