
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.in;
import static java.lang.System.out;
import java.util.ArrayList;
import java.util.Arrays;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Renan
 */
public class B {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int T = parseInt(br.readLine());
        for (int l = 0; l++ < T;) {
            String resposta = "";
            String[] numbers = br.readLine().split(" ");
            int R = parseInt(numbers[0]);
            int N = parseInt(numbers[1]); //numero de numeros
            int M = parseInt(numbers[2]); //numero maximo
            int K = parseInt(numbers[3]);


            for (int r = 1; r <= R; r++) {
                String[] numbers2 = br.readLine().split(" ");
                int[] klist = new int[K];
                for (int k = 0; k < K; k++) {
                    klist[k] = parseInt(numbers2[k]);
                }
                Arrays.sort(klist);
                ArrayList<Integer> fatores = fatora(klist[klist.length - 1]);
                int menosatual = klist.length - 1;
                long count = 0;
                while (fatores.size() != N || count > 1000) {
                    count++;
                    if (fatores.size() < N) {
                        if (klist[--menosatual] == 1) {
                             fatores.add((int) (Math.round(Math.random() * (M - 2) + 2)));
                        } else {
                            fatores.addAll(fatora(klist[--menosatual]));
                        }
                    } else {
                        Integer novo = fatores.get(0) * fatores.get(1);

                        if (novo > M) {
                           
                        } else {
                            fatores.add(novo);
                        }
                        fatores.remove(0);
                        fatores.remove(0);

                    }
                    Arrays.sort(klist);
                }
                while (fatores.size() < N) {
                    fatores.add(2);
                }

                for (Integer iii : fatores) {
                    resposta += iii;
                }
                resposta += "\r\n";

            }

            out.println("Case #" + l + ":\r\n" + resposta);
        }
    }

    public static ArrayList<Integer> fatora(int n) {
        if (n < 2) {
            ArrayList<Integer> r = new ArrayList<>();
            r.add(2);
            return r;
        }
        Integer i, limite;
        ArrayList<Integer> primos = new ArrayList<>(5);
        i = 2;
        limite = (int) Math.sqrt(n);
        while (n > 1 && i <= limite) {
            while (n % i == 0) {
                primos.add(i);
                n = n / i;
            }
            i = i + 1;
        }
        if (n > 1) {
            primos.add(n);
        }
        return primos;
    }
}
