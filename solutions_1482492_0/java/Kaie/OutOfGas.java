package outofgas;

import template.Template;

public class OutOfGas extends Template {
	public static void main(String[] args) throws Exception {
		init("src/outofgas/B-small-attempt0");
		int lines = readInt();
		for (int i = 1; i <= lines; i++) {
			String[] l = readStringArray();
			double d = Double.parseDouble(l[0]);

			int n = Integer.parseInt(l[1]);
			int A = Integer.parseInt(l[2]);

			double[] t = new double[n];
			double[] x = new double[n];

			for (int j = 0; j < n; j++) {
				double[] o = readDoubleArray();
				t[j] = o[0];
				x[j] = o[1];
			}
			double[] a = readDoubleArray();

			write("Case #" + i + ":");

			for (int j = 0; j < A; j++) {
				double position = 0;
				double time = 0;
				double velocity = 0;
				int index = 0;

				for (index = 0; index < t.length; index++) {
					double p1 = position + 0.5 * a[j] * (t[index] - time)
							* (t[index] - time);
					if (p1 <= x[index]) {
						if (p1 > d) {
							time = time
									- velocity
									/ a[j]
									+ Math.sqrt(velocity * velocity / a[j]
											/ a[j] + 2 * (d - position) / a[j]);
							position = d;
						} else {
							position = p1;
							velocity += (t[index] - time) * a[j];
							time = t[index];
						}
					} else {
						if (x[index] > d) {
							time += (d - x[index - 1])
									* (t[index] - t[index - 1])
									/ (x[index] - x[index - 1]);
							position = d;
						} else {
							velocity = Math.sqrt(2 * (x[index] - position)
									/ a[j])
									* a[j];

							position = x[index];
							time = t[index];
						}
					}
				}
				if (position < d) {
					time = time
							- velocity
							/ a[j]
							+ Math.sqrt(velocity * velocity / a[j] / a[j] + 2
									* (d - position) / a[j]);
				}
				write("" + time);

			}
		}

	}

}
