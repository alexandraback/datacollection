import java.io.*;
import java.lang.*;
class Solution {
	public static void main (String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int cases = Integer.parseInt(br.readLine());
			String[] line;
			int ans;
			int maxShy;
			int totalPeople;
			int people;
			String data;
			for (int i = 1; i <= cases; i++) {
				ans=0;
				totalPeople=0;
				line=br.readLine().trim().split(" ");
				maxShy = Integer.parseInt(line[0]);
				data = line[1];
				for (int j = 0; j <= maxShy; j++) {
					people = (int) (data.charAt(j)-'0');
					if (j-totalPeople > ans) {
						ans = j-totalPeople;
					}
					totalPeople+=people;
				}
				System.out.println("Case #"+i+": "+ans);
			}
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

}