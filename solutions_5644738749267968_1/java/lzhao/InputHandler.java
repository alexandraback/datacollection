import java.io.*;
import java.util.*;

public class InputHandler {
    public static void main(String[] args) {
        try {
            BufferedReader br =
                    new BufferedReader(new InputStreamReader(System.in));
            String line;

            int caseCount = 1;
            br.readLine();

            while ((line = br.readLine()) != null) {
                line = br.readLine();
                String[] naomiTokens = line.split(" ");
                line = br.readLine();
                String[] kenTokens = line.split(" ");
                Arrays.sort(naomiTokens);
                Arrays.sort(kenTokens);

                List<Double> naomi = new ArrayList<Double>();
                List<Double> ken = new ArrayList<Double>();

                for(String token : naomiTokens) {
                    naomi.add(Double.parseDouble(token));
                }
                for(String token : kenTokens) {
                    ken.add(Double.parseDouble(token));
                }

                int deceit = DeceitfulWar.deceitWar(naomi, ken, 0);

                naomi.clear();
                ken.clear();

                for(String token : naomiTokens) {
                    naomi.add(Double.parseDouble(token));
                }
                for(String token : kenTokens) {
                    ken.add(Double.parseDouble(token));
                }

                int war = DeceitfulWar.war(naomi, ken);

                System.out.println("Case #" + caseCount + ": " + deceit + " " + war);
                caseCount++;

            }

        } catch (IOException io) {
            io.printStackTrace();
        }

    }

}
