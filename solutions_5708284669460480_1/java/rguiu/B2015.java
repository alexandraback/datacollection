import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.StringTokenizer;

public class B2015 {


    public static void main(String[] args) throws IOException {
        B2015 trans = new B2015();
        trans.doMe();
    }

    private static final String NAME = "B-large";

    public void doMe() throws IOException {
        File file = new File("./inputs/"+NAME + ".in");
        BufferedWriter out = new BufferedWriter(new FileWriter("./output/"+NAME+".out"));
        try {
            //use buffering, reading one line at a time
            //FileReader always assumes default encoding is OK!
            BufferedReader input = new BufferedReader(new FileReader(file));
            try {
                String line = input.readLine();
                int count = Integer.parseInt(line);

                for (int i=0;i<count;i++) {
                    line = input.readLine();
                    String line2 = input.readLine();
                    String line3 = input.readLine();
                    String str = this.proccessLine(line.trim(), line2, line3);
                    out.write("Case #"+(i+1)+": "+str);
                    if (i<count-1)
                        out.write(System.getProperty("line.separator"));
                    System.out.println(str);
                }
            } finally {
                input.close();
                out.flush();
                out.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    int[] toIntArray(String str) {
        StringTokenizer tokens = new StringTokenizer(str);
        int[] a= new int[tokens.countTokens()];
        int i = 0;
        while(tokens.hasMoreElements()) {
            a[i++] = Integer.parseInt(tokens.nextToken());
        }
        return a;
    }

    String proccessLine(String line, String keyboard, String word) {
        int[] raws = toIntArray(line);
        int K = raws[0];
        int L = raws[1];
        int S = raws[2];
        double ma = calcMax(word, S);

        System.out.println("max: " +ma);
        int keys[] = countKeys(keyboard,word);
        for (int h:keys) {
            if (h==0) return Double.toString(0.0);
        }

        double co = probOne(word, keys, keyboard.length());

        double result = ma - (co * (S - L + 1));
        DecimalFormat df = new DecimalFormat("#0.0000000");
        return df.format(result);
    }

    double probOne(String word, int[] keys, int l) {
        double d = 1.0;
        for (int i = 0; i < word.length(); i++) {
            d *= keys[i]*1.0/l;
        }
        return d;
    }

    int calcMax(String s, int l) {
        if (s.length() > l) return 0;
        String sl = s + "";
        int i = 0;
        for (int j = 0; j < l; j++) {
            if (j >= sl.length()) {
                sl = sl + s;
                if (sl.length()>l)
                    sl = sl.substring(0, l);
            }

            if (sl.substring(j).startsWith(s)) {
                i++;
                continue;
            }
            String sub = sl.substring(j);

            if (s.startsWith(sub)) {
                sl = sl + s.substring(sub.length());
                if (sl.length() > l) sl = sl.substring(0, l);
                if (sl.substring(j).startsWith(s)) {
                    i++;
                }
            }
        }
        return i;
    }

    int[] countKeys(String keyboard, String word) {
        int[]keys = new int[word.length()];
        for (int i = 0; i < word.length(); i++) {
            for (int j = 0; j < keyboard.length(); j++) {
                if (keyboard.charAt(j)==word.charAt(i)) {
                    keys[i] ++;
                }
            }
        }
        return keys;
    }
}
