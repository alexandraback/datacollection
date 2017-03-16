
import java.util.Scanner;

/*
 Autor: Edison Arango
 Usuario: edisonarango
 Universidad de los Llanos
 Código: 160002900
 */
public class D {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            int K = in.nextInt();
            int C = in.nextInt();
            int S = in.nextInt();
            System.out.printf("Case #%d:",i+1);
            int necesarios = (int)Math.ceil((double)K/C);
            if (necesarios > S){
                System.out.print(" IMPOSSIBLE");
            }
            else{
                int encontrados = 0;
                for (int j = 0; j < necesarios; j++) {
                    long actual = encontrados;
                    if (C == 1){
                        System.out.print(" "+(j+1));
                    }
                    else{
                        encontrados++;
                        for (int k = 1; k < C; k++) {
                            actual = actual * K;
                            if (encontrados < K){
                                actual += encontrados;
                            }
                            encontrados++;
                        }
                        actual++;
                        System.out.print(" "+actual);
                    }
                }
            }
            System.out.println();
        }
    }
    
}
