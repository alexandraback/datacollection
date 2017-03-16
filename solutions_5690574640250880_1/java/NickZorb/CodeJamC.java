
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.text.ParseException;


public class CodeJamC {
public static void main(String[] args) throws FileNotFoundException, IOException, ParseException {
        CodeJamC jam = new CodeJamC();
        jam.solve("C-large.in");
    }
    
    public void solve(String file) throws FileNotFoundException, IOException, ParseException {
        File f = new File(file);
        FileReader fin = new FileReader(f);
        BufferedReader in = new BufferedReader(fin);
        int cases = Integer.parseInt(in.readLine());
        File outF = new File("resultsC_large.txt");
        PrintStream out = new PrintStream(outF);
        for (int i = 1; i <= cases; i++) {
            String[] tokens = in.readLine().split(" ");
            int height = Integer.parseInt(tokens[0]);
            int width = Integer.parseInt(tokens[1]);
            int tiles = height * width - Integer.parseInt(tokens[2]);
            char[][] table = new char[height][width];
            for (char[] row : table) {
                for (int j = 0; j < row.length; j++) {
                    row[j] = '*';
                }
            }
            table[0][0] = 'c';
            int[] cur = {0, 0};
            tiles--;
            while (tiles > 0) {
                for (int k = -1; k < 2; k++) {
                    for (int l = -1; l < 2; l++) {
                        int curHeight = cur[0] + k;
                        int curWidth = cur[1] + l;
                        if (curHeight >= 0 && curWidth >= 0 && curHeight < height && curWidth < width && table[curHeight][curWidth] == '*') {
                            table[curHeight][curWidth] = '.';
                            tiles--;
                        }
                    }
                }
                int min = 10;
                boolean changed = false;
                boolean done = false;
                for (int j = 0; j < table.length && !done; j++) {
                    for (int k = 0; k < table[0].length && !done; k++) {
                        if (table[j][k] == '.') {
                            int missing = 0;
                            for (int l = -1; l < 2; l++) {
                                for (int m = -1; m < 2; m++) {
                                    int curHeight = j + l;
                                    int curWidth = k + m;
                                    if (curHeight >= 0 && curWidth >= 0 && curHeight < height && curWidth < width && table[curHeight][curWidth] == '*') {
                                        missing++;
                                    }
                                }
                            }
                            if (missing > 0 && (missing < min || missing == tiles)) {
                                changed = true;
                                min = missing;
                                cur[0] = j;
                                cur[1] = k;
                                if (missing == tiles) {
                                    done = true;
                                }
                            }
                        }
                    }
                }
                if (!changed || min > tiles) {
                    break;
                }
            }
            out.println("Case #" + i + ":");
            if (tiles == 0) {
                for (char[] row : table) {
                    for (int j = 0; j < row.length - 1; j++) {
                        out.print(row[j]);
                    }
                    out.println(row[row.length - 1]);
                }
            } else {
                out.println("Impossible");
            }
        }
    }
}