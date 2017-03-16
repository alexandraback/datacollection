import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

/**
 * Created by dkpiychenko on 5/11/14.
 */
public class C_As {
    public static void main(String[] args) {

        /*Map<Fraction, Integer> m = new HashMap<Fraction, Integer>();
        List<List<Fraction>> ll = new ArrayList<List<Fraction>>();
        List<Fraction> l0 = new ArrayList<Fraction>();
        l0.add(new Fraction(0, 1));
        l0.add(new Fraction(1, 1));

        ll.add(l0);
        for(int i = 1; i < 10; i++){
            for(int j = 0; j < (2 ^ (i + 1)) + 1; j++){

            }
        }*/

        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader("/home/dkpiychenko/C_As_input"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        try {
            StringBuilder sb = new StringBuilder();
            String line = br.readLine();
            int n = Integer.parseInt(line);



            for(int i = 0; i < n; i++){
                line = br.readLine();
                String[] ss = line.split("/");
                int p = Integer.parseInt(ss[0]);
                int q = Integer.parseInt(ss[1]);
                Fraction f = new Fraction(p, q);
                f.reduce();

                //System.out.println(f.getNumerator() + " " + f.getDenominator());
                System.out.println("Case #" + (i+1) + ": " + res(f));

            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    static String res(Fraction f){
        int n = f.getDenominator();
        if(n==1) return "" + f.getNumerator();
        int result = 0;

        while(n > 1){
            if (n % 2 == 1){
                return "impossible";
            } else {
                result++;
                n = n/2;
            }
        }
        return "" + (result - log2(f.getNumerator()));
    }

    public static int log2(int n){
        if(n <= 0) throw new IllegalArgumentException();
        return 31 - Integer.numberOfLeadingZeros(n);
    }
}
