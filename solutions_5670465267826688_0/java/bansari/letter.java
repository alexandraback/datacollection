/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;

import static googlecodejam.letter.solve;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * @author Bansari
 */
public class letter {
    int sign;
    static int ccount = 0;    
    Character value;
    
    public letter(){}
    
    public letter(int sign,Character value){
        this.sign = sign;
        this.value = value;
    }
    
    public boolean equals(letter other) {
        return (this.sign == other.sign) && (this.value.equals(other.value));
    }
    
    public static letter multiply(letter a,letter b){
        int s = a.sign * b.sign;
        
        if(a.value.equals('1')){
            return new letter(s,b.value);
        }else if (b.value.equals('1')) {
            return new letter(s, a.value);
        } else if (a.value.equals(b.value)) {
            return new letter(s * -1, '1');
        } else {
            if (a.value.equals('i') && b.value.equals('j')) {
                // i * j = k
                return new letter(s, 'k');
            } else if (a.value.equals('i') && b.value.equals('k')) {
                // i * k = -j
                return new letter(s * -1, 'j');
            } else if (a.value.equals('j') && b.value.equals('i')) {
                // j * i = -k
                return new letter(s * -1, 'k');
            } else if (a.value.equals('j') && b.value.equals('k')) {
                // j * k = i
                return new letter(s, 'i');
            } else if (a.value.equals('k') && b.value.equals('i')) {
                // k * i = j
                return new letter(s, 'j');
            } else if (a.value.equals('k') && b.value.equals('j')) {
                // k * j = -i
                return new letter(s * -1, 'i');
            }
        }
    return null;
    }
    
    public static void solve(BufferedReader f,PrintWriter out) throws Exception {
    //int L = iread(), X = iread();
        StringTokenizer st = new StringTokenizer(f.readLine());
        int L = Integer.parseInt(st.nextToken());
        Long X = Long.parseLong(st.nextToken());
        String str = f.readLine();
        StringBuilder repeatedstr = new StringBuilder();

        for (Long i = (long) 0; i < X; i++) {
            repeatedstr.append(str);
        }

        str = repeatedstr.toString();

        // IF LENGTH IS LESS THAN 3
        if (str.length() < 3) {
//            System.out.println("Case #"+(++ccount)+": NO");
            out.println("Case #"+(++ccount)+": NO");
            return;
        }

        
        int curPosition = 0;
        letter prev = new letter(1, '1'),
             i = new letter(1, 'i'),
             j = new letter(1, 'j'),
             k = new letter(1, 'k'),
             one = new letter(1, '1');
        letter pvalue = new letter();
        boolean goti = false, gotj = false, gotk = false, gotone = false;
        
        // IF 'i' IS POSSIBLE?,THEN GOTI ==TRUE
        for (; curPosition < str.length() ; curPosition++ ) {
            pvalue = multiply(prev, new letter(1, str.charAt(curPosition)));
            prev = pvalue;
            if (pvalue.equals(i)) {
                goti = true;
                curPosition++;
                // reset prev
                prev = one;
                break;
            }
        }
        if (goti == false) {
//            System.out.println("Case #"+(++ccount)+": NO");
            out.println("Case #"+(++ccount)+": NO");
            return;
        }

        // IF 'j' IS POSSIBLE?,THEN GOTJ ==TRUE
        for (; curPosition < str.length() ; curPosition++ ) {
            pvalue = multiply(prev, new letter(1, str.charAt(curPosition)));
            prev = pvalue;
            if (pvalue.equals(j)) {
                gotj = true;
                curPosition++;
                // reset prev
                prev = one;
                break;
            }
        }
        if (gotj == false) {
//            System.out.println("Case #"+(++ccount)+": NO");
            out.println("Case #"+(++ccount)+": NO");
            return;
        }

        // IF 'k' IS POSSIBLE?,THEN GOTk ==TRUE
        for (; curPosition < str.length() ; curPosition++ ) {
            pvalue = multiply(prev, new letter(1, str.charAt(curPosition)));
            prev = pvalue;
            if (pvalue.equals(k)) {
                gotk = true;
                curPosition++;
                // reset prev
                prev = one;
                break;
            }
        }
        if (gotk == false) {
//            System.out.println("Case #"+(++ccount)+": NO");
            out.println("Case #"+(++ccount)+": NO");
            return;
        }

        if (curPosition == str.length()) {
//            System.out.println("Case #"+(++ccount)+": YES");
            out.println("Case #"+(++ccount)+": YES");
            return;
        }

        // Wrap up the rest
        for (; curPosition < str.length() ; curPosition++ ) {
            pvalue = multiply(prev, new letter(1, str.charAt(curPosition)));
            prev = pvalue;
        }
        if (pvalue.equals(one)) {
//            System.out.println("Case #"+(++ccount)+": YES");
            out.println("Case #"+(++ccount)+": YES");
        } else {
//            System.out.println("Case #"+(++ccount)+": NO");
            out.println("Case #"+(++ccount)+": NO");
        }     
        
    }
  public static void main(String ar[]) throws Exception{
    BufferedReader f = new BufferedReader(new FileReader("dijkstra.txt"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
        
        int totacases = Integer.parseInt(f.readLine());
        for(int a = 0;a<totacases;a++){
            solve(f,out);
           
        }
        f.close();
        out.close();
}  
    
}
