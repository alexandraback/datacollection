package contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Util {
    public static void debug(String s) {
//        System.out.flush();
//        System.err.println("DEBUG: " + s);
//        System.err.flush();
    }

    public static int readIntLine(BufferedReader in) throws IOException {
        return Integer.parseInt(in.readLine());
    }

    public static Integer[] readIntArrayLine(BufferedReader in) throws IOException {
        String line = in.readLine();
        List<Integer> ints = new ArrayList<Integer>();
        for (String intStr : line.split(" ")) {
            ints.add(Integer.parseInt(intStr));
        }

        return ints.toArray(new Integer[0]);
    }

    public static String[] readStringArrayLine(BufferedReader in) throws IOException {
        String forward[] = in.readLine().split(" ");
        return forward;
    }
}
