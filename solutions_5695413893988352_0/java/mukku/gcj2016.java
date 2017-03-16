import java.util.*;
import java.io.*;
import java.math.*;


import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;


public class gcj2016{ 



public  static void main(String[] args)   throws Exception, IOException{

    
//    Reader sc = new Reader(System.in);
  //  PrintWriter out=new PrintWriter(System.out);

        Scanner sc =new Scanner(new File("bs.in"));
        File file = new File("ans.txt");
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
    //  sc.useDelimiter("(\\s)+|[,]");
         int T=sc.nextInt();
        sc.nextLine();

        String e[][]=new String[3][];
        e[0]=new String[10];
        for( int i=0; i<10; i++ ){
            e[0][i]=""+i;
        }
        e[1]=new String[100];
        for( int i=0; i<100; i++ ){
            e[1][i]=String.format("%1$02d", i);
        }
         e[2]=new String[1000];
        for( int i=0; i<1000; i++ ){
            e[2][i]=String.format("%1$03d", i);
        }

   int te[]={10,100,1000};
  
        for(int k=1;k<=T;k++){
      
        String s[]=sc.nextLine().split(" ");
        int l=s[1].length()-1;
//        db(s,l);
        String as[]=new String[2]; int mx=100000;

  lp:  for( int i=0; i<te[l]; i++ ){

            for( int v=0; v<l+1; v++ ){
                if(s[0].charAt(v)=='?')continue ;
                if( s[0].charAt(v)!=e[l][i].charAt(v) )continue lp;
            }

pl:        for( int t=0; t<te[l]; t++ ){

  for( int v=0; v<l+1; v++ ){
                if(s[1].charAt(v)=='?')continue;
                if( s[1].charAt(v)!=e[l][t].charAt(v) )continue pl;
            }
        int aa=Integer.parseInt(e[l][i]);
        int bb=Integer.parseInt(e[l][t]);
       if(abs(aa-bb)<mx){ as[0]=e[l][i];as[1]=e[l][t];
        mx=abs(aa-bb);}     

        }


    }

        pw.println("Case #"+k+": "+as[0]+" "+as[1]);
    }

        pw.flush();
        pw.close();  
    //out.println();
   // out.flush();

}




static void db(Object... os){

    System.err.println(Arrays.deepToString(os));

}

static boolean validpos(int x,int y,int r, int c){
    
    return x<r && 0<=x && y<c && 0<=y;
    
}
 
static boolean bit(long x,int k){
    // weather k-th bit (from right) be one or zero
    return  ( 0 < ( (x>>k) & 1 )  )  ? true:false;
}

}



class Reader
{ 
    private BufferedReader x;
    private StringTokenizer st;
    
    public Reader(InputStream in)
    {
        x = new BufferedReader(new InputStreamReader(in));
        st = null;
    }
    public String nextString() throws IOException
    {
        while( st==null || !st.hasMoreTokens() )
            st = new StringTokenizer(x.readLine());
        return st.nextToken();
    }
    public int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    public long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
    }
    public double nextDouble() throws IOException
    {
        return Double.parseDouble(nextString());
    }
}

