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
        int shakes =Integer.parseInt(BR.readLine());
        int Customers= Integer.parseInt(BR.readLine());
        int[][] likes= new int[Customers][];
        for(int i =0;i<Customers;i++){
            String[] S= BR.readLine().split(" ");
            int lshakes =Integer.parseInt(S[0]);
            likes[i]= new int[lshakes+1];
            for(int j =0;j<lshakes;j++){
                int lshake = Integer.parseInt(S[1+2*j]);
                int lik = Integer.parseInt(S[2+2*j]);
                if(lik==1){likes[i][0]=lshake;}else{likes[i][j+1]=lshake;}
            }
        }
        /*for(int i=0;i<Customers;i++){
            for(int j=0;j<likes[i].length;j++){
                System.out.print(likes[i][j]+" ");
            }
            System.out.println("");
        }*/
        int[] malted = new int[shakes];
        // malted[i] tells if shake i+1 is malted
        // looking for first unhappy guy
        boolean goOn=true;
        while(goOn){
            goOn=false;
            for(int i =0;(i<Customers)&&!goOn;i++){
                boolean happy=(likes[i][0]!=0)&&(malted[likes[i][0]-1]==1);
                int j=1;
                while((j<likes[i].length)&&(!happy)){
                    if(likes[i][j]!=0)happy =malted[likes[i][j]-1]==0;
                    j++;
                }
                if(!happy){
                    if(likes[i][0]==0){                        
                        //System.out.println("Customer "+i+" needs one of the shakes to be unmalted");
                        //printArray(malted);
                        return "IMPOSSIBLE";
                    }
                    else{
                        //System.out.println("Customer "+i+" demands his malted shake "+likes[i][0]);                        
                        //printArray(malted);
                        malted[likes[i][0]-1]=1;
                        goOn=true;
                    }
                }
            }
        }
        StringBuffer SB= new StringBuffer();
        SB.append(malted[0]);
        for(int i =1;i<malted.length;i++)SB.append(" "+malted[i]);
        return SB.toString();
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
