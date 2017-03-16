package mp.kotter.challenges.gcj.qualification;

import java.io.IOException;
import java.util.Collections;
import java.util.List;

import mp.kotter.challenges.utils.Solution;

public class Osmos extends Solution {

    public static void main(final String[] args) throws Exception {
        (new Osmos()).run(args);
    }

    @Override
    protected void solve() throws Exception {
        final int T = Integer.parseInt(getInput().readLine());

        for(int c=0; c<T; c++) {
            writeCaseResult(c, solveCase());
        }
    }

    private String solveCase() throws IOException {
        final List<Integer> line = readInts();
        final long a = line.get(0);
        final long n = line.get(1);
        final List<Long> motes = readLongs();

        if (a == 1) {
            return "" + n;
        }

        Collections.sort(motes);

        int minCount = Integer.MAX_VALUE;

        for(int removed = 0; removed <= motes.size(); removed++) {
            int count = removed;
            long ca = a;
            for(int i = 0; i < motes.size() - removed; i++) {
                final long mote = motes.get(i);

                while(ca <= mote) {
                    ca += ca - 1;
                    count++;
                }

                ca += mote;
            }

            if (count < minCount) {
                minCount = count;
            }
        }

        return "" + minCount;
    }
}
