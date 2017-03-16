import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class Password {


	public static void main(String[] args) {
		if (args.length != 1){
			System.out.println("Gimme the right arguments!");
			return;
		}

		File f = new File(args[0]);
		int count =1;
		try{
			BufferedReader reader = new BufferedReader(new FileReader(f));
			String s;
			int cases = Integer.parseInt(reader.readLine());
			while ((s = reader.readLine())!= null){
				String [] temp = s.trim().split(" ");
				int done = Integer.parseInt(temp[0]);
				int total = Integer.parseInt(temp[1]);
				double [] probs = new double[done];
				s = reader.readLine();
				temp = s.trim().split(" ");
				for (int i =0; i<done; i++){
					probs[i]=Double.parseDouble(temp[i]);
				}
				
				double enter = total +2;
				double [] expected = new double[done+1];
				for (int i=0; i< done + 1; i++){
					double pi = 1.0;
					for (int j=0; j<done-i; j++){
						pi *= probs[j];
					}
					expected[i] = (i + total - (done -i)+1)*pi + (i + total - (done -i)
								   +total+2)*(1.0-pi);
				}
				
				double min = enter;
				for (int i=0; i<done+1; i++){
					//System.out.print(expected[i] + " ");
					if (expected[i]<min)
						min=expected[i];
					
				}
				
				System.out.printf("Case #%d: %.6f\n",count,min);
				count++;
			}
		}
		catch (IOException e){
			System.err.println(e);
		}

	}


}
