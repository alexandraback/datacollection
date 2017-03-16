import javax.swing.*;
import java.io.*;
import java.util.Arrays;

public class War {
    void process() throws IOException {
        int nCases = readInt();
        for (int c = 1; c <= nCases; c++) {
            readInt();

            double[] naomi = readDoubles();
            double[] ken = readDoubles();

            int fair = fair(naomi, ken);
            int cheat = cheat(naomi, ken);

            writeln("Case #" + c + ": " + cheat + " " + fair);
        }

        done();
    }

    private int cheat(double[] naomi, double[] ken) {
        Arrays.sort(naomi);
        Arrays.sort(ken);

        int score = 0;
        int kenPos = 0;
        for (int a = 0; a < naomi.length; a++) {
            if (naomi[a] < ken[kenPos]) {
                // lose this one in any case; say ken's highest - epsilon to get rid of it
            } else {
                // lie - say it's higher than Ken's highest, and he will get rid of his lowest
                score++;
                kenPos++;
            }
        }
        return score;
    }

    private int fair(double[] naomi, double[] ken) {
        Arrays.sort(naomi);
        Arrays.sort(ken);

        int score = 0;
        int kenPos = 0;
        for (int a = 0; a < naomi.length; a++) {
            while (kenPos < ken.length && ken[kenPos] < naomi[a])
                kenPos++;
            if (kenPos >= ken.length) {
                score++;
            } else {
                kenPos++;
            }
        }
        return score;
    }

    public War(File inputFile) throws FileNotFoundException {
        this.inputFile = inputFile;
        this.outputFile = new File(inputFile.getParentFile(), inputFile.getName() + ".out");
        this.reader = new LineNumberReader(new FileReader(inputFile));
        this.result = new StringBuilder();
    }

    private StringBuilder result;
    private File inputFile;
    private LineNumberReader reader;
    private File outputFile;

    void done() throws IOException {
        FileOutputStream fos = new FileOutputStream(outputFile);
        fos.write(result.toString().getBytes("UTF-8"));
        fos.close();

        System.out.println(inputFile + " => " + outputFile);
    }

    void writeln(String s) {
        write(s + "\n");
    }

    void write(String s) {
        System.out.print(s);
        result.append(s);
    }

    int readInt() throws IOException {
        return readInts()[0];
    }

    double[] readDoubles() throws IOException {
        String l = reader.readLine().trim();
        String[] parts = l.split(" ");
        double[] res = new double[parts.length];
        for (int a = 0; a < res.length; a++)
            res[a] = Double.parseDouble(parts[a]);
        return res;
    }

    int[] readInts() throws IOException {
        String l = reader.readLine().trim();
        String[] parts = l.split(" ");
        int[] res = new int[parts.length];
        for (int a = 0; a < res.length; a++)
            res[a] = Integer.parseInt(parts[a]);
        return res;
    }

    public static void main(String[] args) throws Exception {
        JFileChooser jfc = new JFileChooser();
        jfc.setCurrentDirectory(new File("/home/mitja/codejam"));
        if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
            new War(jfc.getSelectedFile()).process();
        }
    }
}
