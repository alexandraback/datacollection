import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Lawnmower {

    public static void main(String[] args) {
     
        try {
            Scanner in = new Scanner(new File("lawnmower.txt"));
            int num = in.nextInt();
            for(int z = 1; z <= num; z++) {
                int n = in.nextInt();
                int m = in.nextInt();
                int [][] yard = new int[n][m];
                
                for(int i = 0; i < n; i ++) {
                    for(int j = 0; j < m; j++) {
                        yard[i][j] = in.nextInt();
                    }
                }
                
                boolean f = true;
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        int cur = yard[i][j]; 
                        boolean v = false;
                        boolean h = false;
                        for(int k = 0; k < n; k++) {
                            if(yard[k][j] > cur) {
                                h = true;
                            } 
                        }
                        for(int k = 0; k < m; k++) {
                            if(yard[i][k] > cur) {
                                v = true;
                            }
                        }
                        if(v && h) {
                            f = false;
                            break;
                        }
                    }
                }
                if(f) {
                    System.out.println(String.format("Case #%d: %s", z,"YES"));
                } else {
                    System.out.println(String.format("Case #%d: %s", z,"NO"));
                }
                
                
            }
            
            
            
            
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
