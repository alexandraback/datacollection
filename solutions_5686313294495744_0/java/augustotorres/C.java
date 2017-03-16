/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package R1B2016;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author astorres
 */
public class C {
    
    static String h[] = new String[1000];
    static int nh;
    static String k[] = new String[1000];
    static int nk;
    static int r[][] = new int[2][1000];
    static int M[][] = new int[2][1000];
    
    public static void main(String args[]) throws FileNotFoundException {
        String file = "C-small-attempt2.in";
        Scanner in = new Scanner(new File("C:\\Users\\astorres\\Desktop\\Personal\\CodeJam\\src\\CodeJam\\data\\"+file));
        int n = in.nextInt();
        for(int i=1;i<=n;i++) {
            int t = in.nextInt();
            nh = nk = 0;
            Arrays.fill(r[0],0);
            Arrays.fill(r[1],0);
            Arrays.fill(M[0],0);
            Arrays.fill(M[1],0);
            for(int j=0;j<t;j++) {
                String a = in.next(), b = in.next();
                int ix = -1, iy=-1;
                for(int hh=0;hh<nh;hh++)
                    if(h[hh].compareTo(a)==0)
                        ix = hh;
                if(ix==-1) {
                    h[nh] = a;
                    ix = nh++;
                }
                for(int kk=0;kk<nk;kk++)
                    if(k[kk].compareTo(b)==0)
                        iy = kk;
                if(iy==-1) {
                    k[nk] = b;
                    iy = nk++;
                }
                r[0][ix]++;
                r[1][iy]++;
                M[0][j] = ix;
                M[1][j] = iy;
            }
            int res = 0;
            for(int j=0;j<t;j++) {
                if(r[0][M[0][j]]>1&&r[1][M[1][j]]>1)
                    res++;
            }
            res = Math.min(Math.min(res, t-nh),t-nk);
            
            System.out.println("Case #"+i+": "+res);
        }
    }
    
}
