package jam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by mafulafunk on 13.03.15.
 */
public class Monkey {
    private static int cases;

    public static void main(String[] args) throws IOException {
        File in = new File("/Users/mafulafunk/Downloads/B-small-attempt1.in");
//        File in = new File("/Users/mafulafunk/Code/jam/StoreCredit/src/main/resources/Monkey.in");
        PrintWriter out = new PrintWriter("output.txt");
        BufferedReader br = new BufferedReader(new FileReader(in));
        cases = Integer.valueOf(br.readLine());
        for (int i = 1; i <= cases; i++) {


            int[] line = toIntArray(br.readLine().split(" "));

            int keysLength = line[0];
            int targetLength = line[1];
            int sentenceLenght = line[2];

            String keys = br.readLine();
            String targetWord = br.readLine();


            float[] probabilityArray = new float[targetLength];

            for (int j = 0; j < targetLength; j++) {
                int count = 0;
                for (int k = 0; k < keysLength; k++) {
                    count = targetWord.charAt(j) == keys.charAt(k) ? count + 1 : count;
                }
                probabilityArray[j] = Float.valueOf(count) / keysLength;
            }

            float probability = 1f;
            for (int l = 0; l < probabilityArray.length; l++) {
                probability = probability * probabilityArray[l];
            }


            int commonLength = 0;
            for (int m = 0; m < targetLength - 1; m++) {
                if (targetWord.startsWith(targetWord.substring(targetLength - m))) {
                    commonLength = m;
                }
            }

            int wordsInLine = sentenceLenght / (targetLength - commonLength);

            int bananasToBring = probability > 0.0 ? wordsInLine : 0;

            int wordsGross = sentenceLenght / targetLength;

//            double caseOut = (bananasToBring - (wordsInLine * (Math.pow(probability, wordsGross))));
            double caseOut = (bananasToBring - (wordsInLine * probability));

            out.println("Case #" + i + ": " + caseOut);
        }
        out.flush();
        out.close();
    }

    private static int[] toIntArray(String[] strArray) {
        int[] out = new int[strArray.length];
        for (int i = 0; i < strArray.length; i++) {
            out[i] = Integer.parseInt(strArray[i]);
        }
        return out;
    }

}
