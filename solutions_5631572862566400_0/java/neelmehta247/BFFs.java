package RoundOneA;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by neel on 16/04/16 at 7:34 AM.
 */
public class BFFs {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int num_trials = s.nextInt();
        s.nextLine();
        for (int i = 0; i < num_trials; i++) {
            int n = s.nextInt();
            s.nextLine();
            String line = s.nextLine();
            System.out.println("Case #" + (i + 1) + ": " + getLongestChain(n, line));
        }
    }

    public static String getLongestChain(int n, String bffList) {
        Scanner s = new Scanner(bffList);
        int[] bffWith = new int[n];

        for (int i = 0; i < bffWith.length; i++) {
            bffWith[i] = (s.nextInt() - 1);
        }

        int maxLength = 0;
        ArrayList<Integer> alreadyExplored = new ArrayList<>();
        for (int i = 0; i < bffWith.length; i++) {
            if (alreadyExplored.contains(i)) {
                continue;
            } else {
                alreadyExplored.add(i);
            }
            int nextIndex = bffWith[i];
            int length = 1;
            boolean bffWithPrev = (i == bffWith[nextIndex]);
            while (nextIndex != i && !alreadyExplored.contains(nextIndex)) {
                alreadyExplored.add(nextIndex);
                length++;
                int prevIndex = nextIndex;
                nextIndex = bffWith[prevIndex];
                bffWithPrev = (prevIndex == bffWith[nextIndex]);
            }
            if (bffWithPrev) {
                int index = findSomeoneBFFWith(n - 1, bffWith, alreadyExplored);
                if (index != -1) {
                    ArrayList<Integer> secondAlreadyExplored = new ArrayList<>(alreadyExplored);
                    secondAlreadyExplored.add(index);
                    length++;
                    while (!secondAlreadyExplored.contains(index) && findSomeoneBFFWith(index, bffWith, secondAlreadyExplored) != 1) {
                        index = findSomeoneBFFWith(index, bffWith, secondAlreadyExplored);
                        secondAlreadyExplored.add(index);
                    }
                }
            }
            if (length > maxLength) {
                maxLength = length;
            }
        }

        return String.valueOf(maxLength);
    }

    public static int findSomeoneBFFWith(int n, int[] bffWith, ArrayList<Integer> alreadyExplored) {
        for (int i = 0; i < bffWith.length; i++) {
            if (i != n) {
                if (bffWith[i] == n && !alreadyExplored.contains(i)) {
                    return i;
                }
            }
        }
        return -1;
    }
}
