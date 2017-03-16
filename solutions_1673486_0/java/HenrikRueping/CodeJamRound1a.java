/*
 * CodeJamTester1A.java
 * 
 * Created on 28.07.2008, 14:20:39
 * 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Round1a;
import qualification.*;
import java.util.*;
import java.io.*;
import java.math.*;

/**
 *
 * @author Besitzer
 */
public class CodeJamRound1a {
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
        String[] read =BR.readLine().split(" ");
        int A = Integer.parseInt(read[0]);
        int B = Integer.parseInt(read[1]);
        double[] p = new double[A];
        double[] e=new double[A+1]; //expectation of the strat go back to e
        read =BR.readLine().split(" ");
        for(int i=0;i<A;i++)p[i]=Double.parseDouble(read[i]);
        double curp=1 ;// Prop that it is still correct.
        double emin =B+2;//Enter right away        
        for(int i=0;i<=A;i++){
            e[i]=(B-i)+(A-i)+1+(1-curp)*(B+1);
            //System.out.println(curp+" "+e[i]);
            if (e[i]<emin){emin=e[i];}
            if(i<A)curp*=p[i];             
        }
        //System.out.println(read);
        return ""+emin;
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
    @SuppressWarnings("fallthrough")
    public String testCase4() throws IOException{
        String[] SA=  BR.readLine().split(" ");
        int H = Integer.parseInt(SA[0]);
        int W = Integer.parseInt(SA[1]);
        int D = Integer.parseInt(SA[2]);
        char[][] F = new char[H][];
        int startx=-1,starty=-1;
        int reflCount =0;
        for(int i=0;i<H;i++){
            F[i]=BR.readLine().toCharArray();
            for(int j = 0;j<W;j++)if(F[i][j]=='X'){
                startx =i;starty=j;
                F[i][j]='.';
            }            
        }
        int iterations;
        for(int a2 = 1;a2<=D;a2++)for(int b2=0;b2<D;b2++){
            
            double dit= Math.sqrt(a2*a2+b2*b2);
            int iterations2 = (int) Math.floor(((double)D) /dit);
            
            
            for(int sx2 =-1;sx2<=1;sx2+=2)for(int sy2 =-1;sy2<=1;sy2+=2){
            iterations =iterations2;
            int gcd = new BigInteger(""+a2).gcd(new BigInteger(""+b2)).intValue();
            if(gcd !=1) iterations =0;
            //System.out.println("a "+a+" b "+b+" D "+D+" dit "+dit+" it "+iterations2);
            int px=startx, py=starty;int sx=sx2;int sy=sy2;
            boolean rayLives=true;
            int a=a2;int b=b2;
            if(sx*sy==-1){int c=a;a=b;b=c;}
            //System.out.println("trying "+a*sx +" "+b*sy);
            int abuf =  -b;int bbuf =-a;      
            while((iterations>0)&&(rayLives)){
                 int diff  = (abuf + 2*b)-(bbuf +2*a);
                 if (diff>=0){bbuf +=2*a;}
                 if (diff<=0){abuf +=2*b;}
                 diff=diff>0 ?1:(diff<0 ?-1:0);
            switch(diff){
                case -1:if(F[px+sx][py]=='#'){sx=-sx;}else{px+=sx;}break;                    
                case  1:if(F[px][py+sy]=='#'){sy=-sy;}else{py+=sy;}break;
                case 0:if(F[px+sx][py+sy]=='.')
                {
                    px+=sx;py+=sy;
                }else{
                    if((F[px+sx][py]=='.')&&((F[px][py+sy]=='.'))){rayLives=false;}
                    boolean xbuf =F[px+sx][py]=='#';
                    if(F[px][py+sy]=='#') {sy=-sy;}else{py+=sy;}
                    if(xbuf) {sx=-sx;}else{px+=sx;}
                }  break;                
            }
            //System.out.println(a+" "+b+ " "+raylength+" ");
            if((rayLives)&&(abuf ==(2*a-1)*b) && ((bbuf ==(2*b-1)*a)||(b==0))){
                abuf=-b;bbuf=-a;
                if((px==startx)&&(py==starty)){
                    reflCount++;rayLives=false;
                    //System.out.println("Found:" +a+" "+ b+" "+ sx2+" "+sy2);
                }
                iterations--;
            }
            
                }
            }
        }
        return ""+reflCount;
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
                 case 4: S="Case #"+(i+1)+": "+testCase4(); break;
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
