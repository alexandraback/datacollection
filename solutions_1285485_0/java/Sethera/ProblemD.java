
import java.io.*;
import java.util.*;

/**
 *
 * @author Hilos
 */
public class ProblemD {

    public static BufferedWriter bw;
    public static BufferedReader br;

    public static void main(String[] args) {
        try {

            String filename = "D-small-attempt2";

            br = new BufferedReader(new FileReader("E:\\Downloads\\" + filename + ".in"));
            bw = new BufferedWriter(new FileWriter("E:\\Downloads\\" + filename + ".out"));
            //bw = new BufferedWriter(new OutputStreamWriter(System.out));

            ProblemD prob = new ProblemD();
            prob.SolveFile();

        } catch (Exception exc) {
            System.out.println(exc.toString());
        }
    }
    
    private int H, W, D;
    int mapMultiW, mapMultiH;
    private MapCell[][] map;
    private MapCell myPosition;
    private List<MapCell> myOtherPositions;

    public void SolveFile() throws Exception {
        int caseCount = Integer.parseInt(br.readLine());

        for (int caseNumber = 0; caseNumber < caseCount; caseNumber++) {
            String[] lineParts = br.readLine().split(" ");

            H = Integer.parseInt(lineParts[0]);
            W = Integer.parseInt(lineParts[1]);
            D = Integer.parseInt(lineParts[2]);

            int myX = -1, myY = -1;

            mapMultiW = (2*D) / (W - 2);
            mapMultiH = (2*D) / (H - 2);

            map = new MapCell[(W - 2) + 2 * (W - 2) * mapMultiW][(H - 2) + 2 * (H - 2) * mapMultiH];
            myOtherPositions = new LinkedList();

            for (int row = 0; row < H; row++) {
                String rowStr = br.readLine();
                if (0 < row && row < H - 1) {
                    for (int col = 1; col < W - 1; col++) {
                        char c = rowStr.charAt(col);
                        int x = (W - 2) * mapMultiW + col - 1;
                        int y = (H - 2) * mapMultiH + row - 1;

                        MapCell cell = new MapCell(x, y);
                        map[x][y] = cell;
                        if (c == 'X') {
                            myX = x;
                            myY = y;
                            cell.isMe = true;
                            myPosition = cell;
                        } else if (c == '#') {
                            cell.isMirror = true;
                        }
                    }
                }
            }

            SolveCase(caseNumber + 1);
        }
    }

    public void SolveCase(int caseNumber) throws Exception {
        UnfoldMap();
        
        List<MapCell> definitePositions = new LinkedList();
        
        for(MapCell cell : myOtherPositions){
            boolean blocks = false;
            for(MapCell other : definitePositions){
                if(cBlocksB(myPosition, cell, other)){
                    blocks = true;
                    break;
                }
            }
            if(!blocks){
                definitePositions.add(cell);
            }
        }

        bw.write("Case #" + caseNumber + ": " + definitePositions.size() + "\n");
        bw.flush();
    }

    private boolean cBlocksB(MapCell a, MapCell b, MapCell c) {
        boolean sameLine = (a.y - c.y) * (a.x - b.x) == (a.y - b.y) * (a.x - c.x);
        if(sameLine){
            double aToC = a.distanceTo(c);
            double aToB = a.distanceTo(b);            
            double bToC = b.distanceTo(c);
            if(bToC > aToC && bToC > aToB){
                return false;
            }else{
                return true;
            }            
        }else{
            return false;
        }
    }

    private void UnfoldMap() {
        int minX = mapMultiW * (W - 2);
        int minY = mapMultiH * (H - 2);
        int maxX = minX + W - 3;
        int maxY = minY + H - 3;

        int xlen = W - 2;
        int ylen = H - 2;

        boolean flipx = mapMultiW % 2 == 1;
        boolean flipy = mapMultiH % 2 == 1;

        for (int multiX = 0; multiX < mapMultiW * 2 + 1; multiX++) {
            flipy = mapMultiH % 2 == 1;
                    
            for (int multiY = 0; multiY < mapMultiH * 2 + 1; multiY++) {

                int destx = multiX * xlen;
                int desty = multiY * ylen;

                if (destx != minX || desty != minY) {
                    CopyRegion(minX, minY, destx, desty, xlen, ylen, flipx, flipy);
                }

                flipy = !flipy;
            }
            flipx = !flipx;
        }
    }

    private void CopyRegion(int sx, int sy, int dx, int dy, int xlen, int ylen, boolean flipx, boolean flipy) {
        for (int x = 0; x < xlen; x++) {
            for (int y = 0; y < ylen; y++) {
                MapCell destcell = new MapCell(x + dx, y + dy);
                map[x + dx][y + dy] = destcell;
                MapCell sourcecell;
                if (flipx) {
                    if (flipy) {
                        sourcecell = map[(xlen - 1 - x) + sx][(ylen - 1 - y) + sy];
                    } else {
                        sourcecell = map[(xlen - 1 - x) + sx][y + sy];
                    }
                } else {
                    if (flipy) {
                        sourcecell = map[x + sx][(ylen - 1 - y) + sy];
                    } else {
                        sourcecell = map[x + sx][y + sy];
                    }
                }
                destcell.isMe = sourcecell.isMe && destcell.distanceTo(myPosition) <= (double)D;
                if (destcell.isMe) {
                    myOtherPositions.add(destcell);
                }
                destcell.isMirror = sourcecell.isMirror;
            }
        }
    }

    private class MapCell {

        public int x, y;
        public boolean isMirror, isMe;

        public MapCell(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public double distanceTo(MapCell other) {
            int dx = this.x - other.x;
            int dy = this.y - other.y;
            return Math.sqrt(dx * dx + dy * dy);
        }
    }
}
