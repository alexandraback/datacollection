import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.math.*;

public class ProblemA {

    private static final int CPU_CORES = 8;

    public static String solve(String str) {
        int[] print = new int[26];
        int N = str.length();
        for(int i=0; i<N; i++) {
            print[index(str.charAt(i))]++;
        }

        int[] num = new int[10];
        // 0 zero
        {
            int z = print[index('Z')];
            int e = print[index('E')];
            int r = print[index('R')];
            int o = print[index('O')];
            num[0]=words(print, z,e,r,o);
            cleanup(num[0], print, index('Z'), index('E'), index('R'), index('O'));
        }



        // 8 eight
        {
            int e = print[index('E')];
            int i = print[index('I')];
            int g = print[index('G')];
            int h = print[index('H')];
            int t = print[index('T')];
            num[8]=words(print, e,i,g,h,t);
            cleanup(num[8], print, index('E'), index('I'), index('G'), index('H'), index('T'));
        }

        // 6 six
        {
            int s = print[index('S')];
            int i = print[index('I')];
            int x = print[index('X')];

            num[6] = words(print, s, i, x);
            cleanup(num[6], print, index('S'), index('I'), index('X'));
        }

        // 2 six
        {
            int t = print[index('T')];
            int w = print[index('W')];
            int o = print[index('O')];

            num[2] = words(print, t, w, o);
            cleanup(num[2], print, index('T'), index('W'), index('O'));
        }

        // 3 three
        {
            int t = print[index('T')];
            int h = print[index('H')];
            int r = print[index('R')];
            int e = print[index('E')]/2;
            int e2 = print[index('E')]/2;

            num[3] = words(print, t, h, r, e, e2);
            cleanup(num[3], print, index('T'), index('H'), index('R'), index('E'), index('E'));
        }

        // 4 four
        {
            int f = print[index('F')];
            int o = print[index('O')];
            int u = print[index('U')];
            int r = print[index('R')] ;

            num[4] = words(print, f, o, u, r);
            cleanup(num[4], print, index('F'), index('O'), index('U'), index('R'));
        }

        // 1 one
        {
            int o = print[index('O')];
            int n = print[index('N')];
            int e = print[index('E')];

            num[1] = words(print, o, n, e);
            cleanup(num[1], print, index('O'), index('N'), index('E'));
        }

        // 7 seven
        {
            int s = print[index('S')];
            int e = print[index('E')] / 2;
            int v = print[index('V')];
            int e2 = print[index('E')] / 2;
            int n = print[index('N')];

            num[7] = words(print, s, e, v, e2, n);
            cleanup(num[7], print, index('S'), index('E'), index('V'), index('E'), index('N'));
        }

        // 5 five
        {
            int f = print[index('F')];
            int i = print[index('I')];
            int v = print[index('V')];
            int e = print[index('E')] ;

            num[5] = words(print, f, i, v, e);
            cleanup(num[5], print, index('F'), index('I'), index('V'), index('E'));
        }

         // 9 nine
        {
            int n = print[index('N')]/2;
            int i = print[index('I')];
            int n2 = print[index('N')]/2;
            int e = print[index('E')];
            num[9]=words(print, n,i,n2,e);
            cleanup(num[9], print, index('N'), index('I'), index('N'), index('E'));
        }

        StringBuilder res = new StringBuilder();

        for(int i=0; i<10; i++){
            for(int j=0; j<num[i]; j++) {
                res.append(i);
            }
        }

        return res.toString();
    }

    static void cleanup(int n, int[] print, int... chars) {
        for (int ch : chars) {
            print[ch] -= n;
        }
    }

    static int words(int[] print, int... n) {
        int min = Integer.MAX_VALUE;
        for(int num : n) {
            min = Math.min(num, min);
        }
        return min==Integer.MAX_VALUE ? 0 : min;
    }

    static int index(char ch){
        return ch - 'A';
    }

    public static void main(String[] args) {
        ExecutorService exec = Executors.newFixedThreadPool(CPU_CORES);

        Queue<Future<String>> resultQueue = new ArrayDeque<>();

        try (Scanner sc = new Scanner(System.in); PrintWriter out = new PrintWriter(System.out)) {
            int T = sc.nextInt();
            sc.nextLine();

            for (int i = 1; i <= T; i++) {
                final String S = sc.nextLine();
                // Read test case input
                Future<String> future = exec.submit(
                        new Callable<String>() {
                            @Override
                            public String call() throws Exception {
                                return solve(S);
                            }
                        });
                resultQueue.offer(future);
            }

            int i = 1;
            while (!resultQueue.isEmpty()) {
                out.println("Case #" + (i++) + ": " + resultQueue.poll().get());
            }
        } catch (Throwable ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        } finally {
            exec.shutdownNow();
        }
    }
}