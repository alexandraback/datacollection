import java.util.*;

public class B{
    int a, b;
    boolean passA, passB;
    public B (int a, int b) {
        passA = passB = false;
        this.a = a;
        this.b = b;
    }
        
	public static void main (String [] args) {
				
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();    
		
		for (int t = 1; t <= T; t++) {
			int N = s.nextInt();
            B[] list = new B[N];
            
            for (int i = 0; i < N; i++) {
                list[i] = new B(s.nextInt(), s.nextInt());
            }
            
            
            int ans = 0;
            int star = 0;
                        
            while (star < 2*N) {
                int bestI = -1;
                for (int i = 0; i < N; i++) {
                    if (!list[i].passB && !list[i].passA && list[i].b <= star) {
                        bestI = i;
                        ans++;
                        star += 2;
                        list[i].passB = true;
                        list[i].passA = true;
                        break;
                    }
                }
                
                if (bestI >= 0)
                    continue;
                
                for (int i = 0; i < N; i++) {
                    //if (!list[i].passB && list[i].passA && list[i].b <= star) {
                    if (!list[i].passB && list[i].passA && list[i].b <= star) {
                        bestI = i;
                        ans++;
                        star++;
                        list[i].passB = true;
                        list[i].passA = true;
                        break;
                    }
                }
                
                if (bestI >= 0)
                    continue;
                
                int maxB = 0;
                for (int i = 0; i < N; i++) {
                    if (!list[i].passA && list[i].a <= star && list[i].b > maxB) {
                        maxB = list[i].b;                        
                        bestI = i;
                    }
                }
                    
                if (bestI < 0)
                    break;
                else {
                    ans++;
                    star++;
                    list[bestI].passA = true;
                }                
            }
            
            if (star < 2*N) {
                System.out.println("Case #" + t + ": " + "Too Bad");
            } else {
                System.out.println("Case #" + t + ": " + ans);                
            }
		}
	}
}