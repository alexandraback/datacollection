import java.util.*;
import java.io.*;

public class tt {	
	public static void main(String[] args) throws Exception {
		InputStream is = null;
		OutputStream os = null;
		try {
			is = new FileInputStream("c:/users/user/desktop/input.txt");
			os = new FileOutputStream("c:/users/user/desktop/output.txt");
			
	        BufferedReader reader = new BufferedReader(new InputStreamReader(is));
	        PrintWriter writer = new PrintWriter(os);
	        int cnt = Integer.parseInt(reader.readLine());
	        for (int i=0;i<cnt;++i) {
	        	//String[] lines = new String[4];
	        	//for (int j=0;j<4;++j)lines[j]=reader.readLine();
	        	String[] eles = reader.readLine().split(" ");
	        	writer.println("Case #" + (i+1) + ": " + 
	        			new tt().solve(Long.parseLong(eles[0]), Long.parseLong(eles[1])));
	        }
	        writer.flush();
		} finally {
			if (is != null)is.close();
			if (os != null)os.close();
		}
	}
	
	String solve(long r, long t) {
		long min = 1, max = 807106780L;
		while (min<max) {
			long n = (min + max) /2;
			if (n == min)n=min+1;
			long v1=t/n;
			long v2=(2 * r + 2 * n -1);
			if (v1 >= v2) min = n;
			else max = n -1;
		}
		return ""+min;
	}
	
}