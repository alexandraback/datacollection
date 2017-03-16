import java.util.*;
public class CJ15C {
    
    static int[][] MULT = {{0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4}};
    
    static int mult(int L, int R) {
        boolean neg = (L>3) ^ (R>3);
        return MULT[L&3][R&3] ^ (neg?4:0);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        for (int u=1; u<=k; u++) {
            int n = sc.nextInt();
            long r = sc.nextLong();
            if (r>12) r = r%4 + 12;
            String s = sc.next();
            StringBuilder sb = new StringBuilder();
            for (int i=0; i<r; i++) sb.append(s);
            int[] item = new int[(int)(n*r)];
            for (int i=0; i<n*r; i++) 
                item[i] = sb.charAt(i)=='1'?0:(sb.charAt(i)-'i'+1);
            
            int total = 0;
            for (int i=0; i<n*r; i++) {
                total = mult(total, item[i]);
                //System.out.println(i + " " + total);
            }
            boolean cando = false;
            if (total == 4) {
                total = 0;
                int i, j;
                for (i=0; i<n*r; i++) {
                    total = mult(total, item[i]);
                    if (total == 1) break;
                }
                total = 0;
                for (j=(int)(n*r)-1; j>=0; j--) {
                    total = mult(item[j], total);
                    if (total == 3) break;
                }
                //System.out.println(i + " " + j);
                cando = i<j;
            }
            
            System.out.println("Case #" + u + ": " + (cando?"YES":"NO"));
        }
    }
}