import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[]args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new FileWriter("out2"));
		int numTests = Integer.parseInt(br.readLine());
		for(int i=0; i<numTests; i++){
			int result = cal(br);
			String outPut = "Case #"+(i+1)+": "+result;
			bw.write(outPut);
			bw.newLine();
			System.out.println(outPut);
		}
		bw.close();
	}

	private static int cal(BufferedReader br) throws IOException {
		String[]input = br.readLine().split(" ");
	
		int maxWeight = Integer.parseInt(input[0]);
		int constWgain = Integer.parseInt(input[1]);
		int numPacks = Integer.parseInt(input[2]);
		
		String[] valueArr = br.readLine().split(" ");
		
		return opt(0, maxWeight, maxWeight, valueArr, constWgain, numPacks);
	}

	private static int opt(int i, int maxWeight, int currentWeight, String[] valueArr,
			int constWgain, int numPacks) {
		if(i>=numPacks)
			return 0;
		int max =0;
		for(int usedWeight = 0; usedWeight<=currentWeight; usedWeight++){
			if(currentWeight-usedWeight+constWgain<=maxWeight){
				int curr = opt(i+1,maxWeight, currentWeight-usedWeight+constWgain, valueArr, constWgain, numPacks)+Integer.parseInt(valueArr[i])*usedWeight;
				if(curr>max)
					max = curr;
			}
		}
		return max;
	}
	
}
