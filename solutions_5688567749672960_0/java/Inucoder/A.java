import java.util.*;
import java.io.*;
import java.math.*;

public class A {
    static Scanner in = new Scanner(System.in);
    
    static PrintStream out = System.out;
    
    static long reverse(long n){
        StringBuilder builder = new StringBuilder(Long.toString(n));
        return Long.parseLong(builder.reverse().toString());
    }
    
    public static void main(String[] args) {
        int T = in.nextInt();
        
        long[] next = new long[2];
        
        for (int t = 1; t <= T; t++){
            long N = in.nextLong();
            
            Queue<Long> queue = new LinkedList<>();
            HashSet<Long> S = new HashSet<>();
            HashMap<Long, Long> distance = new HashMap<>();
            
            queue.add(1L);
            S.add(1L);
            distance.put(1L, 0L);
            
            while(!queue.isEmpty()){
                long number = queue.poll();
                
                if (number == N){
                    break;
                }
                
                next[0] = number + 1;
                next[1] = reverse(number);
                
                for (int i = 0; i < 2; i++){
                    if (!S.contains(next[i]) && next[i] <= N && next[i] > number){
                        queue.add(next[i]);
                        S.add(next[i]);
                        distance.put(next[i], distance.get(number) + 1);
                    }
                }
            }
            
            out.println(String.format("Case #%d: %d", t, distance.get(N) + 1));
        }
    }
}
