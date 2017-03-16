

import java.util.Scanner;

public class Password {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int casos = scanner.nextInt();
        for (int i=1;i<casos+1;i++){
            System.out.print("Case #"+i+": ");
            int escritos = scanner.nextInt();
            int totales = scanner.nextInt();
            double []prob = new double[escritos];
            for (int j=0;j<prob.length;j++)
                prob[j] = Double.valueOf(scanner.next());
            double [] pulsaciones = new double [escritos+1];
            double aux = Double.MAX_VALUE;
            for (int k=0;k<pulsaciones.length;k++)
            {
                    pulsaciones [k] = pulsaciones (escritos,totales,prob,k);
                    if (pulsaciones [k] < aux)
                        aux = pulsaciones[k];
            }
            System.out.println(aux);
        }

    }

    static public double pulsaciones (int escritos, int totales, double[]prob, int borrados){
        double pro = 1.0;
        if (escritos == borrados)
            return totales+2;
        else{
        for (int i=0;i<escritos-borrados;i++){
            pro = pro * prob[i];
        }
        //return (pro*(totales-escritos+1+borrados))+((1.0-pro)*(totales-escritos+2+borrados));
        return (pro*(borrados+1+(totales-escritos+borrados)))+((1.0-pro)*(totales+2+borrados+totales-escritos+borrados));
        }
    }

}