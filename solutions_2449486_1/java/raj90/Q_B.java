/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

/**
 *
 * @author user
 */
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
public class Q_B {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        StreamTokenizer in=new StreamTokenizer(new FileReader("Q_B_L.txt"));
        //BufferedReader br=new BufferedReader(new FileReader("Q_.txt"));
        PrintWriter out=new PrintWriter(new FileWriter("Q_B_ans.txt"));
        int i,j,k,l,m,n,c[][],t,p,r;
        in.nextToken();
        t=(int) in.nval;
        for(i=0;i<t;i++){
            in.nextToken();
            n=(int) in.nval;
            in.nextToken();
            m=(int) in.nval;
            c=new int[n][m];
            for(j=0;j<n;j++){
                for(k=0;k<m;k++){
                    in.nextToken();
                    c[j][k]=(int) in.nval;
                }
            }
            boolean t1=false,ans=false;
            for(j=0;j<n;j++){
                for(k=0;k<m;k++){
                    l=c[j][k];
                    t1=false;
                    for(p=0;p<m;p++){
                        if(c[j][p]<=l)
                            t1=true;
                        else{
                            t1=false;
                            break;
                        }
                    }
                    if(!t1){
                        for(p=0;p<n;p++){
                            if(c[p][k]<=l)
                                t1=true;
                            else{
                            t1=false;
                            break;
                        }
                        }
                        
                    }
                    if(!t1){
                        ans=true;
                        break;
                    }
                }
                if(ans)
                    break;
            }
            if(ans)
                    out.println("Case #"+(i+1)+": NO");
            else
                out.println("Case #"+(i+1)+": YES");
        
        }
        out.flush();
        out.close();
    }
}
