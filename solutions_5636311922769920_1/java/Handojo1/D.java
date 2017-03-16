package contest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class D {
	public static void main(String[] args) throws IOException {
		BufferedReader baca;
		BufferedWriter tulis;
		if (args.length == 0) {
			baca = new BufferedReader(new InputStreamReader(System.in));
			tulis = new BufferedWriter(new OutputStreamWriter(System.out));
		} else {
			//System.out.print(args[0] + " " + args[1]);
			baca = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
			tulis = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(args[1])));
		}
		
		int N = Integer.parseInt(baca.readLine());
		for (int l=1;l<=N;++l) {
			tulis.write("Case #"+Integer.toString(l)+":");
			String[] pecah = baca.readLine().split(" ");
			int basis = Integer.parseInt(pecah[0]);
			int generasi = Integer.parseInt(pecah[1]);
			int maks = Integer.parseInt(pecah[2]);
			
			if (generasi == 1) {
				if (maks < basis) {
					tulis.write(" IMPOSSIBLE");
				} else {
					for (int j=1;j<=basis;++j) tulis.write(" "+Integer.toString(j));
				}
			} else {
				if (2*maks < basis) {
					tulis.write(" IMPOSSIBLE");
				} else {
					BigInteger dasar = BigInteger.ONE;
					BigInteger pangkat = BigInteger.ONE;
					for (int j=1;j<generasi;++j) {
						pangkat = pangkat.multiply(BigInteger.valueOf(basis));
						dasar = dasar.add(pangkat);
					}
					
					for (int j=1;j<=basis;j+=2) {
						BigInteger hasil = dasar.multiply(BigInteger.valueOf(j-1)).add(BigInteger.valueOf(2));
						if (j == basis) hasil = hasil.subtract(BigInteger.ONE);
						tulis.write(" "+hasil.toString());
					}
				}
			}
			tulis.append('\n');
		}
		
		baca.close();
		tulis.close();
	}

}
