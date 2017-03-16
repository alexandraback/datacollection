import java.util.*;
import java.io.*;
import java.math.*;
class codeJam2r2
{
    public static void main(String []args)throws IOException{
        FileInputStream fstream = new FileInputStream("input.txt");
        DataInputStream in = new DataInputStream(fstream);
        BufferedReader x = new BufferedReader(new InputStreamReader(in));
        FileOutputStream out = new FileOutputStream(new File("output.txt"));
        int t1=Integer.parseInt(x.readLine());
        //double e=0.01;
        for(int u=1;u<=t1;u++){
            String p[]=x.readLine().split(" ");
            int e=Integer.parseInt(p[0]);
            int r=Integer.parseInt(p[1]);
            int n=Integer.parseInt(p[2]);
            int arr[]=new int[n];
            String p1[]=x.readLine().split(" ");
            for(int i=0;i<n;i++){arr[i]=Integer.parseInt(p1[i]);}
            //System.out.println(val+"            "+rt);
           //Arrays.sort(arr);
           long w[]=new long[n];
           Arrays.fill(w,1);
           if(r>e) r=e;
           long sum=0;
           sum+=arr[n-1]*e;
           e=r;
           for(int i=n-2;i>=0;i--){sum=sum+arr[i]*e;}
            String ans="Case #"+u+": "+sum+"\n";
            byte s[]=ans.getBytes();
            out.write(s);
            //System.out.println();
            //x.readLine();
        }
        out.close();
        //in.close();
}
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