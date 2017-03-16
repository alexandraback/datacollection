import java.util.*;

class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    public void solve() {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            System.out.println("Case #" + (t+1) + ":");
            int N = sc.nextInt();
            Integer[] array = new Integer[N];
            int sum = 0;
            for (int i=0; i<N; i++) {
                sum += array[i] = sc.nextInt();
            }
            Arrays.sort(array);
            System.err.println("sum = " + sum);
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();
            Map<Integer, Integer> map2 = new HashMap<Integer, Integer>();
            map.put(0, 0);
            boolean found = false;
            TOP:
            for (int i=0; i<array.length; i++) {
                int p = array[i];
                for (Map.Entry<Integer, Integer>pair : map.entrySet()) {
                    map2.put(pair.getKey(), pair.getValue());
                    int nk = pair.getKey() + p;
                    int nv = pair.getValue() + (1 << i);
                    System.err.println("nk="+nk+",nv="+nv);
                    if (map.containsKey(nk)) {
                        int v = map.get(nk);
                        if ((v & nv) == 0) {
                            System.err.println("Found!!!! " + nk + ", " + v + ", " + nv);
                            for (int j=0; j<array.length; j++) {
                                if ((v & (1<<j)) != 0) System.out.print(array[j] + " ");
                            }
                            System.out.println();
                            for (int j=0; j<array.length; j++) {
                                if ((nv & (1<<j)) != 0) System.out.print(array[j] + " ");
                            }
                            System.out.println();
                            found = true;
                            break TOP;
                        }
                    }
                    map2.put(nk, nv);
                }
                Map<Integer, Integer> tmp = map;
                map = map2;
                map2 = tmp;
                map2.clear();
            }
            if (!found) {
                System.out.println("Impossible");
            }
        }
    }
}