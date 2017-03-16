package codejam2013c;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;

public class CodeJam2013C {
    //--------------------------------------------------------------------------
    static boolean palindromo(String candidato){
        boolean ret = true;
        int veces = candidato.length()/2;
        int largo = candidato.length()-1;
        for (int i=0;(i<veces)&&(ret);i++){
            if (candidato.charAt(i)!=candidato.charAt(largo-i)){
                ret = false;
            }
        }
        
        return ret;
    }
    //--------------------------------------------------------------------------
    static boolean palindromo(BigInteger candidato){
        return palindromo(candidato.toString(10));
    }
    //--------------------------------------------------------------------------
    public static void main(String[] args) throws FileNotFoundException {
        ArrayList<BigInteger> lista = new ArrayList<BigInteger>();
        int pos = 1;
        BigInteger candidato;
        BigInteger nro = BigInteger.ONE;
        candidato = nro.multiply(nro);
        BigInteger limite = new BigInteger("10");
        limite = limite.pow(15);
        while (candidato.compareTo(limite)<1){
            candidato = nro.multiply(nro);
            boolean esok = palindromo(candidato);
            if (esok)
            {
                boolean esok2 = palindromo(nro);
                if (esok2)
                {
                    //System.err.println((pos-1) + " --> "+ candidato + " : " + nro);
                    pos++;
                    lista.add(candidato);
                }
            }
            
            nro = nro.add(BigInteger.ONE);
        }
        
        //System.err.println(lista.size());
        
        Lector lector = new Lector("C-large-1.in");
        
        int entero = lector.sc.nextInt();
        lector.sc.nextLine();
                        
        for (int caso=1;caso<=entero;caso++){
            String linea = lector.sc.nextLine();
            /*int base = lector.sc.nextInt();
            int tope = lector.sc.nextInt();
            if (lector.sc.hasNextLine()){
                lector.sc.nextLine();
            }*/
            StringTokenizer tk = new StringTokenizer(linea);
            String base = tk.nextToken();
            String tope = tk.nextToken();
            
            BigInteger elTope = new BigInteger((tope));
            int posiciontope = 0;
            while (elTope.compareTo(lista.get(posiciontope))>0){
                posiciontope++;
            }
            
            BigInteger laBase = new BigInteger((base));
            int posicionbase = 0;
            while (laBase.compareTo(lista.get(posicionbase))>0){
                posicionbase++;
            }
            
            int total = posiciontope - posicionbase;
            if (laBase.compareTo(lista.get(posicionbase))==0){
                //total++;
            }
            if (elTope.compareTo(lista.get(posiciontope))==0){
                total++;
            }
            
            //System.err.println("base " + base + " posicion " + posicionbase + " tope " + tope + " posicion " + posiciontope + " total " + total);
            System.out.println("Case #" + caso+": "+total);
            
        }
    }
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
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