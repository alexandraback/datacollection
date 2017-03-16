import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;



public class Problem1 {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("data/A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new File("data/A-small-attempt0.out"));
        
        int T = sc.nextInt();
        
        for(int tc=1;tc<=T;tc++){
            String s = sc.next();
            int[] f = new int[256];
            for(int i=0;i<s.length();i++){
                f[s.charAt(i)]++;
            }
            pw.println("Case #" + tc + ": " + calc(f));
        }
        
        pw.close();
    }
    
    static String calc(int[] f){
        StringBuilder sb = new StringBuilder();
        int[] r = new int[10];
        r[0] = f['Z'];
        f['E'] -= r[0];
        f['R'] -= r[0];
        f['O'] -= r[0];
        
        r[2] = f['W'];
        f['T'] -= r[2];
        f['O'] -= r[2];
        
        r[6] = f['X'];
        f['S'] -= r[6];
        f['I'] -= r[6];
        
        r[7] = f['S'];
        f['E'] -= 2*r[7];
        f['V'] -= r[7];
        f['N'] -= r[7];
        
        r[5] = f['V'];
        f['F'] -= r[5];
        f['I'] -= r[5];
        f['E'] -= r[5];
        
        r[8] = f['G'];
        f['E'] -= r[8];
        f['I'] -= r[8];
        f['H'] -= r[8];
        f['T'] -= r[8];
        
        r[9] = f['I'];
        f['N'] -= 2*r[9];
        f['E'] -= r[9];
        
        r[4] = f['F'];
        f['O'] -= r[4];
        f['U'] -= r[4];
        f['R'] -= r[4];
        
        r[3] = f['T'];
        f['H'] -= r[3];
        f['R'] -= r[3];
        f['E'] -= 2*r[3];
        
        r[1] = f['N'];
        
        for(int i=0;i<=9;i++){
            for(int j=0;j<r[i];j++){
                sb.append(i);
            }
        }
        
        return sb.toString();
    }
}
