
import java.util.Scanner;

/*
 Autor: Edison Arango
 Usuario: edisonarango
 Universidad de los Llanos
 Código: 160002900
 */
public class B {
    
    public static boolean finalizado (char[] estados){
        int felices = 0;
        for (int i=0; i < estados.length; i++){
            if (estados[i] == '+'){
                felices++;
            }
        }
        return felices == estados.length;
    }
    
    public static char[] voltear (char[] estados, int n){
        char[] nuevos = new char[n];
        for (int i = 0; i < n; i++) {
            if (estados[i] == '+'){
                nuevos[i] = '-';
            }
            else{
                nuevos[i] = '+';
            }
        }
        for (int i = 0; i < n; i++) {
            estados[i] = nuevos[n-i-1];
        }
        return estados;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            char[] estados = in.next().toCharArray();
            int cambios = 0;
            boolean finalizado = false;
            while (!finalizado){
                int igualesAlInicio = 0;
                for (int j = 1; j < estados.length; j++) {
                    if (estados[j] != estados[0]){
                        igualesAlInicio = j;
                        break;
                    }
                }
                if (igualesAlInicio == 0){
                    if (estados[0] == '-'){
                        cambios++;
                    }
                    finalizado = true;
                }
                else{
                    B.voltear(estados, igualesAlInicio);
                    cambios++;
                }
            }
            System.out.printf("Case #%d: %d%n",i+1,cambios);
        }
    }
    
}
