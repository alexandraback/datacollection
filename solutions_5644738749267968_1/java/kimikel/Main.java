
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Main {
    
    public static void main(String args[]) throws FileNotFoundException {
        
        final Scanner in = new Scanner(new File("/home/mikel/Desktop/codejam/input.txt"));
        final PrintWriter out = new PrintWriter(new File("/home/mikel/Desktop/codejam/output.txt"));
        
        final int t = in.nextInt();
        for (int it = 1; it <= t; it++) {
            
            final int n = in.nextInt();
            
            final List<Double> naomi1 = new ArrayList<>();
            final List<Double> ken1 = new ArrayList<>();
            
            for (int i = 0; i < n; i++) naomi1.add(in.nextDouble());
            for (int i = 0; i < n; i++) ken1.add(in.nextDouble());
            
            Collections.sort(naomi1);
            Collections.sort(ken1);
            
            final List<Double> naomi2 = new ArrayList<>(naomi1);
            final List<Double> ken2 = new ArrayList<>(ken1);
            
            
            
            
            int scoreDeceitfulWar = 0;
            for (int i = 0; i < n; i++) {
                
                final double naomi = naomi1.get(naomi1.size()-1) > ken1.get(ken1.size()-1) ? naomi1.remove(naomi1.size()-1) : naomi1.remove(0);
                final double ken = ken1.remove(ken1.size()-1);
                
                if (naomi > ken) scoreDeceitfulWar++;
                
            }
            
            
            int scoreWar = 0;
            for (int i = 0; i < n; i++) {
                
                final double naomi = naomi2.remove(0);
                
                int kenIndex = 0;
                for (int j = 0; j < ken2.size(); j++) {
                    if (ken2.get(j) > naomi) {
                        kenIndex = j;
                        break;
                    }
                }
                
                final double ken = ken2.remove(kenIndex);
                
                if (naomi > ken) scoreWar++;
                
            }
            
            
            
            out.println("Case #" + it + ": " + scoreDeceitfulWar + " " + scoreWar);
        }
        
        out.close();
    }
    
}
