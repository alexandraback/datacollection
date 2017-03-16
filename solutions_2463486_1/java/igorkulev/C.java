
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Igor
 */
public class C {
    
    static int T = 839788;
    static BigInteger nums[];
    
    static int countLessOrEqual(BigInteger A) {
        
        int index = Arrays.binarySearch(nums, A);
        
        if (index >= 0) {
            return index + 1;
        } else {
            return -(index + 1);
        }
        
    }
    
    public static void main(String[] args) throws Exception {
        int i;
        
        BufferedReader brData = new BufferedReader(new FileReader("data.txt")); 
        
        nums = new BigInteger[T];
        
        for (i=0;i<T;i++) {
            nums[i] = new BigInteger(brData.readLine());
        }
        
        brData.close();
        
        Arrays.sort(nums);
        
        BufferedReader br = new BufferedReader(new FileReader("C-large-1.in"));
        PrintWriter out = new PrintWriter(new PrintWriter("C-large-1.out"));
        
        int N = Integer.parseInt(br.readLine());
        for (i=0;i<N;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            BigInteger A = new BigInteger(st.nextToken());
            A = A.subtract(BigInteger.ONE);
            BigInteger B = new BigInteger(st.nextToken());
            
            int countA = countLessOrEqual(A);
            int countB = countLessOrEqual(B);
            int res = countB - countA;
            out.println("Case #"+(i+1)+": "+res);
            
        }
        
        br.close();
        out.close();
        
        
        
    }
    
}
