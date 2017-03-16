package qual2013;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/qual2013/B-sample.in"), System.out);
		io = new Kattio(new FileInputStream("src/qual2013/B-small-attempt0.in"), new FileOutputStream("src/qual2013/B-small-attempt0.out"));
//		io = new Kattio(new FileInputStream("src/qual2013/B-large.in"), new FileOutputStream("src/qual2013/B-large.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new B().solve(io);
		}
		io.close();
	}

    private void solve(Kattio io) {
        int ysize = io.getInt(), xsize = io.getInt();
        int a[][] = new int[ysize][xsize];
        for (int y=0;y<ysize;y++) {
            for(int x=0;x<xsize;x++) {
                a[y][x]=io.getInt();
            }
        }
        for (int y=0;y<ysize;y++) {
            for(int x=0;x<xsize;x++) {
                boolean h=false,v=false;
                for(int i=0;i<xsize;i++) {
                    if (a[y][i] > a[y][x]) h=true;
                }
                for(int i=0;i<ysize;i++) {
                    if (a[i][x] > a[y][x]) v=true;
                }
                if (h&&v) {
                    io.println("NO");
                    return;
                }
            }
        }
        io.println("YES");
    }
}
