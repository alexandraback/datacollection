/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Kyoo
 */
public class ProblemA {
    public static void main(String[] args) throws IOException{
        BufferedReader leer= new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(leer.readLine());
        for (int i = 1; i <= T; i++) {
            char[][] tablero=leerTablero(leer);
            leer.readLine();
            int respuesta=resolver(tablero);
            System.out.print("Case #"+i+": ");
            switch(respuesta){
                case 1: System.out.println("X won"); break;
                case 2: System.out.println("O won"); break;
                case 3: System.out.println("Draw"); break;
                case 4: System.out.println("Game has not completed"); break;
            }
        }
    }
    private static char[][] leerTablero(BufferedReader leer) throws IOException {
        char[][] tablero= new char[4][];
        for (int i = 0; i < 4; i++) 
            tablero[i]=leer.readLine().trim().toCharArray();
        return tablero;
    }

    private static int resolver(char[][] tablero) {
        int respuesta;
        if(gana('X',tablero)) respuesta=1;
        else if(gana('O',tablero)) respuesta=2;
        else if(empate(tablero)) respuesta=3;
        else respuesta=4;
        return respuesta;
    }
    private static boolean gana(char c, char[][] tablero) {
        boolean gano;
        //Horizontal
        for (int i = 0; i < 4; i++) {
            gano=true;
            for (int j = 0; j < 4; j++)
                if(tablero[i][j]!=c && tablero[i][j]!='T')
                    gano=false;
            if(gano) return true;
        }
        //Vertical
        for (int j = 0; j < 4; j++) {
            gano=true;
            for (int i = 0; i < 4; i++)
                if(tablero[i][j]!=c && tablero[i][j]!='T')
                    gano=false;
            if(gano) return true;
        }
        //Diagonal
        gano=true;
        for (int i = 0; i < 4; i++)
            if(tablero[i][i]!=c && tablero[i][i]!='T')
                gano=false;
        if(gano) return true;
        
        gano=true;
        for (int i = 0; i < 4; i++)
            if(tablero[i][3-i]!=c && tablero[i][3-i]!='T')
                gano=false;
        return gano;
        
    }
    private static boolean empate(char[][] tablero) {
        boolean empate=true;
        //Horizontal
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if(tablero[i][j]=='.')
                    empate=false;
        return empate;
    }
}