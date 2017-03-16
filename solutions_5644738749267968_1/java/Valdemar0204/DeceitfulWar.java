package gcj;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class DeceitfulWar {
    public static void main(String[] args) {
        try (InputStream is = MagicTrick.class.getResourceAsStream("/DeceitfulWar.txt");
             Scanner in = new Scanner(is);
             FileWriter fw = new FileWriter("C:\\Users\\Valdemar\\Documents\\DeceitfulWar.txt");
             BufferedWriter bw = new BufferedWriter(fw)) {
            int numCases = in.nextInt();
            for (int i = 1; i <= numCases; i++) {
                int n = in.nextInt();
                List<Double> naomisWeights = new ArrayList<>(n);
                List<Double> kensWeights = new ArrayList<>(n);
                for (int j = 0; j < n; j++) {
                    naomisWeights.add(in.nextDouble());
                }
                for (int j = 0; j < n; j++) {
                    kensWeights.add(in.nextDouble());
                }
                Collections.sort(naomisWeights);
                Collections.sort(kensWeights);
                int warScore = playWar(naomisWeights, kensWeights);
                int deceitfulWarResult = playDeceitfulWar(naomisWeights, kensWeights);
                bw.write("Case #" + i + ": " + deceitfulWarResult + " " + warScore + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int playDeceitfulWar(List<Double> naomisWeights, List<Double> kensWeights) {
        naomisWeights = new ArrayList<>(naomisWeights);
        kensWeights = new ArrayList<>(kensWeights);
        int naomisScores = 0;
        int n = naomisWeights.size();
        for (int i = 0; i < n; i++) {
            double chosenNaiomi = naomisWeights.remove(0);
            double smallestKen = kensWeights.get(0);
            Double largestKen = kensWeights.get(kensWeights.size() - 1);
            double toldNaiomi;
            double chosenKen;
            if (chosenNaiomi < smallestKen) {
                toldNaiomi = largestKen - 0.0000001;
                chosenKen = kensWeights.remove(kensWeights.size()-1);
            } else {
                toldNaiomi = largestKen + 0.0000001;
                chosenKen = kensWeights.remove(0);
            }
            if (toldNaiomi > chosenKen) {
                assert chosenNaiomi > chosenKen;
                naomisScores++;
            }
        }
        return naomisScores;
    }

    private static int playWar(List<Double> naomisWeights, List<Double> kensWeights) {
        naomisWeights = new ArrayList<>(naomisWeights);
        kensWeights = new ArrayList<>(kensWeights);
        int naomisScores = 0;
        int n = naomisWeights.size();
        for (int i = 0; i < n; i++) {
            double naiomisWeight = naomisWeights.remove(0);
            double kensWeight = -1;
            for (int j = 0; j < kensWeights.size(); j++) {
                if (kensWeights.get(j) > naiomisWeight) {
                    kensWeight = kensWeights.remove(j);
                    break;
                }
            }
            if (kensWeight < 0) {
                kensWeight = kensWeights.remove(0);
            }
            if (naiomisWeight > kensWeight) {
                naomisScores++;
            }
        }
        return naomisScores;
    }
}
