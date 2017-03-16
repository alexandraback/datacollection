import java.util.Scanner;
import java.util.PriorityQueue;

public class Dijkstra {

    public static String yes = "YES";
    public static String no = "NO";
    public static int[][] times = {{1,2,3,4},
                            {2,-1,4,-3},
                            {3,-4,-1,2},
                            {4,3,-2,-1}};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int f=1;f<=T;f++) {
            int n = sc.nextInt();
            long x = sc.nextLong();
            String q = sc.next();
            int[] L = new int[n];
            for (int h=0; h<n; h++) {
                L[h] = q.charAt(h) - 'g';
            }
            String s = solve(L,n,x);
            System.out.printf("Case #%d: %S", f, s);
            System.out.println("");
        }
    }

    public static int myMult(int a, int b) {
        int c = (int) Math.signum(a);
        int d = (int) Math.signum(b);
        int e = times[Math.abs(a)-1][Math.abs(b)-1];
        return (c*d*e);
    }

    public static int myDiv(int a, int b) {
        // a * ? = b
        if (Math.abs(a) == 1) {
            return (a*b);
        }
        return myMult(-1*a, b);
    }

    public static int geti(int[] L, int posn, int n) {
        int value = L[(posn-1)%n];
        while (posn>n) {
            value = myMult(L[n-1],value);
            posn = posn - n;
        }
        return value;
    }

    public static int getk(int[] L, int posn, int n) {
        int index = (n - 1 - posn) % n;
        if (index < 0) {
            index = index + n;
        }
        int val = myDiv(L[index], L[n-1]);
        while (posn >= n) {
            val = myMult(val,L[n-1]);
            posn = posn - n;
        }
        return val;

    }

    public static String solve(int[] L, int n, long x) {
        if (n*x<3) {
            return no;
        }
        for (int q=1;q<n;q++) {
            L[q] = myMult(L[q-1],L[q]);
        }

        int Lproduct = L[n-1]; int loopLen = 0;
        if (Lproduct==1) {
            return no;
        } else if (Lproduct == -1) {
            if (x%2 != 1) {
                return no;
            } else {
                loopLen = 2;
            }
        } else {
            if (x%4 != 2) {
                return no;
            } else {
                loopLen = 4;
            }
        }

        int iterms = 1;
        int foundi = 0;
        while (foundi == 0 && iterms < (loopLen*n)) {
            int val = geti(L, iterms, n);
            if (val == 2) {
                foundi = 1;
            } else {
                iterms++;
            }
        }
        if (foundi == 0) {
            return no;
        }

        int kterms = 1;
        int foundk = 0;
        while (foundk == 0 && kterms < (loopLen*n)) {
            int val = getk(L, kterms, n);
            if (val == 4) {
                foundk = 1;
            } else {
                kterms++;
            }
        }
        if (foundk==0) {
            return no;
        }

        long product = ((long) n) *  x;
        long sum = ((long) iterms) + ((long) kterms);
        if (sum < product) {
            return yes;
        }
        return no;
    }
}
