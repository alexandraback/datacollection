
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author alvin
 */
public class DancingWithTheGooglers implements Comparable<DancingWithTheGooglers> {
    
    public int a, b, c;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int nTC = sc.nextInt();
        for (int tc = 1; tc <= nTC; tc++) {
            int n = sc.nextInt();
            int s = sc.nextInt();
            int p = sc.nextInt();
            
            DancingWithTheGooglers skor[] = new DancingWithTheGooglers[n];
            for (int i = 0; i < n; i++) {
                skor[i] = new DancingWithTheGooglers(sc.nextInt());
            }
            
            Arrays.sort(skor);
            
            int hasil = 0;
            for (int i = 0; i < n; i++) {
                if (skor[i].a >= p || skor[i].b >= p || skor[i].c >= p) {
                    ++hasil;
                } else if (s > 0) {
                    if ((skor[i].a == skor[i].b) && (skor[i].a + 1 >= p) && (skor[i].b - 1 >= 0)) {
                        ++hasil;
                        --s;
                    } else if ((skor[i].b == skor[i].c) && (skor[i].b + 1 >= p) && (skor[i].c - 1 >= 0)) {
                        ++hasil;
                        --s;
                    }
                }
            }
            
            System.out.format("Case #%d: %d\n", tc, hasil);
        }
    }

    public DancingWithTheGooglers(int skor) {
        a = skor / 3;
        b = skor / 3;
        c = skor / 3;
        
        int sisa = skor - (a + b + c);
        if (sisa == 1) {
            ++a;
        } else if (sisa == 2) {
            ++a; ++b;
        }
    }

    @Override
    public int compareTo(DancingWithTheGooglers o) {
        if (a != o.a) {
            return (o.a - a);
        } else if (b != o.b) {
            return (o.b - b);
        } else if (c != o.c) {
            return (o.c - c);
        } else {
            return 0;
        }
    }
    
}

