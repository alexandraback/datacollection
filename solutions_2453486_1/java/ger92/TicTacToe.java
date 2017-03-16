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
public class TicTacToe {

    public static int[][] mat;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int casos = in.nextInt();
        in.nextLine();

        for (int caso = 0; caso < casos; caso++) {
            mat = new int[6][6];
            System.out.print("Case #" + (caso + 1) + ":");
            int cantXI = 0;
            int cantXD = 0;
            int cantOI=0;
            int cantOD=0;
            int ganador = 0;
            boolean incomplete = false;
            for (int fila = 0; fila < 4; fila++) {
                String linea = in.nextLine();
                if (linea.contains(".")) {
                    incomplete = true;
                }
                if (linea.replace("X", "").replace("T", "").length() == 0) {
                    ganador = 1;
                }else if (linea.replace("O", "").replace("T", "").length() == 0) {
                    ganador = 2;
                }
                for (int col = 0; col < 4; col++) {
                    mat[col][4] += sumarX("" + linea.charAt(col));
                    mat[col][5] += sumarO("" + linea.charAt(col));
                    
                    mat[4][col] += sumarX("" + linea.charAt(col));
                    mat[5][col] += sumarO("" + linea.charAt(col));
                    
                    if (mat[col][4] == 4 || mat[4][col] == 4) {
                        ganador = 1;
                    }else if (mat[col][5] == 4 || mat[5][col] == 4) {
                        ganador = 2;
                    }
                }
                cantXI += sumarX(linea.charAt(fila) + "");
                cantXD += sumarX(linea.charAt(3 - fila) + "");
                cantOI += sumarO(linea.charAt(fila) + "");
                cantOD += sumarO(linea.charAt(3 - fila) + "");
                
                if (cantXI == 4 || cantXD == 4) {
                    ganador = 1;
                }else if (cantOI == 4 || cantOD == 4) {
                    ganador = 2;
                }
            }
            //busco ganadores.
            if (ganador==2) {
                System.out.println(" O won");
            } else if (ganador==1) {
                System.out.println(" X won");
            } else if (incomplete) {
                System.out.println(" Game has not completed");
            } else {
                System.out.println(" Draw");
            }
            in.nextLine();
        }
    }

    static int sumarX(String letra) {
        if (letra.equals("X") || letra.equals("T")) {
            return 1;
        }
        return 0;
    }
    
    static int sumarO(String letra) {
        if (letra.equals("O") || letra.equals("T")) {
            return 1;
        }
        return 0;
    }
}
