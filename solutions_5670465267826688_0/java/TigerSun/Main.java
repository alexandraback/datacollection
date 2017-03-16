import java.util.Scanner;

/**
 * FileName: Main.java
 * @Description:
 *
 * @author Xunhu(Tiger) Sun
 *         email: sunx2013@my.fit.edu
 * @date Apr 10, 2015 8:05:22 PM
 */
public class Main {
    final Scanner sc = new Scanner(System.in);

    void read () {
        long l = sc.nextLong();
        x = sc.nextLong();
        sc.nextLine();
        s = sc.nextLine().toCharArray();
    }
    static final int i = 2;
    static final int j = 3;
    static final int k = 4;
    
    
    static int[][] map = new int[5][5];
    static{
        for(int a = 0; a < 5; a++){
            map[a] = new int[5];
        }
        map[1][1] = 1; 
        map[1][i] = i; 
        map[1][j] = j; 
        map[1][k] = k; 
        map[i][1] = i; 
        map[i][i] = -1; 
        map[i][j] = k; 
        map[i][k] = -j; 
        map[j][1] = j; 
        map[j][i] = -k; 
        map[j][j] = -1; 
        map[j][k] = i; 
        map[k][1] = k; 
        map[k][i] = j; 
        map[k][j] = -i; 
        map[k][k] = -1; 
    }
    char[] s;
    long x;
    
    void solve () {
        int need = i;
        int cur = 1;
        for(;x>0;x--){
            for(int si= 0; si < s.length;si++){
                int c = s[si] - ('i'-2);
                if(cur > 0){
                    cur = map[cur][c];
                } else {
                    cur = -map[-cur][c];
                }
                
                if(cur == need){
                    if(need == i){
                        need = k;
                    }else if(need==k){
                        need = -1;
                    } else if(need == -1){
                        need = 0;
                    }
                }
            }
        }
        if(need ==0 && cur ==-1){
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    void run () {
        final int cn = sc.nextInt();
        sc.nextLine();
        for (int ci = 1; ci <= cn; ci++) {
            read();
            System.out.printf("Case #%d: ", ci);
            solve();
        }
    }

    public static void main (String[] args) {
        new Main().run();
    }
}
