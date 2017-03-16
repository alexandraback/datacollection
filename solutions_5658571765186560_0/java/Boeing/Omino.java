import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Omino {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
				String filename = "D-small-attempt1";
				BufferedReader br = new BufferedReader(new FileReader(filename+".in"));
				FileWriter writer = new FileWriter(filename+".out", false);
				writer.write("");
				writer.close();
				
				writer = new FileWriter(filename+".out", true);
				
				int nbr_case = Integer.parseInt(br.readLine());
				
				String sCurrentLine;
				
				char result;
				
				for (int num_case = 1; num_case <= nbr_case; num_case ++) {
					sCurrentLine = br.readLine();
					String tmp[] = sCurrentLine.split(" ");
					int X = Integer.parseInt(tmp[0]);
					int R = Integer.parseInt(tmp[1]);
					int C = Integer.parseInt(tmp[2]);
					if(X == 1)
						result = 'g';
					else if(X == 2)
						result = (R*C % 2 == 0) ? 'g' : 'r';
					else if(X == 3){
						if(R%3 != 0 && C%3 != 0)
							result = 'r';
						else if(R == 1 || C == 1)
							result = 'r';
						else
							result = 'g';
					}
					else{
						if((R==4 && C>=3)||(C==4 && R>=3))
							result = 'g';
						else
							result = 'r';
					}
					if(result == 'r')
						writer.write("Case #"+num_case+": RICHARD\n");
					else
						writer.write("Case #"+num_case+": GABRIEL\n");
				}
				writer.close();
			}

		}