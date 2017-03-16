package codejam2012.round1c;

import java.util.ArrayList;
import java.util.List;

import reusable.CodeJamBase;

public class A_DiamondInheritance {
	private static class Inherit {
		private List<Inherit> parents = new ArrayList<>();
		private final int number;

		public Inherit(int number) {
			this.number = number;
		}

		@Override
		public boolean equals(Object obj) {
			return number == ((Inherit) obj).number;
		}

		@Override
		public String toString() {
			return String.valueOf(number);
		}
	}

	public static void main(String[] args) {
		new CodeJamBase("A-small-attempt0") {

			int countMatchingParents(List<Inherit> parents, Inherit match) {
				if (parents.size() == 0) {
					return 0;
				}

				int result = 0;

				for (Inherit parent : parents) {
					if (parent.equals(match)) {
						result++;
					}
					result += countMatchingParents(parent.parents, match);
				}

				return result;
			}

			@Override
			protected String solution() {
				int numberOfClasses = nextInt();

				List<Inherit> classes = new ArrayList<>();
				for (int i = 0; i < numberOfClasses; i++) {
					classes.add(new Inherit(i + 1));
				}

				for (int i = 0; i < numberOfClasses; i++) {
					int[] inheritFrom = nextIntArray();
					for (int j = 1; j < inheritFrom.length; j++) {
						classes.get(i).parents.add(classes.get(inheritFrom[j] - 1));
					}
				}

				boolean result = false;

				for (Inherit clazz : classes) {
					for (Inherit clazz2 : classes) {
						if (clazz.equals(clazz2)) {
							continue;
						}
						result |= countMatchingParents(clazz.parents, clazz2) > 1;
					}
				}

				return (result ? "Yes" : "No");
			}

		}.run();
	}
}
