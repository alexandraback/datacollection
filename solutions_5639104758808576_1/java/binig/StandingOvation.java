import java.io.*;

/**
 * Created by benoi_000 on 4/11/2015.
 */
public class StandingOvation {


    public static void main(String args[]) throws IOException {
        InputStream inputStream = args.length<1?System.in:Thread.currentThread().getContextClassLoader().getResourceAsStream(args[0]);
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        PrintStream out = args.length<2?System.out:new PrintStream(new FileOutputStream(args[1]));
        int nbPb = Integer.parseInt( reader.readLine());
        for (int i=0;i<nbPb;i++) {
            processLine(i+1, reader.readLine(),out);
        }

    }

    private static void processLine(int caseNb, String s, PrintStream out) {
        int splitIdx = s.indexOf(' ');
        int sMax = Integer.valueOf(s.substring(0,splitIdx));
        String spec = s.substring(splitIdx+1);
        int nbGuest=0;
        int nbUp=0;
        if (sMax+1!=spec.length()) throw  new IllegalArgumentException("wrong number of shyness "+spec.length());
        for(int i=0;i<=sMax;i++) {
            int nbLvl =Character.getNumericValue(spec.charAt(i));
            if (nbLvl<0||nbLvl>9) throw  new IllegalArgumentException("wrong number of people " + nbLvl +
                    "for shyness "+i);
            if (nbLvl>0) {
                int toAdd = Math.max(i - nbUp, 0);
                nbUp += toAdd + nbLvl;
                nbGuest += toAdd;
            }
        }
        if (nbUp==0) throw new IllegalArgumentException("no public ?");
        out.println( "Case #" +
                 + caseNb+
                ": " +
                nbGuest  );
    }
}
