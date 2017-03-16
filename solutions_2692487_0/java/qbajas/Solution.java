import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Qba
 * Date: 27.04.13
 * Time: 04:30
 * To change this template use File | Settings | File Templates.
 */
public class Solution {

    public static void main(String[] args) throws IOException {
        Solution s=new Solution();

        System.out.println("Starting computing from file ...");
        Scanner scanner = new Scanner(new File("files/input"));

        Path file = Paths.get("files/out");
        BufferedWriter bw = Files.newBufferedWriter(file, Charset.defaultCharset());

        int cases = scanner.nextInt();
        for (int i = 0; i < cases; i++) {
            long Amote=scanner.nextLong();
            long moteCount = scanner.nextLong();
            List<Long> motes = new LinkedList<Long>();
            for (int j = 0; j < moteCount; j++) {
                motes.add(scanner.nextLong());
            }
            long result = s.solve(Amote,motes);
            String r = "Case #" + (i + 1) + ": " + result + "\n";
            bw.write(r);
        }
        bw.close();

    }

    int bestYet = Integer.MAX_VALUE;

    public int solve(long Amote, List<Long> motes) {
        bestYet = Integer.MAX_VALUE;
        Collections.sort(motes);
        return solve(Amote, motes, 0, 0, motes.size() - 1);
    }

    private int solve(long Amote, List<Long> motes, int step, int changes, int stopIndex) {
        if (step >= stopIndex + 1) {
            if (changes < bestYet) {
                bestYet = changes;
            }
            return changes;
        }

        if(changes>bestYet){
            return changes;
        }

        int return_value;
        if (Amote > motes.get(step)) {
            return_value = solve(Amote + motes.get(step), motes, step + 1, changes, stopIndex);
        } else {
            int changesByAddingMote = Integer.MAX_VALUE;
            if (Amote != 1) {
                changesByAddingMote = solve(Amote + Amote - 1, motes, step, changes + 1, stopIndex);
            }
            int changesByDeletingLastMote = solve(Amote, motes, step, changes + 1, stopIndex - 1);
            return_value = Math.min(
                    changesByAddingMote,
                    changesByDeletingLastMote
            );
        }
        return return_value;
    }


}
