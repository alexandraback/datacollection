import java.util.*;

public class C {
	public static void main (String [] args) {
				
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		int[] old = new int[7];
        
        
		for (int t = 1; t <= T; t++) {
			int A = s.nextInt();
            int B = s.nextInt();
			int ans = 0;
            
            for (int n = A; n < B; n++) {
                int time = 0;
                int d = 10;
                while (n >= d) {
                    time++;
                    d *= 10;
                }
                
                int oldSize = 0;
                for (int i = 0; i < time; i++) {
                    int m = movingFront(n, i, time - i);                    
                    if (m > n && m <= B) {
                        boolean unique = true;
                        for (int k = 0; k < oldSize; k++) {
                            if (old[k] == m) {
                                unique = false;
                                break;
                            }
                        }
                        if (unique) {
                            ans++;
                            old[oldSize++] = m;
                        }
                    }
                    
                }
            }
            
			System.out.println("Case #" + t + ": "+ans);
		}
	}
    
    public static int movingFront(int n, int index, int postMult) {
        int front = 0;
        int mult = 1;
        while (index-- >= 0) {
            front += ((n % 10) * mult);
            n /= 10;
            mult *= 10;
        }
        int frontMult = 1;
        while (postMult-- > 0) {
            frontMult *= 10;
        }
        return (front * frontMult) + n;
    }
}