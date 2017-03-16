package codes;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;


public class MinesweeperMaster {
	char[][] configuration;
	int spaceNumber;
	int rowSize;
	int columnSize;
	
	String[][] results;
	
	
	boolean isOneClickSolvable () {
		boolean solvableFlag = true;
		
		int smallerSide;
		if (rowSize <= columnSize)
			smallerSide = rowSize;
		else 
			smallerSide = columnSize;
		
		if (spaceNumber==0) 
			solvableFlag = false;
		
		switch(smallerSide) {
		case 1:
			break;
		case 2:
			if (spaceNumber % 2 == 1 && spaceNumber != 1) 
				solvableFlag = false;
			break;
		default:
			if (spaceNumber == 2 || spaceNumber == 3 || spaceNumber == 5 || spaceNumber == 7)
				solvableFlag = false;
			break;
		}
		
		return solvableFlag;
	}

	
	boolean isSolvable (char[][] config) {
		int ySize = config.length;
		int xSize = config[0].length;
		
		
		// BFS
		
		Set<Integer> revealdNodes = new HashSet<Integer>();
		Queue<Integer> NodesQueue = new LinkedList<Integer>();
		Set<Integer> visitedNodes = new HashSet<Integer>();
		
		NodesQueue.add(0);
		
		int count = 0;
		while (!NodesQueue.isEmpty()) {
			count++;
			if (count > 1000) {
				System.out.println(this.rowSize + " " + this.columnSize + " " + this.spaceNumber);
			}
			
			int node = NodesQueue.poll();
			visitedNodes.add(node);
			revealdNodes.add(node);
			
			
			int y = node / xSize;
			int x = node % xSize;
			// 8 neighbors
			
			int neighborX;
			int neighborY;
			int neighborID;
			
			ArrayList<Integer> neighbors = new ArrayList<Integer>();
			boolean isInternalNode = true;
			// 0
			neighborY = y-1;
			neighborX = x-1;
			neighborID = neighborY*xSize+neighborX;
			
			
			
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}

			// 1
			neighborY = y-1;
			neighborX = x;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}			

			// 2
			neighborY = y-1;
			neighborX = x+1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}

			// 3
			neighborY = y;
			neighborX = x+1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}
			
			// 4
			neighborY = y+1;
			neighborX = x+1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}

			// 5
			neighborY = y+1;
			neighborX = x;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}	
			
			// 6
			neighborY = y+1;
			neighborX = x-1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}

			// 7
			neighborY = y;
			neighborX = x-1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}
			
			
			if (isInternalNode) {
				for (int item : neighbors) {
					if (!visitedNodes.contains(item)) {
						NodesQueue.add(item);
					}						
				}
			}
		}

		return revealdNodes.size()==this.spaceNumber;
	}
	
	boolean smartDFS(char[][] config, int leftSpace, Set<Integer> potentialBoundary, 
			Set<Integer> visitedNodes, boolean clickFlag) {
		int xSize = config[0].length;
		int ySize = config.length;
		
		for (int node : potentialBoundary) {
			int y = node / xSize;
			int x = node % xSize;
			// 8 neighbors
			
			int neighborX;
			int neighborY;
			int neighborID;
			
			ArrayList<Integer> neighbors = new ArrayList<Integer>();
			boolean isInternalNode = true;
			// 0
			neighborY = y-1;
			neighborX = x-1;
			neighborID = neighborY*xSize+neighborX;
			
			
			
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}

			// 1
			neighborY = y-1;
			neighborX = x;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}			

			// 2
			neighborY = y-1;
			neighborX = x+1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}

			// 3
			neighborY = y;
			neighborX = x+1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}
			
			// 4
			neighborY = y+1;
			neighborX = x+1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}

			// 5
			neighborY = y+1;
			neighborX = x;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}	
			
			// 6
			neighborY = y+1;
			neighborX = x-1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}

			// 7
			neighborY = y;
			neighborX = x-1;
			neighborID = neighborY*xSize+neighborX;
			if (neighborX< xSize &&neighborX >=0 && neighborY< ySize && neighborY>=0) {
				if (config[neighborY][neighborX] == '.')
					neighbors.add(neighborID);
				if (config[neighborY][neighborX] == '*')
					isInternalNode = false;
			}
			
			if (isInternalNode && !clickFlag) {
				config[y][x] = 'c';
				clickFlag = true;
			}
			
			for (int item : neighbors) {
				if (!visitedNodes.contains(item)) {
					smartDFS(config, leftSpace, potentialBoundary, visitedNodes, clickFlag);
				}
			}
			
		}
		
		return false;
	}

	
	boolean dfs(char[][] config, int leftSpace, int spaceID) {
		int xSize = config[0].length;
		int ySize = config.length;
		
		int y = spaceID/config[0].length;
		int x = spaceID%config[0].length;
		
		config[y][x] = '.';
		
		
		if (leftSpace == 0  ) {
			if (isSolvable(config)){
				this.configuration = new char[rowSize][columnSize];
				for (int i = 0; i < ySize; ++i) {
					for (int j = 0; j < xSize; ++j) {
						this.configuration[i][j] = config[i][j];
					}
				}
				config[y][x] = '*';
				return true;
			}
			
			config[y][x] = '*';
			return false;
			
		} 
		
		
		
		for (int i = 0; i <config.length; ++i) {
			for (int j = 0; j < config[0].length; ++j) {
				if (config[i][j] == '*') {
					if (dfs(config, leftSpace-1, i * xSize + j)) {
						config[i][j] = '*';
						return true;
					}
				}
			}
		}
		
		config[y][x] = '*';
		return false;
	}
	
	public String[][] createConfiguration (String[] inputData) {
		rowSize = Integer.valueOf(inputData[0]);
		columnSize = Integer.valueOf(inputData[1]);
		int mineNumber = Integer.valueOf(inputData[2]);
		this.spaceNumber = rowSize*columnSize-mineNumber;
		
		char[][] allMines = new char[rowSize][columnSize];
		for (int y = 0; y < rowSize; ++y) {
			for (int x = 0; x < columnSize; ++x) {
				allMines[y][x] = '*';
			}
		}
		
		if (dfs(allMines, this.spaceNumber-1, 0)) {
			results = new String[rowSize][columnSize];
			for (int y = 0; y < rowSize; ++y) {
				for (int x = 0; x < columnSize; ++x) {
					results[y][x] = Character.toString(configuration[y][x]);
				}
			}
			
			results[0][0]="c";
		} else {
			results = new String[][]{{"Impossible"}};
		}
		
		return results;
	}
	
	public String[][] solveMinesweeperMaster(String[]inputData) {
		rowSize = Integer.valueOf(inputData[0]);
		columnSize = Integer.valueOf(inputData[1]);
		int mineNumber = Integer.valueOf(inputData[2]);
		this.spaceNumber = rowSize*columnSize-mineNumber;
		
		if (isOneClickSolvable()) {
			createConfiguration(inputData);
		} else {
			results = new String[][]{{"Impossible"}};
		}
		
		
		return results;
	}

	
}
