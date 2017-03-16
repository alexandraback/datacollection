package dancing;
import java.io.*;
import java.util.StringTokenizer;
import java.util.HashSet;

class Solucion{
    int solucion(String datos){
        int ret = 0;
        int ok = 0;
        int posiblesorpresa = 0;
        
        StringTokenizer tk = new StringTokenizer(datos);
        int jug = Integer.parseInt(tk.nextToken());
        int sorpresas = Integer.parseInt(tk.nextToken());
        int minimo = Integer.parseInt(tk.nextToken());
        
        for (int i=0;i<jug;i++){
            int triple = Integer.parseInt(tk.nextToken());
            int reparto = triple - minimo;
            int particion = reparto / 2;
            int diferencia = minimo - particion;
            
            if (( diferencia < 3) && (reparto >= 0) ){
                if (diferencia == 2){
                    posiblesorpresa++;
                    //System.err.println(triple + " SORPRESA");
                }
                else{
                    ok++;
                    //System.err.println(triple + " SI");
                }
            }
            else{
                //System.err.println(triple + " NO");
            }
        }
        
        ret = ok + Math.min(sorpresas, posiblesorpresa);
        return ret;
    }
}
public class Dancing {
    public static void main(String[] args) throws Exception{
        Solucion s = new Solucion();
        s.solucion("2 1 1 8 0");
        
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader (isr);
        
        String linea;
        linea = br.readLine();
        int casos = Integer.parseInt(linea);
        
        for (int i=0;i<casos;i++){
            linea = br.readLine();
            int ret = s.solucion(linea);
            System.out.println("Case #"+ (i+1) + ": " + ret );
        }
    }
}
