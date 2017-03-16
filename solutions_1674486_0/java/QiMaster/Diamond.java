import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Diamond{


	public static void main(String[] argvs){

		try{
			FileInputStream fstream = new FileInputStream("C:/Temp/codejam/p1.in");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			br.readLine();
			int i=1;
			while ((strLine = br.readLine()) != null)   {
				int amt = Integer.parseInt(strLine);
				ArrayList<String> arg = new ArrayList<String>();
				for (int q=0;q<amt;q++){
					arg.add(br.readLine());
				}
				allDots = new ArrayList<dot>();
				boolean res = solve(arg);
				if (res){
					System.out.println("Case #"+i+": Yes");
				} else {
					System.out.println("Case #"+i+": No");
				}
				i++;
			}
			in.close();
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}










	}

	static ArrayList<dot> allDots = new ArrayList<dot>();

	public static boolean solve(ArrayList<String> lines){
		for (int i=1;i<lines.size()+1;i++){
			String tl = lines.get(i-1);
			if (tl.contains(" ")){
				tl=tl.substring(tl.indexOf(" ")+1);
			} else {
				tl="";
			}
			dot td = getDot(i);
			if (td!=null){

			} else {
				td = new dot(i);
				allDots.add(td);
			}
			while (tl.length()>0){
				int nD=0;
				if (tl.contains(" ")){
					nD =Integer.parseInt(tl.substring(0,tl.indexOf(" ")));
				} else {
					nD =Integer.parseInt(tl);
				}
				dot fD = getDot(nD);
				if (fD!=null){
					td.from.add(fD);
				} else {
					dot newDot = new dot(nD);
					allDots.add(newDot);
					td.from.add(newDot);
				}
				if (tl.contains(" ")){
					tl=tl.substring(tl.indexOf(" ")+1);
				} else {
					tl="";
				}
			}
		}
		return checkForDiamond();
	}

	static boolean checkForDiamond(){
		for (dot td : allDots){
			if (td.checkForDiamond()){
				return true;
			}
		}
		return false;
	}

	public static dot getDot(int d){
		for (dot td : allDots){
			if (td.n==d){
				return td;
			}
		}
		return null;
	}

}

class dot{

	int n;
	ArrayList<dot> from = new ArrayList<dot>();

	public dot(int n){
		this.n=n;
	}

	public boolean checkForDiamond(){
		if (from.size()<2){
			return false;
		}
		ArrayList<ArrayList<Integer>> allFroms = new ArrayList<ArrayList<Integer>>();
		for (dot td : from){
			ArrayList<Integer> cl = td.getAllFrom();
			for (ArrayList<Integer> taf : allFroms){
				for (Integer ti : taf){
					if (cl.contains(ti)){
						return true;
					}
				}
			}
			allFroms.add(cl);
		}
		return false;		
	}

	public ArrayList<Integer> getAllFrom(){
		ArrayList<Integer> r = new ArrayList<Integer>();
		r.add(n);
		for (dot td : from){
			r.add(td.n);
			r.addAll(td.getAllFrom());
		}
		return r;
	}

}