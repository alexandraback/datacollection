package Round1A;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class TheLastWord {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String inputFile = "/Users/abhishekagarwal/Development/Java/codechef/Google_Codejam_2016/A-small-attempt0.in";
		File file = new File(inputFile);
		BufferedInputStream buf = new BufferedInputStream(new FileInputStream(file));
		BufferedReader r = new BufferedReader(new InputStreamReader(buf, StandardCharsets.UTF_8));
		int t = Integer.parseInt(r.readLine());
		int counter = 1;
		while(t > 0) {
			String ans = "";
			char query[] = r.readLine().toCharArray();
			for(int i=0;i<query.length;i++) {
				if(i==0)
					ans = query[i] + ans;
				else {
					if(query[i] >= ans.charAt(0)) {
						ans = query[i] + ans;
					} else
						ans = ans + query[i];
				}
			}
			System.out.println("Case #"+counter+": " +ans);
			counter++;
			t--;
		}
		
		r.close();
		//p.close();
		
	}

}
