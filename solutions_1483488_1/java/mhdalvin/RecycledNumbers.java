
import java.util.HashSet;
import java.util.Scanner;
import java.util.regex.Pattern;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author alvin
 */
public class RecycledNumbers {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int nTC = sc.nextInt();
        for (int tc = 1; tc <= nTC; tc++) {
            int hasil = 0;
            
            int a = sc.nextInt(), b = sc.nextInt();
            
            String batas = Integer.toString(b);
            char maks = batas.charAt(0);
            
            int panjang = batas.length();
            
            for (int n = a; n < b; n++) {
                String s = Integer.toString(n);
                
                if (s.length() == 1) {
                    // System.out.println(s);
                    continue;
                }
                
                if (Pattern.compile("^(.)\\1*$").matcher(s).matches()) {
                    // System.out.println(s);
                    continue;
                }
                
                HashSet<String> sudah = new HashSet<String>();
                for (int i = s.length() - 1; i >= 1; i--) {
                    char c = s.charAt(i);
                    if (c == '0') {
                        continue;
                    }
                    
                    if (c < s.charAt(0)) {
                        continue;
                    }
                    
                    if (c > maks) {
                        continue;
                    }
                    
                    StringBuilder sb = new StringBuilder(panjang);
                    String cek = sb.append(s.substring(i)).append(s.substring(0, i)).toString();
                    
                    if ((cek.compareTo(s) > 0) && (cek.compareTo(batas) <= 0)) {
                        sudah.add(cek);
                    }
                }
                
                hasil += sudah.size();
            }
            
            System.out.format("Case #%d: %d\n", tc, hasil);
        }
    }
    
}
