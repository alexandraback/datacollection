package problem;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author huls
 */
public class ProblemA {

    private static String fileName = ProblemA.class.getSimpleName().replaceFirst("_.*", "");
    private static String inputFileName = fileName + ".in";
    private static String outputFileName = fileName + ".out";
    private static Scanner in;
    private static PrintWriter out;
    private static int numberOfTests;
    
    private static String vowels = "aeiou";
    private static String cons = "bcdfghjklmnpqrstvwxyz";

    public int solve() {
       int solution = 0;
       String name = in.next();
       int consNum = in.nextInt();
       List<String> patterns = new ArrayList<String>();
        for (int i = 0; i < (name.length()-consNum+1); i++) {
            for (int j = 0; j < (name.length()-consNum+1); j++) {
                //String pattern = "["+vowels+"]{"+i+"}"+"["+cons+"]{"+consNum+"}"+"["+vowels+"]{"+j+"}";
                String pattern = "[\\w]{"+i+"}"+"["+cons+"]{"+consNum+"}"+"[\\w]{"+j+"}";
                patterns.add(pattern);
            }
        }
        Pattern p;
        Matcher m;
        Set<String> solSet = new HashSet<String>();
        int kk = 1;
        //System.out.println("P size:"+patterns.size());
        for (String pattern : patterns) {
            //System.out.println(pattern);
            p = Pattern.compile(pattern);
            m =  p.matcher(name);
            
            while (m.find()) {
                //System.out.println(kk);
                solSet.add(m.start()+"_"+m.group());
                //System.out.println(m.group());
                kk++;
            }
        }
        //System.out.println(solSet.size());
        return solSet.size();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        if (args.length >= 2) {
            inputFileName = args[0];
            outputFileName = args[1];
        }
        in = new Scanner(new FileReader(inputFileName));
        out = new PrintWriter(outputFileName);
        numberOfTests = in.nextInt();

        for (int t = 1; t <= numberOfTests; t++) {
            System.out.println(t);
            out.print("Case #" + t + ": ");
            out.print(new ProblemA().solve() + "\n");
        }
        in.close();
        out.close();
    }
}
