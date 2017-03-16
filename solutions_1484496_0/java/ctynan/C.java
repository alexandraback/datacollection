package round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class C {

public static String[] solve(int[] a) {
	
	int[] haveit = new int[2000002];
	Arrays.fill(haveit, -1);
	
	for(int i=0; i<(1<<20); i++) {
		int count = 0;
		for(int j=0; j<20; j++){
			if((i&(1<<j))>0) count+=a[j];
		}
		if(haveit[count]>=0) {
			int N1 = haveit[count];
			int N2 = i;
			
			ArrayList<String> a1 = new ArrayList<String>();
			ArrayList<String> a2 = new ArrayList<String>();
			
			for(int j=0; j<20; j++) {
				if((N1&(1<<j))>0) {
					a1.add(Integer.toString(a[j]));
				}
				if((N2&(1<<j))>0) {
					a2.add(Integer.toString(a[j]));
				}
			}
			
			String[] ret = new String[2]; Arrays.fill(ret, "");
			
			for(int j=0; j<a1.size(); j++) {
				ret[0] += a1.get(j);
				if(j<a1.size()-1) ret[0]+=" ";
			}
			for(int j=0; j<a2.size(); j++) {
				ret[1] += a2.get(j);
				if(j<a2.size()-1) ret[1]+=" ";
			}
			
			return ret;
		}
		else {
			haveit[count]=i;
		}
	}
	
	return new String[]{"Impossible"};
}
	
	
public static void main(String[] args) throws Exception {
		
		String fs_in = "/Users/ctynan/Downloads/test.txt";
		String fs_out = "/Users/ctynan/Documents/C-out.txt";
		String line;
		BufferedReader br = new BufferedReader(new FileReader(fs_in));
		BufferedWriter bw = new BufferedWriter(new FileWriter(fs_out));
		
		line=br.readLine();
		line=line.toLowerCase();
		int tst = Integer.valueOf(line);
		
		for(int ii=0;ii<tst; ii++) {
			line=br.readLine();
			String[] tem = line.split(" ");
			int[] a = new int[tem.length-1];
			for(int i=1; i<a.length; i++) a[i-1] = Integer.valueOf(tem[i]);
			String[] ret = solve(a);
			String output = "Case #" + Integer.toString(ii+1) +":\n";
			bw.write(output);
			if(ret[0]=="Impossible") bw.write(ret[0]);
			else bw.write(ret[0]+'\n'+ret[1]);
			if(ii<tst-1) bw.write('\n');
		}
		bw.close();
		return;
	}
}
