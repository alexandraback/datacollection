import java.io.*;

/**
 * Created by szeyiu on 5/10/15.
 */
public class C1A {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(new File("C1A.in"))));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("C1A.out"))));
        int T = Integer.valueOf(r.readLine());
        C1A c1A = new C1A();
        for(int i=0; i<T; ++i){
            String line = r.readLine();
            String[] splt = line.split(" ");
            int rr = Integer.valueOf(splt[0]);
            int cc = Integer.valueOf(splt[1]);
            int ww = Integer.valueOf(splt[2]);
            int rst = c1A.solve(cc, ww);
            //System.out.println(rr+"\t"+ww+"\t"+cc);
            rst = rr*rst;
            int c = i+1;
            w.write("Case #" + c + ": " + rst + "\n");
        }
        w.flush();
        w.close();
        r.close();
    }

    public static int solve(int c, int w){
        int div = c/w;
        if(c%w==0){
            //System.out.println(div);
            return div+w-1;
        }
        else {
            return div+w;
        }
    }
}
