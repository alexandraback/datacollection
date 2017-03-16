import java.util.*;
import java.io.*;

public class Minesweeper
{

    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        
        int t = in.nextInt();
        
        for (int count = 0; count < t; count++) {
            
            int r = in.nextInt();
            int c = in.nextInt();
            int m = in.nextInt();
            
            System.out.println("Case #" + (count+1) + ":");
            
            // Case of 1 row
            if (r == 1) {
                System.out.print("c");
                print_row(m, c-1);
                
                // Case of 2 rows
            } else if (r == 2) {
                if (m == r*c - 1) {
                    System.out.print("c");
                    print_row(c-1,c-1);
                    print_row(c,c);
                } else if (c == 1) {
                    System.out.println("c");
                    if (m == 0)
                        System.out.println(".");
                    else
                        System.out.println("*");
                }else if (m%2 == 1 || (r*c - m) == 2) {
                    System.out.println("Impossible");
                } else {
                    print_row(m/2, c);
                    System.out.print("c");
                    print_row(m/2, c-1);                        
                }
                
                // Case of 3 or more rows
            } else if (c == 1) {
                // Case of 1 column
                System.out.println("c");
                for (int i = 0; i < (r-m-1); i++) 
                    System.out.println(".");
                for (int i = 0; i < m; i++)
                    System.out.println("*");
                
                // Case of 2 columns
            } else if (c == 2) {
                if (m == r*c-1) {
                    System.out.println("c*");
                    for (int i = 1; i < r; i++)
                        System.out.println("**");
                } else if (m%2 == 1 || (r*c - m) == 2) {
                    System.out.println("Impossible");
                } else {
                    System.out.println("c.");
                    for (int i = 0; i < (r - m/2 - 1); i++)
                        System.out.println("..");
                    for (int i = 0; i < (m/2); i++)
                        System.out.println("**");
                }
                
                // Case of 3x3 or more
            } else {
                int nm = (r*c) - m;
                if (nm == 1) {
                    System.out.print("c");
                    print_row(c-1,c-1);
                    for (int i = 1; i < r; i++)
                        print_row(c,c);
                } else if (nm == 2 || nm == 3 || nm == 5 || nm == 7) {
                    System.out.println("Impossible");
                } else {
                    // If you have a bit more than two rows or more free
                    if (nm > 2*c + 1) {
                        
                        // first row
                        System.out.print("c");
                        print_row(0, c-1);
                        // rows of non-mines
                        for (int i = 1; i < (nm / c) - 1; i++)
                            print_row(0,c);
                        
                        // interchange rows
                        if (nm % c == 0) {
                            print_row(0,c);
                        } else if (nm % c == 1) {
                            print_row(1,c);
                            print_row(c-2,c);
                        } else {
                            print_row(0,c);
                            print_row(c - (nm % c), c);
                        }
                        
                        // rows of all mines
                        for (int i = 0; i < (m / c); i++)
                            print_row(c,c);
                        
                    // If not
                    } else {
                        if (nm % 2 == 0) {
                            System.out.print("c");
                            print_row((c - (nm/2)), c-1);
                            print_row(c - (nm/2), c);
                            for (int i = 0; i < (r - 2); i++)
                                print_row(c,c);
                        } else {
                            System.out.print("c");
                            print_row((c - ((nm-3)/2)), c-1);
                            print_row(c - ((nm-3)/2), c);
                            print_row(c-3,c);
                            for (int i = 0; i < (r - 3); i++)
                                print_row(c,c);
                        }
                    }
                }
            }
            
        }
        
    }
    
    public static void print_row (int m, int c) {
        for (int i = 0; i < (c-m); i++) {
            System.out.print(".");
        }
        for (int i = 0; i < m; i++) {
            System.out.print("*");
        }
        System.out.println();
    }

}