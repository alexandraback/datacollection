package codejam2013d;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Locale;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

//------------------------------------------------------------------------------
class Urna{
    int id;
    int abre;
    ArrayList<Integer> contiene = new ArrayList<Integer>();
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class TipoMemo implements Comparable{
    boolean[] abiertas;
    int id;
    long nro;
    static long contador = 0;
    TipoMemo(int unid,boolean[] unabiertas){
        id = unid;
        abiertas = new boolean[unabiertas.length];
        for (int i=0;i<unabiertas.length;i++){
            abiertas[i] = unabiertas[i];
        }
        nro = contador;
        contador++;
    }
    boolean esIgual(TipoMemo otro){
        boolean soniguales = true;
        for (int i=0;i<otro.abiertas.length;i++){
            soniguales = soniguales && (abiertas[i] == otro.abiertas[i]);
        }
        return (soniguales);
    }

    @Override
    public int compareTo(Object o) {
        TipoMemo otro = (TipoMemo) o;
        boolean es = this.esIgual(otro);
        if (es) return 0;
        if (this.nro>otro.nro) return +1;
        return -1;
    }
    //--------------------------------------------------------------------------
    @Override
    public int hashCode() {
        return (int)nro;
    }
    //--------------------------------------------------------------------------
    //@Override
    public boolean equals(Object o) {
        TipoMemo otro = (TipoMemo) o;
        return (this.esIgual(otro));
    }
}
//------------------------------------------------------------------------------
public class CodeJam2013D {
    static String SOLUCION = "";
    static HashSet<TipoMemo> memo = new HashSet<TipoMemo>();
    static HashSet<String> memo2 = new HashSet<String>();
    //--------------------------------------------------------------------------
    public static boolean verificar(boolean[] abiertas,ArrayList<Integer> llaves, Urna[] urnas){
        boolean ret = true;
        HashMap<Integer,Integer> mapa = new HashMap<Integer,Integer>();
        for (Integer h:llaves){ 
            if (mapa.containsKey(h)){
                mapa.put(h, mapa.get(h)+1);
            }
            else{
                mapa.put(h, 1);
            }
        }
        for (Urna urna:urnas){
            for (Integer h:urna.contiene){
                if (!abiertas[urna.id]){
                    if (mapa.containsKey(h)){
                        mapa.put(h, mapa.get(h)+1);
                    }
                    else{
                        mapa.put(h, 1);
                    }
                }
            }
        }
        Set<Entry<Integer, Integer>> entrySet;
        Iterator<Entry<Integer, Integer>> iterator ;
        /*
        System.err.println(mapa.size());
        Set<Entry<Integer, Integer>> entrySet = mapa.entrySet();
        Iterator<Entry<Integer, Integer>> iterator = entrySet.iterator();
        while (iterator.hasNext()){
            System.err.println(iterator.next().toString());
            
        }
        */
        HashMap<Integer,Integer> mapa2 = new HashMap<Integer,Integer>();
        for (Urna urna:urnas){
            if (!abiertas[urna.id]){
                if (mapa2.containsKey(urna.abre)){
                    mapa2.put(urna.abre, mapa2.get(urna.abre)+1);
                }
                else{
                    mapa2.put(urna.abre, 1);
                }
            }
        }
        //System.err.println(mapa2.size());
        entrySet = mapa2.entrySet();
        iterator = entrySet.iterator();
        while (iterator.hasNext()){
            Entry<Integer, Integer> next = iterator.next();
            Integer clave = next.getKey();
            Integer total = next.getValue();
            
            Integer total2 = mapa.get(clave);
            //System.err.println(clave + " -- " + total + "  " + total2);
            if ((total2==null)
                    ||
                    (total2.compareTo(total)==-1)
                    ){
                ret = false;
            }
            
            
        }
        
        //System.err.println("ret " + ret);
        return ret;
    }
    //--------------------------------------------------------------------------
    public static ArrayList<Urna> candidatas(boolean[] abiertas,ArrayList<Integer> llaves, Urna[] urnas){
        ArrayList<Urna> ret = new ArrayList<Urna>();
        
        for (int i=0;i<abiertas.length;i++){
            if (!abiertas[i]){
                if (llaves.contains(urnas[i].abre)){
                    ret.add(urnas[i]);
                }
            }
        }
        
        return ret;
    }
    //--------------------------------------------------------------------------
    public static ArrayList<Urna> candidatasII(ArrayList<Integer> llaves, ArrayList<Urna> urnas){
        ArrayList<Urna> ret = new ArrayList<Urna>();
        
        for (int i=0;i<urnas.size();i++){
            if (llaves.contains(urnas.get(i).abre)){
                ret.add(urnas.get(i));
            }
        }
        
        return ret;
    }
    //--------------------------------------------------------------------------
    public static void abrirIII(ArrayList<Integer> llaves, ArrayList<Urna> urnas, String solucion,int nivel){
        if (!SOLUCION.equals("")){
            return;
        }
        if (urnas.isEmpty()){
            SOLUCION = solucion;
        }
        else{
            String dato = "";
            /*for (int h=0;h<llaves.size();h++){
                dato += llaves.get(h)+"+";
            }*/
            for (int h=0;h<urnas.size();h++){
                dato += urnas.get(h).id+":";
            }
            //System.err.println(dato+"\tsolucion " +solucion);
            if (memo2.contains(dato)){
               return;
            }
            memo2.add(dato);
            
            ArrayList<Urna> miscandidatas = candidatasII(llaves,urnas);
            for (Urna urna : miscandidatas){
                
                ArrayList<Integer> llaves2 = new ArrayList<Integer>();
                for (int h=0;h<llaves.size();h++){
                    llaves2.add(llaves.get(h));
                }
                llaves2.remove(new Integer(urna.abre));
                
                ArrayList<Urna> urnas2 = new ArrayList<Urna>();
                for (int h=0;h<urnas.size();h++){
                    urnas2.add(urnas.get(h));
                }
                urnas2.remove(urna);
                for (int h=0;h<urna.contiene.size();h++){
                    llaves2.add(new Integer(urna.contiene.get(h)));
                }
                
                abrirIII(llaves2,urnas2, solucion + " "+ (urna.id+1),nivel+1);
                //memo2.clear();
                //if (nivel==0)System.err.println("-++++++++++++++++++++++++++++++++++++++++++++++++++++++");
            }
        }
    }
    //--------------------------------------------------------------------------
    public static void abrir(boolean[] abiertas,ArrayList<Integer> llaves, Urna[] urnas, String solucion,int nivel){
        //java.util.Collections.sort(llaves);
        boolean verificacion = verificar(abiertas,llaves, urnas);
        if ( ! verificacion){
            System.err.println("Ahorro");
            return;
        }
        
        boolean todasabiertas = true;
        for (int i=0;i<abiertas.length;i++){
            todasabiertas = todasabiertas&&abiertas[i];
        }
        if (todasabiertas){
            //System.err.println("aca " + solucion) ;
            SOLUCION = solucion;
        }
        else{
            if (SOLUCION.equals("")){
                ArrayList<Urna> miscandidatas = candidatas(abiertas,llaves,urnas);
               /*
                
                System.err.println("--" + nivel) ;
                for (int i=0;i<abiertas.length;i++){
                    System.err.print(abiertas[i]+" ") ;
                }
                System.err.println();
                for (Urna urna : miscandidatas){
                    System.err.println(urna.id ) ;
                }
                System.err.println("---------------------------" ) ;*/
                
                for (Urna urna : miscandidatas){
                    boolean[] abiertas2 = new boolean[abiertas.length];
                    System.arraycopy(abiertas, 0, abiertas2, 0, abiertas.length);
                    abiertas2[urna.id] = true;

                    ArrayList<Integer> llaves2 = new ArrayList<Integer>();
                    for (int h=0;h<llaves.size();h++){
                        llaves2.add(llaves.get(h));
                    }
                    llaves2.remove(new Integer(urna.abre));
                    for (Integer h:urna.contiene){
                        llaves2.add(h);
                    }
                    
                    TipoMemo  mimemo = new TipoMemo(urna.id,abiertas);
                    if (memo.contains(mimemo)){
                        System.err.println("NO LLAMO");
                    }
                    else{
                        memo.add(mimemo);
                        abrir(abiertas2,llaves2, urnas,solucion + " "+ (urna.id+1)   ,nivel++);
                    }
                    //abrir(abiertas2,llaves2, urnas,""+ (urna.id+1) + " : "  + solucion,nivel++);
                }
            }
        }
        
        //System.err.println("CERRO nivel " + nivel) ;
    }
    //--------------------------------------------------------------------------
    public static void main(String[] args) throws FileNotFoundException {
        Lector lector = new Lector("D-small-attempt1.in");//("salida.txt");//("ejemplo.txt");//;
        
        int entero = lector.sc.nextInt();
        lector.sc.nextLine();
        
        for (int caso=1;caso<=entero;caso++){
            SOLUCION = "";
            int cantidadLlaves = lector.sc.nextInt();
            int cantidadUrnas = lector.sc.nextInt();
            lector.sc.nextLine();
            ArrayList<Integer> llaves = new ArrayList<Integer>();
            StringTokenizer tk = new StringTokenizer(lector.sc.nextLine());
            for (int i=0;i<cantidadLlaves;i++){
                llaves.add(Integer.parseInt(tk.nextToken()));
            }
            Urna[] urnas = new Urna[cantidadUrnas];
            for (int i=0;i<cantidadUrnas;i++){
                String linea = lector.sc.nextLine();
                //System.err.println("\t"+linea);
                tk = new StringTokenizer(linea);
                urnas[i] = new Urna();
                urnas[i].id = i;
                urnas[i].abre = Integer.parseInt(tk.nextToken());
                int totalcontenido = Integer.parseInt(tk.nextToken());
                for (int j=0;j<totalcontenido;j++){
                    urnas[i].contiene.add(Integer.parseInt(tk.nextToken()));
                }
            }
            
            /*
            System.err.println("cantidadLlaves " + cantidadLlaves + " cantidadUrnas " + cantidadUrnas);
            System.err.print("Llaves: ");
            for (Integer llave : llaves){
                System.err.print(llave + " ");
            }
            System.err.println();*/
            
            boolean[] abiertas = new boolean[urnas.length];
            boolean verificacion = verificar(abiertas,llaves, urnas);
            if (verificacion){
                //abrir(abiertas,llaves, urnas,"",0);
                ArrayList<Urna> urnas2 = new ArrayList<Urna>();
                for (int re=0;re<urnas.length;re++)
                    urnas2.add(urnas[re]);
                memo2.clear();
                abrirIII(llaves, urnas2,"",0);
            }
            if (SOLUCION.equals("")) SOLUCION = "IMPOSSIBLE";
            System.out.println("Case #" + caso+": "+SOLUCION.trim());
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
