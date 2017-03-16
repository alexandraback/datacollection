package javaapplication2;
import java.io.*;
import java.util.StringTokenizer;
import java.util.HashSet;

//------------------------------------------------------------------------------
class Solucion{
    double auxi(int tipeadas, int largo, double[] proba, int escapes){
        double seguirTipeando = 0.0;   
        
        double correcto = 1.0;
        int resto = tipeadas-escapes;
        for (int i=0;i<resto;i++){ 
            
                correcto *= proba[i];
            
        }
        
        seguirTipeando = (largo + 2*escapes - tipeadas + 1)*correcto;
        seguirTipeando += ( (largo + 2*escapes - tipeadas + 1) + (largo + 1))*(1-correcto);
        
        
        return seguirTipeando;
    }
    
    double solucion(String linea, String linea2){
        double ret = 0.0;
        int tipeadas;
        int largo;
        
        StringTokenizer tk = new StringTokenizer(linea);
        tipeadas = Integer.parseInt(tk.nextToken());
        largo = Integer.parseInt(tk.nextToken());
        
        double[] proba = new double[tipeadas];
        tk = new StringTokenizer(linea2);
        for (int i=0;i<tipeadas;i++) proba[i] = Double.parseDouble(tk.nextToken());
        
    
        double seguirTipeando = 0.0;
        {   double correcto = 1.0;
            for (int i=0;i<tipeadas;i++) correcto *= proba[i];
            seguirTipeando = (largo - tipeadas + 1)*correcto;
            seguirTipeando += ( (largo - tipeadas + 1) + (largo + 1))*(1-correcto);
        }
        
        
        double giveup = 0.0;
        {    giveup = (largo + 2);
        }
        
        double escapes = 10000000000000.0;
        for (int esca=1;esca<tipeadas;esca++){
            escapes = Math.min(escapes, auxi(tipeadas, largo, proba, esca));
        }
            
        ret = Math.min(seguirTipeando,giveup);
        ret = Math.min(ret,escapes);
        
        return ret;
    }
}
//------------------------------------------------------------------------------
public class JavaApplication2 {

    public static void main(String[] args) throws Exception{
        Solucion s = new Solucion();
        s.solucion("3 4", "1 0.9 0.1");
        
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader (isr);
        
        String linea,linea2;
        linea = br.readLine();
        int casos = Integer.parseInt(linea);
        
        for (int i=0;i<casos;i++){
            linea = br.readLine();
            linea2 = br.readLine();
            double ret = s.solucion(linea, linea2);
            System.out.println("Case #"+ (i+1) + ": " + ret );
        }
    }
}
//------------------------------------------------------------------------------
