import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class BB {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Integer cases = in.nextInt();
        in.nextLine();
        List<String> perms = getAllKLength(new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}, 6);

        for (Integer i = 0; i < cases; i ++) {
            String line = in.nextLine();
            int bestDiff = Integer.MAX_VALUE;
            int bestLeft = Integer.MAX_VALUE;
            int bestRight = Integer.MAX_VALUE;

            char[] lineC = line.toCharArray();
            for (String perm : perms) {
                List<String> newLine = new ArrayList<>();
                char[] permC = perm.toCharArray();
                int index = 0;
                for (char t : lineC) {
                    if (t == '?') {
                        newLine.add(String.valueOf(permC[index]));
                        index++;
                    } else {
                        newLine.add(String.valueOf(t));
                    }
                }
                String listString = "";
                for (String s : newLine)
                {
                    listString += s;
                }
                String[] parts = listString.split(" ");
                int left = Integer.valueOf(parts[0]);
                int right = Integer.valueOf(parts[1]);

                if (Math.abs(left - right) < bestDiff) {
                    bestDiff = Math.abs(left - right);
                    bestLeft = left;
                    bestRight = right;
                } else if (Math.abs(left - right) == bestDiff) {
                    if (left < bestLeft) {
                        bestDiff = Math.abs(left - right);
                        bestLeft = left;
                        bestRight = right;
                    } else if (left == bestLeft) {
                        if (right < bestRight) {
                            bestDiff = Math.abs(left - right);
                            bestLeft = left;
                            bestRight = right;
                        }
                    }
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + padLeft(String.valueOf(bestLeft), line.split(" ")[0].length()) + " " + padLeft(String.valueOf(bestRight), line.split(" ")[1].length()));
        }
    }

    public static String padLeft(String s, int n) {
        return String.format("%1$" + n + "s", s).replace(' ', '0');
    }

    // The method that prints all possible strings of length k.  It is
    //  mainly a wrapper over recursive function printAllKLengthRec()
    static ArrayList<String> getAllKLength(char set[], int k) {
        int n = set.length;
        ArrayList<String> tmp = new ArrayList<>();
        printAllKLengthRec(set, "", n, k, tmp);
        return tmp;
    }

    // The main recursive method to print all possible strings of length k
    static void printAllKLengthRec(char set[], String prefix, int n, int k, ArrayList<String> tmp) {

        // Base case: k is 0, print prefix
        if (k == 0) {
            tmp.add(prefix);
            return;
        }

        // One by one add all characters from set and recursively
        // call for k equals to k-1
        for (int i = 0; i < n; ++i) {

            // Next character of input added
            String newPrefix = prefix + set[i];

            // k is decreased, because we have added a new character
            printAllKLengthRec(set, newPrefix, n, k - 1, tmp);
        }
    }
}
