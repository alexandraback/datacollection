import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by szeyiu on 5/2/15.
 */
public class A2C {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(new File("A2C.in"))));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("A2C.out"))));
        int T = Integer.valueOf(r.readLine());
        A2C a2C = new A2C();
        for(int i=0; i<T; ++i){
            int g = Integer.valueOf(r.readLine());
            List<Integer> poslst = new ArrayList<Integer>();
            List<Integer> mlst = new ArrayList<Integer>();
            for(int j=0; j<g; ++j){
                String line = r.readLine();
                String[] splt =line.split(" ");
                poslst.add(Integer.valueOf(splt[0]));
                mlst.add(Integer.valueOf(splt[2]));
                if(!splt[1].equals("1")){
                    poslst.add(Integer.valueOf(splt[0]));
                    mlst.add(Integer.valueOf(splt[2])+1);
                }
            }
            int rst = a2C.twoHikers(poslst.get(0),mlst.get(0), poslst.get(1),mlst.get(1));
            int c = i+1;
            w.write("Case #" + c + ": " + rst + "\n");
        }
        w.flush();
        w.close();
        r.close();
    }

    public int twoHikers(int pos1, int m1, int pos2, int m2){
        int all = 360;
        double f1 = 1.0*m1*(all-pos1)/all;
        double f2 = 1.0*m2*(all-pos2)/all;
        //System.out.println(f1+"  "+m1+"  "+ f2 + "  "+m2);
        if(f1+m1<=f2 || f2+m2<=f1){
            return 1;
        } else {
            return 0;
        }
    }
}
