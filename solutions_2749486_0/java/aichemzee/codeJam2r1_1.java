import java.util.*;
import java.io.*;
import java.math.*;
class codeJam2r1_1
{
    public static void main(String []args)throws IOException{
        FileInputStream fstream = new FileInputStream("input.txt");
        DataInputStream in = new DataInputStream(fstream);
        BufferedReader x1 = new BufferedReader(new InputStreamReader(in));
        FileOutputStream out = new FileOutputStream(new File("output.txt"));
        int t1=Integer.parseInt(x1.readLine());
        //double e=0.01;
        for(int u=1;u<=t1;u++){
            String p[]=x1.readLine().split(" ");
            int x=Integer.parseInt(p[0]);
            int y=Integer.parseInt(p[1]);
            int jump=1;
            int xs=0;
            int ys=0;
            String ans="";
            if(x>0){
                while(xs+jump<=x){
                    xs+=jump;
                    jump++;
                    ans+="E";
                }
                if(xs<x){
                    while(xs<x){
                        ans+="WE";
                        xs++;
                        jump=jump+2;
                    }
                }
            }
            else{
                x=-x;
                while(xs+jump<=x){
                    xs+=jump;
                    jump++;
                    ans+="W";
                
                }
                if(xs<x){
                    while(xs<x){
                        ans+="EW";
                        xs++;
                        jump=jump+2;
                    }
                }
            }
            if(y>0){
                int todo=y;
                while(todo>0){
                todo--;
                ans+="SN";
                }
            }
            else{
                int todo=-y;
                while(todo>0){
                todo--;
                ans+="NS";
                }
            
            }
            
            String ans1="Case #"+u+": "+ans+"\n";
            byte s[]=ans1.getBytes();
            out.write(s);
            //System.out.println();
            //x.readLine();
        }
        out.close();
        //in.close();
}
/*static long compute(ArrayList<Long> arr,long turns,long start){
int i=0;
    while(arr.get(i)<start) start+=arr.get(i++);
    if(arr.get(i)/start>=arr.size()-i){return (turns+arr.size()-i);}
    

}*/
 public static BigInteger sqrt(BigInteger n) {
    BigInteger a = BigInteger.ONE;
    BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
    while(b.compareTo(a) >= 0) {
      BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
      if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
      else a = mid.add(BigInteger.ONE);
    }
    return a.subtract(BigInteger.ONE);
  }
static boolean todo(boolean b[][]){
int n=b.length;
int m=b[0].length;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!b[i][j]) return true;
    }
}
//return false;
return false;
}
static boolean rowg(int b[][],int x,int min){
int m=b[0].length;
//System.out.println("*******ROWG********       "+m);
for(int i=0;i<m;i++){
if(b[x][i]>min) return false;
//System.out.print(b[x][i]+"    ");
}
//System.out.println("***************");
return true;
}
static boolean colg(int b[][],int y,int min){
int n=b.length;
//System.out.println("*******COLG********           "+n);
for(int i=0;i<n;i++){
if(b[i][y]>min) return false;
//System.out.print(b[i][y]+"    ");
}
//System.out.println("***************");
return true;
}
}
class pair{
int x;int y;
pair(){x=0;y=0;}
pair(int a,int b){x=a;y=b;}

}