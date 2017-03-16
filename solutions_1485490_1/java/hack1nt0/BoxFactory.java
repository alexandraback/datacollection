import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.Vector;

/**
 * Created with IntelliJ IDEA.
 * User: DaiYang
 * Date: 12-5-6
 * Time: 下午6:29
 * To change this template use File | Settings | File Templates.
 */
public class BoxFactory {
    static long[] boxN=new long[100];
        static long[] toyN=new long[100];
        static int[] boxT=new int[100];
        static int[] toyT=new int[100];
        static long res;
    static int N;
    static int M;
    static class Record{
        int i,j;
        long in,jn;

        Record(int i, int j, long in, long jn) {
            this.i = i;
            this.j = j;
            this.in = in;
            this.jn = jn;
        }
//        @Override
//        public boolean equals(Object obj) {
//            Record other = (Record)obj;
//            return i==other.i&&j==other.j&&in==other.in&&jn==other.jn;    //To change body of overridden methods use File | Settings | File Templates.
//        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Record record = (Record) o;

            if (i != record.i) return false;
            if (in != record.in) return false;
            if (j != record.j) return false;
            if (jn != record.jn) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = i;
            result = 31 * result + j;
            result = 31 * result + (int) (in ^ (in >>> 32));
            result = 31 * result + (int) (jn ^ (jn >>> 32));
            return result;
        }
    }
    static HashMap<Record, Long> map;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("test.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("module\\src\\test.out")));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int T = Integer.parseInt(st.nextToken());
        map = new HashMap<Record, Long>();

        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(f.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(f.readLine());

            for (int i = 0; i < N; i++) {
                boxN[i]=Long.parseLong(st.nextToken());
                boxT[i]=Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(f.readLine());
            for (int i = 0; i < M; i++) {
                toyN[i]=Long.parseLong(st.nextToken());
                toyT[i]=Integer.parseInt(st.nextToken());
            }
//            res=0;
            map.clear();
            res=dfs(0,0);
            out.println("Case #"+t+": "+res);
        }
        out.close();
        System.exit(0);
    }

    private static long dfs(int i, int j){
        if(i>=N||j>=M) return 0;
        Record nr=new Record(i,j, boxN[i], toyN[j]);
        if(map.containsKey(nr))
            return map.get(nr);

        long res=0;
        if(boxT[i]==toyT[j]){
            if(boxN[i]>toyN[j]){
                boxN[i]-=toyN[j];
                res=Math.max(res, toyN[j]+dfs(i, j+1));
                boxN[i]+=toyN[j];
            }
            else if(boxN[i]<toyN[j]){
                toyN[j]-=boxN[i];
                res=Math.max(res, boxN[i]+dfs(i+1, j));
                toyN[j]+=boxN[i];
            }
            else{
                res=Math.max(res, boxN[i]+dfs(i+1, j+1));
            }
        }
        else{
            res=Math.max(res, dfs(i+1,j));
            res=Math.max(res, dfs(i,j+1));
        }
        map.put(nr, res);
        return res;
    }

}
