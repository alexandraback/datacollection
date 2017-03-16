package main;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    
    public static final String changeLine = System.getProperty("line.separator");
    
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Main main = new Main();
    }

    public int n;
    public int [] front = new int[105];
    public int [] end = new int[105];
    public int min, max;
    public boolean [] single = new boolean[300];
    public String [] split;
    public long [] val = new long[105];
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/B-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        val[0]=1;
        for (int i = 1; i < 105; i++) {
            val[i] = val[i-1]*i % 1000000007;
        }
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            split = br.readLine().split(" ");
            n = Integer.parseInt(split[0]);
            split = br.readLine().split(" ");
            // output
            System.out.println("Case #"+(caseNum+1)+":");
            bw.write("Case #"+(caseNum+1)+": ");
            bw.write(Long.toString(cal()));
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }

    public long cal(){
        front = new int[105];
        end = new int[105];
        single = new boolean[300];
        for (int i = 0; i < n; i++) {
            front[i] = split[i].charAt(0);
            end[i] = split[i].charAt(split[i].length()-1);
            if (split[i].length()>2) {
                min = 1;
                for (int j = 1; j < split[i].length()-1; j++) {
                    if (split[i].charAt(j) != front[i]) {
                        min = j;
                        break;
                    }
                }
                max = split[i].length()-2;
                for (int j = split[i].length()-2; j > 0; j--) {
                    if (split[i].charAt(j) != end[i]) {
                        max = j;
                        break;
                    }
                }
                for (int j = min; j <= max; j++) {
                    if (split[i].charAt(j) != split[i].charAt(j-1)) {
                        if (single[split[i].charAt(j)]) {
                            return 0;
                        }
                        single[split[i].charAt(j)] = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (single[front[i]]) {
                return 0;
            }
            if (single[end[i]]) {
                return 0;
            }
        }
        long result = 1;
        int remain = n;
        for (int i = 'a'; i <= 'z'; i++) {
            boolean hasF = false, hasE = false;
            int axIndex = 0, xaIndex = 0;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (front[j]==i) {
                    if (end[j] == i) {
                        count ++;
                    } else {
                        if (hasF) {
                            return 0;
                        }
                        hasF = true;
                        axIndex = j;
                    }
                } else if (end[j] == i) {
                    if (hasE) {
                        return 0;
                    }
                    hasE = true;
                    xaIndex= j;
                }
            }
            if (hasF || hasE || count>0) {
                result = result * val[count] % 1000000007;
                remain -= count;
                if (!hasF && !hasE) {
                    remain ++;
                }
                if (hasF && hasE) {
                    remain--;
                    front[axIndex] = end[xaIndex];//connect
                    end[xaIndex] = front[xaIndex];//remove old data
                }
            }
        }
        return result * val[remain] % 1000000007;
    }
}