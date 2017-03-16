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
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
public class Q_C {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        StreamTokenizer in=new StreamTokenizer(new FileReader("Q_C_L.txt"));
        //BufferedReader br=new BufferedReader(new FileReader("Q_.txt"));
        PrintWriter out=new PrintWriter(new FileWriter("Q_C_ans.txt"));
        
        String a[]={"1","4","9","121","484","10201","12321","14641","40804","44944","1002001",
        "1234321","4008004","100020001","102030201","104060401","121242121","123454321",
        "125686521","400080004","404090404","10000200001","10221412201","12102420121","12345654321",
        "40000800004","1000002000001","1002003002001","1004006004001","1020304030201",
        "1022325232201","1024348434201","1210024200121","1212225222121","1214428244121",
        "1232346432321","1234567654321","4000008000004","4004009004004","100000020000001"};
        System.out.println(a.length);
        long i,k,l,m,n,t,a1 = 0,b1 = 0;int j;
        in.nextToken();
        t=(long) in.nval;
        for(i=0;i<t;i++){
            in.nextToken();
            a1=(long) in.nval;
            in.nextToken();
            b1=(long) in.nval;
        
        int ans=0;
        for(j=0;j<a.length;j++){
            l=Long.parseLong(a[j]);
            if(l>=a1&&l<=b1)
                ans++;
        }
        out.println("Case #"+(i+1)+": "+ans);
        }
        out.flush();
        out.close();
    }
    
}
