import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        BufferedWriter writer = null;
        try {
            File outputFile = new File("output.txt");
            if (!outputFile.exists()) {
                outputFile.createNewFile();
            }
            writer = new BufferedWriter(new FileWriter(outputFile));
            BufferedReader reader = new BufferedReader(new FileReader(args[0]));

            //TODO: Stuffs
            int numberOfTests = Integer.parseInt(reader.readLine());

            for (int i=1;i<=numberOfTests;i++) {
                if (i != 1) {
                    writer.newLine();
                }
                String caseNum = String.format(Locale.US, "Case #%d: ", i);

                //TODO: Run the test
                String info = reader.readLine();
                StringTokenizer tokenizer = new StringTokenizer(info);
                long firstRadius = Long.parseLong(tokenizer.nextToken());
                long millilitres = Long.parseLong(tokenizer.nextToken());

                long numCircles = drawCircles(firstRadius, millilitres);

                writer.write(caseNum + numCircles);
            }

            writer.flush();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (writer != null) {
                try {
                    writer.flush();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static long drawCircles(long firstRadius, long millilitres) {
        long numCircles = 0;
        long nextRadius = firstRadius + 1;
        long millilitresLeft = millilitres;

        while (millilitresLeft > 0) {
            millilitresLeft = attemptCircleDraw(nextRadius, millilitresLeft);
            if (millilitresLeft >= 0) {
                numCircles++;
            }
            nextRadius += 2;
        }

        return numCircles;
    }

    public static long attemptCircleDraw(long radius, long millilitres) {
        long innerRadius = radius - 1;
        long innerArea = innerRadius * innerRadius;
        long outerArea = radius * radius;

        long areaToPaint = outerArea - innerArea; //Area in cm2

        return millilitres - areaToPaint;
    }
}
