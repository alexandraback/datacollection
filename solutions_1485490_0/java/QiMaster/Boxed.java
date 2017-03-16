import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.text.NumberFormat;
import java.util.ArrayList;

public class Boxed{


	public static void main(String[] argvs){

		try{
			FileInputStream fstream = new FileInputStream("C:/Temp/codejam/p1.in");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			br.readLine();
			int i=1;
			while ((strLine = br.readLine()) != null)   {
				//int amt = Integer.parseInt(strLine);
				ArrayList<Pair<Double,Integer>> bs = new ArrayList<Pair<Double,Integer>>();
				ArrayList<Pair<Double,Integer>> ts = new ArrayList<Pair<Double,Integer>>();
				String boxLine = br.readLine();
				while (boxLine.length()>0){
					double amt=Double.parseDouble(boxLine.substring(0,boxLine.indexOf(" ")));
					boxLine=boxLine.substring(boxLine.indexOf(" ")+1);
					int type=0;
					if (boxLine.contains(" ")){
						type=Integer.parseInt(boxLine.substring(0,boxLine.indexOf(" ")));
					} else {
						type=Integer.parseInt(boxLine);
					}
					if (boxLine.contains(" ")){
						boxLine=boxLine.substring(boxLine.indexOf(" ")+1);
					} else {
						boxLine="";
					}
					bs.add(new Pair<Double,Integer>(amt,type));
				}
				String toyLine = br.readLine();
				while (toyLine.length()>0){
					double amt=Double.parseDouble(toyLine.substring(0,toyLine.indexOf(" ")));
					toyLine=toyLine.substring(toyLine.indexOf(" ")+1);
					int type=0;
					if (toyLine.contains(" ")){
						type=Integer.parseInt(toyLine.substring(0,toyLine.indexOf(" ")));
					} else {
						type=Integer.parseInt(toyLine);
					}
					if (toyLine.contains(" ")){
						toyLine=toyLine.substring(toyLine.indexOf(" ")+1);
					} else {
						toyLine="";
					}
					ts.add(new Pair<Double,Integer>(amt,type));
				}
				double res = solve(bs,0,ts,0);
				NumberFormat f = NumberFormat.getInstance();
				f.setGroupingUsed(false);
				String refinedNumber = f.format(res);
				System.out.println("Case #"+i+": "+refinedNumber);
				i++;
			}
			in.close();
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}


	}


	public static double solve(ArrayList<Pair<Double,Integer>> boxes,int x,ArrayList<Pair<Double,Integer>> toys,int y){
		double max=0;
		if (x>boxes.size()-1 || y>toys.size()-1){
			return max;
		}
		Pair<Double,Integer> box = boxes.get(x);
		Pair<Double,Integer> toy = toys.get(y);
		//Box a toy
		if (box.second==toy.second){
			if (box.first>toy.first){
				double amt = toy.first;
				box.first-=toy.first;
				max = (solve(boxes,x,toys,y+1)+amt);
			} else if (toy.first>box.first){
				double amt = box.first;
				toy.first-=box.first;
				max = (solve(boxes,x+1,toys,y)+amt);
			} else {
				double amt = toy.first;
				max = (solve(boxes,x+1,toys,y+1)+amt);
			}
		}
		//throw box
		double n = (solve(boxes,x+1,toys,y));
		if (n>max){
			max=n;
		}
		//throw toy
		double q = (solve(boxes,x,toys,y+1));
		if (q>max){
			max=q;
		}

		return max;
	}

}