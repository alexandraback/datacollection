import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class EjercicioA {
	public static boolean prueba = false;

	public static void main(String args[]) {

		try {
			FileOutputStream fos = new FileOutputStream(
					new File("solucion.txt"));

			OutputStream os = System.out;
			if (!prueba)
				os = fos;
			Scanner s = new Scanner(new File("problema.txt"));
			int a = s.nextInt();

			for (int i = 0; i < a; i++) {
				long m = s.nextLong();
				int mots = s.nextInt();
				
				long mot[] = new long[mots];
				for (int j= 0; j < mots; j++ ){
					mot[j] = s.nextLong();
				}
				Arrays.sort(mot);
				int cant[] = new int[10000000];
				long mo[] = new long[10000000];
				int pos = 1;
				mo[0] = m;
				for (int j= 0; j < mots; j++ ){
					for (int k = 0; k < pos; k++){
						long val = mot[j];
						if (mo[k] > val){
							mo[k] += val;
						}else{
							if (mo[k] > 1){
								pos++;
							//	System.out.println(pos);
								mo[pos-1] = mo[k] * 2 -1;
								cant[pos  - 1] = cant[k]+1;
							}
							cant[k]++;
							
						}
					}
				}
				int min = Integer.MAX_VALUE;
				for (int j = 0 ; j < pos ; j++){
					if (min > cant[j])
						min = cant[j];
				}
				
				os.write(("Case #" + (i + 1) + ": " + min + "\n").getBytes());

			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	private static String getCeil(String min) {
		String res = "1";
		for (int i = 1; i < min.length()/2 ; i++)
			res += "0";
		res +=1;
		return res;
	}

	private static String multiplicarString(String a, String b) {
		/*
		 * if (b.length() > a.length()){ String aux = a; b = aux; b = a; a =
		 * aux; }
		 */
		int[] result = new int[a.length() + b.length()];
		for (int i = b.length() - 1; i >= 0; i--) {
			int carry = 0;
			int startIndex = b.length() - 1 - i;
			for (int j = a.length() - 1; j >= 0; j--) {
				int temp = (b.charAt(i) - '0')
						* (a.charAt(j) - '0')
						+ result[result.length - 1 - startIndex
								- (a.length() - 1 - j)] + carry;
				result[result.length - 1 - startIndex - (a.length() - 1 - j)] = temp % 10;
				carry = temp / 10;
			}
			int index = result.length - 1 - startIndex - a.length();
			while (carry != 0) {
				int temp = result[index] + carry;
				result[index] = temp % 10;
				carry = temp / 10;
				index--;
			}
		}
		String p = "";
		for (int i = result[0] == 0 ? 1 : 0; i < result.length; i++) {
			p += result[i];
		}
		return p;
	}

	private static boolean checkPalindrom(String string) {
		for (int i = 0; i < string.length() / 2; i++) {
			if (string.charAt(i) != string.charAt(string.length() - 1 - i))
				return false;
		}
		return true;
	}

	private static int compareTo(String a, String b) {
		if (a.length() == b.length()) {
			return a.compareTo(b);
		}
		return a.length() - b.length();
	}
}
