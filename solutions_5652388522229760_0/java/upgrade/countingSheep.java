package codejam2016.q;


import java.util.*;
import java.io.*;
public class countingSheep {
	public static void main(String[] args) throws Exception {
		Scanner scanner = null;
		OutputStream os = null;
		try {
			String testFolder = "c:/users/HP/desktop/coding/google/test_files/codejam2016/q/";
			scanner = new Scanner(new File(testFolder + "A-small-attempt1.in"));
			os = new FileOutputStream(testFolder + "A-small-attempt1.out");
			
	        PrintWriter writer = new PrintWriter(os);
	        int cnt = scanner.nextInt();
	        for (int i=0;i<cnt;++i) {
	        	String line = "Case #" + (i+1) + ": " + 
	        			new countingSheep().solve(scanner.nextInt());
	        	System.out.println(line);
	        	writer.println(line);
	        }
	        writer.flush();
		} finally {
			if (scanner != null)scanner.close();
			if (os != null)os.close();
		}
	}
	String solve(int n) {
		if (n==0)return "INSOMNIA";
		int target = (1<<10)-1;
		int tv = 0;
		int val = n;
		while(true) {
			int v=val;
			while(v>0) {
				tv|=(1<<(v%10));
				v/=10;
			}			
			if (tv==target)break;
			val+=n;
		}
		return val+"";
	}
}