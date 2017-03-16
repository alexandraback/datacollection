package qual;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;

public class p3 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}

	private static final ArrayList<String> palin = new ArrayList<String>();	
	private static final ArrayList<BigInteger> bs = new ArrayList<BigInteger>();
	private static void prep() {
		palin.add("1");
		palin.add("2");
		palin.add("3");
		gen("",0,27,0,0);
		Collections.sort(palin,mycomp);
	}
	
	private static void gen(String s, int l,int max,int oc,int tc) {
		if(l==max) return;
		if(l > 0) {
			if (tc == 0 && l <= max - 1 && oc<=2) {
				mirror(s + "2", false);
			}
			if(l <= max-1 && oc<5) {
				mirror(s + "1", false);
			}
			if(l <= max-1)
			{
				mirror(s + "0", false);
			}
			mirror(s, true);
		}
		if(l > 0) gen(s+"0",l+1,max,oc,tc);
		if(tc < 1 && l==0) gen(s+"2",l+1,max,oc,tc+1);
		if(oc < 4 && tc==0) gen(s+"1",l+1,max,oc+1,tc);
	}
	private static void mirror(String s,boolean both) {
		StringBuilder sb = new StringBuilder(s);
		sb.reverse();
		if(both) {
			palin.add(s + sb.toString());
		}
		else
		{
			sb.delete(0, 1);
			palin.add(s + sb.toString());
		}
	}
	
	private static String solve(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		BigInteger a=new BigInteger(st.nextToken());
		BigInteger b=new BigInteger(st.nextToken());
				
		int l1 = Collections.binarySearch(bs, a);
		int l2 = Collections.binarySearch(bs, b);
		//debug(l2,l1);
		if(l1 < 0) l1=-(l1+1);
		if(l2 < 0) l2=-(l2+2);
		return "" + (l2 - l1 + 1);
	}
	

	public static void main(String[] rags) throws Exception {
		
		prep();
		//debug(palin);
		//int cnt=0;
		for(String s : palin) {
			BigInteger bi = new BigInteger(s);
			BigInteger res = bi.multiply(bi);
			//if(!isPal(res.toString())) {
				//debug(bi,res,"!!!!!");
				//cnt++;
			//}
			bs.add(res);
		}
		//debug(bs);
		//debug(cnt);
		//debug(bs.size());
		//HashSet<BigInteger> hs = new HashSet<BigInteger>();
		//hs.addAll(bs);
		//debug(hs.size());
		//debug("done");
		//debug(bs.get(bs.size()-1));
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
	
	private static final Comparator<String> mycomp = new Comparator<String> () {
		public int compare(String o1, String o2) {
			if(o1.length() != o2.length()) return o1.length() - o2.length();
			return o1.compareTo(o2);
		}
	};
	
	public static boolean isPal(String p) {
		int n=p.length();
		for(int i=0;i<n/2;i++) {
			if(p.charAt(i) != p.charAt(n - i - 1)) return false;
		}
		return true;
	}
}
