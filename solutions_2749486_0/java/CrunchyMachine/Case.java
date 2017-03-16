package abc;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Set;

import abc.template.AbstractCase;

public class Case extends AbstractCase {

	private final long targetX;
	private final long targetY;
	private final Set<Vertex> visited;

	public Case(int caseNumber, long x, long y) {
		super(caseNumber);
		this.targetX = x;
		this.targetY = y;
		this.visited = new HashSet<>();
	}

	@Override
	protected String doCalculation() {
		Deque<Vertex> queue = new ArrayDeque<>();
		queue.offer((new Vertex(0, 0, 1)));
		while (true) {
			Vertex current = queue.poll();
			if (visited.contains(current)) {
				continue;
			}
			visited.add(current);
			if (current.x == targetX && current.y == targetY) {
				return current.getUsedPath();
			}
			doJump(queue, current.x, current.y + current.jumpSize, current, 'N');
			doJump(queue, current.x, current.y - current.jumpSize, current, 'S');
			doJump(queue, current.x + current.jumpSize, current.y, current, 'E');
			doJump(queue, current.x - current.jumpSize, current.y, current, 'W');
		}
	}

	private void doJump(Deque<Vertex> queue, long x, long y, Vertex current, char usedPath) {
		Vertex newVertex = new Vertex(x, y, current, usedPath);
		if (visited.contains(newVertex)) {
			return;
		}
		queue.offer(newVertex);
	}

	private static class Vertex {
		private final long x;
		private final long y;
		private final long jumpSize;
		private final Vertex previous;
		private final char usedPath;

		public Vertex(long x, long y, long jumpSize) {
			this.x = x;
			this.y = y;
			this.jumpSize = jumpSize;
			this.previous = null;
			this.usedPath = '\0';
		}

		public Vertex(long x, long y, Vertex previous, char usedPath) {
			this.x = x;
			this.y = y;
			this.jumpSize = previous.jumpSize + 1;
			this.previous = previous;
			this.usedPath = usedPath;
		}

		public String getUsedPath() {
			Deque<Character> stack = new ArrayDeque<>();
			Vertex current = this;
			while (current.previous != null) {
				stack.push(current.usedPath);
				current = current.previous;
			}
			StringBuilder sb = new StringBuilder();
			while (!stack.isEmpty()) {
				sb.append(stack.pop());
			}
			return sb.toString();
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (int) (x ^ (x >>> 32));
			result = prime * result + (int) (y ^ (y >>> 32));
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Vertex other = (Vertex) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
	}
}
