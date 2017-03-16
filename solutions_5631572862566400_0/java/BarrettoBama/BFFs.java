import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class BFFs {

	static int n;
	static int[] bff;

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();

		for (int i = 1; i <= t; ++i) {
			n = in.nextInt();
			bff = new int[n + 1];

			LinkedList<Integer> path = new LinkedList<>();
			LinkedList<Integer> toDo = new LinkedList<>();
			LinkedList<List<Integer>> circles = new LinkedList<>();
			LinkedList<List<Integer>> paths = new LinkedList<>();

			for (int j = 1; j <= n; j++) {
				bff[j] = in.nextInt();
				toDo.add(j);
			}
			// System.out.println(toDo);

			while (!toDo.isEmpty()) {
				path = new LinkedList<>();
				path.add(toDo.removeFirst());
				while (true) {
					// System.out.println("TODO: "+toDo);
					// System.out.println("PATH: "+path);

					if (toDo.contains(bff[path.getLast()])) {
						Integer next = toDo.get(toDo.indexOf(bff[path.getLast()]));
						toDo.remove(toDo.indexOf(bff[path.getLast()]));
						path.add(next);
					} else {
						if (path.contains(bff[path.getLast()])) {
							// circle
							int circleFirst = path.indexOf(bff[path.getLast()]);
							circles.add(path.subList(circleFirst, path.size()));
							if (circleFirst != 0)
								paths.add(path.subList(0, circleFirst));
						} else {
							// path
							boolean solved = false;
							for(List<Integer>x:circles){
								if(x.contains(bff[path.getLast()])){
									paths.add(path);
									solved = true;
									break;
								}
							}
							if(!solved){
								for(List<Integer>x:paths){
									if(x.contains(bff[path.getLast()])){
										if(x.get(x.size()-1).intValue() == bff[path.getLast()]){
											LinkedList<Integer> nPath = new LinkedList<>();
											for(int k = 0; k < x.indexOf(bff[path.getLast()]);k++){
												nPath.add(x.get(k));
											}
											nPath.addAll(path);
										}else{
											LinkedList<Integer> nPath = new LinkedList<>();
											for(int k = 0; k < x.indexOf(bff[path.getLast()]);k++){
												nPath.add(x.get(k));
											}
											nPath.addAll(path);
										}
									}
								}
							}else{
								paths.add(path);
							}
							
						}
						break;
					}
				}

			}
			int best = 0;
			for (List<Integer> x : circles) {
				int max = x.size();
				int lA = 0;
				int eA = 0;
				int lB = 0;
				if (max == 2) {
					for (List<Integer> y : paths) {
						if (x.contains(bff[y.get(y.size() - 1)])) {
							if (y.size() > lA && bff[y.get(y.size() - 1)] != eA) {
								lB = lA;
								lA = y.size();
								eA = bff[y.get(y.size() - 1)];
							} else {
								if (y.size() > lB && bff[y.get(y.size() - 1)] != eA) {
									lB = y.size();
								}
							}
						}
					}
				}
				max += lA + lB;
				if (max > best)
					best = max;
			}

			System.out.println("Case #" + i + ": " + best);
		}

		in.close();
	}

}
