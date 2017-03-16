import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class Main {
	
	public static class Chest {
		public long ix;
		public long type;
		public boolean open;
		public List<Long> keys = new ArrayList<Long>();
		public Chest(long ix, long type) {
			this.type = type;
			this.ix = ix;
		}
	}
	
	
	private static String backtrack(final List<Long> keys, List<Chest> chests, LinkedList<Chest> path, Set<Chest> unlucky) {
		
		//System.out.println(sb.toString());
		if (path.size() == chests.size()) {
			StringBuilder sb = new StringBuilder();
			for (Chest chest : path) {
				if (sb.length() > 0) {
					sb.append(" ");
				}
				sb.append(chest.ix);
			}
			return sb.toString();
		} else {
			List<Long> allKeys = new ArrayList<Long>(keys);
			List<Long> allTypes = new ArrayList<Long>();
			for (Chest chest : chests) {
				if (!chest.open) {
					allKeys.addAll(chest.keys);
					allTypes.add(chest.type);
				}
			}
			
			for (Long type : allTypes) {
				boolean removed = allKeys.remove(type);
				if (!removed) {
					return null;
				}
			}
			Set<Chest> unl = new HashSet<Chest>();
			for (Chest chest : chests) {
				
				if (!chest.open && keys.contains(chest.type)) {
					boolean t = true;
					for (Chest ul : unlucky) {
						if (ul.type == chest.type) {
							boolean subset = true;
							List<Long> toCheck = new ArrayList<Long>(ul.keys);
							for (Long k : chest.keys) {
								if (!toCheck.remove(k)) {
									subset = false;
									break;
								}
							}
							if (subset) {
								t = false;
								break;
							}
						}
					}
					if (!t) continue;
					chest.open = true;
					keys.remove(chest.type);
					path.add(chest);
					for (long k : chest.keys) {
						keys.add(k);
					}
					String solution = backtrack(keys, chests, path, unl);
					if (solution != null) {
						return solution;
					}
					unlucky.add(chest);
					chest.open = false;
					keys.add(chest.type);
					for (long k: chest.keys) {
						keys.remove(k);
					}
					path.removeLast();
				}
			}
		}
		return null;
	}

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new FileInputStream(new File("small.txt")));
		int T = scanner.nextInt();
		scanner.nextLine();
		for (int t = 0; t < T; t++) {
			int K = scanner.nextInt();
			int N = scanner.nextInt();
			scanner.nextLine();
			List<Chest> chests = new ArrayList<Main.Chest>();
			List<Long> keys = new ArrayList<Long>();
			for (int k = 0; k < K; k++) {
				keys.add(scanner.nextLong());
			}
			Collections.sort(keys);
			scanner.nextLine();
			for (int n = 0; n < N; n++) {
				long type = scanner.nextLong();
				long numberOfKeys = scanner.nextLong();
				//System.out.print(n + 1 + " " + type + " ");
				Chest chest = new Chest(n + 1, type);
				chests.add(chest);
				for (long key = 0; key < numberOfKeys; key++) {
					long k = scanner.nextLong();
					//System.out.print(k + " ");
					chest.keys.add(k);
					Collections.sort(chest.keys);
				}
				//System.out.println();
				if (scanner.hasNext()) scanner.nextLine();
			}
			String solution = backtrack(keys, chests, new LinkedList<Chest>(), new HashSet<Main.Chest>());
			if (solution == null) {
				System.out.println("Case #" + (t + 1) + ": IMPOSSIBLE");
			} else {
				System.out.println("Case #" + (t + 1) + ": " + solution);
			}
		}
	}

}
