import java.io.*;
import java.util.*;
import java.math.*;

public class B {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/B-large.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			String a = sc.next();
			String b = sc.next();
			
			List<String> ans = fill(a,b);
			
			output += "Case #" + i + ": " + ans.get(0)+" "+ans.get(1) + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/B-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
	
	public static List<String> fill(String a, String b) {
		String ansA = "";
		String ansB = "";
		
		if (a.isEmpty()) {
			List<String> ret = new ArrayList<String>();
			ret.add(ansA);
			ret.add(ansB);
			return ret;
		}
		
		long minDiff = Long.MAX_VALUE;
		long minC = Long.MAX_VALUE;
		long minJ = Long.MAX_VALUE;
		
		if (a.charAt(0)!='?'&&b.charAt(0)!='?') {
			if (a.charAt(0)==b.charAt(0)) {
				List<String> next = fill(a.substring(1),b.substring(1));
				ansA += a.charAt(0)+next.get(0);
				ansB += b.charAt(0)+next.get(1);
			} else if (a.charAt(0)>b.charAt(0)) {
				ansA = a.replace("?", "0");
				ansB = b.replace("?", "9");
			} else {
				ansA = a.replace("?", "9");
				ansB = b.replace("?", "0");
			}
		} else if (a.charAt(0)=='?'&&b.charAt(0)=='?') {
			List<String> next1 = fill("0"+a.substring(1),"0"+b.substring(1));
			List<String> next2 = fill("0"+a.substring(1),"1"+b.substring(1));
			List<String> next3 = fill("1"+a.substring(1),"0"+b.substring(1));
			
			long coders = Long.parseLong(next1.get(0));
			long jammers = Long.parseLong(next1.get(1));
			long diff = Math.abs(coders-jammers);
			if (diff < minDiff || (diff==minDiff&&coders<minC) || (diff==minDiff&&coders==minC&&jammers<minJ)) {
				minDiff = diff;
				minC = coders;
				minJ = jammers;
				ansA = next1.get(0);
				ansB = next1.get(1);
			}
			coders = Long.parseLong(next2.get(0));
			jammers = Long.parseLong(next2.get(1));
			diff = Math.abs(coders-jammers);
			if (diff < minDiff || (diff==minDiff&&coders<minC) || (diff==minDiff&&coders==minC&&jammers<minJ)) {
				minDiff = diff;
				minC = coders;
				minJ = jammers;
				ansA = next2.get(0);
				ansB = next2.get(1);
			}
			coders = Long.parseLong(next3.get(0));
			jammers = Long.parseLong(next3.get(1));
			diff = Math.abs(coders-jammers);
			if (diff < minDiff || (diff==minDiff&&coders<minC) || (diff==minDiff&&coders==minC&&jammers<minJ)) {
				minDiff = diff;
				minC = coders;
				minJ = jammers;
				ansA = next3.get(0);
				ansB = next3.get(1);
			}
		} else if (a.charAt(0)=='?') {
			List<String> next1 = fill((char)Math.min(b.charAt(0)+1, '9')+a.substring(1),b);
			List<String> next2 = fill(b.charAt(0)+a.substring(1),b);
			List<String> next3 = fill((char)Math.max(b.charAt(0)-1, '0')+a.substring(1),b);
			
			long coders = Long.parseLong(next1.get(0));
			long jammers = Long.parseLong(next1.get(1));
			long diff = Math.abs(coders-jammers);
			if (diff < minDiff || (diff==minDiff&&coders<minC) || (diff==minDiff&&coders==minC&&jammers<minJ)) {
				minDiff = diff;
				minC = coders;
				minJ = jammers;
				ansA = next1.get(0);
				ansB = next1.get(1);
			}
			coders = Long.parseLong(next2.get(0));
			jammers = Long.parseLong(next2.get(1));
			diff = Math.abs(coders-jammers);
			if (diff < minDiff || (diff==minDiff&&coders<minC) || (diff==minDiff&&coders==minC&&jammers<minJ)) {
				minDiff = diff;
				minC = coders;
				minJ = jammers;
				ansA = next2.get(0);
				ansB = next2.get(1);
			}
			coders = Long.parseLong(next3.get(0));
			jammers = Long.parseLong(next3.get(1));
			diff = Math.abs(coders-jammers);
			if (diff < minDiff || (diff==minDiff&&coders<minC) || (diff==minDiff&&coders==minC&&jammers<minJ)) {
				minDiff = diff;
				minC = coders;
				minJ = jammers;
				ansA = next3.get(0);
				ansB = next3.get(1);
			}
		}  else if (b.charAt(0)=='?') {
			List<String> next1 = fill(a,(char)Math.min(a.charAt(0)+1, '9')+b.substring(1));
			List<String> next2 = fill(a,a.charAt(0)+b.substring(1));
			List<String> next3 = fill(a,(char)Math.max(a.charAt(0)-1, '0')+b.substring(1));
			
			long coders = Long.parseLong(next1.get(0));
			long jammers = Long.parseLong(next1.get(1));
			long diff = Math.abs(coders-jammers);
			if (diff < minDiff || (diff==minDiff&&coders<minC) || (diff==minDiff&&coders==minC&&jammers<minJ)) {
				minDiff = diff;
				minC = coders;
				minJ = jammers;
				ansA = next1.get(0);
				ansB = next1.get(1);
			}
			coders = Long.parseLong(next2.get(0));
			jammers = Long.parseLong(next2.get(1));
			diff = Math.abs(coders-jammers);
			if (diff < minDiff || (diff==minDiff&&coders<minC) || (diff==minDiff&&coders==minC&&jammers<minJ)) {
				minDiff = diff;
				minC = coders;
				minJ = jammers;
				ansA = next2.get(0);
				ansB = next2.get(1);
			}
			coders = Long.parseLong(next3.get(0));
			jammers = Long.parseLong(next3.get(1));
			diff = Math.abs(coders-jammers);
			if (diff < minDiff || (diff==minDiff&&coders<minC) || (diff==minDiff&&coders==minC&&jammers<minJ)) {
				minDiff = diff;
				minC = coders;
				minJ = jammers;
				ansA = next3.get(0);
				ansB = next3.get(1);
			}
		}
		
		List<String> ret = new ArrayList<String>();
		ret.add(ansA);
		ret.add(ansB);
		return ret;
	}
}