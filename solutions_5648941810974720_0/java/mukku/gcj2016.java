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

        Scanner sc =new Scanner(new File("asm.in"));
        File file = new File("ans.txt");
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
    //  sc.useDelimiter("(\\s)+|[,]");
         int T=sc.nextInt();
        sc.nextLine();
        for(int k=1;k<=T;k++){
         int a=0,l,d[]=new int[26];
        char c[]=sc.nextLine().toCharArray();
        l=c.length;

     for( int i=0; i<l; i++ ){
        d[c[i]-'A']++;
     }
    // db(k,d);
     int n[]=new int[10],ac;
     char x;
     n[0]=d['Z'-'A']; ac=d['Z'-'A'];d['Z'-'A']=0;
     d['E'-'A']-=ac;d['R'-'A']-=ac;d['O'-'A']-=ac;
    
     ac=d['W'-'A']; n[2]=ac;d['W'-'A']=0;
     d['T'-'A']-=ac;d['O'-'A']-=ac;
    
     x='U' ;
     ac=d[x-'A']; n[4]=ac;d[x-'A']=0;
     d['F'-'A']-=ac;d['O'-'A']-=ac;
     d['R'-'A']-=ac;
    
     x='X' ;
     ac=d[x-'A']; n[6]=ac;d[x-'A']=0;
     d['S'-'A']-=ac;d['I'-'A']-=ac;
    
     x='G' ;
     ac=d[x-'A']; n[8]=ac;d[x-'A']=0;
     d['E'-'A']-=ac;d['I'-'A']-=ac;
     d['H'-'A']-=ac;d['T'-'A']-=ac;
    
    
     x='O' ;
     ac=d[x-'A']; n[1]=ac;d[x-'A']=0;
     d['E'-'A']-=ac;d['N'-'A']-=ac;
    
     x='F' ;
     ac=d[x-'A']; n[5]=ac;d[x-'A']=0;
     d['I'-'A']-=ac;d['V'-'A']-=ac;
     d['E'-'A']-=ac;

     x='S' ;
     ac=d[x-'A']; n[7]=ac;d[x-'A']=0;
     d['E'-'A']-=ac;d['V'-'A']-=ac;
     d['E'-'A']-=ac;d['N'-'A']-=ac;

     x='T' ;
     n[3]=d[x-'A'];
     x='I';   
     n[9]=d[x-'A'];

     StringBuffer sb=new StringBuffer();

     for( int i=0; i<10; i++ ){
        for( int t=0; t<n[i]; t++ ){
            sb.append(i);
        }
     }

        pw.println("Case #"+k+": "+sb);
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

