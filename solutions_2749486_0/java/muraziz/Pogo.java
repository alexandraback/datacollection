package roundC;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Pogo {
    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            System.out.println("You should supply two file names (input and output files)");
            return;
        }
        
        new Pogo().run(args);
    }
    
    private void run(String[] args) throws IOException {
        Scanner scan = new Scanner(new File(args[0]));
        StringBuffer writer = new StringBuffer();
        int T = scan.nextInt();
        
        for (int i=0; i<T; i++) {            
            int X = scan.nextInt();
            int Y = scan.nextInt();                    
            
            writer.append(String.format("Case #%d: %s", i+1, solve(X, Y)));
            writer.append("\n");
            scan.nextLine();
        }
        FileWriter fw = new FileWriter(args[1]);
        fw.write(writer.toString());        
        fw.close();
        
        System.out.println(writer.toString());
    }
    
    static char WEST = 'W';
    static char EAST = 'E';
    static char NORTH = 'N';
    static char SOUTH = 'S';
    

    private String solve(int x, int y) {        
        
        StringBuffer path = new StringBuffer();
        
        if (x < 0) {
            for (int i=0; i<-x; i++) {                
                path.append(EAST);
                path.append(WEST);
            }    
        } else if (x > 0) {
            for (int i=0; i<x; i++) {
                path.append(WEST);
                path.append(EAST);
            }
        }
        
        if (y < 0) {
            for (int i=0; i<-y; i++) {
                path.append(NORTH);
                path.append(SOUTH);
            }            
        } else if (y > 0) {
            for (int i=0; i<y; i++) {
                path.append(SOUTH);
                path.append(NORTH);
            }
        }
        return path.toString();
    }    
}
