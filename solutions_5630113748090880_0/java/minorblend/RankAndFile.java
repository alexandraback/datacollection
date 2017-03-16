import java.util.*;

public class RankAndFile {
    public static Integer[] findMissingList(ArrayList<Integer> lists) {
        HashSet<Integer> heights = new HashSet<>();
        for (Integer height: lists) {
            if (heights.contains(height)) {
                heights.remove(height);
            } else {
                heights.add(height);
            }
        }
        Integer[] list = heights.toArray(new Integer[heights.size()]);
        Arrays.sort(list);
        return list;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(sc.nextLine());
            ArrayList<Integer> lists = new ArrayList<>();
            for (int j = 0; j < n * n * 2 - n; j++) {
                lists.add(sc.nextInt());
            }
            sc.nextLine();
            Integer[] missingList = findMissingList(lists);
            System.out.printf("Case #%d:", i + 1);
            for (int height: missingList) {
                System.out.printf(" %d", height);
            }
            System.out.println();
        }
    }
}
