package src;

import java.awt.*;
import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class C2014 {

	
	public static void main(String[] args) throws IOException {
        C2014 trans = new C2014();
		trans.doMe();
	}
	
	private static final String NAME = "large1";

    int iter = 0;
    private boolean[][] recursive(boolean[][]cells, List<Poi>pois, int c, int free) {
        iter++;
        if (iter>2000) return null;
        if (c==free) return cells;
        for(Poi p:pois) {
            List<Poi>tpois = new ArrayList<>();
            for(int j=-1;j<=1;j++) {
                for(int k=-1;k<=1;k++) {
                    if (j==0 && k==0) continue;
                    int u = p.x + j;
                    int v = p.y + k;
                    if (u<0 || u>=cells.length) continue;
                    if (v<0 || v>=cells[0].length) continue;
                    if (cells[u][v]) continue;
                    tpois.add(new Poi(u,v));
                }
            }
            if (tpois.size() + c > free) continue;
            //c += tpois.size();
            //pois.addAll(tpois);
            List<Poi>tpoisr = new ArrayList<>();
            for(Poi po:tpois) {
                cells[po.x][po.y] = true;
            }
            tpoisr.addAll(pois);
            tpoisr.remove(p);
            tpoisr.addAll(tpois);
            boolean[][]st = recursive(cells,tpoisr,c + tpois.size(),free);
            if (st!=null) {
                return st;
            } else {
                for(Poi po:tpois) {
                    cells[po.x][po.y] = false;
                }
            }
        }
        return null;
    }

	public void doMe() throws IOException {
        Path path = FileSystems.getDefault().getPath(".", NAME+".in");
        List<String> lines = Files.readAllLines(path, Charset.defaultCharset());

        Path pathO = FileSystems.getDefault().getPath(".", NAME+".2out");


        int T = Integer.parseInt(lines.remove(0));
        StringBuilder buffer = new StringBuilder();
        for(int i = 0; i<T; i++) {
            iter = 0;
            String vs[] = lines.get(i).split(" ");
            int R = Integer.parseInt(vs[0]);
            int C = Integer.parseInt(vs[1]);
            int M = Integer.parseInt(vs[2]);

            boolean cells[][] = new boolean[C][R];

            int free = (C*R) - M;

            int c = 1;
            cells[0][0] = true;
            List<Poi>pois = new ArrayList<>();
            pois.add(new Poi(0,0));

            cells = recursive(cells,pois,c,free);

            buffer.append("Case #" + (i + 1) + ": \n");
            if (cells==null) {
                buffer.append("Impossible\n");
            } else {
                for (int j = 0; j < R; j++) {
                    for (int k = 0; k < C; k++) {
                        if (j==0 && k==0) {
                            buffer.append("c");
                        } else if (cells[k][j]) {
                            buffer.append(".");
                        } else {
                            buffer.append("*");
                        }
                    }
                    buffer.append("\n");
                }
            }

            FileWriter fw = new FileWriter(new File(NAME+".out"));
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(buffer.toString());
            bw.close();
        }

	}

    class Poi {
        int x = -1;
        int y = -1;
        public Poi(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
