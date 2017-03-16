import java.io.*;
import java.util.*;
import java.text.*;

public class ProblemC {

	public static void main(String[] args) {
		try {
			new ProblemC().solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}


    public void solve() throws IOException {
    	System.setIn(new FileInputStream("D:\\inputC.in"));
    	Scanner scan = new Scanner(System.in);
    	PrintWriter out = new PrintWriter(System.out);
    	
    	int T = scan.nextInt();
    	
    	for (int i=0;i<T;i++) {
    		int N = scan.nextInt();
    		int M = scan.nextInt();
    		
    		long[] totalL1 = new long[N];
    		int[] typesL1 = new int[N];
    		long[] totalL2 = new long[M];
    		int[] typesL2 = new int[M];
    		
    		for (int j=0;j<N;j++) {
    			long t1 = scan.nextLong();
    			int t2 = scan.nextInt();
    			totalL1[j] = t1;
    			typesL1[j] = t2;
    		}
    		for (int j=0;j<M;j++) {
    			long t1 = scan.nextLong();
    			int t2 = scan.nextInt();
    			totalL2[j] = t1;
    			typesL2[j] = t2;
    		}
    		
    		
    		long sum1 = 0;
    		long sum2 = 0;
    		int l1 = 0; int l2 = 0;
    		
    		while (l1 < N && l2 < M) {
    			int t1pos = -1;
    			int t2pos = -1;
    			
    			for (int j=l2;j<M;j++) {
    				if (typesL2[j] == typesL1[l1]) {
    					t2pos = j;
    					break;
    				}
    				
    			}
    			for (int j=l1;j<N;j++) {
    				if (typesL1[j] == typesL2[l2]) {
    					t1pos = j;
    					break;
    				}
    			}
    			
    			if (t1pos == -1 && t2pos >= 0) {
    				l2=t2pos;
    			} else if (t1pos >= 0 && t2pos == -1) {
    				l1 = t1pos;
    			} else if (t1pos >= 0 && t2pos >= 0) {
    				
    				if (t1pos-l1 < t2pos-l2) {
        				l1 = t1pos;
        			} else if (t1pos-l1 > t2pos-l2) {
        				l2 = t2pos;
        			} else {
        				
        				long v1 = Math.min(totalL1[l1], totalL2[t2pos]);
        				long v2 = Math.min(totalL2[l2], totalL1[t1pos]);
        				
        				if (v1 < v2) {
        					l1 = t1pos;
        				} else if (v1 > v2) {
        					l2 = t2pos;
        				} else {
        					l1 = t1pos;
        				}
        				
        			}
    				
    			} else if (t1pos == -1 && t2pos == -1) {
    				break;
    			}
    			
    			
    			sum1 += Math.min(totalL1[l1], totalL2[l2]);
    			if (totalL1[l1] < totalL2[l2]) {
    				totalL2[l2] -= totalL1[l1];
    				totalL1[l1] = 0;
    				l1++;
    			} else if (totalL1[l1] > totalL2[l2]) {
    				totalL1[l1] -= totalL2[l2];
    				totalL2[l2] = 0;
    				l2++;
    			} else {
    				l1++;
    				l2++;
    			}
    		}
    		
    		out.println("Case #"+ (i+1) + ": " +Math.max(sum1, sum2));
    		out.flush();
    	}


		out.flush();
		out.close();
		scan.close();
    }



}