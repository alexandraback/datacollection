
import com.sun.tools.javac.util.Pair;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;

/**
 *
 * @author peterboyen
 */
public class KingdomRush {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("/Users/peterboyen/Downloads/B-small-attempt2.in"));

        String line = br.readLine();

        int testCases = Integer.parseInt(line);

        PrintStream ps = new PrintStream("/Users/peterboyen/Downloads/B-small-attempt2.out");
        //PrintStream ps = System.out;
        for (int i = 1; i <= testCases; i++) {
            int N = Integer.parseInt(br.readLine());

            LinkedList<Pair<Integer, Integer>> levels = new LinkedList<Pair<Integer, Integer>>();
            //int[][] levels = new int[N][2];
            for (int j = 0; j < N; j++) {
                String[] split = br.readLine().split(" ");
                //levels[j][0] = Integer.parseInt(split[0]);
                //levels[j][1] = Integer.parseInt(split[1]);
                levels.add(new Pair<Integer, Integer>(Integer.parseInt(split[0]), Integer.parseInt(split[1])));
            }

            ps.println("Case #" + i + ": " + solve(levels));
        }

        br.close();
        ps.close();
    }

    private static String solve(LinkedList<Pair<Integer, Integer>> levels) {
        LinkedList<Pair<Integer, Integer>> levels2 = (LinkedList<Pair<Integer, Integer>>) levels.clone();

        Collections.sort(levels, new FirstStarRatingComparator());
        Collections.sort(levels2, new SecondStarRatingComparator());

        LinkedList<Pair<Integer, Integer>> oneStarCollected = new LinkedList<Pair<Integer, Integer>>();


        int stars = 0;
        int completes = 0;

        /*System.out.println(levels);
        System.out.println(levels2);
        System.out.println(oneStarCollected);
        System.out.println(completes + " " + stars);
        System.out.println();*/


        while (levels2.size() > 0 || oneStarCollected.size() > 0) {
            if (levels2.size() > 0 && levels2.getFirst().snd <= stars) {
                stars += 2;
                completes++;
                levels.remove(levels2.removeFirst());
            } else if (oneStarCollected.size() > 0 && oneStarCollected.getFirst().snd <= stars) {
                stars += 1;
                completes++;

                oneStarCollected.removeFirst();
            } else if (levels.size() > 0 && levels.getFirst().fst <= stars) {
                stars += 1;
                completes++;

                LinkedList<Pair<Integer, Integer>> possibles = new LinkedList<Pair<Integer, Integer>>();
                int i = 0;
                while (levels.size() > i && levels.get(i).fst <= stars) {
                    possibles.add(levels.get(i));
                    i++;
                }

                Collections.sort(possibles, new SecondStarRatingComparator());

                Pair<Integer, Integer> oldPair = possibles.removeLast();
                System.out.println("possibles: " + possibles + " | " + oldPair + " " + stars);
                levels.remove(oldPair);
                levels2.remove(oldPair);

                oneStarCollected.add(oldPair);
                Collections.sort(oneStarCollected, new SecondStarRatingComparator());
            } else {
                return "Too Bad";
            }

            /*System.out.println(levels);
            System.out.println(levels2);
            System.out.println(oneStarCollected);
            System.out.println(completes + " " + stars);
            System.out.println();*/

        }


        return "" + completes;
    }

    private static class FirstStarRatingComparator implements Comparator<Pair<Integer, Integer>> {

        public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
            return o1.fst - o2.fst;
        }
    }

    private static class SecondStarRatingComparator implements Comparator<Pair<Integer, Integer>> {

        public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
            return o1.snd - o2.snd;
        }
    }
}
