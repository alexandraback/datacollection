import java.io.*;
import java.nio.channels.FileChannel;
import java.util.Date;

/**
 * Date: 10/05/2015
 * Time: 11:03
 */

public class Brattleship {

    public static void main(String[] args) throws IOException {
        new Brattleship().doSomething();
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

            File fsrc = new File("src" + System.getProperty("file.separator") + "Brattleship.java");
            File fsrcCopy = new File(test.getAbsolutePath() + System.getProperty("file.separator") + "Brattleship.java");
            if (fsrcCopy.exists()) {
                fsrcCopy.delete();
            }
            fsrcCopy.createNewFile();
            FileChannel fsrcChannel = new FileInputStream(fsrc).getChannel();
            FileChannel fsrcCopyChannel = new FileOutputStream(fsrcCopy).getChannel();
            fsrcCopyChannel.transferFrom(fsrcChannel, 0, fsrcChannel.size());
            fsrcChannel.close();
            fsrcCopyChannel.close();

            File fOut = new File(test.getAbsolutePath() + System.getProperty("file.separator") + "Brattleship.out");
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
        int r = Integer.valueOf(s[0]);
        int c = Integer.valueOf(s[1]);
        int w = Integer.valueOf(s[2]);

        int count = r * (c / w);
        int rest = c % w;

        if (rest == 0) {
            return Integer.toString(count + w - 1);
        } else {
            return Integer.toString(count + w);
        }
    }
}
