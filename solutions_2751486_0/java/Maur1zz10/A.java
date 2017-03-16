import java.io.*;
import java.util.*;


public class A {
    static final String filename = "A";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        A solver = new A();
        solver.solve(s, w);
        w.close();
    }

    String name;
    int N;
    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            name=s.next();
            N=s.nextInt();

            String ans=solve();

            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";

            w.write(out);
            System.out.print(out);
        }
    }

    String solve(){
        int ans=0;
        for(int a=0;a<name.length();a++){
            for(int b=a+N;b<=name.length();b++){
                int cnt=0;
                boolean ok=false;
                int c;
                for(c=a;c<b;c++){
                    if(name.charAt(c)=='a'||name.charAt(c)=='e'||name.charAt(c)=='i'||name.charAt(c)=='o'||name.charAt(c)=='u'){
                        cnt=0;
                    }
                    else
                        cnt++;
                    if(cnt>=N){
                        ok=true;
                        break;
                    }
                }
                if(ok){
                    ans+=name.length()-(c);
                    break;
                }
            }
        }
        return ans+"";
    }

}