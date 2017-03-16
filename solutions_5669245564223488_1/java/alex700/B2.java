import java.util.*;
import java.io.*;

public class B2 {
    FastScanner in;
    PrintWriter out;
    public void solve() throws IOException {
    	int t = in.nextInt();
    	for (int h = 1; h <= t; h++) {
    		System.out.println(h);
    		out.print("Case #" + h + ": ");
    		int n = in.nextInt();
    		char[][] s = new char[n][];
    		boolean badString = false;
    		for (int i = 0; i < n; i++) {
    			s[i] = in.next().toCharArray();
    		}
    		
    		Set<Character> bigSet = new TreeSet<>();
    		Set<Character> mainSet = new TreeSet<>();
    		Set<Character> first = new TreeSet<>();
    		Set<Character> last = new TreeSet<>();
    		Map<Character, Integer> full = new TreeMap<>();
    		for (int i = 0; i < 26; i++) {
    			full.put((char)((int)'a'+i), 0);
    		}
    		for1: for (int i = 0; i < n; i++) {
    			char fs = s[i][0];
    			char ls = s[i][s[i].length - 1];
    			Set<Character> set = new TreeSet<>();
    			char c = '#';
    			for (int j = 0; j < s[i].length; j++) {
    				if (c != s[i][j]) {
    					if (mainSet.contains(s[i][j])) {
    						boolean fullString = true;
    						for (int k = 0; k < s[i].length; k++) {
    							if (s[i][j] != s[i][k]) {
    								fullString = false;
    								break;
    							}
    						}
    						if (!fullString) {
    							badString = true;
    							break for1;
    						} else {
    							full.put(s[i][j], full.get(s[i][j]) + 1);
    							continue for1;
    						}
    					} else if (set.contains(s[i][j]) || bigSet.contains(s[i][j])) {
    						badString = true;
							break for1;
    					} else {
    						set.add(s[i][j]);
    					}
    				}
    				c = s[i][j];
    			}
    			if (set.size() == 1) {
    				full.put(c, full.get(c) + 1);
    			} else {
    				set.remove(fs);
    				set.remove(ls);
    				bigSet.addAll(set);
    				if (first.contains(fs) || last.contains(ls)) {
    					badString = true;
						break for1;
    				}
    				first.add(fs);
    				last.add(ls);
    				if (last.contains(fs)) {
    					mainSet.add(fs);
    					last.remove(fs);
    					first.remove(fs);
    				}
    				if (first.contains(ls)) {
    					mainSet.add(ls);
    					first.remove(ls);
    					last.remove(ls);
    				}
    			}
    		}
    		long count = 1;
    		if (badString) {
    			out.println(0);
    		} else {
    			
    			long mod = (long) 1e9 + 7;
    			long[] f = new long[200];
    			f[0] = 1;
    			for (int i = 1; i < 200; i++) {
    				f[i] = (f[i - 1] * i) % mod;
    			}
    			for (int i = 0; i < 26; i++) {
    				char cc = (char)((int)'a'+i);
        			int x = full.get(cc);
        			if (x > 0 && !mainSet.contains(cc) && !last.contains(cc) && !first.contains(cc)) {
        				first.add(cc);
        			}
        			count *= f[x];
        			count %= mod;
        		}
    			if (first.size() == 0) {
    				out.println(0);
    			} else {
    			//out.println(first.size());
    				count = (count*f[first.size()]) % mod;
    				out.println(count);
    			}
    		}
    	}
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-large.in"));
            out = new PrintWriter(new File("B-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new B2().run();
    }
}