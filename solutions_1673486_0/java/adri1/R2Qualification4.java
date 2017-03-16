package question;

import java.text.DecimalFormat;

import utils.FileTools;

public class R2Qualification4 {
	public static void main(String[] args) {
		try {
			FileTools ft = new FileTools("A-small-attempt0.in");
			int T = Integer.parseInt(ft.in.readLine());
			String line;
			int l = 0;
			DecimalFormat r = new DecimalFormat();
			r.applyPattern("#0.000000");// 保留小数位数，不足会补零
			while ((line = ft.in.readLine()) != null) {
				ft.out.write("Case #" + (++l) + ": ");
				String[] str = line.split(" ");
				int typed = Integer.parseInt(str[0]);
				int length = Integer.parseInt(str[1]);
				double total = 0.0;
				double expected;
				line = ft.in.readLine();
				str = line.split(" ");
				double ch[] = new double[str.length];
				for (int i = 0; i < str.length; i++) {
					ch[i] = Double.parseDouble(str[i]);
				}
				total = length > 0 ? length + 2 : length + 1;
				double totalchance = 1;
				for (int i = 0; i < typed; i++) {
					totalchance *= ch[i];
					int need = (length - typed + 1 + 2 * (typed - 1 - i));
					expected = totalchance * need + (1 - totalchance)
							* (need + length + 1);
					if (expected < total)
						total = expected;
				}

				ft.out.write(r.format(total));
				System.out.println("Case #" + l + ": " + r.format(total));
				ft.out.newLine();
			}
			ft.out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
