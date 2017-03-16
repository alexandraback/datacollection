package password;

import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

import commons.FileUtilities;

public class Password {

    public static void main(String[] args) throws IOException {
        
        List<String> cases = FileUtilities.readFile(new File("A-large.in"));
        
        int nrCases = new Scanner(cases.get(0)).nextInt();
        List<String> result = new LinkedList<String>();
        
        for (int i = 1; i <= 2*nrCases; i++) {
            
            Scanner s = new Scanner(cases.get(i));
            
            int A = s.nextInt();
            int B = s.nextInt();
            i++;
            Scanner s1 = new Scanner(cases.get(i));
            s1.useLocale(Locale.US);
            double[] probs = new double[A];
            for (int j = 0; j < A; j++) {
                probs[j] = Double.parseDouble(s1.next());
            }
            
            double[] strokes = new double[A + 2];
            
            
            // As many backspaces as A
            strokes[0] = A + B + 1;
            
            for (int j = 1; j < A; j++) {
                // hit backspace till there
                double mulprobs = 1;
                for (int k = 0; k < j; k++) {
                    mulprobs *= probs[j];
                }
                strokes[j] = B - j - 1 + mulprobs * (B - A + 1) + (1-mulprobs) * (B - A + 1 + B + 1);
            }
            
            // hit enter
            if (B > A) {
                strokes[A] = B + 2; 
            } else {
                double mulprobs = 1;
                for (int k = 0; k < A; k++) {
                    mulprobs *= probs[k];
                }
                strokes[A] = mulprobs * 1 + mulprobs * (1 + B + 1);
            }
            
            // keep typing
            double mulprobs = 1;
            for (int k = 0; k < A; k++) {
                mulprobs *= probs[k];
            }
            strokes[A + 1] = mulprobs * (B - A + 1) + (1-mulprobs) * (B - A + 1 + B + 1);
            
            double min = Integer.MAX_VALUE;
            for (int j = 0; j < strokes.length; j++) {
                if (strokes[j] < min) min = strokes[j];
            }
            result.add(Double.toString(min));
        }
        
        FileUtilities.writeFile(result, new File("A-large.out"));
    }
}
