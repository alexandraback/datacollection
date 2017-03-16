import java.util.HashSet;


public class R1 {
	double answer[];
	public R1(String[] input){
		answer = new double[Integer.parseInt(input[0])];
		int stringCounter =1;
		for (int i =0; i< answer.length;i++){
			String[] desc = input[stringCounter].split(" ");
			stringCounter ++;
			String[] probS = input[stringCounter].split(" ");
			double[] prob = new double[Integer.parseInt(desc[0])];
			for (int j =0; j < prob.length; j++){
				prob[j] = Double.parseDouble(probS[j]);
			}
			stringCounter ++;
			answer[i] =calc(Integer.parseInt(desc[1]), prob);
			System.out.print("Case #"+(i+1)+": ");
			System.out.printf("%.6f", (answer[i]));
			System.out.println();
		}
		
	}
	public double calc(int r, double[] d){
		double typed = d.length;
		double remaining = r-d.length;
		//enter
		double enter = r + 2;
		
		double placeholder = typed;
		
		while (placeholder >=0){
			double backspaced = typed - placeholder;
			double alltrue = 1;
			for(int i = 0; i < d.length-backspaced; i++){
				alltrue *= d[i];
			}
			//System.out.println(alltrue);
			double expected = alltrue *(2*backspaced + remaining +1) + (1-alltrue) *(2*backspaced + remaining + (placeholder ==0?1:(r+ 2)));
			
			//System.out.println((2*backspaced + remaining + 1 )+ " " + (2*backspaced + remaining + r+ 2));
			
			//System.out.println(expected);
			if (expected < enter){
				enter = expected;
			}
			placeholder --;
		}
		
		
		return enter;
	}
}

