import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class CloseMatch {

    public static void main(String[] args)
            throws FileNotFoundException, UnsupportedEncodingException {
        Scanner in = new Scanner(new File("B-small-attempt1.in"));
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        String countStr = in.nextLine();
        int count = Integer.parseInt(countStr);
        for (int c = 0; c < count; c++) {
            String s = in.nextLine();
            if (c == count - 1) {
                writer.print("Case #" + (c + 1) + ": " + closeMatch(s));
            } else {
                writer.println("Case #" + (c + 1) + ": " + closeMatch(s));
            }
        }
        writer.close();
        in.close();
    }

    public static String closeMatch(String s) {
        int bar = s.indexOf(" ");
        String s1 = s.substring(0, bar);
        String s2 = s.substring(bar + 1);
        if (numLoc(s1) < numLoc(s2)) {
            //s1 = cleanQ(s1, numLoc(s1));
            //s2 = cleanQ(s2, numLoc(s1));
        } else {
            //s1 = cleanQ(s1, numLoc(s2));
            //s2 = cleanQ(s2, numLoc(s2));
        }
        if (!s1.contains("?") && !s2.contains("?")) {
            return s1 + " " + s2;
        }
        return findMatch(s1, s2);
    }

    public static String findMatch(String s1, String s2) {
        ArrayList<String> p1 = generatePos(s1);
        ArrayList<String> p2 = generatePos(s2);

        p1.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                // TODO Auto-generated method stub
                return o1.compareTo(o2);
            }
        });
        p2.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                // TODO Auto-generated method stub
                return o1.compareTo(o2);
            }
        });

        int delta = Math
                .abs(Integer.parseInt(p1.get(0)) - Integer.parseInt(p2.get(0)));
        System.out.println(" L " + delta);
        String xf = p1.get(0);
        String yf = p2.get(0);
        for (int x = 0; x < p1.size(); x++) {
            for (int y = 0; y < p2.size(); y++) {
                int hold = Math.abs(Integer.parseInt(p1.get(x))
                        - Integer.parseInt(p2.get(y)));
                if (hold < delta) {
                    delta = hold;
                    xf = p1.get(x);
                    System.out.println(xf);
                    yf = p2.get(y);
                }
            }
        }
        return xf + " " + yf;
    }

    public static ArrayList<String> generatePos(String s) {
        ArrayList<String> p = new ArrayList<String>();
        String temp;
        for (int c = 0; c < 10; c++) {
            temp = s.replaceFirst("[?]", c + "");
            //System.out.println(temp);
            if (temp.contains("?")) {
                p.addAll(generatePos(temp));
            } else {
                p.add(temp);
            }
        }
        return p;
    }

    public static String cleanQ(String s, int loc) {
        if (loc == -1) {
            String ret = "";
            for (int c = 0; c < s.length(); c++) {
                ret = ret + "0";
            }
            return ret;
        }
        String ret = s;
        for (int c = 0; c < loc; c++) {
            ret = ret.substring(0, c) + "0" + ret.substring(c + 1);
        }
        return ret;
    }

    public static int numLoc(String s) {
        for (int c = 0; c < s.length(); c++) {
            if (s.charAt(c) != '?') {
                return c;
            }
        }
        return -1;
    }

}
