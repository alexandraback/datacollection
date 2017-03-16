import java.io.*;

public class Lawnmower {

    private static void debug(String msg) {
        System.err.println(msg);
    }

    public static final void main(String[] args) throws Exception {
        String inputfile = args[0];
        String outputfile = args[1];
        
        BufferedReader in = new BufferedReader(new FileReader(inputfile));
        PrintWriter out = new PrintWriter(new FileWriter(outputfile));
        
        int cases = Integer.parseInt(in.readLine());
        debug("Number of test cases: " + cases);

        for (int i = 1; i <= cases; ++i) {
            debug("Processing Case #" + i);

            String[] sizes = in.readLine().split(" ");
            assert(sizes.length == 2) : "incorrect number of sizes " + sizes.length;
            int rows = Integer.parseInt(sizes[0]);
            int columns = Integer.parseInt(sizes[1]);
            debug("  lawn is " + rows + " x " + columns);
            int[][] lawn = new int[rows][columns];
            
            for (int r = 0; r < rows; ++r) {
                String[] heights = in.readLine().split(" ");
                assert(heights.length == columns) : "incorrect number of columns " + heights.length;
                for (int c = 0; c < columns; ++c) {
                    lawn[r][c] = Integer.parseInt(heights[c]);
                    assert(lawn[r][c] > 0);
                }
            }
            
            String debugmsg = "";
            for (int r = 0; r < rows; ++r) {
                debugmsg += ' ';
                for (int c = 0; c < columns; ++c)
                    debugmsg += " " + lawn[r][c];
                debugmsg += '\n';
            }
            debug(debugmsg);
            
            boolean possible = false;
            
            while (true) {
                int minheight = Integer.MAX_VALUE;
                int minrow = 0;
                int mincol = 0;
                for (int r = 0; r < rows; ++r) {
                    for (int c = 0; c < columns; ++c) {
                        if ((lawn[r][c] != 0) && (lawn[r][c] < minheight)) {
                            minheight = lawn[r][c];
                            minrow = r;
                            mincol = c;
                        }
                    }
                }
                
                if (minheight == Integer.MAX_VALUE) {
                    possible = true;
                    break;
                }
                
                boolean colreducible = true;
                for (int r = 0; r < rows; ++r) {
                    if ((lawn[r][mincol] != minheight) && (lawn[r][mincol] != 0)) {
                        colreducible = false;
                        break;
                    }
                }
                if (colreducible)
                    for (int r = 0; r < rows; ++r)
                        lawn[r][mincol] = 0;
                
                boolean rowreducible = true;
                for (int c = 0; c < columns; ++c) {
                    if ((lawn[minrow][c] != minheight) && (lawn[minrow][c] != 0)) {
                        rowreducible = false;
                        break;
                    }
                }
                if (rowreducible)
                    for (int c = 0; c < columns; ++c)
                        lawn[minrow][c] = 0;
                
                if (!colreducible && !rowreducible) {
                    possible = false;
                    break;
                }
            }
            
            out.println("Case #" + i + ": " + (possible ? "YES" : "NO"));
            debug("  possible: " + possible);
       }
        
        out.close();
        in.close();
    }
    
}
