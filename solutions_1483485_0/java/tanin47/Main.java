import java.io.*;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: tanin
 * Date: 4/14/12
 * Time: 8:01 AM
 * To change this template use File | Settings | File Templates.
 */
public class Main {


    static char[] map = new char[26];
    public static void main(String[] args) throws Exception {
        
        init();
        
        String filename = "speaking_small";
        String outFilename = filename + "_out";

        FileInputStream fis = new FileInputStream(new File(filename));
        Scanner input = new Scanner(new BufferedInputStream(fis));

        FileOutputStream fOut = new FileOutputStream(new File(outFilename));
        BufferedOutputStream bOut = new BufferedOutputStream(fOut);
        DataOutputStream out = new DataOutputStream(bOut);

        int numCases = input.nextInt();
        input.nextLine();
        
        for (int caseNumber=0;caseNumber<numCases;caseNumber++) {

            String sentence = input.nextLine();
            out.writeBytes("Case #" + (caseNumber+1) + ": " + solve(sentence) + "\n");
        }

        out.flush();
        out.close();
        
        bOut.flush();
        bOut.close();

        fOut.flush();
        fOut.close();
    }


    public static void init() {
        String[][] examples = { {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand"},
                {"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities"},
                {"de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up"},
                {"q","z"}, {"e","o"}, {"a", "y"}};



        boolean[] checked = new boolean[26];

        for (int i=0;i<examples.length;i++) {

            char[] googlereses = examples[i][0].toCharArray();
            char[] real = examples[i][1].toCharArray();

            for (int j=0;j<real.length;j++) {
                if (real[j] == ' ') continue;

                int gIndex = googlereses[j] - 'a';
                map[gIndex] = real[j];

                checked[real[j] - 'a'] = true;
            }
        }


//        for (int i=0;i<map.length;i++) {
//            System.out.println((char)(i + 'a') + "(" + checked[i] + ") -> " + map[i]);
//        }

        map['z'-'a'] = 'q'; // not in the example

    }
    
    
    public static String solve(String init) {
        StringBuffer sb = new StringBuffer();
        
        char[] c = init.toCharArray();

        for (int i=0;i<c.length;i++) {
            if (c[i] == ' ') sb.append(' ');
            else sb.append(map[c[i] - 'a']);
        }

        return sb.toString();
    }
    
}
