import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class B {
    
    static class P {
        public P(int x, int y,int step) {
            this.x = x;
            this.y = y;
            this.step = step;
        }
        int x;
        int y;
        int step ;
        String road = "";
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + x;
            result = prime * result + y;
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            P other = (P)obj;
            if (x != other.x)
                return false;
            if (y != other.y)
                return false;
            return true;
        }
        
    }
   
    
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("pogo.txt"));
            int num = in.nextInt();
            for(int z = 1; z <= num; z++) {
                int x = in.nextInt();
                int y = in.nextInt();
                Set<P> set = new HashSet<P>();

                P p0 = new P(0,0,0);
                set.add(p0);
                String road = null;
                while(true) {
                    Set<P> tmpSet  = new HashSet<P>();
                    for(P p : set) {
                        // n
                        P tmp = new P(p.x,p.y+p.step+1,p.step+1);
                        tmp.road = p.road+"N";
                        tmpSet.add(tmp);
                        
                        // s 
                        tmp = new P(p.x,p.y-p.step-1,p.step+1);
                        tmp.road = p.road+"S";
                        tmpSet.add(tmp);
                        // w
                        tmp = new P(p.x-p.step-1,p.y,p.step+1);
                        tmp.road = p.road+"W";
                        tmpSet.add(tmp);
                        // e
                        tmp = new P(p.x+p.step+1,p.y,p.step+1);
                        tmp.road = p.road+"E";
                        tmpSet.add(tmp);
                    }
                    
                    // check
                    for(P p : tmpSet) {
                        if(p.x == x && p.y == y) {
                            road = p.road;
                            break;
                        }
                    }
                    
                    set.addAll(tmpSet);
                    
                    if( road != null) {
                        break;
                    }
                }
                
                System.out.println(String.format("Case #%d: %s",z,road));
                
            }
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
