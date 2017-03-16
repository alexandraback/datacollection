package codejam2016.r1b;


import java.util.*;
import java.io.*;
public class b {
	public static void main(String[] args) throws Exception {
		Scanner scanner = null;
		OutputStream os = null;
		try {
			String testFolder = "c:/users/HP/desktop/coding/google/test_files/codejam2016/r1b/";
			scanner = new Scanner(new File(testFolder + "B-large.in"));
			os = new FileOutputStream(testFolder + "B-large.out");
			
	        PrintWriter writer = new PrintWriter(os);
	        int cnt = scanner.nextInt();
	        for (int i=0;i<cnt;++i) {
	        	String line = "Case #" + (i+1) + ": " + 
	        			new b().solve(new char[][]{scanner.next().toCharArray(), 
	        					scanner.next().toCharArray()});
	        	System.out.println(line);
	        	writer.println(line);
	        }
	        writer.flush();
		} finally {
			if (scanner != null)scanner.close();
			if (os != null)os.close();
		}
	}
	
	String tostr(long val, int len) {
		String res="";
		for (int i=0;i<len;++i) {
			res=val%10 + res;
			val/=10;
		}
		return res;
	}
	
	long mindiff=Long.MAX_VALUE;
	long minc=-1;
	long minj=-1;
	int len;
	char[][] strs;
	long[][] zeros;
	long[][] nines;
	long[] bases;
	
	void go(int idx, long val1, long val2) {
		if (idx==len) {
			long diff=Math.abs(val1-val2);
			if (diff < mindiff || diff==mindiff && (val1<minc || val1==minc && val2<minj)){
				mindiff = diff;
				minc=val1;
				minj=val2;		
			}
			return;		
		}
		if (val1!=val2) {			
			if (val1<val2)go(len, val1+nines[len-idx][0], val2+zeros[len-idx][1]);
			else go(len, val1+zeros[len-idx][0], val2+nines[len-idx][1]);
			return;
		}
		char ch1=strs[0][idx];
		char ch2=strs[1][idx];
		long base=bases[len-idx];
		if (ch1!='?' && ch2!='?') {
			go(idx+1, val1+base*(ch1-'0'), val2+base*(ch2-'0'));			
		}else if (ch1=='?' && ch2=='?') {
			go(idx+1, val1+base*0, val2+base*1);
			go(idx+1, val1+base*1, val2+base*0);
			go(idx+1, val1+base*0, val2+base*0);
		}else if(ch1!='?'){
			int tv=ch1-'0';
			go(idx+1, val1+base*tv, val2+base*tv);
			if (tv<9)go(idx+1, val1+base*tv, val2+base*(tv+1));
			if (tv>0)go(idx+1, val1+base*tv, val2+base*(tv-1));			
		}else{
			int tv=ch2-'0';
			go(idx+1, val1+base*tv, val2+base*tv);
			if (tv<9)go(idx+1, val1+base*(tv+1), val2+base*tv);
			if (tv>0)go(idx+1, val1+base*(tv-1), val2+base*tv);		
		}
	}
	
	String solve(char[][] strs) {
		this.strs=strs;
		this.len = strs[0].length;
		
		this.zeros=new long[len+1][2]; // left length of chars
		this.nines=new long[len+1][2];
		this.bases=new long[len+1];
		long base = 1;
		for (int i=0;i<len;++i) {
			for (int j=0;j<2;++j) {
				char ch=strs[j][len-1-i];
				if (ch!='?') {
					int tv=ch-'0';
					zeros[i+1][j] = base*tv + zeros[i][j];
					nines[i+1][j] = base*tv + nines[i][j];
				} else {
					zeros[i+1][j] = base*0 + zeros[i][j];
					nines[i+1][j] = base*9 + nines[i][j];
				}
			}
			this.bases[i+1]=base;
			base*=10;
		}
		
		go(0,0,0);//idx,val1,val2
		
		
		return tostr(minc,len) + " " + tostr(minj,len);
	}
}