package rondac;
import java.io.*;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.ArrayList;
import java.math.BigInteger;

//------------------------------------------------------------------------------
class Solucion2{
    boolean hay = false;
    
    int[][] prod(int[][] m, int[][] b){
        int[][] r = new int[m.length][m.length];
        
        for(int i = 0; i < m.length; i++){  
            for(int j = 0; j < b.length; j++){  
                int suma = 0;  
                for(int k = 0; k < b.length; k++){  
                    suma += m[i][k] * b[k][j];  
                }  
                r[i][j] = suma;  
            }  
        }  
        
        return r;
    }
    
    int[][] suma(int[][] m, int[][] b){
        int[][] r = new int[m.length][m.length];
        
        for(int i = 0; i < m.length; i++){  
            for(int j = 0; j < b.length; j++){    
                r[i][j] = m[i][j] + b[i][j];  
                if (r[i][j] > 1) 
                    hay = true;
            }  
        }  
        
        return r;
    }
    
    boolean solucion(String[] linea){
        hay = false;
        int clases = Integer.parseInt(linea[0]);
        int[][] m = new int[clases][clases];
        int[][] r = new int[clases][clases];
        
        for (int i=0;i<clases;i++){
            StringTokenizer tk = new StringTokenizer(linea[i+1]);
            tk.nextToken();
            while (tk.hasMoreTokens()){
                int j = Integer.parseInt(tk.nextToken()) - 1;
                m[i][j] = r[i][j] = 1;
            }
        }
        
        for (int i=0;i<clases;i++){
            r = prod(m,r);
            r = suma(m,r);
            if (hay) 
                return true;
        }
        
        return false;
    }
}
//------------------------------------------------------------------------------    
public class RondaC {

    public static void main(String[] args) throws Exception {
        Solucion2 s = new Solucion2();
        /*String[] data = {"5",
"2 2 3",
"1 4",
"1 5",
"1 5",
"0"}; */
        //s.solucion(data);
        //s.solucion("20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600");
        //s.solucion("8 0 0 0 0 72 0 0 0");
        
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader (isr);
        
        String linea,linea2;
        linea = br.readLine();
        int casos = Integer.parseInt(linea);
        
        for (int i=0;i<casos;i++){
            linea = br.readLine();
            int clases = Integer.parseInt(linea);
            String[] lineas = new String[clases+1];
            lineas[0] = linea;
            for (int p=0;p<clases;p++){
                lineas[p+1] = br.readLine();
            }
            
            System.out.print("Case #"+ (i+1) + ": "  );
            boolean ret = s.solucion(lineas);
            if (ret)
                System.out.println("Yes"  );
            else
                System.out.println("No"  );
        }
    }
}
