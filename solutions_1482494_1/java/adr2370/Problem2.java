import java.io.*;
import java.util.*;
class Problem2
{
    public static void main (String [] args) throws Exception 
    {
        BufferedReader f = new BufferedReader(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.java")));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int T=Integer.parseInt(st.nextToken());
        for(int t=0;t<T;t++) {
            st=new StringTokenizer(f.readLine());
            int N=Integer.parseInt(st.nextToken());
            int[] a=new int[N];
            int[] b=new int[N];
            for(int i=0;i<N;i++) {
                st=new StringTokenizer(f.readLine());
                a[i]=Integer.parseInt(st.nextToken());
                b[i]=Integer.parseInt(st.nextToken());
            }
            int currStars=0;
            boolean anyChanged=true;
            boolean[] firstStars=new boolean[N];
            boolean[] secondStars=new boolean[N];
            int count=0;
            while(currStars<2*N&&anyChanged) {
                anyChanged=false;
                for(int i=0;i<N;i++) {
                    if(currStars>=b[i]&&!secondStars[i]) {
                        if(firstStars[i])
                            currStars++;
                        else
                            currStars+=2;
                        firstStars[i]=true;
                        secondStars[i]=true;
                        anyChanged=true;
                        count++;
                    }
                }
                int indexMax=-1;
                for(int i=0;!anyChanged&&i<N;i++) {
                    if(currStars>=a[i]&&!firstStars[i]) {
                        if(indexMax==-1) {
                            indexMax=i;
                        } else {
                            if(b[i]>b[indexMax]) {
                                indexMax=i;
                            }
                        }
                    }
                }
                if(indexMax!=-1) {
                    currStars++;
                    firstStars[indexMax]=true;
                    anyChanged=true;
                    count++;
                }
            }
            String ans;
            if(currStars!=2*N)
                ans="Too Bad";
            else
                ans=count+"";
            out.println("Case #"+(t+1)+": "+ans);
        }
        out.close();
        System.exit(0);
    }
}