import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.ObjectInputStream.GetField;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;





public class Gcj1a {
    
    
    static int solve(int startMote, List<Integer> otherMotes) {
        
        Collections.sort(otherMotes);
        
        int ownMote = startMote;
        
        int next = 0;
        int created = 0;
        int minChange = otherMotes.size();
        
        while (next<otherMotes.size()
                && created < minChange)
        {
            if (ownMote > otherMotes.get(next)) {
                ownMote += otherMotes.get(next);
                ++next;
            } else {
                ownMote += (ownMote-1);
                ++created;
            }
            
            if (created + (otherMotes.size()-next) < minChange) {
                minChange = created + (otherMotes.size()-next);
            }
        }
        
        return minChange;
    }
    
    
    public static void main(String[] args) {
        
        try {
            Scanner scanner = new Scanner(new File(args[0]));
            BufferedWriter writer = new BufferedWriter(new FileWriter(args[1]));
            
            int T = scanner.nextInt();
            for (int k=0;k<T;++k) {
                
                int A = scanner.nextInt();
                int N = scanner.nextInt();
                
                ArrayList<Integer> others = new ArrayList<Integer>(N);
                for (int i=0;i<N;++i) {
                    others.add(scanner.nextInt());
                }
                
                writer.write("Case #"+(k+1)+": "+solve(A,others)+"\n");
            }
            scanner.close();
            writer.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
