package qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemB {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("input.txt"));
            FileWriter writer = new FileWriter(new File("output.txt"));
            
            int T = scanner.nextInt();
            scanner.nextLine();
            
            for (int t = 1; t <= T; t++) {
                
                int N = scanner.nextInt();
                int M = scanner.nextInt();
                scanner.nextLine();
                
                int[][] H = new int[N][M];
                //boolean satisfied[][] = new boolean[N][M];
                int satisfiedCount = 0;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        H[i][j] = scanner.nextInt();
                        if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                            //satisfied[i][j] = true;
                            //satisfiedCount++;
                        }
                    }
                    if (i != N - 1) {
                        scanner.nextLine();
                    }
                }
                
                int currentMax = 0;
                
                boolean satisfiedHor[][] = new boolean[N][M];
                for (int i = 0; i < N; i++) {
                    int fromLeft = 0;
                    currentMax = 0;
                    while (fromLeft < M) {
                        if (H[i][fromLeft] >= currentMax && !satisfiedHor[i][fromLeft]) {
                            satisfiedHor[i][fromLeft] = true;
                            satisfiedCount++;
                        }
                        currentMax = Math.max(currentMax, H[i][fromLeft]);
                        fromLeft++;
                    }
                    
                    int fromRight = M - 1;
                    currentMax = 0;
                    while (fromRight >= 0) {
                        if (H[i][fromRight] < currentMax && satisfiedHor[i][fromRight]) {
                            satisfiedHor[i][fromRight] = false;
                            satisfiedCount++;
                        }
                        currentMax = Math.max(currentMax, H[i][fromRight]);
                        fromRight--;
                    }
                    
                }
                
                
                boolean satisfiedVer[][] = new boolean[N][M];
                for (int j = 0; j < M; j++) {
                    int fromUp = 0;
                    currentMax = 0;
                    while (fromUp < N) {
                        if (H[fromUp][j] >= currentMax && !satisfiedVer[fromUp][j]) {
                            satisfiedVer[fromUp][j] = true;
                            satisfiedCount++;
                        }
                        currentMax = Math.max(currentMax, H[fromUp][j]);
                        fromUp++;
                    }
                    
                    int fromDown = N - 1;
                    currentMax = 0;
                    while (fromDown >= 0) {
                        if (H[fromDown][j] < currentMax && satisfiedVer[fromDown][j]) {
                            satisfiedVer[fromDown][j] = false;
                            satisfiedCount++;
                        }
                        currentMax = Math.max(currentMax, H[fromDown][j]);
                        fromDown--;
                    }
                    
                }
                
                boolean satisfied = true;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (!satisfiedHor[i][j] && !satisfiedVer[i][j]) {
                            satisfied = false;
                            break;
                        }
                    }
                    if (!satisfied) {
                        break;
                    }
                }
                String result = "Case #" + t + ": ";
                if (satisfied) {
                    result += "YES";
                } else {
                    result += "NO";
                }
                

                System.out.println(result);
                writer.write(result + "\n");

            }
            
            scanner.close();
            writer.close();
            
            
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
    }
}