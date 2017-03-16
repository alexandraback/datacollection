package codejam2016.q;


import java.util.*;
import java.io.*;
public class fractiles {
	public static void main(String[] args) throws Exception {
		Scanner scanner = null;
		OutputStream os = null;
		try {
			String testFolder = "c:/users/HP/desktop/coding/google/test_files/codejam2016/q/";
			scanner = new Scanner(new File(testFolder + "D-large.in"));
			os = new FileOutputStream(testFolder + "D-large.out");
			
	        PrintWriter writer = new PrintWriter(os);
	        int cnt = scanner.nextInt();
	        for (int i=0;i<cnt;++i) {
	        	String line = "Case #" + (i+1) + ": " + 
	        			new fractiles().solve(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
	        	System.out.println(line);
	        	writer.println(line);
	        }
	        writer.flush();
		} finally {
			if (scanner != null)scanner.close();
			if (os != null)os.close();
		}
	}
	String solve(int k, int c, int s) {
		int min=(k+c-1)/c;
		if (min > s)return "IMPOSSIBLE";
		String res="";
		int pos=0;
		for (int i=0;i<min;++i) {
			long tv=0;
			for (int j=0;j<c && pos<k;++j) {
				tv=tv*k+pos++;
			}
			res+=" " + (tv+1);
		}
		return res.substring(1);	
	}
}