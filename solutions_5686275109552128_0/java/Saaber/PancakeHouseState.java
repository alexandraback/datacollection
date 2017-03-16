import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class PancakeHouseState {

	List<Integer> pancakes;
	public PancakeHouseState(){
		this.pancakes = new ArrayList<Integer>();
	}
	
	public int getMax(){
		Collections.sort(this.pancakes);
		return pancakes.get(pancakes.size()-1);
	}
	
	public int getSecondMax(){
		if(pancakes.size() > 1)
			return pancakes.get(pancakes.size()-2);
		else return 0;
	}

	public void clonePancakes(List<Integer> pancakes2) {
		for(int i: pancakes2){
			this.pancakes.add(i);
		}
	}
}
