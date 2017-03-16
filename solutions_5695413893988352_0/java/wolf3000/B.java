import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws FileNotFoundException {

		 Scanner in = new Scanner(new File("B-small-attempt2.in"));
		 Formatter out = new Formatter(new File("B-small-attempt2.out"));
//
//		Scanner in = new Scanner(System.in);
//		Formatter out = new Formatter(System.out);

		int t = in.nextInt();
		int caseNum = 1;

		while (caseNum <= t) {
			output(caseNum, in.next(), in.next(), out);
			caseNum++;
		}

		out.flush();
		out.close();
	}

	private static void output(int caseNum, String left, String right,
			Formatter out) {

		int n = left.length();

//		int[] lres = new int[n];
//		int[] rres = new int[n];
//
//		for (int i = 0; i < n; ++i) {
//			if (left.charAt(i) != '?') {
//				lres[i] = left.charAt(i) - '0';
//			}
//			if (right.charAt(i) != '?') {
//				rres[i] = right.charAt(i) - '0';
//			}
//		}
//
//		char l = left.charAt(0);
//		char r = right.charAt(0);
//
//		if (r != '?' && l == '?') {
//			lres[0] = r - '0';
//			rres[0] = r - '0';
//		} else if (r == '?' && l != '?') {
//			lres[0] = l - '0';
//			rres[0] = l - '0';
//		}
//
//		boolean eq = true;
//		boolean leftMore = false;
//
//		if (lres[0] != rres[0]) {
//			eq = false;
//			leftMore = lres[0] > rres[0];
//		}
//
//		long pow = (long)Math.pow(10, n);
//		
//		for (int i = 1; i < n; ++i) {
//			pow/=10;
//			l = left.charAt(i);
//			r = right.charAt(i);
//
//			if (l == '?' && r == '?') {
//				if (!eq) {
//					if (leftMore) {
//						lres[i] = 0;
//						rres[i] = 9;
//					} else {
//						lres[i] = 9;
//						rres[i] = 0;
//					}
//				}
//			} else if (l == '?') {
//				if (eq) {
//					lres[i] = rres[i];
//				} else {
//					if (leftMore) {
//						lres[i] = 0;
//					} else {
//						lres[i] = 9;
//					}
//				}
//			} else if (r == '?') {
//				if (eq) {
//					rres[i] = lres[i];
//				} else {
//					if (leftMore) {
//						lres[i] = 9;
//					} else {
//						lres[i] = 0;
//					}
//				}
//			} else {
//				if (eq) {
//					if(lres[i]!=rres[i]){
//						eq = false;
//					}
//					
//					int ll = left.charAt(i)-'0';
//					int rr = right.charAt(i)-'0';
//					
//					if(ll>rr){
//						leftMore = true;
//						if(pow*(rr+10-ll)<(ll-rr)*pow){
//							if(right.charAt(i-1)=='?'&&lres[i-1]!=9){
//								leftMore = false;
//								rres[i-1] = lres[i-1]+1;
//							}else if(left.charAt(i-1)=='?'&&rres[i-1]!=0){
//								leftMore = false;
//								lres[i-1] = rres[i-1]-1;
//							}
//						}
//					}else if(rr>ll){
//						if(ll+10-rr<rr-ll){
//							if(left.charAt(i-1)=='?'&&rres[i-1]!=9){
//								leftMore = true;
//								lres[i-1] = rres[i-1]+1;
//							}else if(right.charAt(i-1)=='?'&&lres[i-1]!=0){
//								leftMore = true;
//								rres[i-1] = lres[i-1]-1;
//							}
//						}						
//					}
//					
//				}
//			}			
//		}
//		
//		StringBuffer leftResult = concat(lres);
//		StringBuffer rightResult = concat(rres);
//		
//		int ll = Integer.parseInt(leftResult.toString());
//		int rr = Integer.parseInt(rightResult.toString());		
//		int abs = Math.abs(ll-rr);
//		
//		System.out.println(left+" "+right);
		
		int abs = 10000;
		int l = 0;
		int r = 0;
		
		for(int i=0;i<1000;++i){
			for(int j=0;j<1000;++j){
				if(ok(""+i,left)&&ok(""+j,right)){
					if(Math.abs(i-j)<abs){
						abs = Math.abs(i-j);
						l = i;
						r = j;
					}else if(Math.abs(i-j)==abs){						
						if(i<l){
							l = i;
							r = j;
						}else if(i==l){
							r = Math.min(r,	 j);
						}
					}
				}
			}
		}
		
		String leftRes = ""+l;
		String rightRes = ""+r;
		
		if(leftRes.length()<n){
			leftRes = "0" + leftRes;
		}
		
		if(leftRes.length()<n){
			leftRes = "0" + leftRes;
		}

		if(rightRes.length()<n){
			rightRes = "0" + rightRes;
		}
		
		if(rightRes.length()<n){
			rightRes = "0" + rightRes;
		}

		
//		out.format("Case #%d: %s %s%n",caseNum,leftResult.toString(),rightResult.toString());
		out.format("Case #%d: %s %s%n",caseNum,leftRes,rightRes);

	}

	private static boolean ok(String i, String left) {
		if(i.length()>left.length()){
			return false;
		}
		if(i.length()<left.length()){
			i = "0"+i;
		}
		if(i.length()<left.length()){
			i = "0"+i;
		}
		
		for(int index = 0;index<i.length();++index){
			if(i.charAt(index)!=left.charAt(index)&&left.charAt(index)!='?'){
				return false;
			}
		}
		
		return true;
	}

	private static StringBuffer concat(int[] lres) {
		StringBuffer result = new StringBuffer();
		for(int digit:lres){
			result.append(digit);
		}
		return result;
	}

}
