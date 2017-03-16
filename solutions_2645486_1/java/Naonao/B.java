import java.util.*;
public class B {
    public static void main(String[]args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int caseNum = 1; caseNum <= T; caseNum++) {
            int e = in.nextInt();
            int r = in.nextInt();
            int n = in.nextInt();
            //System.err.println(e + " " + r + " " +n);
            int[] vals = new int[n];
            for(int i = 0 ; i <vals.length; i++){
                vals[i] = in.nextInt();
            }
            //System.err.println(Arrays.toString(vals));
            long ret = 0;
            int[] best = new int[n];
            Stack<Integer> s = new Stack<Integer>();
            s.push(0);
            for(int i = 1; i < n; i++){
                if(vals[i] > vals[i-1]){
                    while(!s.empty() && vals[s.peek()] <= vals[i]){
                        best[s.pop()] = i;
                    }
                }
                s.push(i);
            }

            long[] curs = new long[n];
            int[] eng = new int[n];
            int cur = e;
            for(int i = 0; i < n; i++){
                //System.out.println(cur + " "+ ret);
                cur = Math.min(cur + r, e);
                if(best[i] ==0 ){
                    ret += 1l *cur * vals[i];
                    cur = 0;
                } else {
                    ret += 1l * Math.min(cur , Math.max(0, cur + (best[i] - i)*r - e)) * vals[i];
                    cur -= Math.min(cur , Math.max(0, cur + (best[i] - i)*r - e));
                }
                curs[i] = ret;
                eng[i] = cur;
            }
            //System.err.println(Arrays.toString(curs));
            //System.err.println(Arrays.toString(eng));
            //System.err.println(Arrays.toString(best));
            System.out.printf("Case #%d: %d\n", caseNum, ret);
        }
    }
}