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
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;
public class Q_D {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        StreamTokenizer in=new StreamTokenizer(new FileReader("Q_D.txt"));
        //BufferedReader br=new BufferedReader(new FileReader("Q_.txt"));
        PrintWriter out=new PrintWriter(new FileWriter("Q_D_ans.txt"));
        //PriorityQueue<Integer> Q=new PriorityQueue<Integer>();
        int i,j,k,l,m,n,t,K[],N[],t1,k1,M[],p,q;boolean tes[];
        Map<Integer,ArrayList<Integer>> mp=new HashMap<Integer,ArrayList<Integer>>();
        in.nextToken();
        t=(int) in.nval;
        for(i=0;i<t;i++){
            mp=new HashMap<Integer,ArrayList<Integer>>();
            in.nextToken();
        k=(int) in.nval;
        in.nextToken();
        n=(int) in.nval;
        K=new int[k];
        N=new int[n];
        M=new int[n];
        tes=new boolean[n];
        Arrays.fill(tes, false);
        Chest ches[]=new Chest[n];
        for(j=0;j<k;j++){
            in.nextToken();
            K[j]=(int) in.nval;
        }
        for(j=0;j<n;j++){
             in.nextToken();
        t1=(int) in.nval;
        in.nextToken();
        N[j]=t1;
        M[j]=t1;
         if (!mp.containsKey(t1)) 
        mp.put(t1, new ArrayList<Integer>() );
        mp.get(t1).add(j);
        k1=(int) in.nval;
        ches[j]=new Chest(k1);
        ches[j].key=t1;
        for(l=0;l<k1;l++){
            in.nextToken();
            ches[j].kin[l]=(int) in.nval;
        }
        }
        /*Iterator iter = mp.entrySet().iterator();
        while (iter.hasNext()) {
		Map.Entry mEntry = (Map.Entry) iter.next();
		System.out.println(mEntry.getKey() + " : " + mEntry.getValue());
        }*/
      ArrayList<Integer> a=new ArrayList<Integer>();
        ArrayList<Integer> b;//=new ArrayList<Integer>();
        PriorityQueue<Integer> Q=new PriorityQueue<Integer>();
        Q.clear();
        for(j=0;j<k;j++){
            
            
            l=K[j];
            //b=new ArrayList<Integer>();
            if(mp.containsKey(l)){
                b=new ArrayList<Integer>(mp.get(l));
                
                System.out.println(b);
                if(!b.isEmpty()){
                for(q=0;q<b.size();q++)
                    if(!Q.contains(b.get(q)))
                    Q.add(b.get(q));
            }
            }
            
        }
            System.out.println(Q);
        int s1;
        while(!Q.isEmpty()){
            l=Q.remove();
            //System.out.println(Q);
            
            tes[l]=true;
            for(j=0;j<ches[l].kin.length;j++){
                p=ches[l].kin[j];
                //s1=Arrays.binarySearch(N, p);
                if(mp.containsKey(p)){
                b=new ArrayList<Integer>(mp.get(p));
                if(!b.isEmpty()){
                for(q=0;q<b.size();q++){
                    if(!Q.contains(b.get(q))&&
                        !tes[b.get(q)])
                        Q.add(b.get(q));
                
            }
                }
            }
            }
            if(!a.contains(l+1))
            a.add((l+1));
        }
        boolean test=false;
        for(j=0;j<n;j++){
            if(tes[j])
                test=true;
            else{
                test=false;
                break;
            }
        }
        if(!test)
            out.println("Case #"+(i+1)+": IMPOSSIBLE");
        else{
            out.print("Case #"+(i+1)+": ");
            for(Integer s:a)
                out.print(s+" ");
            out.println();
        }
        }
        out.flush();
        out.close();
    }
    
}
class Chest{
        int key,numk,kin[];
        Chest(int a){
            numk=a;
            kin=new int[a];
        }
    }
/*class Qimplement implements Comparator<Integer>{
         ArrayList<Integer> a=new ArrayList<Integer>();
    @Override
    public int compare(Integer o1, Integer o2) {
        return a.get(o1).compareTo(o2);
        //throw new UnsupportedOperationException("Not supported yet.");
    }
    
}*/