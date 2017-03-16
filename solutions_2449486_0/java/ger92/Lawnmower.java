/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.util.Scanner;

/**
 *
 * @author German
 */
public class Lawnmower {

    public static final int max = 100;
    public static int[][] mat = new int[max + 1][max + 1];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int casos = in.nextInt();
        for (int caso = 0; caso < casos; caso++) {
            System.out.print("Case #" + (caso + 1) + ": ");
            int aux = 0;
            int filas = in.nextInt();

            int columnas = in.nextInt();
            for (int fila = 0; fila < filas; fila++) {
                mat[fila][max] = 0;
            }

            for (int col = 0; col < columnas; col++) {
                aux = in.nextInt();
                mat[0][col] = aux;
                mat[0][max] = Math.max(mat[0][max], aux);
                mat[max][col] = aux;
            }
            for (int fila = 1; fila < filas; fila++) {
                for (int col = 0; col < columnas; col++) {
                    aux = in.nextInt();
                    mat[fila][col] = aux;
                    mat[fila][max] = Math.max(aux, mat[fila][max]);
                    mat[max][col] = Math.max(aux, mat[max][col]);
                }
            }
            boolean es = true;
            for (int fila = 0; fila < filas; fila++) {
                for (int col = 0; col < columnas; col++) {
                    if (mat[fila][col] < mat[fila][max] && mat[fila][col] < mat[max][col]) {
                        System.out.print("NO");
                        es = false;
                        fila = filas;
                        col = columnas;
                    }
                }
            }
            if (es) {
                System.out.print("YES");
            }
            System.out.println("");
        }
    }
}
