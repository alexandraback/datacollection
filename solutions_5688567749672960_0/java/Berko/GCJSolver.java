/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package GCJ;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import javax.imageio.IIOException;

/**
 *
 * @author t7639192
 */
public abstract class GCJSolver {

	protected Scanner in;
	protected PrintWriter out;
	private int solved;
	private int T;

	public GCJSolver(String inputFilename, String outputFilename) throws IOException {
		this.in = new Scanner(new File(inputFilename));
		this.out = new PrintWriter(outputFilename);
		this.solved = 0;
		if (!in.hasNextInt()) {
			throw new IIOException("T is missing.");
		}
		this.T = in.nextInt();
	}

	public int casesLeft() {
		return this.T - this.solved;
	}

	public abstract void solve() throws IOException;

	public GCJSolver solveAll() throws IOException {
		while (this.casesLeft() > 0) {
			this.out.print("Case #" + (this.solved + 1) + ": ");
			this.solve();
			this.solved++;
		}
		return this;
	}

	public void close() throws IOException {
		this.in.close();
		this.out.close();
	}
}
