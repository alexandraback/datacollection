
import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.Long.parseLong;
import static java.lang.System.*;
import static java.util.Arrays.*;
import static java.util.Collection.*;

public class A {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int T = parseInt(br.readLine());
        for (int l = 0; l++ < T;) {
            String testcaseline = br.readLine();
            String[] numbers = testcaseline.split(" ");
            long r = parseLong(numbers[0]);
            long t = parseLong(numbers[1]);

            long resposta = 0;
            long tintarestante = t;
            long raioatual = r;
            do {
                tintarestante -= ((raioatual + 1) * (raioatual + 1)) - (raioatual * raioatual);
                raioatual += 2;
                resposta++;
                //out.println("tinta restante: " + resposta);
            } while (tintarestante >= ((raioatual + 1) * (raioatual + 1)) - (raioatual * raioatual));


            out.println("Case #" + l + ": " + resposta);
        }
    }
}