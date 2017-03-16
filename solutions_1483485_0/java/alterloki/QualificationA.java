/**
 * Created by IntelliJ IDEA.
 * User: ashevenkov
 * Date: 14.04.12
 * Time: 11:17
 */
package codejam.codejam2012;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

/**
 * @author ashevenkov
 */
public class QualificationA {

    private Map<String, String> inputToOutput = new HashMap<String, String>();
    private Map<Character, Character> mapping = new TreeMap<Character, Character>();

    public QualificationA() {
        inputToOutput.put(
                "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "our language is impossible to understand");
        inputToOutput.put(
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "there are twenty six factorial possibilities");
        inputToOutput.put(
                "de kr kd eoya kw aej tysr re ujdr lkgc jv",
                "so it is okay if you want to just give up");
        init();
    }

    private void init() {
        for(Map.Entry<String, String> entry : inputToOutput.entrySet()) {
            char[] inCa = entry.getKey().toCharArray();
            char[] outCa = entry.getValue().toCharArray();
            for(int i = 0; i < inCa.length; i++) {
                char in = inCa[i];
                char out = outCa[i];
                if(in != ' ') {
                    mapping.put(in, out);
                }
            }
        }
        mapping.put('q', 'z');
        mapping.put('z', 'q');
    }

    public static void main(String[] args) throws Exception {
        new QualificationA().calculate(
                "/home/ashevenkov/projects/codejam/2012-QualificationA.in",
                "/home/ashevenkov/projects/codejam/2012-QualificationA.out");
    }

    public void calculate(String in, String out) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(in));
        FileWriter fw = new FileWriter(out);
        String line = br.readLine();
        int cases = Integer.parseInt(line);
        for(int i = 0; i < cases; i++) {
            line = br.readLine();
            String result = translate(line);
            System.out.println("Case #" + (i + 1) + ": " + result);
            fw.write("Case #" + (i + 1) + ": " + result);
            fw.write("\n");
        }
        fw.flush();
        fw.close();
    }

    private String translate(String line) {
        StringBuilder sb = new StringBuilder();
        char[] ca = line.toCharArray();
        for(int i = 0; i < ca.length; i++) {
            char c = ca[i];
            if(c != ' ') {
                sb.append(mapping.get(c));
            } else {
                sb.append(' ');
            }
        }
        return sb.toString();
    }

}
