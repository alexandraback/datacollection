
import java.util.ArrayList;
import java.util.Scanner;

/*
 Autor: Edison Arango
 Usuario: edisonarango
 Universidad de los Llanos
 Código: 160002900
 */
public class A {
    
    public static void main(String[] args) {
        ArrayList<Integer> digitos = new ArrayList<>();
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            int j = 1;
            int M = N;
            boolean insomnia = false;
            while (digitos.size() < 10 && !insomnia){
                M = N*j;
                String Ns = M+"";
                if(M == 0){
                    insomnia = true;
                }
                else{
                    for (int k = 0; k < Ns.length(); k++) {
                        int digito = Ns.charAt(k) - '0';
                        if (digitos.indexOf(digito) == -1){
                            digitos.add(digito);
                        }
                    }
                }
                j++;
            }
            digitos.clear();
            if(insomnia) {
                System.out.printf("Case #%d: INSOMNIA%n",i+1);
            }
            else{
                System.out.printf("Case #%d: %d%n",i+1,M);
            }
        }
    }
    
}
