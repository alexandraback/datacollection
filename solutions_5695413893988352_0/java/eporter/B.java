

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

// Using the Google Guava library.
public class B {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-small-attempt0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
		    String c = in.next();
		    String j = in.next();
		    CJ cj = new CJ(c.toCharArray(), j.toCharArray());
		    List<CJ> possible = new ArrayList<>();
		    for (int i = 0; i < c.length(); i++) {
		        if (cj.c[i] == '?' && cj.j[i] == '?') {
		            {
		                CJ p1 = cj.assign(false, i, 0);
		                p1 = p1.assignAll(false, i+1, 9);
		                p1 = p1.assign(true, i, 1);
		                p1 = p1.assignAll(true, i+1, 0);
		                possible.add(p1);
		            }
                    {
                        CJ p1 = cj.assign(true, i, 0);
                        p1 = p1.assignAll(true, i+1, 9);
                        p1 = p1.assign(false, i, 1);
                        p1 = p1.assignAll(false, i+1, 0);
                        possible.add(p1);
                    }
                    cj = cj.assign(true, i, 0);
                    cj = cj.assign(false, i, 0);
		        } else if (cj.c[i] == '?' && cj.j[i] != '?') {
		            if (cj.j[i] != '9') {
		                CJ p1 = cj.assign(true, i, cj.j[i] - '0' + 1);
		                p1 = p1.assignAll(true, i+1, 0);
		                p1 = p1.assignAll(false, i+1, 9);
                        possible.add(p1);
		            }
                    if (cj.j[i] != '0') {
                        CJ p1 = cj.assign(true, i, cj.j[i] - '0' - 1);
                        p1 = p1.assignAll(true, i+1, 9);
                        p1 = p1.assignAll(false, i+1, 0);
                        possible.add(p1);
                    }
                    cj = cj.assign(true, i, cj.j[i] - '0');
		        } else if (cj.c[i] != '?' && cj.j[i] == '?') {
                    if (cj.c[i] != '9') {
                        CJ p1 = cj.assign(false, i, cj.c[i] - '0' + 1);
                        p1 = p1.assignAll(false, i+1, 0);
                        p1 = p1.assignAll(true, i+1, 9);
                        possible.add(p1);
                    }
                    if (cj.c[i] != '0') {
                        CJ p1 = cj.assign(false, i, cj.c[i] - '0' - 1);
                        p1 = p1.assignAll(false, i+1, 9);
                        p1 = p1.assignAll(true, i+1, 0);
                        possible.add(p1);
                    }
                    cj = cj.assign(false, i, cj.c[i] - '0');
                } else if (cj.c[i] != cj.j[i]) {
                    if (cj.c[i] > cj.j[i]) {
                        CJ p1 = cj.assignAll(true, i+1, 0);
                        p1 = p1.assignAll(false, i+1, 9);
                        possible.add(p1);
                    } else {
//                        System.out.println(cj);
                        CJ p1 = cj.assignAll(true, i+1, 9);
//                        System.out.println(p1);
                        p1 = p1.assignAll(false, i+1, 0);
//                        System.out.println(p1);
                        possible.add(p1);
                    }
//                    break;
                }
		    }
		    possible.add(cj);
//		    System.out.println(possible);
		    CJ min = Collections.min(possible);
			String ans = "Case #"+cs+": " + new String(min.c) + " " + new String(min.j);
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
	
	private static class CJ implements Comparable<CJ> {
	    private char [] c, j;

        public CJ(char [] c, char [] j) {
            this.c = c;
            this.j = j;
        }
        
        public CJ assign(boolean isC, int i, int val) {
            char [] arr = isC ? c : j;
            arr = arr.clone();
            if (arr[i] == '?') {
                arr[i] = (char) ('0' + val);
            }
            return isC ? new CJ(arr, j) : new CJ(c, arr);
        }
        
        public CJ assignAll(boolean isC, int i, int val) {
            char [] arr = isC ? c : j;
            arr = arr.clone();
            for ( ; i < arr.length; i++) {
                if (arr[i] == '?') {
                    arr[i] = (char) ('0' + val);
                }
            }
            return isC ? new CJ(arr, j) : new CJ(c, arr);
        }

        @Override
        public int compareTo(CJ o) {
            BigInteger bc = new BigInteger(new String(c));
            BigInteger bj = new BigInteger(new String(j));
            BigInteger bd = bc.subtract(bj).abs();
                    

            BigInteger oc = new BigInteger(new String(o.c));
            BigInteger oj = new BigInteger(new String(o.j));
            BigInteger od = oc.subtract(oj).abs();
            
            int bcmp = bd.compareTo(od);
            if (bcmp != 0) {
                return bcmp;
            }
            int ccmp = bc.compareTo(oc);
            if (ccmp != 0) {
                return ccmp;
            }
            return bj.compareTo(oj);
        }
        
        @Override
        public String toString() {
            return new String(c) + " " + new String(j);
        }
        
	}
}
