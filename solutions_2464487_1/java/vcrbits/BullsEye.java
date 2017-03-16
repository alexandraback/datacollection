import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

/**
 *
 * @author Vikash
 */
public class BullsEye {

    /**
     * @param args the command line arguments
     */
    static BufferedWriter bw;
    static BufferedReader br;
    static String inputFile = "C:\\Users\\Aakash\\Documents\\NetBeansProjects\\practice\\src\\A-large.in" ;
    static String outputFile = "C:\\Users\\Aakash\\Documents\\NetBeansProjects\\practice\\src\\outlarge.txt";
    
    public static void main(String[] args)throws IOException {
        init(); 
        processInput();
        fin();
    }
    
    public static void fin() throws IOException {
        if (br != null) {
            br.close();
        }
        bw.close();
    }
    
    public static void processInput() throws IOException {
        int n = Integer.parseInt(br.readLine());
        BigInteger two = new BigInteger("2");
        for (int i = 1; i <= n; i++) {
            String str = br.readLine();
            BigInteger r = new BigInteger(str.split(" ")[0]);
            BigInteger t = new BigInteger(str.split(" ")[1]);
            BigInteger k = new BigInteger("1");
            BigInteger tmp = (two.multiply(r).multiply(k)).add(two.multiply(k).multiply(k)).subtract(k);
            if (tmp.compareTo(t) > 0){
                bw.write("Case #" + i + ": " + i);
                bw.write("\n");
                continue;
            }
            while ( tmp.compareTo(t) <= 0){
                k = k.multiply(two);
                tmp = (two.multiply(r).multiply(k)).add(two.multiply(k).multiply(k)).subtract(k);
            }
            bw.write("Case #" + i + ": " + search(BigInteger.ZERO,k,t,r));
            bw.write("\n");
        }
    }
    
    public static BigInteger search(BigInteger l,BigInteger h,BigInteger t,BigInteger r){
        BigInteger two = new BigInteger("2");
        BigInteger m = (l.add(h)).divide(two);
        BigInteger tmp = (two.multiply(r).multiply(m)).add(two.multiply(m).multiply(m)).subtract(m);
        if(h.compareTo(l)<0) {
            return new BigInteger("-1");
        }
            
        if (tmp.compareTo(t) <= 0){
            BigInteger p = search(m.add(BigInteger.ONE),h,t,r);
            if (p.compareTo(new BigInteger("-1")) == 0) {
                return m;
            }
            else {
                return p;
            }
        }
        else {
            return search(l,m.subtract(new BigInteger("1")),t,r);
        }
    }
    
    public static void init() throws IOException {
        br = new BufferedReader(new FileReader(inputFile));
        File file = new File(outputFile);
        if (!file.exists()) {
            file.createNewFile();
        }
        FileWriter fw = new FileWriter(file.getAbsoluteFile());
        bw = new BufferedWriter(fw);
    }
}