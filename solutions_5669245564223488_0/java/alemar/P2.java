package round1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

/**
 * Created by alemar on 11.05.2014.
 */
public class P2 {
    //private static final String inputFileName = "input/round1c/p2/test.in";
    private static final String inputFileName = "input/round1c/p2/B-small-attempt1.in";
    private static final String outputFileName = "answer.out";

    public static void main(String[] args) throws Exception {
        File inputFile = new File(inputFileName);
        Scanner scanner = new Scanner(inputFile);

        File outputFile = new File(outputFileName);
        outputFile.delete();
        outputFile.createNewFile();
        FileWriter fw = new FileWriter(outputFile);
        BufferedWriter bw = new BufferedWriter(fw);

        int numOfTestCases = scanner.nextInt();

        for (int i = 1; i <= numOfTestCases; i++) {
            int n = scanner.nextInt();

            List<String> cars = new LinkedList<String>();

            for (int j = 0; j < n; j++) {
                cars.add(scanner.next());
            }

            Problem2 problem = new Problem2(cars);

            String testCase = "Case #" + i + ": " + problem.solve();
            bw.append(testCase + "\n");
            System.out.println(testCase);
        }

        bw.flush();
        fw.flush();

        bw.close();
        fw.close();
    }
}


class Problem2 {
    List<String> cars = new LinkedList<String>();
    long res = 0;

    Problem2(List<String> list) {


        for (String s : list) {
            String newS = "";
            char[] chars = s.toCharArray();
            char prev = chars[0];
            newS = String.valueOf(prev);
            for (char c : chars) {
                if (c != prev) {
                    prev = c;
                    newS += c;
                }
            }
            cars.add(newS);
        }


    }

    public long solve() {
        recursion("", cars);
        return res;
    }

    private void recursion(String head, List<String> list) {
        if (list.size() == 1) {
            if (check(head + list.get(0))){
                res++;
            }
            return;
        }

        for (int i = 0; i < list.size(); i++) {
            String newHead = head + list.get(i);
            if (check(newHead)) {
                List<String> clone = new LinkedList<String>(list);
                clone.remove(i);
                recursion(newHead, clone);
            }
        }
    }

    private boolean check(String s){
        Set<Character> dublicate = new HashSet<Character>();
        char[] chars = s.toCharArray();
        char prev = chars[0];
        dublicate.add(prev);
        for (char c : chars) {
            if (c != prev) {
                prev = c;
                if (dublicate.contains(c)) {
                    return false;
                }
                dublicate.add(c);
            }
        }

        return true;
    }
}
