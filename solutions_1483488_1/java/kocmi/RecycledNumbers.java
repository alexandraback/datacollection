package recyclednumbers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * @author Kocmi
 */
public class RecycledNumbers {

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st;

            st = new StringTokenizer(br.readLine());
            int tests = Integer.parseInt(st.nextToken());
            int[] results = new int[tests]; //final result
            int A,B;
            
            for (int i = 0; i < tests; i++) {
                st = new StringTokenizer(br.readLine());
                A = Integer.parseInt(st.nextToken());
                B = Integer.parseInt(st.nextToken());
                
                results[i] = recycled(A,B,Integer.toString(A).length());
            }
            
            for (int i = 0; i < tests; i++) {
                System.out.println("Case #"+(i+1)+": "+results[i]);
            }
        } catch (Exception ex) {
        }
    }
    
    public static int recycled(int A, int B, int length){
        int result = 0;
        for (int n = A; n < B; n++) {
            //check n
            result += check(n,B,length);
        }
        
        return result;
    }
    
    public static int check(int n, int B, int length){
        int cycles = 0;
        int m = n;
        int rest;
        boolean a;
        int[] correct = new int[7];
        
        for (int i = 0; i < length-1; i++) {
            rest = m%10;
            m = (m/10);
            m = m+rest*(int)Math.pow(10,(length-1));
            
            if(n<m && m<=B){
                a = true;
                for (int j = 0; j < cycles; j++) {
                    if(correct[j]==m){
                        a=false;
                    }
                }
                if(a){
                    correct[cycles] = m;
                    cycles++;
                }
            }
        }
        return cycles;
    }
}
