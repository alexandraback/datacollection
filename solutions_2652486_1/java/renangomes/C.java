
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
public class C {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int T = parseInt(br.readLine());
        for (int l = 0; l++ < T;) {
            String resposta = "";
            String[] numbers = br.readLine().split(" ");
            long R = parseInt(numbers[0]);
            long N = parseInt(numbers[1]); //numero de numeros
            long M = parseInt(numbers[2]); //numero maximo
            long K = parseInt(numbers[3]);


            for (int r = 1; r <= R; r++) {
                String[] numbers2 = br.readLine().split(" ");
                long[] klist = new long[(int) K];
                for (int k = 0; k < K; k++) {
                    klist[k] = parseLong(numbers2[k]);
                }
                Arrays.sort(klist);



                boolean respostaok = false;
                ArrayList<Long> divisores = new ArrayList<>();
                for (int a = klist.length - 1; a >= 0; a--) {
                    divisores = fatora(klist[a]);

                    if (divisores.size() > N) {
                        respostaok = true;
                        break;
                    }
                }
                if (respostaok == false) {
                    divisores.clear();
                    for (Long atual : klist) {
                        for (long z = 2; z <= M; z++) {
                            if (atual % z == 0) {
                                divisores.add(z);
                            }
                        }
                    }
                    ArrayList<Long> divisoresunicos = new ArrayList<>();

                    for (Long atual : divisores) {
                        if (!divisoresunicos.contains(atual)) {
                            divisoresunicos.add(atual);
                        }
                    }
                    while (divisoresunicos.size() < N) {
                        if (divisores.size() > 0) {
                            divisoresunicos.add(divisores.get(Math.min((int) Math.round(Math.random() * divisores.size()), divisores.size() - 1)));
                        } else {
                            divisoresunicos.add(Math.round((Math.random() * (M - 2)) + 2));
                        }
                    }
                    divisores = divisoresunicos;
                } else {
                    while (divisores.size() > N) {
                        divisores.add(divisores.get(0) * divisores.get(1));
                        divisores.remove(0);
                        divisores.remove(0);
                    }
                }
                String addnaresposta = "";
                for (Long iii : divisores) {
                    addnaresposta += iii;
                }
                if (addnaresposta.length() > N) {
                    addnaresposta = addnaresposta.substring((int) (addnaresposta.length()-N), (int) N);
                }
                resposta += addnaresposta + "\r\n";

            }

            out.println("Case #" + l + ":\r\n" + resposta);
        }
    }

    public static ArrayList<Long> fatora(long n) {
        if (n < 2) {
            ArrayList<Long> r = new ArrayList<>();
            r.add((long) 2);
            return r;
        }
        Integer i, limite;
        ArrayList<Long> primos = new ArrayList<>(5);
        i = 2;
        limite = (int) Math.sqrt(n);
        while (n > 1 && i <= limite) {
            while (n % i == 0) {
                primos.add((long) i);
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
