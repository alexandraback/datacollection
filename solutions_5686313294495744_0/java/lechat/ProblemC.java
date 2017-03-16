import java.io.PrintWriter;
import java.util.*;
import java.util.Queue;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.math.*;


public class ProblemC {

    private static final int CPU_CORES = 8;

    public static String solve(String[] list) {
        HashMap<String, Integer> set1 = new HashMap<>();
        HashMap<String, Integer> set2 = new HashMap<>();

        //boolean[] valid = new boolean[list.length];
        int fake = 0;
        int valid = 0;

        for(int i=0; i<list.length; i++){
            String[] split = list[i].split(" ");
            if (set1.get(split[0]) == null) {
                set1.put(split[0], 0);
            }
            set1.put(split[0], set1.get(split[0]) + 1);

            if (set2.get(split[1]) == null) {
                set2.put(split[1], 0);
            }
            set2.put(split[1], set2.get(split[1]) + 1);
        }

        for(int i=0; i<list.length; i++) {
            String[] split = list[i].split(" ");
            if(set1.get(split[0])==1 || set2.get(split[1])==1){
                valid++;
            }
        }

        return (list.length-valid) + "";
    }

    public static void main(String[] args) {
        ExecutorService exec = Executors.newFixedThreadPool(CPU_CORES);

        Queue<Future<String>> resultQueue = new ArrayDeque<>();

        try (Scanner sc = new Scanner(System.in); PrintWriter out = new PrintWriter(System.out)) {
            int T = sc.nextInt();
            sc.nextLine();

            for (int i = 1; i <= T; i++) {
                int N = sc.nextInt();
                final String[] in = new String[N];
                for(int j=0; j<N; j++) {
                    in[j] = sc.next() + " " + sc.next();
                }
                // Read test case input
                Future<String> future = exec.submit(
                        new Callable<String>() {
                            @Override
                            public String call() throws Exception {
                                return solve(in);
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