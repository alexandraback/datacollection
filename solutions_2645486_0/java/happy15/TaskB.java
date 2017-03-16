import java.util.*;

public class TaskB {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numTests = in.nextInt();

        for (int testId = 1; testId <= numTests; ++testId) {
            System.out.print("Case #" + testId + ": ");

            int E = in.nextInt();
            int R = in.nextInt();
            int N = in.nextInt();
            Long[] v = new Long[N];
            for (int i = 0; i < N; ++i) {
                v[i] = in.nextLong();
            }
//            Arrays.sort(v, new Comparator<Long>() {
//                @Override
//                public int compare(Long o1, Long o2) {
//                    return o1 > o2 ? -1 : 1;
//                }
//            });
//            System.out.println(Arrays.toString(v));

            long[] f = new long[E + 1];
            Arrays.fill(f, 0);
            List<Integer> status = new ArrayList<Integer>();
            status.add(E);
            long ans = 0;
            for (int i = 0; i < N; ++i) {
                long[] newF = new long[E + 1];
                Arrays.fill(newF, 0);
                List<Integer> newS = new ArrayList<Integer>();
                for (int j = 0; j < status.size(); ++j) {
                    int EE = status.get(j);
                    for (int k = 0; k <= EE; ++k) {
                        int newEE = Math.min(EE - k + R, E);
                        if (!newS.contains(newEE)) {
                            newS.add(newEE);
                            newF[newEE] = f[EE] + k * v[i];
                        }
                        newF[newEE] = Math.max(newF[newEE], f[EE] + k * v[i]);
                        ans = Math.max(ans, newF[newEE]);
//                        if (!status.contains(newEE)) {
//                            status.add(newEE);
//                            f[newEE] = f[EE] + k * v[i];
//                        }
//                        f[newEE] = Math.max(f[newEE], f[EE] + k * v[i]);
//                        ans = Math.max(ans, f[newEE]);

                    }
                }
                f = newF;
                status = newS;
//                System.out.println(Arrays.toString(newF));
            }

            System.out.println(ans);
        }
    }
}
