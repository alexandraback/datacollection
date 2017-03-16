import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String line;
		String filename1 = "B-small-attempt0.in";
		String filename2 = filename1.split("[.]")[0] + ".out";
		BufferedReader input;
		BufferedWriter output;
		int counter = 0;
		int numberOfCases = 0;
		int levelTotal = 0;
		boolean level = false;
		int caseNr = 0;
		// correctly typed
		ArrayList<Integer> array = new ArrayList<Integer>();
		int tempCounter = 0;
		try {
			input = new BufferedReader(new FileReader(filename1));
			output = new BufferedWriter(new FileWriter(filename2));
			while ((line = input.readLine()) != null) {
				if (counter == 0) {
					numberOfCases = Integer.parseInt(line);
					level = true;
				} else {
					// 0 - charstyped/total
					if (level) {
						caseNr++;
						levelTotal = Integer.parseInt(line);
						level = false;
						tempCounter = levelTotal;
						array = new ArrayList<Integer>();
					} else {
						tempCounter--;
						String[] arrayS = line.split("[ ]");
						for (int i = 0; i < arrayS.length; i++) {
							array.add(Integer.parseInt(arrayS[i]));
						}
						if (tempCounter == 0) {
							level = true;
							output.write("Case #" + caseNr + ": ");
							output.write(skaiciuok(array, levelTotal));
							output.write("\n");
							// skaiciuoju 
						}
					}
				}
				counter++;
			}
			input.close();
			output.close();
		} catch (IOException e1) {
			System.exit(1);
		}
		//		System.out.println(array);
	}

	public static String skaiciuok(ArrayList<Integer> arrayList, int levelTotal) {
		int[] array = new int[arrayList.size()];
		for (int i = 0; i < array.length; i++) {
			array[i] = arrayList.get(i);
		}
		int currentStars = 0;
		int timesTried = 0;
		boolean randu = true;
		while (randu) {
			randu = false;
			// antra leveli
			for (int i = 1; i < array.length; i += 2) {
				if (currentStars >= array[i]) {
					currentStars += 2;
					if (array[i - 1] == Integer.MAX_VALUE) {
						currentStars--;
					}
					array[i] = Integer.MAX_VALUE;
					array[i - 1] = Integer.MAX_VALUE;
					randu = true;
					timesTried++;
				}
			}
			// pirma
			int tempMax=-1;
			int tempNr=-1;
			if (!randu) {
				for (int i = 0; i < array.length; i += 2) {
					if (currentStars >= array[i]) {
						if(tempNr!=-1){
							if(array[i+1]>tempMax){
								tempNr=i;
								tempMax=array[i+1];
							}
						}else{
							tempNr=i;
							tempMax=array[i+1];
						}
						randu = true;
					}
				}
				if(randu){
					currentStars++;
					array[tempNr] = Integer.MAX_VALUE;
					timesTried++;
				}
			}
			
		}
		System.out.println(currentStars);
		System.out.println(timesTried);
		System.out.println("-----");
		if (currentStars == levelTotal * 2) {
			return "" + timesTried;
		}
		return "Too Bad";
	}
}
