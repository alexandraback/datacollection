package bsevero.codejam.round1c;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class DiagramClass {

	private int num;
	private Map<Integer, Boolean> inheritances = new HashMap<Integer, Boolean>();
	private Map<Integer, Boolean> originalInheritances = new HashMap<Integer, Boolean>();
	
	public void setStringInheritance(String inheritance) {
		if(inheritance.split(" ").length > 1) {
			String[] inheritanceClasses = inheritance.split(" ");
			inheritanceClasses = Arrays.copyOfRange(inheritanceClasses, 1, inheritanceClasses.length);
			for(String classD : inheritanceClasses) {
				inheritances.put(Integer.valueOf(classD), true);
				originalInheritances.put(Integer.valueOf(classD), true);
			}
		}
	}
	
	
	public Map<Integer, Boolean> getInheritances() {
		return inheritances;
	}
	public void setInheritances(Map<Integer, Boolean> inheritances) {
		this.inheritances = inheritances;
	}
	
	public void setNum(int num) {
		this.num = num;
	}
	
	public int getNum() {
		return num;
	}
	
	public Map<Integer, Boolean> getOriginalInheritances() {
		return originalInheritances;
	}
	
	
}
