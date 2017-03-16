package codejam2016.r1b;


import java.util.*;
import java.io.*;
public class a {
	public static void main(String[] args) throws Exception {
		Scanner scanner = null;
		OutputStream os = null;
		try {
			String testFolder = "c:/users/HP/desktop/coding/google/test_files/codejam2016/r1b/";
			scanner = new Scanner(new File(testFolder + "A-large.in"));
			os = new FileOutputStream(testFolder + "A-large.out");
			
	        PrintWriter writer = new PrintWriter(os);
	        int cnt = scanner.nextInt();
	        for (int i=0;i<cnt;++i) {
	        	String str=scanner.next();
	        	String line = "Case #" + (i+1) + ": " + 
	        			new a().solve(str.toCharArray());
	        	System.out.println(line);
	        	writer.println(line);
	        }
	        writer.flush();
		} finally {
			if (scanner != null)scanner.close();
			if (os != null)os.close();
		}
	}

	static int[] nums=new int[2000];
	String solve(char[] chs) {
		int tn=0;
		int[] cns=new int[26];
		for(char ch:chs)++cns[ch-'A'];
		
		String[] tstrs=new String[] {"ZERO","TWO","FOUR","SIX","EIGHT"};
		char[] tchs=new char[]{'Z','W','U','X','G'};
		int[] tvs=new int[]{0,2,4,6,8};
		for (int i=0;i<tchs.length;++i) {
			int tch=tchs[i]-'A';
			int sub=cns[tch];
			if(sub>0) {
				for (char ch:tstrs[i].toCharArray()) {
					cns[ch-'A']-=sub;
				}
			}
			for (int j=0;j<sub;++j)nums[tn++]=tvs[i];
		}
		
		tstrs=new String[] {"ONE","THREE","FIVE","SEVEN"};
		tchs=new char[]{'O','R','F','S'};
		tvs=new int[]{1,3,5,7};
		for (int i=0;i<tchs.length;++i) {
			int tch=tchs[i]-'A';
			int sub=cns[tch];
			if(sub>0) {
				for (char ch:tstrs[i].toCharArray()) {
					cns[ch-'A']-=sub;
				}
			}
			for (int j=0;j<sub;++j)nums[tn++]=tvs[i];
		}	

		tstrs=new String[] {"NINE"};
		tchs=new char[]{'I'};
		tvs=new int[]{9};
		for (int i=0;i<tchs.length;++i) {
			int tch=tchs[i]-'A';
			int sub=cns[tch];
			if(sub>0) {
				for (char ch:tstrs[i].toCharArray()) {
					cns[ch-'A']-=sub;
				}
			}
			for (int j=0;j<sub;++j)nums[tn++]=tvs[i];
		}	
		
		for (int cn:cns)if (cn!=0)throw new RuntimeException("err");
		
		Arrays.sort(nums, 0, tn);
		String res="";
		for (int i=0;i<tn;++i)res+=nums[i];
		return res;
	}
}