import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CodeJam2016R1AP1 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int caseid=1; caseid<=T; caseid++)
		{
			String s = br.readLine();
			String res = s.charAt(0)+"";
			for(int i = 1; i < s.length(); i++) {
				if(res.charAt(0) > s.charAt(i)) {
					res = res + s.charAt(i);
				} else {
					res = s.charAt(i) + res;
				}
			}
			
			System.out.println("Case #"+caseid + ": " + res);
		}
		br.close();
	}
}
