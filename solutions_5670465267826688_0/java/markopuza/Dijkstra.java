import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


 class Kvat {

	private boolean sign;
	private char ch;
	
	public Kvat(boolean b, char ch) {
		this.sign = b;
		this.ch = ch;
	}
	
	public Kvat() {
		this.sign = true;
		this.ch = '1';
	}
	
	public void setSign(boolean s) {
		this.sign = s;
	}
	
	public void setCh (char ch) {
		this.ch = ch;
	}
	
	public boolean getSign() {
		return this.sign;
	}
	
	public char getCh() {
		return this.ch;
	}
	
	public String toString() {
		return ("" + this.sign + " " + this.ch);
	}
}



public class Dijkstra {
	
	public static Kvat op(Kvat k, Kvat q) {
		Kvat result = new Kvat();
		result.setSign((k.getSign() ^ q.getSign()));
		
		switch (k.getCh()) {
		case '1':
			switch (q.getCh()) {
			case '1': result.setCh('1');
				break;

			case 'i': result.setCh('i');
				break;

			case 'j': result.setCh('j');
				break;

			case 'k': result.setCh('k');
				break;
			default:
				break;
			}
			
			break;

		case 'i':
			switch (q.getCh()) {
			case '1': result.setCh('i');
				break;

			case 'i': result.setCh('1');
				result.setSign(!result.getSign());
				break;

			case 'j': result.setCh('k');
				break;

			case 'k':  result.setCh('j');
			result.setSign(!result.getSign());
				break;
			default:
				break;
			}
			break;

		case 'j':
			switch (q.getCh()) {
			case '1': result.setCh('j');
				break;

			case 'i': result.setCh('k');
			result.setSign(!result.getSign());
				break;

			case 'j': result.setCh('1');
			result.setSign(!result.getSign());
				break;

			case 'k': result.setCh('i');
				break;
			default:
				break;
			}
			break;

		case 'k':
			switch (q.getCh()) {
			case '1': result.setCh('k');
				break;

			case 'i': result.setCh('j');
				break;

				case 'j': result.setCh('i');
				result.setSign(!result.getSign());
				break;

			case 'k':
				result.setCh('1');
				result.setSign(!result.getSign());
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		result.setSign(!result.getSign());
		return result;
	}

	public static Kvat product(String s) {
		Kvat result = new Kvat(true, '1');
		for (int k = 0; k < s.length(); k++) {
			result = op(result, new Kvat(true, s.charAt(k)));
			//System.out.println("medzikrok " + result.toString());
		}
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		
		/* String test = "1ijk";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				System.out.println(op(new Kvat(true, test.charAt(i)), new Kvat(true, test.charAt(j))));
			}
		}
		*/ 
		
		BufferedReader in = new  BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= t; i++) {
			
			String[] next = in.readLine().split(" ");
			int l = Integer.parseInt(next[0]);
			int x = Integer.parseInt(next[1]);
			String s = in.readLine();
			String sentence = "";
			if (x % 4 == 0) {
				System.out.println("Case #" + i + ": " + "NO");
				continue;
			} 
			
			if (x <= 8) {
				for (int k = 0; k < x; k++) {
					sentence += s;
				}
			}
			else {
				for (int k = 0; k < (8 + x % 4); k++) {
					sentence += s;
				}
			}	
			Kvat wholeProduct = product(sentence);
			if (wholeProduct.getSign() != false || wholeProduct.getCh() != '1') {
				System.out.println("Case #" + i + ": " + "NO");
				continue;
			}
			//System.out.println("Sentence: " + sentence);
			
			Kvat[] partialProducts = new Kvat[sentence.length()];
			partialProducts[0] = new Kvat(true, sentence.charAt(0));
			for (int k = 1; k < sentence.length(); k++) {
				partialProducts[k] = op(partialProducts[k-1], new Kvat(true, sentence.charAt(k)));
			}
			
			//for (int k = 0; k < sentence.length(); k++) {
			//	System.out.println(partialProducts[k].toString());
			//}
			
			boolean result = false;
			for (int k = 0; k < sentence.length(); k++) {
				if (partialProducts[k].getSign() == true && partialProducts[k].getCh() == 'i') {
					int cursj = k+1;
					Kvat currentProduct = new Kvat(true, '1');
					//System.out.println("cursj " + cursj + " sl " + sentence.length());
					while (!result && cursj < sentence.length()) {
						//System.out.println("curprod " + currentProduct.toString());
						currentProduct = op(currentProduct, new Kvat(true, sentence.charAt(cursj)));
						if (currentProduct.getSign() == true && currentProduct.getCh() == 'j') {
							result = true;
							//System.out.println("i " + k + " j " + cursj);
							break;
						}
						else {
							cursj++;
						}
					}
				}
			}
			
			if (result) System.out.println("Case #" + i + ": " + "YES");
			else System.out.println("Case #" + i + ": " + "NO");
			
		}
	}

}
