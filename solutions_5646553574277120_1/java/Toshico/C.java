package toshico.gcj_2015.round_1c;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class C {

	private final int input_C, input_D, input_V;
	private final int[] money;

	private int output = 0;

	public C(final Scanner sc) {
		super();
		this.input_C = sc.nextInt();
		this.input_D = sc.nextInt();
		this.input_V = sc.nextInt();
		this.money = new int[this.input_D];
		for (int i = 0; i < this.input_D; i++) {
			this.money[i] = sc.nextInt();
		}
		int max = 1;
		int ind_1 = 0;
		int ind_2 = 0;
		int next_d = 0;
		int insert = 0;
		boolean inserted = false;
		while (max <= this.input_V) {
			if (inserted == false && ind_1 < this.input_D) {
				next_d = this.money[ind_1];
			} else if (inserted == true) {
				next_d = insert;
			} else {
				next_d = -1;
			}
			if (next_d > 0 && next_d <= max) {
				max += next_d;
			} else {
				inserted = true;
				insert = max;
				this.output++;
				next_d = max;
				max += next_d;
				ind_2 = 0;
			}
			ind_2++;
			if (ind_2 >= this.input_C) {
				ind_2 = 0;
				if (inserted == false) {
					ind_1++;
				} else {
					inserted = false;
				}
			}
		}
	}

	@Override
	public String toString() {
		return String.valueOf(this.output);
	}

	public static void main(final String[] args) {
		try (final Scanner sc = new Scanner(args.length > 0 ? new FileInputStream(args[0]) : System.in);
				final PrintStream pr = args.length > 1 ? new PrintStream(args[1]) : System.out;) {
			final int nb_test = sc.nextInt();
			for (int i = 1; i <= nb_test; i++) {
				System.out.println("Case #" + i + ": " + new C(sc));
			}
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
