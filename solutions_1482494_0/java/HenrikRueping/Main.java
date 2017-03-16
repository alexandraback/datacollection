/*
 * Main.java
 * 
 * Created on 14.04.2012, 10:03:46
 * 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam12;

import Round1a.CodeJamRound1a;

/**
 *
 * @author Besitzer
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    /*public static void main(String[] args) {
        char[] C = new char[26];      
        CodeJamQuali CJQ =new CodeJamQuali();
        CJQ.fillDict("our language is impossible to understand","ejp mysljylc kd kxveddknmc re jsicpdrysi",C);
        CJQ.fillDict("there are twenty six factorial possibilities","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",C);
        CJQ.fillDict("so it is okay if you want to just give up","de kr kd eoya kw aej tysr re ujdr lkgc jv",C);
        C['z'-'a']='q';        
        C['q'-'a']='z';
        System.out.println("abcdefghijklmnopqrstuvwxyz");
        System.out.println(C);
        for(int i =0;i<26;i++)if(C[i]=='z')System.out.println("found");
        
    }*/
    
    public static void main(String[] args) {

        CodeJamRound1a CJQ =new CodeJamRound1a();
        //CJQ.go("src/qualification/A-small-attempt0.in", 1);
        CJQ.go("src/Round1a/B-small-attempt0.in", 2);
        //System.out.println(new java.math.BigInteger("2").gcd(java.math.BigInteger.ZERO));
    }

}
