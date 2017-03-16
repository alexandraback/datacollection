import java.io.*;
import java.text.DecimalFormat;
import java.util.*;
import java.lang.*;

public class monkey{
	int testNum, K, L, S, max, times, totalbanana, len;
	float ans;
	String keyboard, target;
	boolean[] used;
	StringBuffer sb, tmpsb;
	public void findnext(int x){
		int i, j, tmpAns, tmpLen;
		String tmpStr;
		if (x > S){
			times += 1;
			tmpAns = 0;
			for (i = 0; i < sb.length()-target.length()+1; i++){
				tmpsb = new StringBuffer();
				for (j = i; j < i+target.length(); j++){
					tmpsb.append(sb.charAt(j));
				}
				tmpStr = tmpsb.toString();
				if (tmpStr.length() < target.length())
					continue;
				if (tmpStr.compareTo(target) == 0)
					tmpAns += 1;
			}
			totalbanana += tmpAns;
			if (tmpAns > max)
				max = tmpAns;
			return;
		}
		tmpLen = sb.length();
		for (i = 0; i < len; i++){
			sb.append(keyboard.charAt(i));
			findnext(x+1);
			sb.deleteCharAt(tmpLen);
		}
	}
	public void solve(){
		int i, j;
		max = times = totalbanana = 0;
		len = keyboard.length();
		used = new boolean[len];
		sb = new StringBuffer();
		for (i = 0; i < len; i++)
			used[i] = false;
		for (i = 0; i < len; i++){
			sb.append(keyboard.charAt(i));
			findnext(2);
			sb.deleteCharAt(0);
		}
	}
	public void calculate(String filename){
		int testcase, i, j;
		Integer myInt;
		Float myFloat;
		String tmptmp;
		try{
			Scanner fin = new Scanner(new File(filename));
			BufferedWriter fout = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("out.txt")));
			testNum = fin.nextInt();
			for (testcase = 1; testcase <= testNum; testcase++){
				K = fin.nextInt();
				L = fin.nextInt();
				S = fin.nextInt();
				keyboard = fin.next();
				target = fin.next();
				solve();
				ans = (float)((float)max - (float)totalbanana/(float)times);
				myInt = testcase;
				fout.write("Case #"+myInt.toString()+": ");
				DecimalFormat df = new DecimalFormat("#0.0000000");
				tmptmp = df.format(ans);
				fout.write(tmptmp);
				fout.newLine();
				
			}
			fout.close();
			fin.close();
		} catch(Exception e){
			
		}
	}
	public static void main(String[] args){
		monkey myClass = new monkey();
		myClass.calculate("B-small-attempt0.in");
	}
}