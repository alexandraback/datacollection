
import java.io.BufferedReader;
import java.io.FileReader;
import java.text.DecimalFormat;
import java.util.Locale;

/*
 * To change this template, choose Tools | Templates and open the template in
 * the editor.
 */
/**
 *
 * @author thomas
 */
public class SafetyNumbers {

    public static void main(String[] args) {
        String linea;
        try {

            FileReader fis = new FileReader("A-small-attempt4.in");
//            FileReader fis = new FileReader("SafetyNumbers.in");
            BufferedReader buffer = new BufferedReader(fis);
            linea = buffer.readLine();
            int T = Integer.parseInt(linea.trim());
            String[] aux;
            int Ni[];
            int suma;
            for (int caso = 1; caso <= T; caso++) {
                suma = 0;
                linea = buffer.readLine();
                aux = linea.split(" ");
                int N = Integer.parseInt(aux[0]);
                Ni = new int[N];
                int val;
                for (int i = 0; i < Ni.length; i++) {
                    val = Integer.parseInt(aux[i + 1]);
                    suma += val;
                    Ni[i] = val;
                }
                procesar(caso, suma, Ni);
            }
            buffer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void procesar(int caso, double suma, int[] Ni) {
        DecimalFormat nf = (DecimalFormat) DecimalFormat.getInstance(Locale.US);
        nf.applyPattern("0.0#####");
        System.out.print("Case #" + caso + ":");
        double Ri[] = new double[Ni.length];
        double acumNeg = 0d;
        double coutNeg = 0d;
        for (int i = 0; i < Ni.length; i++) {
            Ri[i] = ((suma / (double) Ni.length * 2d - Ni[i]) / suma)*100;
            if (Ri[i] < 0) {
                acumNeg += Ri[i];
                coutNeg++;
            }
        }
        if (coutNeg > 0) {
            for (int i = 0; i < Ri.length; i++) {
                if (Ri[i] < 0) {
                    Ri[i] = 0;
                } else {
                    Ri[i] += acumNeg / (Ni.length - coutNeg);
                }
            }
        }
        for (int i = 0; i < Ri.length; i++) {
            System.out.print(" " + nf.format(Ri[i]));
        }

        System.out.println(
                "");

    }
}
