package codejam2016.q;


import java.util.*;
import java.io.*;
public class pancake {
	public static void main(String[] args) throws Exception {
		Scanner scanner = null;
		OutputStream os = null;
		try {
			String testFolder = "c:/users/HP/desktop/coding/google/test_files/codejam2016/q/";
			scanner = new Scanner(new File(testFolder + "B-large.in"));
			os = new FileOutputStream(testFolder + "B-large.out");
			
	        PrintWriter writer = new PrintWriter(os);
	        int cnt = scanner.nextInt();
	        for (int i=0;i<cnt;++i) {
	        	String line = "Case #" + (i+1) + ": " + 
	        			new pancake().solve(scanner.next().toCharArray());
	        	System.out.println(line);
	        	writer.println(line);
	        }
	        writer.flush();
		} finally {
			if (scanner != null)scanner.close();
			if (os != null)os.close();
		}
	}
	String solve(char[] chs) {
		int res=0;
		for (int i=1;i<chs.length;++i) {
			if (chs[i] != chs[i-1])++res;
		}
		if (chs[chs.length-1] == '-')++res;
		return res+"";
	}
}