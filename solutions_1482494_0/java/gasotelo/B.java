
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.TreeMap;
import java.util.TreeSet;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author G
 */
public class B {

    public static void main(String ... args)throws Exception{
        PrintWriter pw = new PrintWriter("B.out");
        BufferedReader br = new BufferedReader(new FileReader("F:/Documents/Desktop/B-large.in"));
        int T = Integer.parseInt(br.readLine());
        for(int k=0;k<T;k++){
            String[] caso = br.readLine().split(" +|\t+");
            int c = Integer.parseInt(caso[0]);
            char[][] trans = new char[c][3];
            for(int e=0;e<c;e++){
                trans[e]=caso[e+1].toCharArray();
            }
            int d = Integer.parseInt(caso[c+1]);
            char[][] opp = new char[d][2];
            for(int e=0;e<d;e++){
                opp[e]=caso[c+2+e].toCharArray();
            }
            int n = Integer.parseInt(caso[d+1+c+1]);
            char[] cadena = caso[d+c+3].toCharArray();
            ArrayList<Character> elementos = new ArrayList<Character>();
            c:for(int e=0;e<cadena.length;e++){
                if(elementos.size()==0){
                    elementos.add(cadena[e]);
                    continue c;
                }
                char ant = elementos.get(elementos.size()-1);

                for(char[] t:trans)if((t[0]==ant&&t[1]==cadena[e])||(t[1]==ant&&t[0]==cadena[e])){
                    elementos.remove(elementos.size()-1);
                    elementos.add(t[2]);
                    continue c;
                }
                for(char[] t:opp){
                    if(t[0]==cadena[e]&&elementos.contains(t[1])){
                        elementos=new ArrayList<Character>();
                        continue c;
                    }
                    if(t[1]==cadena[e]&&elementos.contains(t[0])){
                        elementos=new ArrayList<Character>();
                        continue c;
                    }
                }
                elementos.add(cadena[e]);
            }
            pw.println("Case #"+(k+1)+": "+Arrays.toString(elementos.toArray(new Character[0])));
        }
        pw.close();;
    }
}
