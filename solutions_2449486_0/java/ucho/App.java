package net.purevirtual.googlejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import org.apache.commons.lang.StringUtils;

/**
 * Hello world!
 *
 */
public class App {
    private static class Lawn {
        int[][] lawn;
        int rows;
        int cols;
        public Lawn(Scanner scanner) {
            rows = scanner.nextInt();
            cols = scanner.nextInt();
            scanner.nextLine();
            lawn = new int[rows][cols];
            System.out.println("new lawn "+rows+" "+cols);
            for (int i = 0; i < rows; i++) {
                lawn[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    lawn[i][j] = scanner.nextInt();
                }
                scanner.nextLine();    
            }
            //scanner.nextLine();
        }
        
        
        private int getRowMaximum(int row) {
            int maximum = lawn[row][0];
            for (int j = 1; j < cols; j++) {
                    if(lawn[row][j] > maximum) {
                        maximum = lawn[row][j];
                    }
            }
            return maximum;
        }
        
        private int getColMaximum(int col) {
            int maximum = lawn[0][col];
            for (int i = 1; i < rows; i++) {
                    if(lawn[i][col] > maximum) {
                        maximum = lawn[i][col];
                    }
            }
            return maximum;
        }
        
        public boolean isValid() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int val = lawn[i][j];
                    if (val >= getColMaximum(j) || val >= getRowMaximum(i)) {
                        //ok
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    
    
    
        
    public static void main(String[] args) throws FileNotFoundException, IOException {
        PrintWriter writer = new PrintWriter(new FileWriter("output"));
        Scanner scanner = new Scanner(new FileReader("input"));
        int tests = scanner.nextInt();
        scanner.nextLine();
        for(int t=0;t<tests;t++) {
            Lawn lawn = new Lawn(scanner);
            String result = lawn.isValid() ? "YES" : "NO";
            String msg = "Case #"+(t+1)+": "+result;
            System.out.println(msg);
            writer.println(msg);
        }
        writer.close();
    }
}
