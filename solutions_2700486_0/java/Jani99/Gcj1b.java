import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Gcj1b {
    
    static int pileHeight(int n) {
        int k = 0;
        while ((k+1)*(2*k+1)<=n) {
            ++k;
        }
        return k;
    }
    
    static class MySpecialPascalTriangle {
        public MySpecialPascalTriangle(int rows) {
            data = new ArrayList<ArrayList<Double>>(rows);
            data.add(new ArrayList<Double>(1));
            data.get(0).add(1.0);
            for (int i=1;i<rows;++i) {
                ArrayList<Double> lastRow = data.get(i-1);
                ArrayList<Double> newRow = new ArrayList<Double>(i+1);
                newRow.add(lastRow.get(0)*.5);
                for (int j=1;j<i;++j) {
                    newRow.add(lastRow.get(j-1)*.5+lastRow.get(j)*.5);
                }
                newRow.add(lastRow.get(0)*.5);
                data.add(newRow);
            }
        }
        double get(int row, int element) {
            return data.get(row).get(element);
        }
        
        ArrayList<ArrayList<Double>> data;
    }

    static double solve(int n, int x, int y) {
        
        int h = pileHeight(n);
        
        // inside the full pyramid
        if (Math.abs(x)+y<=2*(h-1)) {
            return 1.0;
        }
        
        // outside the pile
        if (Math.abs(x)+y>=2*(h+1)) {
            return 0.0;
        }
        
        // on the top
        if (x==0) {
            return 0.0;
        }
        
        // on the edge
        int edgePieces = n - h*(2*h-1);
        int fullEdge = h*2;
        int neededPieces = y+1;
        
        if (edgePieces-fullEdge >= neededPieces) {
            return 1.0;
        }
        
        double r = 0;
        for (int i=neededPieces; i<edgePieces+1; ++i) {
            r += p.get(edgePieces,i);
        }
        
        return r;
    }
    
    static MySpecialPascalTriangle p;
    
    
    public static void main(String[] args) {
        
        p = new MySpecialPascalTriangle(1000);

        
        try {
            Scanner scanner = new Scanner(new File(args[0]));
            BufferedWriter writer = new BufferedWriter(new FileWriter(args[1]));
            
            int T = scanner.nextInt();
            for (int k=0;k<T;++k) {
                
                int N = scanner.nextInt();
                int X = scanner.nextInt();
                int Y = scanner.nextInt();
                
                writer.write("Case #"+(k+1)+": "+solve(N,X,Y)+"\n");
            }
            scanner.close();
            writer.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }

}
