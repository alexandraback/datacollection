import org.omg.PortableInterceptor.LOCATION_FORWARD;

import java.io.*;
import java.nio.channels.FileChannel;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;

/**
 * Date: 10/05/2015
 * Time: 11:29
 */

public class LessMoneyMoreProblems {

    public static void main(String[] args) throws IOException {
        new LessMoneyMoreProblems().doSomething();
    }

    void doSomething() throws IOException {
        try {
            File test = new File(System.getProperty("user.home") + System.getProperty("file.separator") + "Downloads").getAbsoluteFile();
            File[] inList = test.listFiles(new FilenameFilter() {
                @Override
                public boolean accept(File dir, String name) {
                    return name.toLowerCase().contains(".in");
                }
            });
            File fIn = inList[0];
            for (int i = 1; i < inList.length; i++) {
                if (new Date(fIn.lastModified()).compareTo(new Date(inList[i].lastModified())) < 0) {
                    fIn = inList[i];
                }
            }

            File fsrc = new File("src" + System.getProperty("file.separator") + "LessMoneyMoreProblems.java");
            File fsrcCopy = new File(test.getAbsolutePath() + System.getProperty("file.separator") + "LessMoneyMoreProblems.java");
            if (fsrcCopy.exists()) {
                fsrcCopy.delete();
            }
            fsrcCopy.createNewFile();
            FileChannel fsrcChannel = new FileInputStream(fsrc).getChannel();
            FileChannel fsrcCopyChannel = new FileOutputStream(fsrcCopy).getChannel();
            fsrcCopyChannel.transferFrom(fsrcChannel, 0, fsrcChannel.size());
            fsrcChannel.close();
            fsrcCopyChannel.close();

            File fOut = new File(test.getAbsolutePath() + System.getProperty("file.separator") + "LessMoneyMoreProblems.out");
            BufferedReader in = new BufferedReader(new FileReader(fIn));
            BufferedWriter out = new BufferedWriter(new FileWriter(fOut));
            int n = Integer.valueOf(in.readLine());
            for (int i = 1; i <= n; i++) {
                out.write("Case #" + i + ": " + solve(in));
                out.newLine();
            }
            in.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    String solve(BufferedReader in) throws IOException {
        String[] s = in.readLine().split(" ");
        long c = Long.valueOf(s[0]);
        long d = Long.valueOf(s[1]);
        long v = Long.valueOf(s[2]);
        long count = 0;
        s = in.readLine().split(" ");
        ArrayList<Long> coins = new ArrayList<>();
        for (int i = 0; i < d; i++) {
            coins.add(Long.valueOf(s[i]));
        }

        Collections.sort(coins);
        if (coins.get(0) != 1) {
            coins.add(0, 1L);
            count = count + 1;
        }

        long sum = 0;

        for (int i = 1; i < coins.size(); i++) {
            sum = sum + c * coins.get(i - 1);
            if (sum < coins.get(i) - 1) {
                coins.add(i, sum + 1);
                count = count + 1;
            }
        }
        sum = sum + c * coins.get(coins.size() - 1);

        while (sum < v) {
            coins.add(sum + 1);
            sum = sum + c * coins.get(coins.size() - 1);
            count = count + 1;
        }

        return Long.toString(count);
    }

}
