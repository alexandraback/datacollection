import java.util.*;
import java.io.*;
public class Gcj {
    private int num_case;
    private BufferedReader buff;
    private int r, t;

    Gcj(){
        buff=new BufferedReader(new InputStreamReader(System.in));
        try{
            num_case=Integer.parseInt(buff.readLine());
        }
        catch(Exception e){
            System.err.println(e);
        }
        // System.out.println(T);
    }

    private void read_args(){
        String line;
        String[] str;
        try{
            line=buff.readLine();
            str=line.split(" ");
            r=Integer.parseInt(str[0]);
            t=Integer.parseInt(str[1]);
            System.err.println("");
            System.err.println("r="+r+", "+"t="+t);
        }
        catch(Exception e){
            System.err.println(e);
        }
        return;
    }

    private int paint_volume(int r, int n){
        return 2*n*n+(2*r-1)*n;
    }

    private void solve(){
        int res=0;
        for(int i=1; i<1000; i++){
            if(paint_volume(r, i) <= t) res=i;
            else break;
        }
        System.out.println(res);
        return;
    }

    public int get_num_case(){
        return num_case;
    }

    public void run(int case_num){
        System.out.print(String.format("Case #%d: ", case_num+1));
        read_args();
        solve();
        //        System.out.println(Arrays.toString(input));
        return;
    }

    public static final void main(final String[] args) {
        Gcj gcj_instance=new Gcj();

        int num_case=gcj_instance.get_num_case();
        for(int i=0; i<num_case; i++)
            gcj_instance.run(i);

        return;
    }
}
