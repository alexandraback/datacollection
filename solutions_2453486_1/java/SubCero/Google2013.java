package google2013;
import java.io.*;
import java.util.Locale;
import java.util.Scanner;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
public class Google2013 {

    public static void main(String[] args) throws FileNotFoundException {
        Lector lector = new Lector("A-large.in");
        
        int entero = lector.sc.nextInt();
        lector.sc.nextLine();
        String[] tablero = new String[4];
                
        for (int caso=1;caso<=entero;caso++){
            boolean completo = true;
            boolean xwon = false;
            boolean owon = false;
            int[] x = new int[4];
            int[] o = new int[4];
            for (int i=0;i<4;i++){
                tablero[i] = lector.sc.nextLine();
                for (int j=0;j<4;j++){
                    if (tablero[i].charAt(j)=='.'){
                        completo = false;
                    }
                    if ((tablero[i].charAt(j)=='X')||(tablero[i].charAt(j)=='T')){
                        x[i]++;
                    }
                    if ((tablero[i].charAt(j)=='O')||(tablero[i].charAt(j)=='T')){
                        o[i]++;
                    }
                    if (x[i]==4){
                        xwon = true;
                    }
                    if (o[i]==4){
                        owon = true;
                    }
                }
            }
            
            
            x = new int[4];
            o = new int[4];
            for (int i=0;i<4;i++){
                for (int j=0;j<4;j++){
                    if ((tablero[j].charAt(i)=='X')||(tablero[j].charAt(i)=='T')){
                        x[i]++;
                    }
                    if ((tablero[j].charAt(i)=='O')||(tablero[j].charAt(i)=='T')){
                        o[i]++;
                    }
                    if (x[i]==4){
                        xwon = true;
                    }
                    if (o[i]==4){
                        owon = true;
                    }
                }
            }
            
            x = new int[4];
            o = new int[4];
            for (int i=0;i<4;i++){
                    if ((tablero[i].charAt(i)=='X')||(tablero[i].charAt(i)=='T')){
                        x[0]++;
                    }
                    if ((tablero[i].charAt(i)=='O')||(tablero[i].charAt(i)=='T')){
                        o[0]++;
                    }
                    if (x[0]==4){
                        xwon = true;
                    }
                    if (o[0]==4){
                        owon = true;
                    }
            }
            
            x = new int[4];
            o = new int[4];
            for (int i=0;i<4;i++){
                    if ((tablero[i].charAt(3-i)=='X')||(tablero[i].charAt(3-i)=='T')){
                        x[0]++;
                    }
                    if ((tablero[i].charAt(3-i)=='O')||(tablero[i].charAt(3-i)=='T')){
                        o[0]++;
                    }
                    if (x[0]==4){
                        xwon = true;
                    }
                    if (o[0]==4){
                        owon = true;
                    }
            }
            
            if (caso!=entero){
                lector.sc.nextLine();
            }
            
            System.out.print("Case #" + caso+": ");
            if (xwon) System.out.print("X won");
            else
            if (owon) System.out.print("O won");
            else
            if (completo) System.out.print("Draw");
            else System.out.print("Game has not completed");
            
            System.out.println();
        }
    }
}
//------------------------------------------------------------------------------
class Lector{
    Scanner sc;
    
    Lector(String filename) throws FileNotFoundException{
        Locale usLocale = new Locale("en", "US");
        String dir = "c:\\CodeJam2013\\";
        File f = new File(dir, filename);
        InputStream in = new FileInputStream(f);
        sc = new Scanner(in);
        sc.useLocale(usLocale);
    }
}
//------------------------------------------------------------------------------