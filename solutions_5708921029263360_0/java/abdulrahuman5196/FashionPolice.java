
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author ABDULRAHUMAN
 */
public class FashionPolice {
    static class node{
        int i,j,k;
        node(int a,int b,int c){
            i=a;
            j=b;
            k=c;
        }
    }
   public static void main(String args[]) throws FileNotFoundException, IOException{
       //Scanner in=new Scanner(System.in);
       Scanner in=new Scanner(new FileReader("E:\\c.in"));
       PrintWriter out=new PrintWriter(new FileWriter("E:\\c.out"));
       int t=in.nextInt();
       for(int z=1;z<=t;z++){
           int jj=in.nextInt();
           int pp=in.nextInt();
           int ss=in.nextInt();
           int kk=in.nextInt();
           int fact=pp*ss*kk;
           System.out.println(jj+" "+pp+" "+ss+" "+kk);
           ArrayList<node> arr=new ArrayList<>();
           
           for(int k=1;k<=jj;k++){
               for(int l=1;l<=pp;l++){
                   for(int m=1;m<=ss;m++){
                       //System.out.println(k+" "+l+" "+m);
                       arr.add(new node(k,l,m));
                   }
               }
           }
           ArrayList<node> temp=new ArrayList<node>(arr);
           for(int i=0;i<temp.size();i++){
               int count=1;
               for(int j=i+1;j<temp.size();j++){
                   node n1=temp.get(i);
                   node n2=temp.get(j);
                   if(n1.i==n2.i&&n1.j==n2.j){
                       count++;
                       if(count>kk){
                           temp.remove(n2);
                           j--;
                       }
                   }
               }
               count=1;
               for(int j=i+1;j<temp.size();j++){
                   node n1=temp.get(i);
                   node n2=temp.get(j);
                   if(n1.k==n2.k&&n1.j==n2.j){
                       count++;
                       if(count>kk){
                           temp.remove(n2);
                           j--;
                       }
                   }
               }
               count=1;
               for(int j=i+1;j<temp.size();j++){
                   node n1=temp.get(i);
                   node n2=temp.get(j);
                   if(n1.k==n2.k&&n1.i==n2.i){
                       count++;
                       if(count>kk){
                           temp.remove(n2);
                           j--;
                       }
                   }
               }
           }
           
           System.out.println("Case #"+z+": "+temp.size());
           out.println("Case #"+z+": "+temp.size());
           
          for(int i=0;i<temp.size();i++){
              node n=temp.get(i);
              System.out.println(n.i+" "+n.j+" "+n.k);
              out.println(n.i+" "+n.j+" "+n.k);
          }
       }
       out.close();
   }   
}
