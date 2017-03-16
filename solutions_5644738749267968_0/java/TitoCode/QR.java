
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 *
 * @author Tito
 */
public class QR {

    private static String inputFileName = "x.in";
    private static String outputFileName = "x.out";

    private static void writeOutputToFile(String str) {
        Path file = Paths.get(outputFileName);
        try {
            Files.write(file, str.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String args[]) throws IOException {
        //input
        BufferedReader br = new BufferedReader(new FileReader(inputFileName));
        //to store output
        StringBuilder out = new StringBuilder();

        int testNo = Integer.parseInt(br.readLine());
        for (int i = 1; i <= testNo; i++) {

            //solution of this test case
            String sol = "";

            int blockNum = Integer.parseInt(br.readLine());

            double[] nArr = new double[blockNum], kArr = new double[blockNum];
            ArrayList<Double> nList = new ArrayList<>(), kList = new ArrayList<>();
            String[] nSArr = br.readLine().split(" ");
            String[] kSArr = br.readLine().split(" ");
            for (int nn = 0; nn < blockNum; nn++) {
                nArr[nn] = Double.parseDouble(nSArr[nn]);
                nList.add(Double.parseDouble(nSArr[nn]));
                kArr[nn] = Double.parseDouble(kSArr[nn]);
                kList.add(Double.parseDouble(kSArr[nn]));
            }

            Collections.sort(nList, (Double a, Double b) -> a <= b ? -1 : 1);
            Collections.sort(kList, (Double a, Double b) -> a <= b ? -1 : 1);

            int fair = fairGame(nList, kList);
            int cheat = cheatGame(nList, kList);

            out.append("Case #").append(i).append(": ").append(cheat).append(" ").append(fair);
            out.append("\n");
        }
        writeOutputToFile(out.toString());
    }

    private static int fairGame(ArrayList<Double> nList_, ArrayList<Double> kList_) {
        int score = 0;
        ArrayList<Double> nList = (ArrayList<Double>) nList_.clone();
        ArrayList<Double> kList = (ArrayList<Double>) kList_.clone();

        while (true) {
            if (nList.isEmpty()) {
                break;
            }
            int size = nList.size() - 1;
            if (nList.get(size) > kList.get(size)) {
                score++;
                nList.remove(size);
                kList.remove(0);
            } else {
                nList.remove(size);
                kList.remove(size);
            }

        }

        System.out.println(score);
        return score;
    }

    private static int cheatGame(ArrayList<Double> nList, ArrayList<Double> kList) {
        int score = 0;
        
        while (true) {
            if (nList.isEmpty()) {
                break;
            }
            int size = nList.size() - 1;
            if (nList.get(0) > kList.get(0)) {
                score++;
                nList.remove(0);
                kList.remove(0);
            } else {
                nList.remove(0);
                kList.remove(size);
            }

        }

        System.out.println(score);
        return score;
    }

}
