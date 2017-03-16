package google2013b;
import java.io.*;
import java.util.Locale;
import java.util.Scanner;
//------------------------------------------------------------------------------
class Celda{
    int x;
    int y;
    int valor;
}
//------------------------------------------------------------------------------
public class Google2013B {
    //--------------------------------------------------------------------------
    static Celda minimo(int[][] pasto){
        Celda retorno = new Celda();
        retorno.valor = 10000;
        
        for (int i=0;i<pasto.length;i++){
            for (int j=0;j<pasto[0].length;j++){
                if (pasto[i][j]<retorno.valor){
                    retorno.valor = pasto[i][j];
                    retorno.x = i;
                    retorno.y = j;
                }
            }
        }
        return retorno;
    }
    //--------------------------------------------------------------------------
    static int[][] sacarcolumna(int[][] pasto, int col){
        int[][] ret = new int[pasto.length][pasto[0].length-1];
        
        for (int i=0;i<pasto.length;i++){
            for (int j=0;j<pasto[0].length-1;j++){
                if (j<col){
                    ret[i][j] = pasto[i][j];
                }
                else{
                    ret[i][j] = pasto[i][j+1];
                }
            }
        }
        
        return ret;
    }
    //--------------------------------------------------------------------------
    static int[][] sacarfila(int[][] pasto, int fila){
        int[][] ret = new int[pasto.length-1][pasto[0].length];
        
        for (int i=0;i<pasto.length-1;i++){
            for (int j=0;j<pasto[0].length;j++){
                if (i<fila){
                    ret[i][j] = pasto[i][j];
                }
                else{
                    ret[i][j] = pasto[i+1][j];
                }
            }
        }
        
        return ret;
    }
    //--------------------------------------------------------------------------
    static boolean vale(int[][] pasto){
        if (pasto.length==1) return true;
        if (pasto[0].length==1) return true;
        
        boolean valecolumna = true;
        boolean valefila = true;
        
        Celda miminimo = minimo(pasto);
        for (int i=0;i<pasto[0].length;i++){
            if (pasto[miminimo.x][i]>miminimo.valor){
                valefila = false;
            }
        }
        for (int i=0;i<pasto.length;i++){
            if (pasto[i][miminimo.y]>miminimo.valor){
                valecolumna = false;
            }
        }
        
        if ((valefila)&&(valecolumna)){
            int[][] m1 = sacarcolumna(pasto, miminimo.y);
            int[][] m2 = sacarfila(pasto, miminimo.x);
            return (vale(m1)||vale(m2));
        }
        if (valefila){
            int[][] m2 = sacarfila(pasto, miminimo.x);
            return (vale(m2));
        }
        if (valecolumna){
            int[][] m1 = sacarcolumna(pasto, miminimo.y);
            return (vale(m1));
        }
        
        return false;
    }
    //--------------------------------------------------------------------------
    public static void main(String[] args) throws FileNotFoundException {
        Lector lector = new Lector("B-small-attempt0.in");
        
        int entero = lector.sc.nextInt();
        lector.sc.nextLine();
                        
        for (int caso=1;caso<=entero;caso++){
            int fila = lector.sc.nextInt();
            int columna = lector.sc.nextInt();
            lector.sc.nextLine();
            //System.err.println(fila+" "+columna);
            int[][] pasto = new int[fila][columna];
            for (int i=0;i<fila;i++){
                for (int j=0;j<columna;j++){
                    pasto[i][j] = lector.sc.nextInt();
                }
                if (lector.sc.hasNextLine()){
                    lector.sc.nextLine();
                }
            }
            boolean ok = vale(pasto);
            System.out.print("Case #" + caso+": ");
            if (ok) 
                System.out.println("YES");
            else
                System.out.println("NO");
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
