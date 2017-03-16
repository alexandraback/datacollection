import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class D {
    private static final double EPSILON = 0.000001;
    private static final double EPSILON2 = 0.000000001;

    public static void main(String[] args) throws Throwable {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numCases = Integer.parseInt(reader.readLine());

        for (int c = 1; c <= numCases; c++) {
            String casedesc = reader.readLine();
            String[] tokens = casedesc.split(" ");
            int h = Integer.parseInt(tokens[0]);
            int w = Integer.parseInt(tokens[1]);
            int d = Integer.parseInt(tokens[2]);
            boolean mirrors[][] = new boolean[h][w];
            double targetR = 0;
            double targetC = 0;
            int currentx = 0;
            int currenty = 0;
            for (int row = 0; row < h; row++ ) {
                String line = reader.readLine();
                byte[] bytes = line.getBytes("us-ascii");
                for (int col = 0; col < w; col++) {
                    if (bytes[col] == '#') {
                        mirrors[row][col] = true;
                    } else if (bytes[col] == 'X') {
                        currentx = row;
                        currenty = col;
                        targetR = row + 0.5;
                        targetC = col + 0.5;
                    }
                }
            }
            int ways = 0;
            int x = 0;
            for (double i = 0; i < 360; i += 0.1) {
                double rad = StrictMath.toRadians(i);
                double cos = StrictMath.cos(rad);
                if (x == 900) {
                    cos = Double.MIN_VALUE;
                } else if (x == 2700) {
                    cos = -Double.MIN_VALUE;
                }
                double sin = StrictMath.sin(rad);
                if (x == 0) {
                    sin = Double.MIN_VALUE;
                } else if (x == 1800) {
                    sin = -Double.MIN_VALUE;
                }
                x++;
                if (toNextIntersection(-1, -1, 0, d, new Point2D.Double(targetR, targetC), cos, sin, currentx, currenty, mirrors)) {
                    ways++;
                }
            }
            System.out.println("Case #" + c + ": " + ways);
        }
    }

    private static boolean toNextIntersection(int targetx, int targety, double len, double limit,
                                              Point2D.Double currentPos, double cos, double sin,
                                              int currentx, int currenty,
                                              boolean mirrors[][]) {
        double t;
        int nextx;
        int nexty;
        double newcos = cos;
        double newsin = sin;
        boolean finalTry = false;
        if (cos > 0) {
            if (sin > 0) {
                // top or right
                double tt = (currenty + 1.0 - currentPos.y) / sin;
                double tr = (currentx + 1.0 - currentPos.x) / cos;
                double diff = tt - tr;
                if (StrictMath.abs(diff) < EPSILON2) {
                    t = tt < tr ? tt : tr;
                    nextx = currentx + 1;
                    nexty = currenty + 1;
                    if (mirrors[nextx][nexty]) {
                        if (mirrors[currentx][nexty] && mirrors[nextx][currenty]) {
                            if ((len + t) * 2.0 <= limit + EPSILON) {
                                return true;
                            }
                            finalTry = true;
                        } else if (mirrors[currentx][nexty]) {
                            newsin = -sin;
                            nexty = currenty;
                        } else if (mirrors[nextx][currenty]) {
                            newcos = -cos;
                            nextx = currentx;
                        }
                    }
                } else if (diff > 0.0) {
                    t = tr;
                    nextx = currentx + 1;
                    nexty = currenty;
                    if (mirrors[nextx][nexty]) {
                        newcos = -cos;
                        nextx = currentx;
                    }
                } else {
                    t = tt;
                    nextx = currentx;
                    nexty = currenty + 1;
                    if (mirrors[nextx][nexty]) {
                        newsin = -sin;
                        nexty = currenty;
                    }
                }
            } else {
                // bottom or right
                double tb = (currenty - currentPos.y) / sin;
                double tr = (currentx + 1.0 - currentPos.x) / cos;
                double diff = tb - tr;
                if (StrictMath.abs(diff) < EPSILON2) {
                    t = tb < tr ? tb : tr;
                    nextx = currentx + 1;
                    nexty = currenty - 1;
                    if (mirrors[nextx][nexty]) {
                        if (mirrors[currentx][nexty] && mirrors[nextx][currenty]) {
                            if ((len + t) * 2.0 <= limit + EPSILON) {
                                return true;
                            }
                            finalTry = true;
                        } else if (mirrors[currentx][nexty]) {
                            newsin = -sin;
                            nexty = currenty;
                        } else if (mirrors[nextx][currenty]) {
                            newcos = -cos;
                            nextx = currentx;
                        }
                    }
                } else if (diff > 0.0) {
                    t = tr;
                    nextx = currentx + 1;
                    nexty = currenty;
                    if (mirrors[nextx][nexty]) {
                        newcos = -cos;
                        nextx = currentx;
                    }
                } else {
                    t = tb;
                    nextx = currentx;
                    nexty = currenty - 1;
                    if (mirrors[nextx][nexty]) {
                        newsin = -sin;
                        nexty = currenty;
                    }
                }
            }
        } else {
            if (sin > 0) {
                // top or left
                double tt = (currenty + 1.0 - currentPos.y) / sin;
                double tl = (currentx + - currentPos.x) / cos;
                double diff = tt - tl;
                if (StrictMath.abs(diff) < EPSILON2) {
                    t = tt < tl ? tt : tl;
                    nextx = currentx - 1;
                    nexty = currenty + 1;
                    if (mirrors[nextx][nexty]) {
                        if (mirrors[currentx][nexty] && mirrors[nextx][currenty]) {
                            if ((len + t) * 2.0 <= limit + EPSILON) {
                                return true;
                            }
                            finalTry = true;
                        } else if (mirrors[currentx][nexty]) {
                            newsin = -sin;
                            nexty = currenty;
                        } else if (mirrors[nextx][currenty]) {
                            newcos = -cos;
                            nextx = currentx;
                        }
                    }
                } else if (diff > 0.0) {
                    t = tl;
                    nextx = currentx - 1;
                    nexty = currenty;
                    if (mirrors[nextx][nexty]) {
                        newcos = -cos;
                        nextx = currentx;
                    }
                } else {
                    t = tt;
                    nextx = currentx;
                    nexty = currenty + 1;
                    if (mirrors[nextx][nexty]) {
                        newsin = -sin;
                        nexty = currenty;
                    }
                }
            } else {
                // bottom or left
                double tb = (currenty - currentPos.y) / sin;
                double tl = (currentx - currentPos.x) / cos;
                double diff = tb - tl;
                if (StrictMath.abs(diff) < EPSILON2) {
                    t = tb < tl ? tb : tl;
                    nextx = currentx - 1;
                    nexty = currenty - 1;
                    if (mirrors[nextx][nexty]) {
                        if (mirrors[currentx][nexty] && mirrors[nextx][currenty]) {
                            if ((len + t) * 2.0 <= limit + EPSILON) {
                                return true;
                            }
                            finalTry = true;
                        } else if (mirrors[currentx][nexty]) {
                            newsin = -sin;
                            nexty = currenty;
                        } else if (mirrors[nextx][currenty]) {
                            newcos = -cos;
                            nextx = currentx;
                        }
                    }
                } else if (diff > 0.0) {
                    t = tl;
                    nextx = currentx - 1;
                    nexty = currenty;
                    if (mirrors[nextx][nexty]) {
                        newcos = -cos;
                        nextx = currentx;
                    }
                } else {
                    t = tb;
                    nextx = currentx;
                    nexty = currenty - 1;
                    if (mirrors[nextx][nexty]) {
                        newsin = -sin;
                        nexty = currenty;
                    }
                }
            }
        }
        Point2D.Double newPos = new Point2D.Double(currentPos.x + t * cos, currentPos.y + t * sin);

        if (targetx >= 0) {
            if (currentx == targetx && currenty == targety) {
                if (new Line2D.Double(currentPos, newPos).intersects(new Rectangle2D.Double(targetx + 0.5 - 0.001, targety + 0.5 - 0.001, 0.002, 0.002))) {
                    if (len + StrictMath.sqrt(StrictMath.pow(targetx + 0.5 - currentPos.x, 2) + StrictMath.pow(targety + 0.5 - currentPos.y, 2)) <= limit + EPSILON) {
                        return true;
                    }
                }
            }
        } else {
            targetx = currentx;
            targety = currenty;
        }
        if (finalTry) {
            return false;
        }

        len += t;

        if (len > limit + EPSILON) {
            return false;
        }
        if (toNextIntersection(targetx, targety, len, limit, newPos, newcos, newsin, nextx, nexty, mirrors)) {
            return true;
        }
        return false;
    }
}