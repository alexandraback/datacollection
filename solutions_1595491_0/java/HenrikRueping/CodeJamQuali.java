/*
 * CodeJamTester1A.java
 * 
 * Created on 28.07.2008, 14:20:39
 * 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package qualification;
import java.util.*;
import java.io.*;
import java.math.*;

/**
 *
 * @author Besitzer
 */
public class CodeJamQuali {
    int testcases;
    String dict="yhesocvxduiglbkrztnwjpfmaq";
    BufferedReader BR;
    BigInteger ZERO =BigInteger.ZERO;
    BigInteger ONE =BigInteger.ONE;
    BigInteger TWO =new BigInteger("2");
    BigInteger THREE =new BigInteger("3");
    
    public void sort(long[] a){
        for(int i=0;i<a.length;i++){
            long max=a[i];
            int minAt=-1;
            for(int j=i+1;j<a.length;j++){
                if(a[j]>max){max=a[j];minAt=j;}
            }
            //System.out.println("maxAT:"+minAt+" max: "+max);
            if(minAt>-1){
                long buf =a[i];
                a[i]=a[minAt];
                a[minAt]=buf;
            }
        }
    }
    
    public void fillDict(String E, String G, char[] C){
        for(int i=0;i<E.length();i++){
            char e= E.charAt(i);
            char g =G.charAt(i);
            int p = g-'a';
            if(g!=' ')C[p]=e;
        }
    }

    
    public String testCase1() throws IOException{
        String read =BR.readLine();
        //System.out.println(read);
        for(char c='a';c<='z';c++)
        {
            read=read.replace(c,Character.toUpperCase(dict.charAt(c-'a')));
        }
        return read.toLowerCase();
    }
    
    
           
    public String testCase2() throws IOException{
        String[] St= BR.readLine().split(" ");
        int N = Integer.parseInt(St[0]);
        int S = Integer.parseInt(St[1]);
        int p = Integer.parseInt(St[2]);
        int incable=0;
        int ok=0;int cur;
        int incbound = 3*p-4;
        incbound =incbound >1 ? incbound :1;
        for(int i =0;i<N;i++){
            cur=Integer.parseInt(St[3+i]);
            if(cur>=3*p-2){
                ok++;
            }else{
                if(cur>=incbound)incable++;
            }
        }
        S=S<incable ?S:incable;
        ok=ok+S;
        return ""+ok;

    }
    
    public void printArray(int[] a){
        System.out.print(a[0]);
        for(int i=1;i<a.length;i++)System.out.append(" "+a[i]);
        System.out.println("");
    }

    
    public String testCase3() throws IOException{
        long n= Long.parseLong(BR.readLine());
        if(n==0)return "1";
        if(n==1)return "6";
        long cur=6;long prev=2;long buf;long n0=n-1;
        while(n0>0){
            buf= (6*cur-4*prev)%1000;
            if(buf<0)buf=(10000+buf)%1000;
            prev=cur;cur=buf;            
            n0--;
            // abuse periority of the pairs 
            if((prev==144)&&(cur==752)&&(n-n0!=4)){
                System.out.println(n-n0-4);
                n0=n0%(n-n0-4);
            }
        }        
        String S= ""+(cur+999)%1000;
        while(S.length()<3)S="0"+S;
        return S;
    }
    
    public void go(String filename,int exerciseNr){
        java.io.File F =  new java.io.File(filename);       
        try{                    
            BR = new BufferedReader(new FileReader(F));
            BufferedWriter BW= new BufferedWriter(new FileWriter(new File("output.txt")));
            int cases = Integer.parseInt(BR.readLine());            
            for(int i=0;i<cases;i++){
                String S="";
                switch(exerciseNr){
                 case 1: S="Case #"+(i+1)+": "+testCase1(); break;
                 case 2: S="Case #"+(i+1)+": "+testCase2(); break;
                 case 3: S="Case #"+(i+1)+": "+testCase3(); break;
             }
                BW.write(S+"\n");
                System.out.println(S);
            }
            BR.close();
            BW.close();
        }catch(FileNotFoundException e){System.err.println(e);}
        catch(IOException e){System.err.println(e);}
    }


}
