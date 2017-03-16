package roundA2;

import java.io.*;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by szeyiu on 5/2/15.
 */
public class A2A {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(new File("A2A.in"))));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("A2A.out"))));
        int T = Integer.valueOf(r.readLine());
        A2A a2A = new A2A();
        for(int i=0; i<T; ++i){
            long N = Long.valueOf(r.readLine());
            long rst = a2A.countN(N);
            int c = i+1;
            w.write("Case #"+c+": "+rst+"\n");
        }
        w.flush();
        w.close();
        r.close();
    }

    public long countN(long N){
        HashSet<Long> seen = new HashSet<Long>();
        long count = 0;
        Queue<Long> q = new LinkedList<Long>();
        q.offer(-1L);
        q.offer(1L);
        long cur = q.poll();
        while(cur!=N){
            if(cur<0){
                q.offer(cur);
                count++;
                cur = q.poll();
                continue;
            }
            long cur1 = cur+1;
            long cur2 = rev(cur);
            long cur3 = rev(cur2);
            if(!seen.contains(cur1)){
                q.offer(cur1);
                seen.add(cur1);
            }
            if(!seen.contains(cur2)){
                q.offer(cur2);
                seen.add(cur2);
            }
            if(!seen.contains(cur3)){
                q.offer(cur3);
                seen.add(cur3);
            }
            cur = q.poll();
        }
        return count;
    }

    public long rev(long n){
        long m = 0;
        while(n!=0){
            long r = n%10;
            m *= 10;
            m = m+r;
            n /= 10;
        }
        return m;
    }
}
