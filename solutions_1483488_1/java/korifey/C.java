package gcj2012.qual;

import java.util.Arrays;

import common.AbstractRunner;
import common.AbstractRunner.SIZE;

public class C extends AbstractRunner {
		
	
	@Override
	public void handleCase(int caseNumber) throws Exception {
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		
		int pow = 1;
		int n = 0;
		for (int p = A; p>=10; p = p/10) {
			n++;
			pow *= 10;
		}
		
		int res = 0;
		int [] rr = new int[n];
		for (int x=A; x<=B; x++) {
			Arrays.fill(rr, 0);
			int rrlen = 0;
			int xx = x;
			cycle: for (int i=0; i<n; i++) {
				xx = (xx % 10) * pow + (xx/10);
				if (xx > x && xx <=B) {
					for (int j=0; j<rrlen; j++) {
						if (rr[j] == xx) continue cycle;
					}
					rr[rrlen++] = xx;
					res ++;
				}
			}
		}
		
		out.write(Integer.toString(res)+"\n");
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		new C().init(SIZE.large).execute();
	}

}
