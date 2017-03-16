import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {

    private static int maxEnergy;
    private static int regainAmount;

    public static void main(String[] args) {
        BufferedWriter writer = null;
        try {
            File outputFile = new File("output.txt");
            if (!outputFile.exists()) {
                outputFile.createNewFile();
            }
            writer = new BufferedWriter(new FileWriter(outputFile));
            BufferedReader reader = new BufferedReader(new FileReader(args[0]));

            int numberOfTests = Integer.parseInt(reader.readLine());

            for (int i=1;i<=numberOfTests;i++) {
                if (i != 1) {
                    writer.newLine();
                }
                String caseNum = String.format(Locale.US, "Case #%d: ", i);

                String baseInfo = reader.readLine();
                String nodes = reader.readLine();

                StringTokenizer baseTokens = new StringTokenizer(baseInfo);
                maxEnergy = Integer.parseInt(baseTokens.nextToken());
                regainAmount = Integer.parseInt(baseTokens.nextToken());
                int numNodes = Integer.parseInt(baseTokens.nextToken());

                StringTokenizer nodeTokens = new StringTokenizer(nodes);
                ArrayList<Integer> nodeList = new ArrayList<Integer>(numNodes);
                while (nodeTokens.hasMoreTokens()) {
                    nodeList.add(new Integer(nodeTokens.nextToken()));
                }

                int maxValue = findMaxValue(maxEnergy, nodeList, 0);

                writer.write(caseNum + maxValue);
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

    private static int findMaxValue(final int currentEnergy, final ArrayList<Integer> nodeList, int position) {
        //We are done!
        if (position >= nodeList.size()) return 0;
        int currentNode = nodeList.get(position);

        int totalGain = 0;
        for (int i=0;i<=currentEnergy;i++) {
            int gain = (i * currentNode) + findMaxValue(regainEnergy(currentEnergy-i), nodeList, position+1);
            if (gain > totalGain) totalGain = gain;
        }

        return totalGain;
    }

    private static int regainEnergy(int energy) {
        int newEnergy = energy + regainAmount;
        if (newEnergy > maxEnergy) newEnergy = maxEnergy;
        return newEnergy;
    }
}

