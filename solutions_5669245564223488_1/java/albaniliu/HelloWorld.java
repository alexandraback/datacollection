import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.TreeSet;

public class HelloWorld {
    
    public static void main(String[] args) {
        try {
//            BufferedReader br = new BufferedReader(new FileReader("D:/codejam/a.txt"));
//            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            
//          BufferedReader br = new BufferedReader(new FileReader("D:/codejam/D-large-practice.in"));
//          BufferedWriter bw = new BufferedWriter(new FileWriter("D:/codejam/D-large-result.txt"));
//            
//            BufferedReader br = new BufferedReader(new FileReader("D:/codejam/B-small-attempt0.in"));
//            BufferedWriter bw = new BufferedWriter(new FileWriter("D:/codejam/B-small-result.txt"));
//            BufferedReader br = new BufferedReader(new FileReader("D:/codejam/B-small-attempt1.in"));
            
            BufferedReader br = new BufferedReader(new FileReader("D:/codejam/B-large.in"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("D:/codejam/B-large-result.txt"));

            String line;
            int mod = 1000000007;
            long[] P = new long[110];
            P[0] = P[1] = 1;
            for (int i = 2; i < 110; i++) {
                P[i] = (P[i-1] * i) % mod;
            }

            line = br.readLine();
            int T = Integer.parseInt(line);
            
            for (int cas = 1; cas <= T; cas++) {
                line = br.readLine();
                int N = Integer.parseInt(line);
                line = br.readLine();
                String[] all = line.split(" ");
                long ret = 1;
                boolean ok = true;
                ArrayList<String> part = new ArrayList<String>();
                int allSame[] = new int[26];
                Arrays.fill(allSame, 0);
                for (int i = 0; i < N ;i++) {
                    boolean same = true;
                    for (int j = 0; j < all[i].length() - 1; j++) {
                        if (all[i].charAt(j) != all[i].charAt(j+1)) {
                            same = false;
                            break;
                        }
                    }
                    if (same) {
                        allSame[all[i].charAt(0) - 'a']++;
                    } else {
                        part.add(all[i]);
                    }
                }
                
                int n = part.size();
                boolean[][] table = new boolean[n][n];
                for (boolean[] x: table) {
                    Arrays.fill(x, false);
                }
                
                for (int i = 0; i < n ;i++) {
                    for (int j = 0; j < n ;j++) if (i != j) {
                        String a = part.get(i);
                        String b = part.get(j);
                        if (a.charAt(a.length() - 1) == b.charAt(0)) table[i][j] = true;
                    }
                }
                
                int[] count = new int[n];
                for (int i = 0; i < n; i++) {
                    int cnt = 0;
                    for (int j = 0; j < n; j++) if (table[i][j]) {
                        cnt++;
                        count[j]++;
                    }
                    if (cnt > 1) ok = false;
                    cnt = 0;
                    for (int j = 0; j < n; j++) if (table[j][i]) {
                        cnt++;
                    }
                    if (cnt > 1) ok = false;
                }
                
                StringBuilder sb = new StringBuilder();
                if (ok) {
                    int contain = 0;
                    int usedStr = 0;
                    for (int i = 0; i < n; i++) if (count[i] == 0) {
                        contain++;
                        int curNode = i;
                        ret *= P[allSame[part.get(i).charAt(0) - 'a']];
                        ret %= mod;
                        allSame[part.get(i).charAt(0) - 'a'] = 0;
                        
                        while (curNode != -1) {
                            usedStr++;
                            sb.append(part.get(curNode));
                            int newNode = -1;
                            String tmpStr = part.get(curNode);
                            ret *= P[allSame[tmpStr.charAt(tmpStr.length() -1) - 'a']];
                            ret %= mod;
                            allSame[tmpStr.charAt(tmpStr.length() -1) - 'a'] = 0;
                            
                            for (int j = 0; j < n ;j++) if (table[curNode][j]) {
                                newNode = j;
                                break;
                            }
                            curNode = newNode;
                        }
                    }
                    
                    if (usedStr != n) {
                        ok = false;
                    }
                    
                    for (int i = 0; i < 26; i++) if (allSame[i] > 0) {
                        contain++;
                        ret *= P[allSame[i]];
                        ret %= mod;
                        sb.append((char)('a' + i));
                    }
                    
                    ret *= P[contain];
                    ret %= mod;
                    
                    sb.append('A');
                    ok &= valid(sb.toString());
                }
//                bw.write(sb.toString());
//                bw.newLine();
                if (!ok) {
                    bw.write("Case #" + cas + ": 0");
                } else {
                    bw.write("Case #" + cas + ": " + ret);
                }
                bw.newLine();
                bw.flush();
            }
            
            br.close();
            bw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static boolean valid(String str) {
        boolean[] visited = new boolean[26];
        
        for (int i = 0;i < str.length() - 1; i++) {
            if (str.charAt(i) != str.charAt(i+1)) {
                if (visited[str.charAt(i) - 'a']) {
                    return false;
                }
                visited[str.charAt(i) - 'a'] = true;
            }
        }
        return true;
    }
    
}
