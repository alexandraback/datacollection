package codejam2016.q;


import java.util.*;
import java.io.*;
public class coinjam {
	public static void main(String[] args) throws Exception {
		Scanner scanner = null;
		OutputStream os = null;
		try {
			String testFolder = "c:/users/HP/desktop/coding/google/test_files/codejam2016/q/";
			scanner = new Scanner(new File(testFolder + "C-large.in"));
			os = new FileOutputStream(testFolder + "C-large.out");
			
	        PrintWriter writer = new PrintWriter(os);
	        int cnt = scanner.nextInt();
	        for (int i=0;i<cnt;++i) {
	        	String line = "Case #" + (i+1) + ":" + 
	        			new coinjam().solve(scanner.nextInt(), scanner.nextInt());
	        	System.out.println(line);
	        	writer.println(line);
	        }
	        writer.flush();
		} finally {
			if (scanner != null)scanner.close();
			if (os != null)os.close();
		}
	}
	String solve(int len, int pn) {
		// small=> len:16, pn:50
		// large=> len:32, pn:500
		long[][] bs=new long[11][17];
		for (int i=2;i<=10;++i) {
			bs[i][0] = 1;
			bs[i][1] = i;
			for (int j=2;j<=16;++j) {
				bs[i][j] = bs[i][j-1] * bs[i][1];
			}
		}
		
		String part2="";
		for (int i=2;i<=10;++i)part2+=" " + (1+bs[i][len/2]);	
		
		String res="";
		for (int i=0;i<pn;++i) {
			String part1="1";
			int tv=i;
			for (int k=0;k<(len/2-2);++k){
				if (tv%2==0)part1+="0";
				else part1+="1";
				tv>>=1;
			}			
			part1+="1";
			res+="\n"+part1+part1+part2;
		}		
		return res;
	}
}