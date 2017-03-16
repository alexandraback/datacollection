import java.util.*;

public class c {
	static class Ch {
		public int sign;
		public char ch;
	
		public Ch(int s, char c) {
			sign = s;
			ch = c;
		}
		
		public void minus() {
			multiply(-1);
		}
		
		public void multiply(int s) {
			sign = sign * s;
		}
		
		public Boolean equal(Ch other) {
			return sign == other.sign && ch == other.ch;
		}
		
		public void multiply(int s, char c1, char c2) {
			switch (c1) {
			case '1':
				switch (c2) {
				case '1': sign = s * 1; ch = '1'; return;
				case 'i': sign = s * 1; ch = 'i'; return;
				case 'j': sign = s * 1; ch = 'j'; return;
				case 'k': sign = s * 1; ch = 'k'; return;
				default:
					System.out.println("Error !! " + c2);
					sign = s * 1; ch = '1'; return;
				}
			case 'i':
				switch (c2) {
				case '1': sign = s * 1; ch = 'i'; return;
				case 'i': sign = s * -1; ch = '1'; return;
				case 'j': sign = s * 1; ch = 'k'; return;
				case 'k': sign = s * -1; ch = 'j'; return;
				default:
					System.out.println("Error !! " + c2);
					sign = s * 1; ch = '1'; return;
				}
			case 'j':
				switch (c2) {
				case '1': sign = s * 1; ch = 'j'; return;
				case 'i': sign = s * -1; ch = 'k'; return;
				case 'j': sign = s * -1; ch = '1'; return;
				case 'k': sign = s * 1; ch = 'i'; return;
				default:
					System.out.println("Error !! " + c2);
					sign = s * 1; ch = '1'; return;
				}
			case 'k':
				switch (c2) {
				case '1': sign = s * 1; ch = 'k'; return;
				case 'i': sign = s * 1; ch = 'j'; return;
				case 'j': sign = s * -1; ch = 'i'; return;
				case 'k': sign = s * -1; ch = '1'; return;
				default:
					System.out.println("Error !! " + c2);
					sign = s * 1; ch = '1'; return;
				}
				
			default:
				System.out.println("Error !!! " + c1);
				sign = s * 1; ch = '1'; return;
			}
		}

		
		public void multiply(char c) {
			multiply(sign, ch, c);
		}
		public void multiply(Ch other) {
			multiply(sign * other.sign, ch, other.ch);
		}
		
		public void premultiply(char c) {
			multiply(sign, c, ch);
		}
	}
	
	static class Pos {
		public int cnt;
		public int pos;
		public Pos(int c, int p) {
			cnt = c;
			pos = p;
		}
		
		public Pos() {
			this(-1, -1);
		}
		
		public Boolean valid() {
			return cnt >= 0;
		}
	}
	static Pos before(String line){
		int cnt = 0;
		int pos = 0;
		int length = line.length();
		Ch now = new Ch(1, '1');
		now.multiply(line.charAt(pos));
		
//		System.out.println(line.charAt(pos));
//		System.out.printf("now: sign %d, char %c\n", now.sign, now.ch);
		
		Ch i = new Ch(1, 'i');
		
		while (!now.equal(i) && cnt < 4) {
			pos ++;
			if (pos >= length) {
				cnt ++;
				pos = 0;
			}
			now.multiply(line.charAt(pos));
//			System.out.println(line.charAt(pos));
//			System.out.printf("now: sign %d, char %c\n", now.sign, now.ch);
		}
		
		if (now.equal(i)) return new Pos(cnt, pos);
		else return new Pos(-1, -1);
	}
	
	static Pos end(String line){
		int cnt = 0;
		int length = line.length();
		int pos = length - 1;
		Ch now = new Ch(1, '1');
		now.multiply(line.charAt(pos));

//		System.out.println(line.charAt(pos));
//		System.out.printf("now: sign %d, char %c\n", now.sign, now.ch);
		Ch k = new Ch(1, 'k');
		
		while (!now.equal(k) && cnt < 4) {
			pos --;
			if (pos <= -1) {
				cnt ++;
				pos = length - 1;
			}
			now.premultiply(line.charAt(pos));

//			System.out.println(line.charAt(pos));
//			System.out.printf("now: sign %d, char %c\n", now.sign, now.ch);
		}
		
		if (now.equal(k)) return new Pos(cnt, pos);
		else return new Pos(-1, -1);
	}
	
	static Boolean mid(String line, int before, int end, int cnt) {
		if(cnt > 5) {
			cnt = cnt % 4;
			if (cnt <= 1) cnt += 4;
		}
		
		int length = line.length();
		int pos = before+1;
		
		if (pos >= length) {
			cnt --;
			pos = 0;
			if(cnt <= 0) return false;
		}
		if (cnt == 1 && pos >= end) return false;
		
		Ch now = new Ch(1, '1');
		now.multiply(line.charAt(pos));
		
		Ch j = new Ch(1, 'j');
		
		while (true) {
			pos ++;
			if (pos >= length) {
				cnt --;
				pos = 0;
				if(cnt <= 0) break;
			}
			if (cnt == 1 && pos >= end) break;
			now.multiply(line.charAt(pos));
		}
		
		if (now.equal(j)) return true;
		else return false;
		
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			// TODO

			int l = in.nextInt();
			int x = in.nextInt();
			in.nextLine();
			String line = in.nextLine();
			
//			System.out.println(line);
			
			Boolean re = true;
			
			if (l == 1) {
				re = false;
			} else {
				Pos b = before(line);
				
//				System.out.printf("before: cnt %d, pos %d\n", b.cnt, b.pos);
				
				Pos e = end(line);
//				System.out.printf("end: cnt %d, pos %d\n", e.cnt, e.pos);
				
				if (b.valid() && e.valid() && x - b.cnt - e.cnt > 0) 
					re = mid(line, b.pos, e.pos, x - b.cnt - e.cnt);
				else re = false;
			}
			
			System.out.printf("Case #%d: %s\n", t, re?"YES":"NO");
		}
	}
}