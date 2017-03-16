package ondra;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Technobabble {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        new Technobabble().run();
    }

    private void run() throws FileNotFoundException, IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader("C-small-attempt0.in"));
                PrintWriter writer = new PrintWriter(new FileWriter("C-small-attempt0.out"))) {
            String line;
            reader.readLine(); // ignore
            int c = 1;
            while ((line = reader.readLine()) != null) {
                int n = Integer.parseInt(line);
                List<String[]> list = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    line = reader.readLine();
                    list.add(line.split(" "));
                }
                int fakes = 0;
                int fakeIndex = -1;
                do {
                    fakeIndex = findFakeIndex(list);
                    if (fakeIndex != -1) {
                        list.remove(fakeIndex);
                        fakes++;
                    }
                } while (fakeIndex != -1);
//                System.out.println(fakes);
                writer.println(String.format("Case #%s: %s", c, fakes));

                System.out.println(c);
                c++;
            }
        }
    }

    private int findFakeIndex(List<String[]> list) {
        int result = -1;

        for (int i = 0; i < list.size(); i++) {
            String[] candidate = list.get(i);
            boolean leftFound = false;
            boolean rightFound = false;
            for (int j = 0; j < list.size(); j++) {
                if (i != j) {
                    String[] other = list.get(j);
                    if (candidate[0].equals(other[0])) leftFound = true;
                    if (candidate[1].equals(other[1])) rightFound = true;
                    if (leftFound && rightFound) return i;
                }
            }
        }

        return result;
    }

}
