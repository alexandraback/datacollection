import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashSet;
import java.util.List;


public class C {
	static String file = "C-large";
	static String dictionary = "garbled_email_dictionary.txt";
	static HashSet<String> dic = new HashSet<String>();
	static int maxL = -1;
	
	static int[][] cache = null;
	
	static char[] letters = new char[] {'a', 'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	public static void main(String[] args) throws IOException {	
		
		Calendar cal = Calendar.getInstance();
		Date start = cal.getTime();
		
		FileInputStream fis2 = new FileInputStream(dictionary);
		InputStreamReader isr2 = new InputStreamReader(fis2);
		BufferedReader br2 = new BufferedReader(isr2);
		String line = null;		
		while ((line = br2.readLine()) != null) {
			dic.add(line);
			maxL = Math.max(maxL, line.length());
		}
		
		System.out.println(maxL);
		
		FileInputStream fis = new FileInputStream(file+ ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 0;
		for (int i = 0; i < problemCount; i++) {
			String msg = lines.get(++currentIndex);
			
			cache = new int[msg.length()+1][msg.length()+2];
			for (int j = 0; j < cache.length; j++) {
				for (int j2 = 0; j2 < cache[0].length; j2++) {
					cache[j][j2] = -1;
				}
			}
			
			long solution = getSolution(msg,0,-1);
			String r = "Case #" + (i+1) + ": " + solution;
						
			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
		
		cal = Calendar.getInstance();
		Date end = cal.getTime();

		System.out.println("T = " + (end.getTime() - start.getTime()));
	}
	
	public static long getSolution(String msg, int cur, int last)
	{
		if(cur>=msg.length())
			return 0;
		
		if (cache[cur][last+1] > -1)
		{
			return cache[cur][last+1];
		}
		
		int s = Integer.MAX_VALUE;
		
		for (int l = 1; l <= maxL; l++) {			
			if (msg.length()<cur+l)
				break;
			
			String tmp = msg.substring(cur,cur+l);
			
			if (dic.contains(tmp))
			{
				long s1 = getSolution(msg,cur+l,last);
				s = (int) Math.min(s, s1);
			}
			
			char[] current = tmp.toCharArray();
			int low = Math.max(0,5-(cur-last));
			if (last ==-1)
				low = 0;
			for (int i = low; i < tmp.length(); i++) {											
				for (int j = 0; j < letters.length; j++) {
			
					StringBuilder sb = new StringBuilder();
					for (int j2 = 0; j2 < i; j2++) {
						sb.append(current[j2]);
					}
					sb.append(letters[j]);
					for (int j2 = i+1; j2 < current.length; j2++) {
						sb.append(current[j2]);
					}					
					String t = sb.toString();
					
					//System.out.println(t);
					if (dic.contains(t))
					{
						long s1 = getSolution(msg,cur+l,cur+i);
						s = (int) Math.min(s, s1+1);
					}
					
				}						
			} // for
			
			for (int i = low; i < tmp.length(); i++) { // prva zmena
				for (int j = i+5; j < tmp.length(); j++) { // druha zmena
					for (int j2 = 0; j2 < letters.length; j2++) { // prva zmena value
						for (int j3 = 0; j3 < letters.length; j3++) { // druha zmena value
							StringBuilder sb = new StringBuilder();
							for (int x = 0; x < i; x++) {
								sb.append(current[x]);
							}
							sb.append(letters[j2]);
							for (int x = i+1; x < j; x++) {
								sb.append(current[x]);
							}					
							sb.append(letters[j3]);							
							for (int x = j+1; x < current.length; x++) {
								sb.append(current[x]);
							}
							
							String t = sb.toString();												
							if (dic.contains(t))
							{
								long s1 = getSolution(msg,cur+l,cur+j);
								s = (int) Math.min(s, s1+2);
							}		
						}
					}
				}
			}// for
		}
				
		cache[cur][last+1] = s;		
		
		return s;
	}
}

