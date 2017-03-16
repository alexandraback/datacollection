package c2434486.a;

import java.util.ArrayList;
import java.util.Collections;

import com.google.common.collect.Lists;



class Case {
    final int num;
    long A;
    int N;
    int[] n;


    public Case(int num) {
        this.num = num;
    }
}

class Solver {
    private final Case cas;
    private int result = 0;

    public Solver(Case cas) {
        this.cas = cas;
    }

    String solve() {
		ArrayList<Integer> ll = Lists.newArrayListWithCapacity(cas.N);
		for (int i = 0; i < cas.N; i++) {
			ll.add(cas.n[i]);
		}
		Collections.sort(ll);

		long a = cas.A;

		for (int i = 0; i < cas.N; i++) {
			int n = ll.get(i);
			if (n < a) {
				a += n;
				continue;
			}

			int costToRemoveAllTheRest = cas.N - i;
			int costToDigestNext = 0;
			while (a <= n && costToDigestNext < costToRemoveAllTheRest) {
				a += (a-1);
				costToDigestNext++;
			}
			if (costToRemoveAllTheRest <= costToDigestNext) {
				result += costToRemoveAllTheRest;
				break;
			} else {
				result += costToDigestNext;
				a += n;
			}

			if (result >= cas.N) {
				result = cas.N;
				break;
			}
		}


		return result + "";
    }

}
