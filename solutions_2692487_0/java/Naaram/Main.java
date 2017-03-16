import com.google.common.base.Splitter;
import com.google.common.collect.Lists;

import java.io.*;
import java.util.*;

public class Main {
    private static final String TEST_INPUT = "4\n" +
            "2 2\n" +
            "2 1\n" +
            "2 4\n" +
            "2 1 1 6\n" +
            "10 4\n" +
            "25 20 9 100\n" +
            "1 4\n" +
            "1 1 1 1\n";


    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new FileReader("c:\\comp\\small.in"));
        //BufferedReader bufferedReader = new BufferedReader(new StringReader(TEST_INPUT));
        final PrintStream outStream = new PrintStream(new FileOutputStream("c:\\comp\\small.out"));
        int numCases = Integer.valueOf(bufferedReader.readLine());

        for(int i = 1; i <= numCases; i++) {
            String line = bufferedReader.readLine();
            Iterator<String> lineTokens = Splitter.on(" ").split(line).iterator();
            long size = Long.valueOf(lineTokens.next());
            long numMotes = Long.valueOf(lineTokens.next());

            line = bufferedReader.readLine();
            lineTokens = Splitter.on(" ").split(line).iterator();
            List<Long> motes = Lists.newArrayListWithCapacity((int) numMotes);
            for(int j = 0; j < numMotes; j++) {
                motes.add(Long.valueOf(lineTokens.next()));
            }

            Collections.sort(motes);

            int result = motes.size();
            if(size > 1) {
                result = solve(size, 0, motes);
            }

            System.out.println("Case #" + i + ": " + result);
            outStream.println("Case #" + i + ": " + result);
        }
    }

    private static int solve(long size, int currentIndex, List<Long> motes) {
        for(int j = currentIndex; j < motes.size(); j++) {
            if(size <= motes.get(j)) {
                int option1 = solve(size * 2 - 1, j, motes) + 1;
                int option2 = motes.size() - j;
                return Math.min(option1, option2);
            } else {
                size += motes.get(j);
            }
        }

        return 0;
    }
}
