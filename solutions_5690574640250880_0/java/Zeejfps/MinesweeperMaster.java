package gcj2014.qualification.c;

import java.io.*;
import java.net.URISyntaxException;
import java.util.ArrayList;

/**
 * Created by zeejfps on 4/11/14.
 */
public class MinesweeperMaster {

    public static void main(String[] args) {

        try {

            File input_file = new File(MinesweeperMaster.class.getResource("input.in").toURI());
            File output_file = new File("/home/zeejfps/Programming/Java/GoogleCodeJam/src/gcj2014/qualification/c/output.txt");

            BufferedReader br = new BufferedReader(new FileReader(input_file));
            BufferedWriter bw = new BufferedWriter(new FileWriter(output_file));

            int num_cases = Integer.parseInt(br.readLine());
            int impossible_count = 0;
            int solved_count = 0;

            for (int i_case = 0; i_case < num_cases; i_case++) {

                System.out.println("Case #" + (i_case+1) + ":");
                bw.write("Case #" + (i_case+1)+ ":");
                bw.newLine();

                String[] tokens = br.readLine().split(" ");
                int height = Integer.parseInt(tokens[0]);
                int width = Integer.parseInt(tokens[1]);
                int bombs = Integer.parseInt(tokens[2]);

                System.out.println("--> Width: " + width);
                System.out.println("--> Height: " + height);
                System.out.println("--> Bombs: " + bombs);

                char[][] grid = new char[height][width];
                boolean impossible = false;
                top:
                for (int i = 0; i < Math.ceil(height/2.0); i++) {

                    for (int j = 0; j < Math.ceil(width/2.0); j++) {

                        int free_space = width*height - bombs;
                        impossible = false;
                        System.out.println("--> Space: " + free_space);
                        resetGrid(grid);

                        grid[i][j] = 'c';
                        free_space--;
                        printGrid(grid);
                        System.out.println("--> Space: " + free_space);
                        System.out.println("~~~~~~~~~~~~~~~~~");

                        if (free_space == 0) {

                            for (int k = 0; k < height; k++) {

                                for (int z = 0; z < width; z++) {

                                    bw.write(grid[k][z]);

                                }
                                bw.newLine();

                            }

                            solved_count++;
                            break top;

                        }

                        int neighbors = getNeightborsCount(grid, j, i);
                        free_space -= getNeightborsCount(grid, j, i);
                        clear(grid, j, i);
                        printGrid(grid);
                        System.out.println("--> Space: " + free_space);
                        System.out.println("~~~~~~~~~~~~~~~~~");

                        while (free_space > 0) {

                            int max = 0, x = 0, y = 0;
                            middle:
                            for (int k = 0; k < height; k++) {

                                for (int z = 0; z < width; z++) {

                                    if (grid[k][z] == '.') {
                                        int num_neighbors = getNeightborsCount(grid, z, k);
                                        /*
                                        for (int d = 0; d < factors.size(); d++) {

                                            //System.out.println("Factors: " + factors.get(d));
                                            if (num_neighbors == factors.get(d)) {

                                                max = num_neighbors;
                                                x = z;
                                                y = k;
                                                break middle;

                                            }

                                        }*/

                                        if (num_neighbors > max) {

                                            max = num_neighbors;
                                            x = z;
                                            y = k;

                                        }

                                    }

                                }

                            }
                            //System.out.println("--> max: " + max);
                            //System.out.println("--> X: " + x);
                            //System.out.println("--> Y: " + y);
                            int neighbor_count = getNeightborsCount(grid, x, y);
                            if (free_space - neighbor_count < 2) {

                                max = 0;
                                ArrayList<Integer> factors = factors(free_space);
                                lolz:
                                for (int k = 0; k < height; k++) {

                                    for (int z = 0; z < width; z++) {

                                        if (grid[k][z] == '.') {
                                            int num_neighbors = getNeightborsCount(grid, z, k);

                                            if (free_space - num_neighbors == 0) {

                                                max = num_neighbors;
                                                x = z;
                                                y = k;
                                                break lolz;

                                            }

                                            for (int d = 0; d < factors.size(); d++) {

                                                //System.out.println("Factors: " + factors.get(d));
                                                if (num_neighbors == factors.get(d) && num_neighbors > max) {

                                                    max = num_neighbors;
                                                    x = z;
                                                    y = k;

                                                }

                                            }

                                        }

                                    }

                                }

                            }


                            free_space -= getNeightborsCount(grid, x, y);

                            if (neighbor_count <= 0)  {
                                break;
                            }
                            clear(grid, x, y);

                            printGrid(grid);
                            System.out.println("--> Space: " + free_space);
                            System.out.println("~~~~~~~~~~~~~~~~~");

                        }

                        if (getBombCount(grid) == bombs) {

                            printGrid(grid);
                            for (int k = 0; k < height; k++) {

                                for (int z = 0; z < width; z++) {

                                    bw.write(grid[k][z]);

                                }
                                bw.newLine();

                            }
                            solved_count++;
                            break top;

                        } else {

                            impossible = true;

                        }

                        //printGrid(grid);

                    }

                }

                if (impossible) {
                    impossible_count++;
                    System.out.println("--> Impossible");
                    bw.write("Impossible");
                    bw.newLine();
                }

            }

            System.out.println("IMPOSIBLE: " + impossible_count);
            System.out.println("SOLVED: " + solved_count);

            br.close();
            bw.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (URISyntaxException e) {
            e.printStackTrace();
        }

    }

    public static void printGrid(char[][] grid) {

        for (int j = 0; j < grid.length; j++) {

            System.out.print("\t");
            for (int k = 0; k < grid[j].length; k++) {

                System.out.print(grid[j][k]);

            }
            System.out.println();

        }

    }

    public static int getBombCount(char[][] grid) {

        int count = 0;
        for (int i = 0; i < grid.length; i++) {

            for (int j = 0; j < grid[i].length; j++) {

                if (grid[i][j] == '*')
                    count++;

            }

        }

        return count;
    }

    public static int getNeightborsCount(char[][] grid, int x, int y) {

        int count = 0;

        for (int i = y -1; i <= y + 1; i ++) {

            if (i < 0 || i >= grid.length) continue;

            for (int j = x -1; j <= x + 1; j++) {

                if (j < 0 || j >= grid[y].length) continue;
                //if (j == x && i == y) continue;

                if (grid[i][j] == '*')
                    count++;

            }

        }

        return count;
    }

    public static void clear(char[][] grid, int x, int y) {

        for (int i = y -1; i <= y + 1; i ++) {

            if (i < 0 || i >= grid.length) continue;

            for (int j = x -1; j <= x + 1; j++) {

                if (j < 0 || j >= grid[y].length) continue;
                if (j == x && i == y) continue;

                if (grid[i][j] != 'c')
                    grid[i][j] = '.';

            }

        }

    }

    public static void resetGrid(char[][] grid) {

        for (int i = 0; i < grid.length; i++) {

            for (int j = 0; j < grid[i].length; j++) {

                grid[i][j] = '*';

            }

        }

    }

    public static ArrayList<Integer> factors(int num) {

        ArrayList<Integer> factors = new ArrayList<Integer>();
        for (int i = 1; i <= Math.ceil(Math.sqrt(num)); i++) {

            if (num % i == 0) {
                factors.add(i);
            }

        }

        return factors;
    }

}
