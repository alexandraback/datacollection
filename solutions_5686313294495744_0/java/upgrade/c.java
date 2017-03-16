package codejam2016.r1b;


import java.util.*;
import java.io.*;
public class c {
	public static void main(String[] args) throws Exception {
		Scanner scanner = null;
		OutputStream os = null;
		try {
			String testFolder = "c:/users/HP/desktop/coding/google/test_files/codejam2016/r1b/";
			scanner = new Scanner(new File(testFolder + "C-small-attempt0.in"));
			os = new FileOutputStream(testFolder + "C-small-attempt0.out");
			
	        PrintWriter writer = new PrintWriter(os);
	        int cnt = scanner.nextInt();
	        for (int i=0;i<cnt;++i) {
	        	int n=scanner.nextInt();
	        	String[][]strs=new String[n][2];
	        	for (int j=0;j<n;++j){
	        		strs[j][0]=scanner.next();
	        		strs[j][1]=scanner.next();
	        	}
	        	String line = "Case #" + (i+1) + ": " + 
	        			new c().solve(n, strs);
	        	System.out.println(line);
	        	writer.println(line);
	        }
	        writer.flush();
		} finally {
			if (scanner != null)scanner.close();
			if (os != null)os.close();
		}
	}
	int res=0;	
	int n;
	int[][] ids;
	
	void go(int mask1, int mask2, int uval, int tr) {
		if (uval==(1<<n)-1) {
			if (tr>res)res=tr;
			return;
		}
		// let it not fake
		int id1,id2;
		int pmask1=mask1,pmask2=mask2,puval=uval,ptr=tr;
		for (int i=0;i<n;++i) {
			if (((1<<i) & uval)==0) {
				id1=ids[i][0];
				id2=ids[i][1];
				mask1|=(1<<id1);
				mask2|=(1<<id2);
				uval|=(1<<i);
				for (int j=0;j<n;++j) {
					int tid1=ids[j][0];
					int tid2=ids[j][1];
					if (((1<<j) & uval)==0 && ((1<<tid1)&mask1) > 0 && ((1<<tid2)&mask2) > 0) {
						++tr;
						uval|=(1<<j);
					}
				}
				go(mask1,mask2,uval,tr);
				mask1=pmask1; mask2=pmask2; uval=puval; tr=ptr;
			}			
		}
	}
	
	String solve(int n, String[][] strs) {
		this.n=n;
		this.ids=new int[n][2];
		int id1=0,id2=0;
		HashMap<String,Integer> map1=new HashMap<String,Integer>();
		HashMap<String,Integer> map2=new HashMap<String,Integer>();
		int[][] nums=new int[n][2];
		for (int i=0;i<n;++i) {
			String str=strs[i][0];
			if (!map1.containsKey(str)) {
				map1.put(str, id1++);
			}
			ids[i][0]=map1.get(str);
			nums[ids[i][0]][0]++;
			
			str=strs[i][1];
			if (!map2.containsKey(str)) {
				map2.put(str, id2++);
			}
			ids[i][1]=map2.get(str);
			nums[ids[i][1]][1]++;
		}
		
		int mask1=0,mask2=0,uval=0;
		for (int i=0;i<n;++i) {
			id1=ids[i][0];
			id2=ids[i][1];
			if (nums[id1][0] == 1 || nums[id2][1] == 1) {
				mask1|=(1<<id1);
				mask2|=(1<<id2);
				uval|=(1<<i);
			}
		}

		for (int i=0;i<n;++i) {
			id1=ids[i][0];
			id2=ids[i][1];
			if (((1<<i) & uval)==0 && ((1<<id1)&mask1) > 0 && ((1<<id2)&mask2) > 0) {
				++res;
				uval|=(1<<i);
			}
		}
		
		go(mask1,mask2,uval,res);
		
		return res+"";
	}
}