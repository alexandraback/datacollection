package round1a;


import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;

public class ProblemB {
	
	// Workaround for not being able to pipe a file to stdin in Eclipse.
	private static final String IN_FILE = "text/" + "B-large.in";
	
	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE)))) {
			int numCases = in.nextInt();
			for (int i = 0; i < numCases; i++) {
				int size = in.nextInt();
				int[][] lines = new int[2 * size - 1][size];
				for (int j = 0; j < 2 * size - 1; j++) {
					for (int k = 0; k < size; k++) {
						lines[j][k] = in.nextInt();
					}
				}
				
				int[] result = solve(lines);
				StringBuilder resultStr = new StringBuilder();
				for (int j = 0; j < result.length; j++) {
					resultStr.append(""+result[j]);
					if (j < result.length - 1) {
						resultStr.append(" ");
					}
				}
				
				System.out.println(String.format("Case #%s: %s", i+1, resultStr));
			}
		}
	}

	private static int[] solve(int[][] lines) {
		Set<Integer> initRowPoss = new HashSet<>();
		Set<Integer> initColPoss = new HashSet<>();
		for (int i = 0; i < lines[0].length; i++) {
			initRowPoss.add(i);
			initColPoss.add(i);
		}
		
		List<PossibilitySet> initPoss = new ArrayList<>(lines.length);
		for (int[] line : lines) {
			initPoss.add(new PossibilitySet(line, new HashSet<>(initRowPoss),
					new HashSet<>(initColPoss)));
		}
		
		Solution result = backTrackSolve(new Solution(lines[0].length), Arrays.asList(lines),
				initPoss, null, false, -1);
		return result.soln();
	}
	
	private static Solution backTrackSolve(Solution curr, List<int[]> lines,
		List<PossibilitySet> domains, int[] prev, boolean prevWasRow, int prevAssignIdx)
	{
		List<PossibilitySet> newDomains;
		if (prev != null) {
			newDomains = domains.stream().map(PossibilitySet::clone).collect(Collectors.toList());
			for (PossibilitySet domain : newDomains) {
				domain.removeConflicts(prev, prevWasRow, prevAssignIdx);
				if (domain.rowPoss.isEmpty() && domain.colPoss.isEmpty()) {
					return null;
				}
			}
		}
		else {
			newDomains = domains;
		}
		
		if (lines.isEmpty()) {
			return curr;
		}
		
		int[] nextLine = lines.get(0);
		PossibilitySet options = newDomains.get(0);
		for (int row : options.rowPoss) {
			curr.rows[row] = nextLine;
			Solution recurseResult = backTrackSolve(curr, lines.subList(1, lines.size()),
					newDomains.subList(1, newDomains.size()), nextLine, true, row);
			if (recurseResult == null) {
				curr.rows[row] = null;
			}
			else {
				return recurseResult;
			}
		}
		for (int col : options.colPoss) {
			curr.cols[col] = nextLine;
			Solution recurseResult = backTrackSolve(curr, lines.subList(1, lines.size()),
					newDomains.subList(1, newDomains.size()), nextLine, false, col);
			if (recurseResult == null) {
				curr.cols[col] = null;
			}
			else {
				return recurseResult;
			}
		}
		
//		for (int i = 0; i < curr.rows.length; i++) {
//			if (curr.rowPossible(i, nextLine)) {
//				curr.rows[i] = nextLine;
//				Solution recurseResult = backTrackSolve(curr, lines.subList(1, lines.size()),
//						newDomains.subList(1, newDomains.size()), nextLine, true, i);
//				if (recurseResult == null) {
//					curr.rows[i] = null;
//				}
//				else {
//					return recurseResult;
//				}
//			}
//			if (curr.colPossible(i, nextLine)) {
//				curr.cols[i] = nextLine;
//				Solution recurseResult = backTrackSolve(curr, lines.subList(1, lines.size()),
//						newDomains.subList(1, newDomains.size()), nextLine, false, i);
//				if (recurseResult == null) {
//					curr.cols[i] = null;
//				}
//				else {
//					return recurseResult;
//				}
//			}
//		}
		
		return null;
	}
	
	private static class PossibilitySet implements Cloneable {
		Set<Integer> rowPoss;
		Set<Integer> colPoss;
		int[] line;
		
		public PossibilitySet(int[] line, Set<Integer> rowPoss, Set<Integer> colPoss) {
			this.line = line;
			this.rowPoss = new HashSet<>(rowPoss);
			this.colPoss = new HashSet<>(colPoss);
		}
		
		public void removeConflicts(int[] newAssigned, boolean wasAssignedRow, int assignedIdx) {
			boolean isLess = true;
			boolean isMore = true;
			for (int i = 0; i < newAssigned.length; i++) {
				if (line[i] <= newAssigned[i]) {
					isMore = false;
				}
				if (line[i] >= newAssigned[i]) {
					isLess = false;
				}
				if (!isMore && !isLess) {
					break;
				}
			}
			
			Iterator<Integer> iter = rowPoss.iterator();
			while (iter.hasNext()) {
				int nextRowPoss = iter.next();
				if (wasAssignedRow) {
					if (nextRowPoss == assignedIdx) {
						iter.remove();
					}
					else if (nextRowPoss > assignedIdx && !isMore) {
						iter.remove();
					}
					else if (nextRowPoss < assignedIdx && !isLess) {
						iter.remove();
					}
				}
				else {
					if (line[assignedIdx] != newAssigned[nextRowPoss]) {
						iter.remove();
					}
				}
			}
			
			iter = colPoss.iterator();
			while (iter.hasNext()) {
				int nextColPoss = iter.next();
				if (!wasAssignedRow) {
					if (nextColPoss == assignedIdx) {
						iter.remove();
					}
					else if (nextColPoss > assignedIdx && !isMore) {
						iter.remove();
					}
					else if (nextColPoss < assignedIdx && !isLess) {
						iter.remove();
					}
				}
				else {
					if (line[assignedIdx] != newAssigned[nextColPoss]) {
						iter.remove();
					}
				}
			}
		}
		
		@Override
		public PossibilitySet clone() {
			PossibilitySet result;
			try {
				result = (PossibilitySet) super.clone();
			}
			catch (CloneNotSupportedException e) {
				assert (false);
				return null;
			}
			result.rowPoss = new HashSet<>(result.rowPoss);
			result.colPoss = new HashSet<>(result.colPoss);
			
			return result;
		}
	}
	
	private static class Solution {
		int[][] rows;
		int[][] cols;
		
		public Solution(int size) {
			rows = new int[size][];
			cols = new int[size][];
		}
		
//		public boolean rowPossible(int row, int[] candidate) {
//			if (rows[row] != null) {
//				return false;
//			}
//			
//			for (int col = 0; col < cols.length; col++) {
//				if (cols[col] != null && cols[col][row] != candidate[col]) {
//					return false;
//				}
//				if (row > 0 && rows[row-1] != null && rows[row-1][col] >= candidate[col]) {
//					return false;
//				}
//				if (row < rows.length - 1 && rows[row+1] != null
//						&& rows[row+1][col] <= candidate[col])
//				{
//					return false;
//				}
//			}
//			
//			return true;
//		}
//		
//		public boolean colPossible(int col, int[] candidate) {
//			if (cols[col] != null) {
//				return false;
//			}
//			
//			for (int row = 0; row < rows.length; row++) {
//				if (rows[row] != null && rows[row][col] != candidate[row]) {
//					return false;
//				}
//				if (col > 0 && cols[col-1] != null && cols[col-1][row] >= candidate[row]) {
//					return false;
//				}
//				if (col < cols.length - 1 && cols[col+1] != null
//						&& cols[col+1][row] <= candidate[row])
//				{
//					return false;
//				}
//			}
//			
//			return true;
//		}
		
		public int[] soln() {
			Integer nullRow = null;
			Integer nullCol = null;
			int[][] board = new int[rows.length][cols.length];
			for (int i = 0; i < rows.length; i++) {
				if (rows[i] == null) {
					nullRow = i;
				}
				else {
					for (int j = 0; j < cols.length; j++) {
						board[i][j] = rows[i][j];
					}
				}
			}
			for (int i = 0; i < cols.length; i++) {
				if (cols[i] == null) {
					nullCol = i;
				}
				else {
					for (int j = 0; j < rows.length; j++) {
						board[j][i] = cols[i][j];
					}
				}
			}
			
			int[] result = new int[rows.length];
			if (nullRow != null) {
				for (int i = 0; i < rows.length; i++) {
					result[i] = board[nullRow][i];
				}
			}
			else {
				assert (nullCol != null);
				for (int i = 0; i < rows.length; i++) {
					result[i] = board[i][nullCol];
				}
			}
			
			return result;
		}
	}
}
