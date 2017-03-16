/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package googelese;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 * @author admin
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
         FileReader fr=new FileReader("A-small-attempt0.in");
        BufferedReader br=new BufferedReader(fr);
        FileWriter fw=new FileWriter("result.txt");
        PrintWriter pw=new PrintWriter(fw);
getOutPut(br,pw);

        pw.close();
    }
      public static void printOutPut(int i,PrintWriter pw,int result){
    pw.println("Case #"+(i+1)+": "+result);
        System.out.println("Case #"+(i+1)+": "+result);
    }

    public  static void getOutPut(BufferedReader br,PrintWriter pw) throws IOException {
        int t=Integer.parseInt(br.readLine());
        String[] s;
        for(int i=0;i<t;i++){
        s=br.readLine().split(" ");
        pw.print("Case #"+(i+1)+": ");
        translate(s,pw);
        pw.println();
        }
    }

    public  static void translate(String[] s, PrintWriter pw) {
        char c;

        for(int i=0;i<s.length;i++){
            for(int j=0;j<s[i].length();j++){
                if(s[i].charAt(j)=='y'){
                pw.print('a');
                }
                if(s[i].charAt(j)=='e'){
                pw.print('o');
                }
                if(s[i].charAt(j)=='q'){
                pw.print('z');
                }
                if(s[i].charAt(j)=='j'){
                pw.print('u');
                }
                if(s[i].charAt(j)=='p'){
                pw.print('r');
                }
                if(s[i].charAt(j)=='m'){
                pw.print('l');
                }
                if(s[i].charAt(j)=='s'){
                pw.print('n');
                }
                if(s[i].charAt(j)=='l'){
                pw.print('g');
                }
                if(s[i].charAt(j)=='c'){
                pw.print('e');
                }
                if(s[i].charAt(j)=='k'){
                pw.print('i');
                }
                if(s[i].charAt(j)=='d'){
                pw.print('s');
                }
                if(s[i].charAt(j)=='x'){
                pw.print('m');
                }
                if(s[i].charAt(j)=='v'){
                pw.print('p');
                }
                if(s[i].charAt(j)=='n'){
                pw.print('b');
                }
                if(s[i].charAt(j)=='r'){
                pw.print('t');
                }
                if(s[i].charAt(j)=='i'){
                pw.print('d');
                }
                if(s[i].charAt(j)=='g'){
                pw.print('v');
                }
                if(s[i].charAt(j)=='b'){
                pw.print('h');
                }
                if(s[i].charAt(j)=='t'){
                pw.print('w');
                }
                if(s[i].charAt(j)=='a'){
                pw.print('y');
                }
                if(s[i].charAt(j)=='h'){
                pw.print('x');
                }
                if(s[i].charAt(j)=='w'){
                pw.print('f');
                }
                if(s[i].charAt(j)=='f'){
                pw.print('c');
                }
                if(s[i].charAt(j)=='o'){
                pw.print('k');
                }
                if(s[i].charAt(j)=='u'){
                pw.print('j');
                }
                if(s[i].charAt(j)=='z'){
                pw.print('q');
                }
            }
            if(i!=s.length-1)
                pw.print(" ");
        }
    }

}
