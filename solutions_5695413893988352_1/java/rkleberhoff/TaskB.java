

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


/**
 * 
 * @author ralf
 *
 */
public class TaskB {
	
	String cString;
	String jString;
    
    
    public TaskB(Scanner input) {
    	cString = input.next();
    	jString = input.next();
    }
    
    public String solve() {
    	List<long[]> init = Arrays.asList(new long[] {0L, 0L});
        long[] result = step(0, init);
        return extend(result[0]) + " " + extend(result[1]);
    }
    
    String extend(long n) {
    	String sn = String.valueOf(n);
    	int pad = cString.length() - sn.length();
    	return "00000000000000000000".substring(0, pad) + sn;
    }
    
    long[] step(int nextPos, List<long[]> candidates) {
    	if (nextPos == cString.length()) {
    		return best(candidates);
    	}
    	List<long[]> nextCandidates = new ArrayList<long[]>();
    	for (long[] cand : candidates) {
    		nextCandidates.addAll(step1(nextPos, cand[0], cand[1]));
    	}
    	long bestDelta = Long.MAX_VALUE;
    	for (long[] cand : nextCandidates) {
    		long candDelta = delta(cand);
    		if (candDelta < bestDelta) {
    			bestDelta = candDelta;
    		}
    	}
    	List<long[]> goodCandidates = new ArrayList<long[]>();
    	for (long[] cand : nextCandidates) {
    		long candDelta = delta(cand);
    		if (candDelta <= bestDelta+2) {
    			goodCandidates.add(cand);
    		}
    	}
    	return step(nextPos+1, goodCandidates);
    }
    
    private long[] best(List<long[]> candidates) {
		Collections.sort(candidates, new Comparator<long[]>() {
			@Override
			public int compare(long[] o1, long[] o2) {
				int result = Long.compare(delta(o1), delta(o2));
				if (result != 0) {
					return result;
				}
				result = Long.compare(o1[0], o2[0]);
				if (result != 0) {
					return result;
				}
				return Long.compare(o1[1], o2[1]);
			}
		});
		return candidates.get(0);
	}

	long delta(long[] candidate) {
    	return Math.abs(candidate[1] - candidate[0]);
    }
    
    List<long[]> step1(int nextPos, long c, long j) {
    	char cc = cString.charAt(nextPos);
    	char cj = jString.charAt(nextPos);
    	List<long[]> result = new ArrayList<long[]>();
    	if (cc == '?' && cj == '?') {
    		if (c > j) {
    			result.add(new long[] {10*c+0, 10*j+9});
    		} else if (c < j) {
    			result.add(new long[] {10*c+9, 10*j+0});
    		} else {
    			result.add(new long[] {10*c+1, 10*j+0});
    			result.add(new long[] {10*c+0, 10*j+0});
    			result.add(new long[] {10*c+0, 10*j+1});
    		}
    	} else if (cc == '?') {
    		int d = Character.digit(cj, 10);
    		if (c > j) {
    			result.add(new long[] {10*c+0, 10*j+d});
    		} else if (c < j) {
    			result.add(new long[] {10*c+9, 10*j+d});
    		} else {
    			if (d > 0) {
    				result.add(new long[] {10*c+d-1, 10*j+d});
    			}
    			result.add(new long[] {10*c+d, 10*j+d});
    			if (d < 9) {
    				result.add(new long[] {10*c+d+1, 10*j+d});
    			}
    		}
    	} else if (cj == '?') {
    		int d = Character.digit(cc, 10);
    		if (c > j) {
    			result.add(new long[] {10*c+d, 10*j+9});
    		} else if (c < j) {
    			result.add(new long[] {10*c+d, 10*j+0});
    		} else {
    			if (d > 0) {
    				result.add(new long[] {10*c+d, 10*j+d-1});
    			}
    			result.add(new long[] {10*c+d, 10*j+d});
    			if (d < 9) {
    				result.add(new long[] {10*c+d, 10*j+d+1});
    			}
    		}
    	} else {
    		int dc = Character.digit(cc, 10);
    		int dj = Character.digit(cj, 10);
    		result.add(new long[] {10*c+dc, 10*j+dj});
    	}
    	return result;
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("data/B.in"));
        PrintWriter writer = new PrintWriter("data/B.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            TaskB task = new TaskB(scanner);
            StringBuilder builder = new StringBuilder();
            String result = task.solve();
            builder.append("Case #" + i + ": ").append(result);
            
            writer.println(builder);
            System.out.println(builder);
        }
        scanner.close();
        writer.close();
        long finish = System.currentTimeMillis();
        System.out.println("Time=" + (finish - start) + "ms");
    }
    
}
