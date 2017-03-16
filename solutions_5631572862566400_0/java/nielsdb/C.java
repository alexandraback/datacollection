import java.awt.List;
import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;


public class C {
	public static void main(String[] args) {
		boolean printToFile = true;
		try {
			if(printToFile){
				System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("out.txt")), true));
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		new C();
	}

	public boolean isValidPlacement(){
		for(int i = 0; i < currentPlacement.size(); i++){
			if(bffs.get(currentPlacement.get(i)-1) != currentPlacement.get((i+1)%currentPlacement.size()) && bffs.get(currentPlacement.get(i)-1) != currentPlacement.get((i-1+currentPlacement.size())%currentPlacement.size())){
				return false;
			}
		}
		return true;
	}

	ArrayList<Integer> bffs = new ArrayList<>();
	int bestLen = 0;
	ArrayList<Integer> currentPlacement = new ArrayList<>();
	public void dfs(){
		for(int i = 1; i < currentPlacement.size()-2; i++){
			if(bffs.get(currentPlacement.get(i)-1) != currentPlacement.get(i+1) && bffs.get(currentPlacement.get(i)-1) != currentPlacement.get(i-1)){
				return;
			}
		}


		if(currentPlacement.size() > bestLen && bffs.get(currentPlacement.get(0)-1) == currentPlacement.get(currentPlacement.size()-1) ){
			if(isValidPlacement()){
				bestLen = currentPlacement.size();
			}
		}
		if(bestLen == bffs.size())
			return;

		for(int i = 1; i <= bffs.size(); i++){
			if(!currentPlacement.contains(i)){
				currentPlacement.add(i);
				dfs();
				currentPlacement.remove(currentPlacement.size()-1);
			}
		}
	}


	public C() {
		Scanner sc = new Scanner(System.in);
		int nbProblems = sc.nextInt();
		for(int caseNb = 1; caseNb <= nbProblems; caseNb++){
			int n = sc.nextInt();
			bffs.clear();
			bestLen=0;
			for(int i = 0; i < n; i++){
				int in = sc.nextInt();
				bffs.add(in);
			}
			dfs();
			System.out.println("Case #" + caseNb + ": " + bestLen);
		}
	}
}
