import java.util.*;

/**
 * Created by Wenzhao on 4/15/16.
 */
public class A2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(sc.nextLine());
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            for (int j = 1; j <= 2 * n - 1; j++) {
                for (int m = 1; m <= n; m++) {
                    int height = sc.nextInt();
                    if (map.containsKey(height)) {
                        map.put(height, map.get(height) + 1);
                    }
                    else {
                        map.put(height, 1);
                    }
                }
            }
            sc.nextLine();
            List<Integer> list = new ArrayList<Integer>();
            for (Map.Entry<Integer, Integer> entry: map.entrySet()) {
                if (entry.getValue() % 2 == 1) {
                    list.add(entry.getKey());
                }
            }
            Collections.sort(list);
            System.out.print("Case #" + (i + 1) + ": ");
            for (Integer height: list) {
                System.out.print(height + " ");
            }
            System.out.println();
        }
    }
}
