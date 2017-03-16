import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

/**
 * Created by Cristi on 4/12/2014.
 */
public class War {
    public static ArrayList<String> readFile(String path) {
        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader(path));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        String line = null;
        ArrayList<String> result = new ArrayList<String>();
        try {
            while ((line = reader.readLine()) != null) {
                result.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return result;
    }

    public static void writeFile(String path, ArrayList<String> content) {
        FileWriter f0 = null;
        String newLine = System.getProperty("line.separator");

        try {
            f0 = new FileWriter(path);
            for (int i = 0; i < content.size(); i++) {
                f0.write(content.get(i) + newLine);
            }
            f0.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static ArrayList<String> process(ArrayList<String> input) {
        ArrayList<String> result = new ArrayList<String>();
        int sets = Integer.parseInt(input.get(0));
        for (int i = 0; i < sets; i++) {
            String[] split = input.get(i * 3 + 2).split(" ");
            double naomi[] = new double[split.length];
            for (int j = 0; j < split.length; j++) {
                naomi[j] = Double.parseDouble(split[j]);
            }
            split = input.get(i * 3 + 3).split(" ");
            double ken[] = new double[split.length];
            for (int j = 0; j < split.length; j++) {
                ken[j] = Double.parseDouble(split[j]);
            }
            result.add(processEntry(i + 1, naomi, ken));
        }
        return result;
    }

    public static String processEntry(int nr, double naomi[], double ken[]) {
        Arrays.sort(naomi);
        Arrays.sort(ken);
        int size = naomi.length;
        int scoreWar = 0;
        int scoreDWar = 0;
        if (size == 1) {
            if (naomi[0] > ken[0]) {
                scoreWar = 1;
                scoreDWar = 1;
            }
        } else {
            scoreWar = playWar(toList(naomi), toList(ken));
            scoreDWar = playDWar(toList(naomi), toList(ken));
        }
        return "Case #" + nr + ": " + scoreDWar + " " + scoreWar;
    }

    public static int playWar(LinkedList<Double> naomi, LinkedList<Double> ken) {
        int score = 0;
        while (naomi.size() > 0) {
            double n = naomi.pollFirst();
            double k = playKen(ken, n);
            if (n > k) {
                score++;
            }
        }
        return score;
    }

    public static int playDWar(LinkedList<Double> naomi, LinkedList<Double> ken) {
        int score = 0;
        while (naomi.size() > 0) {
            if (naomi.getFirst() > ken.getFirst()) {
                double n = naomi.pollFirst();
                double k = playKen(ken, ken.getLast() + 0.000001);
                score++;
            } else {
                double n = naomi.pollFirst();
                double k = playKen(ken, ken.getLast() - 0.000001);
            }
        }
        return score;
    }

    public static double playKen(LinkedList<Double> ken, double target) {
        for (double d : ken) {
            if (d > target) {
                ken.remove(d);
                return d;
            }
        }
        return ken.pollFirst();
    }

    public static LinkedList<Double> toList(double array[]) {
        LinkedList<Double> result = new LinkedList<Double>();
        for (int i = 0; i < array.length; i++) {
            result.addLast(array[i]);
        }
        return result;
    }

    public static void main(String[] args) {
        ArrayList<String> input = readFile("e:\\Downloads\\input.in");
        ArrayList<String> result = process(input);
        writeFile("e:\\Downloads\\output.txt", result);
    }
}
