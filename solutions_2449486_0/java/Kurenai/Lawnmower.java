package googlecodejam.lawnmower;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Lawnmower {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        ArrayList<Lawn> lawns = getLawns("C:\\Users\\Patri\\Downloads\\B-small-attempt0.in");
        for (int i = 0; i < lawns.size(); i++) {
            Lawn lawn = lawns.get(i);
            System.out.println("Case #" + (i + 1) + ": " + lawn.toString());
        }
    }

    public static ArrayList<Lawn> getLawns(String aFileName) throws FileNotFoundException, IOException {
        ArrayList<Lawn> lawns = new ArrayList<Lawn>();
        ArrayList<String> lines = readFile(aFileName);

        boolean readNumPatterns = true;
        boolean readNM = false;
        boolean readPattern = false;

        int N = 0, M = 0, patternLine = 0;
        int[][] pattern = null;

        for (String line : lines) {


            if (readNumPatterns) {
                readNumPatterns = false;
                readNM = true;

            } else if (readNM) {
                String[] split = line.split(" ");
                N = Integer.parseInt(split[0]);
                M = Integer.parseInt(split[1]);
                pattern = new int[N][M];
                readNM = false;
                readPattern = true;

            } else if (readPattern) {
                String[] split = line.split(" ");
                for (int j = 0; j < M; j++) {
                    pattern[patternLine][j] = Integer.parseInt(split[j]);
                }
                if (patternLine < N - 1) {
                    patternLine++;
                } else {
                    lawns.add(new Lawn(pattern));
                    patternLine = 0;
                    readPattern = false;
                    readNM = true;
                }
            }
        }
        return lawns;
    }

    public static ArrayList<String> readFile(String aFileName) throws FileNotFoundException, IOException {
        ArrayList<String> result = new ArrayList<String>();
        FileReader fr = new FileReader(aFileName);
        BufferedReader br = new BufferedReader(fr);
        String s;
        while ((s = br.readLine()) != null) {
            result.add(s);
        }
        return result;
    }
}
