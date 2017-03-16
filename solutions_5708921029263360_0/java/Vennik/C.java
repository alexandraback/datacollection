import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class C {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new File("C-small-attempt1 (1).in"));
        FileWriter fw = new FileWriter(new File("c.out"));
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            fw.append(String.format("Case #%d: %s", i, new C().solve(sc))).append('\n');
        }
        fw.close();
        sc.close();

    }

    private String solve(Scanner sc) {

        System.out.println("------------");

        StringBuilder sb = new StringBuilder();
        int counter = 0;

        Map<Outfit, Integer> map = new HashMap<>();

        int J = sc.nextInt();
        int P = sc.nextInt();
        int S = sc.nextInt();
        int K = sc.nextInt();

        for (int i = 0; i < J; i++) {
            for (int j = 0; j < P; j++) {
                for (int k = 0; k < S; k++) {
                    int[] temp = new int[]{i, j, k};
                    Outfit outfit = new Outfit(temp, 0);
                    boolean found = false;

                    Outfit t2, t4, t5;

                    t2 = new Outfit(new int[]{i, -1, k}, 1);
                    t4 = new Outfit(new int[]{i, j, -1}, 1);
                    t5 = new Outfit(new int[]{-1, j, k}, 1);

                    Outfit[] ajaj = new Outfit[]{t2, t4, t5};

                    for (int z = 0; z < 3; z++) {
                        int test1 = map.getOrDefault(ajaj[z], 0);
                        if (test1 >= K) {
                            found = true;
                        }
                    }

                    if (!found) {
                        for (int z = 0; z < 3; z++) {
                            map.put(ajaj[z], map.getOrDefault(ajaj[z], 0) + 1);
                        }

                        counter++;
                        sb.append('\n').append(outfit.toString());
                        System.out.println(outfit);
                    } else {
                        System.out.println("x " + outfit);
                    }
                }
            }
        }

        return counter + sb.toString();

    }

    class Outfit {

        int[] items;
        int occ;

        public Outfit(int[] items, int occ) {
            this.items = items;
            this.occ = occ;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Outfit outfit = (Outfit) o;

            return Arrays.equals(items, outfit.items);

        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(items);
        }

        @Override
        public String toString() {
            return (items[0] + 1) + " " + (items[1] + 1) + " " + (items[2] + 1);
        }
    }

}
