import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class HouseOfPancakes {

	static List<PancakeHouseState> states = new ArrayList<PancakeHouseState>();
	
	public static void main(String[] args) throws IOException{
		
		String fileName = "C:/codeJam/2/";
		BufferedReader br = new BufferedReader(new FileReader(fileName+"small.in"));
		
		String line = br.readLine();
		
		int caseNum = 1;
		StringBuilder sb = new StringBuilder();
		while (br.readLine() != null) {
			line = br.readLine();
			states.add(makeState(line.split(" ")));
			int bestTime = servePancakes(states.get(0));
			
			sb.append("Case #"+caseNum+": "+bestTime);
			sb.append(System.lineSeparator());
			caseNum++;
			states.clear();
		}
		File file = new File(fileName+"small.out");
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        output.write(sb.toString());
        output.close();
	}

	private static int servePancakes(PancakeHouseState firstState) {
		PancakeHouseState state = firstState;
		int maxPlate = state.getMax();
		while(maxPlate > 3){
			PancakeHouseState newState = new PancakeHouseState();
			if(maxPlate/2 > state.getSecondMax()){
				if(maxPlate == 9){
					newState.clonePancakes(state.pancakes);
					newState.pancakes.remove(newState.pancakes.size()-1);
					newState.pancakes.add(3);
					newState.pancakes.add(3);
					newState.pancakes.add(3);
				}else {
					newState.clonePancakes(state.pancakes);
					newState.pancakes.remove(newState.pancakes.size()-1);
					newState.pancakes.add(maxPlate/2);
					newState.pancakes.add(maxPlate - maxPlate/2);
				}
			} else {
				if(maxPlate == state.getSecondMax()){
					newState.clonePancakes(state.pancakes);
					while(newState.getMax() == state.getSecondMax()){
						newState.pancakes.remove(newState.pancakes.size()-1);
						newState.pancakes.add(state.getSecondMax()/2);
						newState.pancakes.add(state.getSecondMax() - state.getSecondMax()/2);
					}
					
				}else
				if(maxPlate == 9 && state.getSecondMax() == 6){
					newState.clonePancakes(state.pancakes);
					newState.pancakes.remove(newState.pancakes.size()-1);
					newState.pancakes.add(3);
					newState.pancakes.add(3);
					newState.pancakes.add(3);
				}else{
					newState.clonePancakes(state.pancakes);
					newState.pancakes.remove(newState.pancakes.size()-1);
					newState.pancakes.add(maxPlate/2);
					newState.pancakes.add(maxPlate - maxPlate/2);
				}
			}
			states.add(newState);
			state = newState;
			maxPlate = state.getMax();
		}
		return findBestStateTime();
	}

	private static int findBestStateTime() {
		int bestTime = states.get(0).getMax();
		for(PancakeHouseState state : states){
			if(state.getMax() + (state.pancakes.size() - states.get(0).pancakes.size()) < bestTime)
				bestTime = state.getMax() + (state.pancakes.size() - states.get(0).pancakes.size());
		}
		return bestTime;
	}

	private static PancakeHouseState makeState(String[] panckase) {
		PancakeHouseState firstState = new PancakeHouseState();
		for(String p : panckase){
			firstState.pancakes.add(Integer.parseInt(p));
		}
		return firstState;
	}
}
