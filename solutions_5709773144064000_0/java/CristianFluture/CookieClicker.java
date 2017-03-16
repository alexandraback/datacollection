import java.io.*;
import java.util.ArrayList;

/**
 * Created by Cristi on 4/12/2014.
 */
public class CookieClicker {
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

    public static ArrayList<String> process(ArrayList<String> input){
        ArrayList<String> result = new ArrayList<String>();
        int rows = Integer.parseInt(input.get(0));
        for (int i = 0; i < rows; i++) {
            String[] split = input.get(i + 1).split(" ");
            double c = Double.parseDouble(split[0]);
            double f = Double.parseDouble(split[1]);
            double x = Double.parseDouble(split[2]);
            result.add(processEntry(i + 1, c, f, x));
        }
        return result;
    }

    public static String processEntry(int nr, double c, double f, double x){
        double result = 0;
        // init values
        double rate = 2;
        double remaining = x;
        double elapsed = 0;

        double remainingWithoutBuy = remaining / rate;
        double remainingWithBuy = c / rate + remaining / (rate + f);

        while (remainingWithBuy < remainingWithoutBuy) {
            elapsed = elapsed + c / rate;
            rate = rate + f;

            remainingWithoutBuy = remaining / rate;
            remainingWithBuy = c / rate + remaining / (rate + f);
        }
        return "Case #" + nr + ": " + (remainingWithoutBuy + elapsed);
    }

    public static void main(String[] args){
        ArrayList<String> input = readFile("e:\\Downloads\\B-small-attempt0.in");
        ArrayList<String> result = process(input);
        writeFile("e:\\Downloads\\output.txt", result);
    }

}
