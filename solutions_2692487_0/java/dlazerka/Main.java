package c2434486.a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.ArrayList;

import util.Util;

public class Main {

	public static void main(String[] args) throws Exception {
	    long startedAt = System.currentTimeMillis();
		Input input = new Input(new File(Main.class.getResource("in").toURI()));
		input.parse();
		Writer output = new BufferedWriter(new FileWriter(new File(Main.class.getResource("out").toURI())));
		try {
			for (Case c : input.cases) {
			    Solver solver = new Solver(c);
				String line = "Case #" + c.num + ": " + solver.solve() + "\n";
				output.write(line);
				System.out.print(line);
			}
		} finally {
			output.close();
		}
		long endedAt = System.currentTimeMillis();
		System.out.println((endedAt - startedAt) + "ms");
	}
}

class Input {
    private BufferedReader reader;

    ArrayList<Case> cases;

    public Input(File file) throws FileNotFoundException {
        reader = new BufferedReader(new FileReader(file));
    }

    public Input(InputStream is) {
        this.reader = new BufferedReader(new InputStreamReader(is));
    }

    public void parse() throws IOException {
        try {
            int T = Util.readInt(reader);
            cases = new ArrayList<Case>(T);

            for (int ci = 1; ci <= T; ci++) {
                Case c = new Case(ci);
                int[] ii = Util.readInts(reader);
				c.A = ii[0];
                c.N = ii[1];
                c.n = Util.readInts(reader);
                cases.add(c);
            }
        } finally {
            reader.close();
        }
    }
}