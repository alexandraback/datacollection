import java.io.*;
import java.util.ArrayList;

/**
 * Created by Cristi on 4/12/2014.
 */
public class Minesweeper {
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
        int rows = Integer.parseInt(input.get(0));
        for (int i = 0; i < rows; i++) {
            String[] split = input.get(i + 1).split(" ");
            int r = Integer.parseInt(split[0]);
            int c = Integer.parseInt(split[1]);
            int m = Integer.parseInt(split[2]);
            result.addAll(processEntry(i + 1, r, c, m));
        }
        return result;
    }

    public static ArrayList<String> processEntry(int nr, int r, int c, int m) {
        ArrayList<String> result = new ArrayList<String>();
        result.add("Case #" + nr + ":");
        Matrix<Integer> mat = new Matrix<Integer>(Integer.class, r, c);
        mat.fill(0);
        mat.setConversion(0, "*");
        mat.setConversion(1, "c");
        mat.setConversion(2, ".");
        mat.set(0, 0, 1); // start position
        int free = r * c - m;
        if (free == 1) {
            result.add(mat.toString());
            return result;
        }
        if (fill(mat, free)) {
            result.add(mat.toString());
        } else {
            result.add("Impossible");
        }
        return result;
    }

    private static boolean fill(Matrix<Integer> mat, int count) {
        int rows = mat.getRows();
        int cols = mat.getCols();
        if (rows == 1) {
            for (int i = 1; i < count; i++) {
                mat.set(0, i, 2);
            }
            return true;
        }
        if (cols == 1) {
            for (int i = 1; i < count; i++) {
                mat.set(i, 0, 2);
            }
            return true;
        }
        if (count == 2 || count == 3 || count == 5 || count == 7)
            return false;
        if ((rows == 2 || cols == 2) && count % 2 != 0)
            return false;

        mat.set(0, 1, 2);
        mat.set(1, 0, 2);
        mat.set(1, 1, 2);

        if (count == 4) {
            return true;
        }
        if (rows == 2) {
            for (int i = 2; i < count / 2; i++) {
                mat.set(0, i, 2);
                mat.set(1, i, 2);
            }
            return true;
        }
        if (cols == 2) {
            for (int i = 2; i < count / 2; i++) {
                mat.set(i, 0, 2);
                mat.set(i, 1, 2);
            }
            return true;
        }

        mat.set(2, 0, 2);
        mat.set(2, 1, 2);

        if (count == 6) {
            return true;
        }

        mat.set(0, 2, 2);
        mat.set(1, 2, 2);

        if (count == 8) {
            return true;
        }
        //from here every case is solvable
        int remaining = count - 8;
        int forRemaining = remaining / 2 + 3;
        for (int i = 3; i < Math.min(forRemaining, rows); i++) {
            mat.set(i, 0, 2);
            mat.set(i, 1, 2);
            remaining -= 2;
        }
        if (remaining == 1) {
            mat.set(2, 2, 2);
            return true;
        }
        if (remaining == 0) {
            return true;
        }
        forRemaining = remaining / 2 + 3;
        for (int i = 3; i < Math.min(forRemaining, cols); i++) {
            mat.set(0, i, 2);
            mat.set(1, i, 2);
            remaining -= 2;
        }
        if (remaining == 1) {
            mat.set(2, 2, 2);
            return true;
        }
        if (remaining == 0) {
            return true;
        }
        for (int i = 2; i < rows; i++) {
            for (int j = 2; j < cols; j++) {
                mat.set(i, j, 2);
                remaining--;
                if (remaining == 0) {
                    return true;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        ArrayList<String> input = readFile("e:\\Downloads\\C-small-attempt0.in");
        ArrayList<String> result = process(input);
        writeFile("e:\\Downloads\\output.txt", result);
    }
}
