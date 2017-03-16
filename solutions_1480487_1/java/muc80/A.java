import java.util.Scanner;

public class A {

    public static void main(String[] args) throws Exception {
    	Scanner in = new Scanner(System.in);
       
       int T = in.nextInt();

       for (int zz = 1; zz <= T; zz++) {
           int N = in.nextInt();
           int[] puntos = new int[N];
           int suma = 0;
           for (int j = 0; j < N; j++) {
        	   puntos[j] = in.nextInt();
        	   suma += puntos[j];
           }
           System.out.print("Case #" + zz + ":");
           for (int i = 0; i < N; i++) {
               double menor = 0, mayor = 1;
               for (int j = 0; j < 100; j++) {
                   double media = (menor + mayor)/2;
                   double score = puntos[i] + media*suma;
                   double total = 0;
                   for (int k = 0; k < N; k++) if (k != i) {
                	   total += Math.max(0, (score - puntos[k])/suma);
                   }
                   if (total + media > 1) mayor = media;
                   else menor = media;
               }
               if (menor<0.000000001)
            	   System.out.print(" " + 0.000000);
               else
            	   System.out.print(" " + (100*menor));
           }
           System.out.println();
       }
    }
}
