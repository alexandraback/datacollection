package a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

public class A {

    public static BufferedReader br = null;
    public static BufferedWriter bw = null;
    public static long T, n;
    public static String L;
    public static ArrayList<String> lista = new ArrayList<String>();

    public static void lee() {
        try {
            lista.clear();
            String linea = br.readLine();
            StringTokenizer st = new StringTokenizer(linea);
            while (st.hasMoreTokens()) {
                lista.add(st.nextToken());
            }

        } catch (IOException ex) {
            Logger.getLogger(A.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static boolean vowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    public static int solucion() {
        int size = L.length();
        int s2 = size;
        int cont = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i+(int)n; j <= s2; j++) {
                String parte = L.substring(i, j);
                //System.out.println(parte);
                if(conValor(parte,n)){
                    //System.out.println(parte);
                    cont++;
                }
            }
        }
        return cont;
    }

    public static boolean conValor(String cadena, long n) {
        if (cadena.length() < n) {
            return false;
        }
        int cont = 0;
        int size = cadena.length();
        for(int i = 0; i < size ; i++){
            char c = cadena.charAt(i);
            if(vowel(c)){
                cont = 0;
            }else{
                cont++;
            }
            if(cont == n){
                return true;
            }
        }
        return (cont == n);
    }

    public static void main(String[] args) {
        try {
            br = new BufferedReader(new FileReader("A-small-attempt0.in"));
            bw = new BufferedWriter(new FileWriter(new File("A-Output.txt")));
            T = Long.parseLong(br.readLine());
            //System.out.println("T: "+T);
            int aux = 1;
            while (aux <= T) {
                String linea = br.readLine();
                StringTokenizer st = new StringTokenizer(linea);
                L = st.nextToken();
                n = Long.parseLong(st.nextToken());
                //System.out.println(L+" "+n);

                long cont = solucion();
                String sol = "Case #" + aux + ": " + cont;
                System.out.println(sol);
                bw.write(sol + "\n");
                aux++;
            }

            bw.close();
        } catch (Exception ex) {
            System.out.println(ex.toString());
        }
    }

}
