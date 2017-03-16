import java.io.*;
import java.nio.channels.FileChannel;
import java.util.Date;

/**
 * Date: 02/05/2015
 * Time: 18:15
 */

public class CounterCulture {

    public static void main(String[] args) throws IOException {
        new CounterCulture().doSomething();
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

            File fsrc = new File("src" + System.getProperty("file.separator") + "CounterCulture.java");
            File fsrcCopy = new File(test.getAbsolutePath() + System.getProperty("file.separator") + "CounterCulture.java");
            if (fsrcCopy.exists()) {
                fsrcCopy.delete();
            }
            fsrcCopy.createNewFile();
            FileChannel fsrcChannel = new FileInputStream(fsrc).getChannel();
            FileChannel fsrcCopyChannel = new FileOutputStream(fsrcCopy).getChannel();
            fsrcCopyChannel.transferFrom(fsrcChannel, 0, fsrcChannel.size());
            fsrcChannel.close();
            fsrcCopyChannel.close();

            File fOut = new File(test.getAbsolutePath() + System.getProperty("file.separator") + "CounterCulture.out");
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
        long n = Long.valueOf(in.readLine());
        long start = n;
        long count = 0;
        long tmp = 0;
        int size = 0;
        long secondHalf = 0;

        do {
            size = 0;
            for (int i = 0; i < 15; i++) {
                if (n % Math.pow(10, i) == n) {
                    size = i;
                    break;
                }
            }
            if (size == 1) {
                return Long.toString(count + n);
            }

            secondHalf = ((Double) (n % Math.pow(10, (size + 1) / 2))).longValue();
            if (secondHalf > 1) {
                count = count + secondHalf - 1;
                n = n - secondHalf + 1;
            }

            if (secondHalf == 0) {
                n = n - 1;
                count++;
            } else if (secondHalf == 1) {
                tmp = Long.valueOf(new StringBuilder(Long.toString(n)).reverse().toString());
                if (tmp < n) {
                    n = tmp;
                    count++;
                } else {
                    n = n - 2;
                    count = count + 2;
                }
            }
        } while(true);
    }

}
