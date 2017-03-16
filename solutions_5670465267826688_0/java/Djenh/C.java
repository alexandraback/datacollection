package Qualification_2015 ;


import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class Dijkstra {
     
    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;
    static int test;
    
    static void solve() throws Exception {
        
        int L = nextInt();
        int X = nextInt();
        
        boolean iTest = false;
        boolean jTest = false;
        boolean kTest = false;
        
        StringBuilder format = new StringBuilder(next());
        StringBuilder chaine = new StringBuilder();
        
        for(int i=1; i<=X; i++){
            chaine = chaine.append(format);
        }
        
        int depart = 0;
        String Calcul = ""+chaine.charAt(depart);
        //int depart = 0;
        for(int i=(depart + 1); i<chaine.length(); i++){
            
            //out.print("Calcul progressif " + Calcul + " "+chaine.charAt(i) + " ");
            Calcul = matDijkstra( Calcul, ""+chaine.charAt(i));
            //out.println(Calcul);
            
            
            if(Calcul.equals("i")){
                iTest = true;
                depart = i+1;
                break;
                //C = "";
//                C.replace(depart, i, " ");
//                depart = i + 1;
            }
            
        }
        
        if( (iTest == true) && (depart < chaine.length()) ){
            Calcul = ""+chaine.charAt(depart);
            
            for(int i=(depart + 1); i<chaine.length(); i++){
                Calcul = matDijkstra( Calcul, ""+chaine.charAt(i));
                if(Calcul.equals("j")){
                    jTest = true;
                    depart = i+1;
                    break;
                
                }
            }
            
        }
        
        if( (iTest == true) && (jTest == true) && (depart < chaine.length()) ){
            Calcul = ""+chaine.charAt(depart);
            
            for(int i=(depart + 1); i<chaine.length(); i++){
                Calcul = matDijkstra( Calcul, ""+chaine.charAt(i));
                
            }
            
            if(Calcul.equals("k")){
                kTest = true;
            }
            
            
        }
        
        //out.println("La chaine "  + chaine + " Sa longueur " + chaine.length() );
        
        if( (chaine.length() == 3) ){
            //out.println("Longuer chaine "   + chaine.length());
//            out.println(chaine.charAt(0));
//            out.println(chaine.charAt(1));
//            out.println(chaine.charAt(2));
//            
//            out.println(chaine.charAt(0) == 'i');
//            out.println(chaine.charAt(1) ==  'j');
//            out.println(chaine.charAt(2) == 'k');
            
            
            if( chaine.charAt(0)== 'i' && chaine.charAt(1)== 'j' && chaine.charAt(2)== 'k'){
                iTest = true;
                jTest = true;
                kTest = true;
            } 
                
            
        }
        
        printCase();
        
        if( (iTest == true) && (jTest == true) && (kTest == true) ){
           out.println("YES");
        }
        else{
            out.println("NO");
        }
        //printCase();
        //out.println(chaine);
    }
    
    
    
    static String matDijkstra (String ligne, String colonne){
        int indiceLigne = 0, indiceColonne=0;
        
        String [][] mat = { {"1","i","j","k","-1","-i","-j","-k"},
                            {"i","-1","k","-j","-i","1","-k","j"},
                            {"j","-k","-1","i","-j","k","1","-i"},
                            {"k","j","-i","-1","-k","-j","i","1"},
                            {"-1","-i","-j","-k","1","i","j","k"},
                            {"-i","1","-k","j","i","-1","k","-j"},
                            {"-j","k","1","-i","j","-k","-1","i"},
                            {"-k","-j","i","1","k","j","-i","-1"}
                        };
        
        if(ligne.equals("1")){
            indiceLigne = 0;
        }
        else if(ligne.equals("i")){
            indiceLigne = 1;
        }
        else if(ligne.equals("j")){
            indiceLigne = 2;
        }
        else if (ligne.equals("k")){
            indiceLigne = 3;
        }
        else if(ligne.equals("-1")){
            indiceLigne = 4;
        }
        else if(ligne.equals("-i")){
            indiceLigne = 5;
        }
        else if(ligne.equals("-j")){
            indiceLigne = 6;
        }
        else if (ligne.equals("-k")){
            indiceLigne = 7;
        }
        
        
        if(colonne.equals("1")){
            indiceColonne = 0;
        }
        else if(colonne.equals("i")){
            indiceColonne = 1;
        }
        else if(colonne.equals("j")){
            indiceColonne = 2;
        }
        else if (colonne.equals("k")){
            indiceColonne = 3;
        }
        else if(colonne.equals("-1")){
            indiceColonne = 4;
        }
        else if(colonne.equals("-i")){
            indiceColonne = 5;
        }
        else if(colonne.equals("-j")){
            indiceColonne = 6;
        }
        else if (colonne.equals("-k")){
            indiceColonne = 7;
        }
       
        return ( mat[indiceLigne][indiceColonne]);
    
    }

            
    static void printCase() {
    out.print("Case #" + test + ": ");
    }
    
    static void printlnCase() {
    out.println("Case #" + test + ":");
    }
    
    static int nextInt() throws IOException {
    return parseInt(next());
    }

    static long nextLong() throws IOException {
    return parseLong(next());
    }

    static double nextDouble() throws IOException {
    return parseDouble(next());
    }

    static String next() throws IOException {
    while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
    }
    return tok.nextToken();
    }

    
    public static void main(String[] args) {
        
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
            int tests = nextInt();
            for (test = 1; test <= tests; test++) {
                solve();
            }
            in.close();
            out.close();
            } catch (Throwable e) {
                e.printStackTrace();
                exit(1);
            }
    } 
    }
    

