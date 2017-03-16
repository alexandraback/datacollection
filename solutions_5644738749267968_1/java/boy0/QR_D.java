package boy0;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;

public class QR_D {
	public static void main(String[] args) throws IOException {
		String strLine;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		QR_D me = new QR_D();

		// me.init();

		strLine = br.readLine();
		int T = Integer.parseInt(strLine);
		String[] as;
		int y, z;
		for (int x = 1; x <= T; x++) {
			strLine = br.readLine();
			int n = Integer.parseInt(strLine);
			LinkedList<Integer> naomi = new LinkedList<Integer>();
			LinkedList<Integer> ken = new LinkedList<Integer>();
			strLine = br.readLine();
			as = strLine.split(" ");
			for (int i = 0; i < n; i++) {
				naomi.add((int) (Double.parseDouble(as[i]) * 1000000));
			}
			Collections.sort(naomi);
			strLine = br.readLine();
			as = strLine.split(" ");
			for (int i = 0; i < n; i++) {
				ken.add((int) (Double.parseDouble(as[i]) * 1000000));
			}
			Collections.sort(ken);
			y = me.exec_deceitful(n, new LinkedList<Integer>(naomi),
					new LinkedList<Integer>(ken));
			z = me.exec_war(n, new LinkedList<Integer>(naomi),
					new LinkedList<Integer>(ken));
			System.out.println("Case #" + x + ": " + y + " " + z);
			// System.out.println(naomi);
			// System.out.println(ken);
		}
	}

	private int priv_length = 0;

	public void init() {

	}

	public int exec_deceitful(int n, LinkedList<Integer> naomi,
			LinkedList<Integer> ken) {
		int y = 0;
		// War에서 Ken 의 전략: 더 높은 수가 있으면 낸다. 없으면 가장 낮은 수를 버린다.
		// Deceitful War에서 Naomi 의 전략:
		// Ken의 가장 낮은 수 보다 낮은 수는 모두 높게 속여 버린다.
		// Ken의 가장 낮은 수 보다 조금 높은 수를 내면 포인트 획득. Ken의 가장 높은 수 보다 높다고 속여서 Ken이 낮은
		// 수를 내도록 유도하는 속임수.

		for (int i = 0; i < n; i++) {
			Integer chosen_naomi = naomi.removeFirst(); // 작은거 부터.
			Integer min_ken = ken.getFirst();
			if (min_ken.compareTo(chosen_naomi) > 0) {
				// ken win
				ken.removeLast();
			} else {
				// naomi win
				y++;
				ken.removeFirst();
			}
		}

		return y;
	}

	public int exec_war(int n, LinkedList<Integer> naomi,
			LinkedList<Integer> ken) {
		int z = 0;
		// War에서 Ken 의 전략: 더 높은 수가 있으면 낸다. 없으면 가장 낮은 수를 버린다.
		// War에서 Naomi 의 전략: 가장 높은 수 부터 하나씩 낸다.

		for (int i = 0; i < n; i++) {
			Integer chosen_naomi = naomi.removeLast(); // 큰거 부터.
			Integer max_ken = ken.getLast();
			if (max_ken.compareTo(chosen_naomi) > 0) {
				// ken win
				ken.removeLast();
			} else {
				// naomi win
				z++;
				ken.removeFirst();
			}
		}

		return z;
	}

	private boolean func_priv(int offset) {
		return true;
	}

}
