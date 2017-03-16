
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Igor
 */
public class BPogoSmall {
    
    // N, S, E, W
    static int dx[] = new int[]{0, 0, 1, -1};
    static int dy[] = new int[]{1, -1, 0, 0};
    static char sides[] = new char[]{'N', 'S', 'E', 'W'};
    static int REF = 200;
    
    static String encode(int x, int y) {
        return Integer.toString(x)+" "+Integer.toString(y);
    }
    
    static String solve(int x, int y) {
        int i,j,k;
        int nx,ny,ns;
        int px,py,ps,prx,pry;
        Character tmpc;
        
        HashMap<String, Character> hmprev = new HashMap<String, Character>();
        HashMap<String, Integer> hmprevx = new HashMap<String, Integer>();
        HashMap<String, Integer> hmprevy = new HashMap<String, Integer>();
        
        Queue<Integer> qx = new LinkedList<Integer>();
        Queue<Integer> qy = new LinkedList<Integer>();
        Queue<Integer> qs = new LinkedList<Integer>();
        
        hmprev.put(encode(0, 0), '#');
        qx.add(0);
        qy.add(0);
        qs.add(1);
        hmprevx.put(encode(0, 0), -1);
        hmprevy.put(encode(0, 0), -1);
        
        while (true) {
            px = qx.poll();
            py = qy.poll();
            ps = qs.poll();
            
            for (k=0;k<4;k++) {
                nx = px + ps * dx[k];
                ny = py + ps * dy[k];
                ns = ps + 1;
                
                tmpc = hmprev.get(encode(nx, ny));
                
                if ((tmpc == null)||(tmpc == 0)) {
                    hmprev.put(encode(nx, ny), sides[k]);
                    qx.add(nx);
                    qy.add(ny);
                    qs.add(ns);
                    hmprevx.put(encode(nx, ny), px);
                    hmprevy.put(encode(nx, ny), py);
                    
                    if ((nx == x)&&(ny == y)) {
                        // we have found the solution
                        
                        StringBuilder sb = new StringBuilder();
                        char tmp = hmprev.get(encode(nx, ny));
                        
                        while (tmp != '#') {
                            //System.out.println(nx+" "+ny+" "+prev[REF+nx][REF+ny]);
                            sb.append(hmprev.get(encode(nx, ny)));
                            px = hmprevx.get(encode(nx, ny));
                            py = hmprevy.get(encode(nx, ny));
                            nx = px;
                            ny = py;
                            tmp = hmprev.get(encode(nx, ny));
                        }
                        
                        sb = sb.reverse();
                        return sb.toString();
                    }
                    
                }
                
            }
            
        }
        
    }
    
    public static void main(String[] args) throws Exception {
        int i, j, k;
        int x, y;
        
        BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("B-small-attempt0.out"));
        
        int T = Integer.parseInt(br.readLine());
        
        for (k=1;k<=T;k++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            
            String res = solve(x, y);
            
            System.out.println(check(res, x, y));
            out.println("Case #"+k+": "+res);
        }
        
        out.close();
        
    }
    
    static boolean check(String s, int x, int y) {
        int i,j,k;
        int px = 0, py = 0;
        int step = 1;
        
        for (i=0;i<s.length();i++) {
            if (s.charAt(i) == 'N') {
                py += step;
            } else if (s.charAt(i) == 'S') {
                py -= step;
            } else if (s.charAt(i) == 'E') {
                px += step;
            } else if (s.charAt(i) == 'W') {
                px -= step;
            }
            step++;
        }
        
        if ((px == x)&&(py == y)) {
            return true;
        }
        
        return false;
    }
    
}
