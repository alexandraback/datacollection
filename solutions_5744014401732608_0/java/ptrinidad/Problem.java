package commons;

public class Problem {
	int buildings;
	int paths;
	int currentPaths;
	
	public Problem (int nBuildings, int nPaths) {
		this.buildings = nBuildings;
		this.paths = nPaths;
	}
	
	public Result execute () {
		Result res = new Result(buildings);
		
		int [] starting = new int[1];
		starting[0] = 1;
		res.setResults(buildings-2, buildings-1, 1);
		res.setResults(buildings-2, buildings-2, 1);
		currentPaths = 1;
		
		for (int currentBuilding = buildings - 3; currentBuilding >= 0; currentBuilding--) {
			int from = currentBuilding + 1;
			currentPaths = 0;
			for (int to = from; to < buildings; to++) {
				int value = res.getBuildingPaths(from, to);
				if ((currentPaths + value) <= paths) {
					currentPaths += value;
					res.setResults(currentBuilding, to, value);
				} else {
					//res.setResults(currentBuilding, to, 0);
				}
			}
			res.setResults(currentBuilding,currentBuilding,currentPaths);
		}
		
		if (currentPaths != paths)
			res.setImpossible();
		
		return res;
	}
}
