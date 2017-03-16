import javax.swing.*;
import java.io.*;

public class Cookies {
    void process() throws IOException {
        int nCases = readInt();
        for (int c = 1; c <= nCases; c++) {
            double[] in = readDoubles();
            double farmCost = in[0];
            double farmGain = in[1];
            double target = in[2];

            double time = 0;
            double rate = 2;
            while (target / rate > (farmCost / rate + target / (rate + farmGain))) {
                time += farmCost / rate;
                rate += farmGain;
            }
            time += target / rate;

            writeln("Case #" + c + ": " + time);
        }

        done();
    }

    public Cookies(File inputFile) throws FileNotFoundException {
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

    int[][] readIntMatrix(int nLines) throws IOException {
        int[][] res = new int[nLines][];
        for (int a = 0; a < nLines; a++)
            res[a] = readInts();
        return res;
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
            new Cookies(jfc.getSelectedFile()).process();
        }
    }
}
