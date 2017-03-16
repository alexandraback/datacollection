import java.io.*;
import java.util.*;
class Problem2
{
    public static void main (String [] args) throws Exception 
    {
        BufferedReader f = new BufferedReader(new FileReader("input.java"));
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
            ArrayList<String> possible=new ArrayList<String>();
            for(int i=0;i<Math.pow(2,N);i++) {
                String curr=Integer.toBinaryString(i);
                while(curr.length()<N) curr="0"+curr;
                possible.add(curr);
            }
            int result=-1;
            while(possible.size()>0) {
                String curr=possible.remove(0);
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
                        } else if(currStars>=a[i]&&!firstStars[i]&&curr.charAt(i)=='1') {
                            currStars++;
                            firstStars[i]=true;
                            anyChanged=true;
                            count++;
                        }
                    }
                }
                if(currStars==2*N) {
                    if(result==-1) result=count;
                    else result=Math.min(result,count);
                }
            }
            String ans;
            if(result==-1)
                ans="Too Bad";
            else
                ans=result+"";
            out.println("Case #"+(t+1)+": "+ans);
        }
        out.close();
        System.exit(0);
    }
}