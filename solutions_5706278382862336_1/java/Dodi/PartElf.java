import java.util.ArrayList;
import java.util.List;

import commons.read.ProblemReader;
import commons.read.model.Case;
import commons.read.model.Cases;
import commons.write.SolutionWriter;


public class PartElf {
	private static final String PATH = "/home/dodie/workspace_codejam/codejam201404/PartElf/src/main/resources";
	private static final String INPUT_FILE = "A-large.in";
	private static final String OUT_FILE = "A-large.out";
	
	public static void main(String[] args) {
		Cases cases = new ProblemReader(PATH, INPUT_FILE).read().split().toProblem();
		List<String> solution = new ArrayList<String>();
		
		for (Case problem : cases) {
			System.out.println(problem);
			String input = problem.getLines().get(0).get(0);
			
			long p = Long.parseLong(input.substring(0, input.indexOf("/")));
			long q = Long.parseLong(input.substring(input.indexOf("/") + 1));
			
			Model model = new Model(p, q);
			
			if (model.depth() != Integer.MAX_VALUE) {
				int elfgen = model.firstElfGeneration();
				if (elfgen != Integer.MAX_VALUE) {
					solution.add("Case #" + problem.getCaseNumber() + ": " + elfgen);
				} else {
					solution.add("Case #" + problem.getCaseNumber() + ": impossible");
				}
			} else {
				solution.add("Case #" + problem.getCaseNumber() + ": impossible");
			}
		}
		
		new SolutionWriter(PATH, OUT_FILE).write(solution);
	}
	
	
	private static class Model {
		final long p;
		final long q;
		
		public Model(long p, long q) {
			this.p = p;
			this.q = q;
		}
		
		public int firstElfGeneration() {
			return firstElfGeneration(0);
		}
		
		private int firstElfGeneration(int currentDepth) {
			if (currentDepth > 40) {
				return Integer.MAX_VALUE;
			}
			
			if (p == q) {
				return currentDepth;
			} else {
				long childValueSum = p * 2;
				
				if (childValueSum <= q) {
					return new Model(childValueSum, q).firstElfGeneration(currentDepth + 1);
				} else {
					return currentDepth + 1;
				}
			}
		}

		public int depth() {
			return depth(0);
		}
		
		private int depth(int currentDepth) {
			if (currentDepth > 40) {
				return Integer.MAX_VALUE;
			}
			
			if (p == 0 || p == q) {
				return currentDepth;
			} else {
				long childValueSum = p * 2;
				
				if (childValueSum <= q) {
					return new Model(childValueSum, q).depth(currentDepth + 1);
				} else {
					return new Model(childValueSum - q, q).depth(currentDepth + 1);
				}
			}
		}
		
	}
	
}
