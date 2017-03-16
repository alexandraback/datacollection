/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package gcj2012.round1a;

import gcj2012.qual.*;
import gcj2010.round2.*;
import gcj2009.*;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author scbit
 */
public class P2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new P2().run();
    }
    PrintWriter pw;

    void run() throws Exception{
        File infile=new File("B-small-attempt1.in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int T=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        //N=Integer.parseInt(br.readLine());
        Scanner sc=new Scanner(infile);
        T=sc.nextInt();

        for(int case_i=1;case_i<=T;case_i++) {
            int result = 0;
            int N=sc.nextInt();
            List<tower> towers=new ArrayList<tower>();

            
            
            for(int i=0;i<N;i++){
                int a=sc.nextInt();
                int b=sc.nextInt();
                towers.add(new tower(a, b));
            }
            Collections.sort(towers);
            
            int time=0;
            int star=0;
            boolean suc=true;
c1:         while(true){
                if(star==(2*N)){
                    break;
                }
                for(int i=0;i<N;i++){
                    tower t=towers.get(i);
                    if(t.status==0){
                        if(t.b<=star){
                            t.status=2;
                            star+=2;
                            time++;
                            continue c1;
                        }
                    }
                }
                for(int i=0;i<N;i++){
                    tower t=towers.get(i);
                    if(t.status==1){
                        if(t.b<=star){
                            t.status=2;
                            star+=1;
                            time++;
                            continue c1;
                        }
                    }
                }
                for(int i=0;i<N;i++){
                    tower t=towers.get(i);
                    if(t.status==0){
                        if(t.a<=star){
                            t.status=1;
                            star+=1;
                            time++;
                            continue c1;
                        }
                    }
                }
                suc=false;
                break;
            }
            if(suc){
            pw.printf("Case #%d: %d\n", case_i,time);
            System.out.printf("Case #%d: %d\n", case_i,time);
            }
            else{
                pw.printf("Case #%d: %s\n", case_i,"Too Bad");
            System.out.printf("Case #%d: %s\n", case_i,"Too Bad");
            }
        }
        pw.close();
    }

}
class tower implements Comparable<tower> {
    int a;
    int b;
    int d;
    int status=0;
    public tower(int a,int b){
        this.a=a;
        this.b=b;
        d=b-a;
    }

    @Override
    public int compareTo(tower t) {
        //reverse
        return (t.b-this.b)*2100+(t.a-this.a);
    }
    public String toString(){
        return ""+a+" "+b+" "+d;
    }
    
}