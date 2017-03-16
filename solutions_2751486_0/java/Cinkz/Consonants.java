import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Consonants {
	
	public static int nValuePart(int preStart, int preClen, int start, int clen, int n, int len, boolean first) {
		int ans;
		if (first)
			ans = (start + 1) * (len - (start + n) + 1);
		else
			ans = (start - (preStart + preClen - (n - 1)) + 1) * (len - (start + n) + 1);
		for (int i = 1; i <= clen - n; i++) {
			ans += (len - (start + i + n) + 1);
		}
		return ans;
	}

	public static void main(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
			BufferedWriter out = new BufferedWriter(new FileWriter(args[1]));
			int cases = Integer.valueOf(in.readLine());
			String line;
			String[] tmp;
			for (int c = 1; c <= cases; c++) {
				line = in.readLine();
				tmp = line.split(" ");
				String name = tmp[0];
				int n = Integer.valueOf(tmp[1]);
				int len = name.length();
				int[] startPoint = new int[len];
				int[] conLen = new int[len];
				for (int i = 0; i < len; i++) {
					startPoint[i] = -1;
					conLen[i] = -1;
				}
				Pattern p = Pattern.compile("[bcdfghjklmnpqrstvwxyz]{" + n + ",}");
				Matcher m = p.matcher(name);
				
				int start = 0;
				int count = 0;
				
				while(m.find(start)) {
					String s = m.group(0);
					int cLen = s.length();
					
					start = m.end();
					startPoint[count] = start - cLen;
					conLen[count] = cLen;
					count++;
				}
				
				int ans = 0;
				
				for (int i = 0; i < len; i++) {
					if (startPoint[i] == -1)
						break;
					if (i == 0) {
						ans += nValuePart(-1, 1, startPoint[i], conLen[i], n, len, true);
					}
					else {
						ans += nValuePart(startPoint[i - 1], conLen[i - 1], startPoint[i], conLen[i], n, len, false);
					}
					
				}
				out.write("Case #" + c + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}
