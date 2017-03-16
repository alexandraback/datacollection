import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;






public class InfHousePancakeSanaz {

	static List<InfHouseState> states = new ArrayList<InfHouseState>();
	
	public static void main(String[] args) throws IOException{
		//inja hich kare khasi nemikonim
		int hereCount = 0;
		String fileName = "C:/codeJam/2/";
		BufferedReader bufferReader = new BufferedReader(new FileReader(fileName+"B-small-attempt0.in"));
		
		String line = bufferReader.readLine();
		
		int numOfCase = 1;
		StringBuilder sb = new StringBuilder();
		while (bufferReader.readLine() != null) {
			hereCount++;
			line = bufferReader.readLine();
			states.add(makeState(line.split(" ")));
			findAllStates(states.get(0));
			int bestTime = stateWithBestTime();
			
			if(hereCount > 0)
				System.out.println(hereCount);
			sb.append("Case #"+numOfCase+": "+bestTime);
			sb.append(System.lineSeparator());
			numOfCase++;
			states.clear();
		}
		File file = new File(fileName+"sanaz.out");
        BufferedWriter bufferWriter = new BufferedWriter(new FileWriter(file));
        bufferWriter.write(sb.toString());
        bufferWriter.close();
	}

	private static void findAllStates(InfHouseState state) {
		int maxPlate = state.getMax();
		if(maxPlate > 3){
			InfHouseState newState = new InfHouseState();
			InfHouseState newState2 = null;
			InfHouseState newState3 = null;
			
			if(maxPlate/2 > state.getSecondMax()){
				newState3 = new InfHouseState();
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
				if(maxPlate == 9){
					newState.clonePancakes(state.pancakes);
					newState.pancakes.remove(newState.pancakes.size()-1);
					newState.pancakes.add(5);
					newState.pancakes.add(4);
					
					newState2 = new InfHouseState();
					newState2.clonePancakes(state.pancakes);
					newState2.pancakes.remove(newState2.pancakes.size()-1);
					newState2.pancakes.add(3);
					newState2.pancakes.add(3);
					newState2.pancakes.add(3);
					states.add(newState2);
				}else{
					newState.clonePancakes(state.pancakes);
					newState.pancakes.remove(newState.pancakes.size()-1);
					newState.pancakes.add(maxPlate/2);
					newState.pancakes.add(maxPlate - maxPlate/2);
				}
			}
			states.add(newState);
			if(newState2 != null)
				findAllStates(newState2);
			findAllStates(newState);
		}
	}

	private static int stateWithBestTime() {
		int bestTime = states.get(0).getMax();
		for(InfHouseState state : states){
			if(state.getMax() + (state.pancakes.size() - states.get(0).pancakes.size()) < bestTime)
				bestTime = state.getMax() + (state.pancakes.size() - states.get(0).pancakes.size());
		}
		return bestTime;
	}

	private static InfHouseState makeState(String[] panckase) {
		InfHouseState firstState = new InfHouseState();
		for(String p : panckase){
			firstState.pancakes.add(Integer.parseInt(p));
		}
		return firstState;
	}
}
