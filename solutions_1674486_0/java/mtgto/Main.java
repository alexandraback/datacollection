import java.util.*;
import java.math.*;

class C {
    int idx;
    int toCount;
    Set<Integer> to;
    List<Integer> from;
    
    C(int _idx) {
        idx = _idx;
        toCount = 0;
        to = new HashSet<Integer>();
        from = new ArrayList<Integer>();
    }
    @Override public int hashCode() {
        return idx;
    }

    @Override public boolean equals(Object o) {
        return idx == ((C)o).idx;
    }

    @Override public String toString() {
        return String.format("%d: %d, %s, %s", idx, toCount, to, from);
    }
}

class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    public void solve() {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            System.out.printf("Case #%d: ", t+1);
            int N = sc.nextInt();
            C[] array = new C[N];
            for (int i=0; i<N; i++) {
                array[i] = new C(i);
            }
            for (int i=0; i<N; i++) {
                int M = sc.nextInt();
                for (int j=0; j<M; j++) {
                    int mi = sc.nextInt();
                    array[i].toCount++;
                    array[mi-1].from.add(i);
                }
            }
            Set<C> set = new HashSet<C>();
            boolean found = false;
            TOP:
            for (int i=0; i<N; i++) {
                System.err.println(Arrays.toString(array));
                for (int j=0; j<N; j++) {
                    if (set.contains(array[j])) continue;
                    if (array[j].toCount == 0) {
                        set.add(array[j]);
                        System.err.println("j="+j);
                        for (int fromIdx : array[j].from) {
                            C from = array[fromIdx];
                            if (from.to.contains(j)) {
                                System.err.println("j="+j+",from="+fromIdx);
                                System.out.println("Yes");
                                found = true;
                                break TOP;
                            } else {
                                from.to.add(j);
                                for (int to : array[j].to) {
                                    if (from.to.contains(to)) {
                                        System.out.println("Yes");
                                        found = true;
                                        break TOP;
                                    }
                                    from.to.add(to);
                                }
                                from.toCount--;
                            }
                        }
                        break;
                    }
                }
            }
            if (!found) {
                System.out.println("No");
            }
        }
    }
}