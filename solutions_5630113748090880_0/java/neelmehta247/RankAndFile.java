package RoundOneA;

import java.util.*;

/**
 * Created by neel on 16/04/16 at 6:53 AM.
 */
public class RankAndFile {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int num_trials = s.nextInt();
        s.nextLine();
        for (int i = 0; i < num_trials; i++) {
            int n = s.nextInt();
            s.nextLine();
            String input = "";
            for (int j = 0; j < 2 * n - 1; j++) {
                input += s.nextLine() + "\n";
            }
            System.out.println("Case #" + (i + 1) + ": " + getMissingList(input, n));
        }
    }

    public static String getMissingList(String str, int n) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        ArrayList<Integer> keys = new ArrayList<>();

        Scanner lineScanner = new Scanner(str);
        for (int i = 0; i < 2 * n - 1; i++) {
            String thisLine = lineScanner.nextLine();
            Scanner scanner = new Scanner(thisLine);
            for (int j = 0; j < n; j++) {
                int currentNum = scanner.nextInt();
                if (hashMap.containsKey(currentNum)) {
                    hashMap.put(currentNum, hashMap.get(currentNum) + 1);
                } else {
                    hashMap.put(currentNum, 1);
                    keys.add(currentNum);
                }
            }
        }

        ArrayList<Integer> toSubmit = new ArrayList<>();
        for (Integer key : keys) {
            if (hashMap.get(key) % 2 == 1) {
                toSubmit.add(key);
            }
        }

        Collections.sort(toSubmit, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });

        String toReturn = "";
        for (Integer aToSubmit : toSubmit) {
            toReturn += aToSubmit + " ";
        }
        return toReturn.trim();
    }
}
