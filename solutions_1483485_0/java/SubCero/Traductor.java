package traductor;
import java.io.*;

class Solucion{
    char[] mapa;
    
    String solucion(String dato){
        String ret = "";
        char car;
        
        for (int i=0;i<dato.length();i++){
            car = dato.charAt(i);
            ret += mapa[car];
        }
        
        return ret;
    }
    void inicializar(){
        mapa = new char[256];
        for (int i=0;i<256;i++) mapa[i] = '.';
        
        String cod = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
        String claro = "our language is impossible to understand";
        armar(cod, claro);
        cod = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
        claro = "there are twenty six factorial possibilities";
        armar(cod, claro);
        cod = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
        claro = "so it is okay if you want to just give up";
        armar(cod, claro);
        
        mapa['q']='z';
        mapa['z']='q';
    }
    void armar(String cod, String claro){
        for (int i=0;i<cod.length();i++){
            char car0 = cod.charAt(i);
            char car1 = claro.charAt(i);
            mapa[car0] = car1;
        }
            
    }
    
    Solucion(){
        inicializar();
    }
}
public class Traductor {
    public static void main(String[] args) throws Exception{
        Solucion s = new Solucion();
        s.solucion("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
        
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader (isr);
        
        String linea;
        linea = br.readLine();
        int casos = Integer.parseInt(linea);
                
        for (int i=0;i<casos;i++){
            linea = br.readLine();
            String ret = s.solucion(linea);
            System.out.println("Case #"+ (i+1) + ": " + ret );
        }
    }
}
