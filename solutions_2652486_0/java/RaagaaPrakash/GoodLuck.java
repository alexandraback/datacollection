import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;


public class GoodLuck {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		InputStream input = System.in;
		InputStreamReader inputRead = new InputStreamReader(input);

		BufferedReader br = null;

		
		
		
		try {
			br = new BufferedReader(inputRead);
			String sCurrentLine = br.readLine();
			sCurrentLine = br.readLine();
			String[] temp = sCurrentLine.split(" ");
			int numberOfsets = Integer.parseInt(temp[0]);
			int howMany = Integer.parseInt(temp[1]);
			int max = Integer.parseInt(temp[2]);
			int numberOfProducts = Integer.parseInt(temp[3]);
			int[] products = new int[numberOfProducts];
			System.out.println("Case #1:");
			for(int count=0; count<numberOfsets; count++){
				sCurrentLine = br.readLine();
				String[] temp1 = sCurrentLine.split(" ");
				for(int i=0; i<numberOfProducts; i++){
					products[i] = Integer.parseInt(temp1[i]);
				}
				guess(products, max, howMany);
			}

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
		

	}
	
	public static void guess(int[] products, int max, int howMany){
		int result[] = new int[howMany];
		int higherProduct = 0;
		for(int count=0; count<products.length; count++){
			higherProduct = Math.max(products[count], higherProduct);
		}
		boolean inComplete = true;
		int index = 0;
		while(inComplete){
			for(int count=max; count>0; count--){
				if(higherProduct % count == 0){
					if(count == 1){
						result[index] = 2;
					}else{
						result[index] = count;
					}
					
					higherProduct = higherProduct / count;
					max = count;
					index++;
					if(index == howMany){
						inComplete = false;
					}
					break;
				}
				
			}
			
		}
		StringBuffer buffer = new StringBuffer();
		for(int count=0; count<howMany; count++){
			buffer.append(result[count]);
			
		}
		System.out.println(buffer.toString());
	}

}
