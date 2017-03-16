
import java.util.Scanner;

/*
 Autor: Edison Arango
 Usuario: edisonarango
 Universidad de los Llanos
 Código: 160002900
 */
public class C {
    
    public static int factor (long numero){
        double raiz = Math.ceil(Math.sqrt(numero));
        for (int i = 2; i < (int)raiz; i++) {
           if (numero%i == 0){
               return i;
           }
        }
        return -1;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.printf("Case #%d:%n",i+1);
            long N = in.nextInt();
            int J = in.nextInt();
            String numero = "1";
            for (int k = 1; k < N-1; k++) {
                numero += "0";
            }
            numero += "1";
            for (int j = 0; j < J; j++) {
                boolean valido = false;
                while (!valido){
                    int[] factores = new int[9];
                    valido = true;
                    for (int k = 2; k <= 10; k++) {
                        long numDecimal = Long.parseLong(numero, k);
                        factores[k-2] = C.factor(numDecimal);
                        if (factores[k-2] == -1){
                            valido = false;
                            break;
                        }
                    }
                    if (valido){
                        if (numero.startsWith("1") && numero.charAt(numero.length()-1) == '1'){
                            System.out.print(numero);
                            for (int k = 0; k < factores.length; k++) {
                                System.out.print(" "+factores[k]);
                            }
                            System.out.println();
                        }
                        else{
                            valido = false;
                        }
                    }
                    long nuevo = Long.parseLong(numero, 2) + 1;
                    numero = Long.toString(nuevo, 2);
                }
            }
        }
    }
    
}
