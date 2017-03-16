import java.util.ArrayList;
import java.util.List;


public class C {
	private  static List<QV> createQVs(String s) {
		List<QV> result = new ArrayList<QV>();
		for (int i = 0; i < s.length(); i++) {
			result.add(new QV(1, Q.valueOf(s.substring(i, i+1))));
		}
		return result;
	}
	
	private static void reduce(List<QV> qvs) {
		QV qv = qvs.remove(0);
		qvs.set(0, qv.mul(qvs.get(0)));
	}
	
	public static boolean solve(String s) {
		List<QV> qvs = createQVs(s);
		
		List<QV> qvs2 = new ArrayList<QV>(qvs);
//		System.err.println(qvs2.toString());
		while (qvs2.size() > 1) {
			reduce(qvs2);
		}
//		System.err.println(qvs2.toString());
		if (!qvs2.get(0).equals(QV.NE)) {
			return false;
		}
		
		return find1(qvs);
	}

	private static boolean find1(List<QV> qvs) {
		int i = 0;
		while (qvs.size() > 2) {
			if (qvs.get(0).equals(QV.I)) {
//				System.err.println("Found i by " + i + " reductions");
				List<QV> qvs2 = new ArrayList<QV>(qvs);
				qvs2.remove(0);
				if (find2(qvs2)) {
					return true;
				}
			}
			reduce(qvs);
			i++;
		}
		
		return false;
	}

	private static boolean find2(List<QV> qvs) {
		int i = 0;
		while (qvs.size() > 1) {
			if (qvs.get(0).equals(QV.J)) {
//				System.err.println("Found j by " + i + " reductions");
				return true;
				
//				List<QV> qvs2 = new ArrayList<QV>(qvs);
//				qvs2.remove(0);
//				if (find3(qvs2)) {
//					return true;
//				}
			}
			reduce(qvs);
			i++;
		}
		
		return false;
	}

	private static boolean find3(List<QV> qvs) {
		System.err.println(qvs);
		while (qvs.size() > 1) {
			reduce(qvs);
		}
		System.err.println(qvs);
		return qvs.get(0).equals(QV.K);
	}
	
}
