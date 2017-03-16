import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CloseMatch {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int caseNr = 1; caseNr <= T; caseNr++){
			String c = sc.next();
			String j = sc.next();
			List<String> cPos = Generate(c, c.length(), "");
			List<String> jPos = Generate(j, j.length(), "");
			int minDiff = 1000;
			int minc = 1000;
			int minj = 1000;
			String mincString ="";
			String minjString ="";
			for(int i = 0; i<cPos.size(); i++){				
				for(int k = 0; k<jPos.size(); k++){
					int cConv = 0;
					int jConv = 0;
					try{
						cConv = Integer.parseInt(cPos.get(i));
						jConv = Integer.parseInt(jPos.get(k));
					} catch(Exception e){}
					int diff = Math.abs(cConv-jConv);
					if( diff < minDiff){
						minDiff = diff;
						minc = cConv;
						minj = jConv;
						mincString = cPos.get(i);
						minjString = jPos.get(k);
					}
					else if (diff == minDiff && cConv < minc){
						minDiff = diff;
						minc = cConv;
						minj = jConv;
						mincString = cPos.get(i);
						minjString = jPos.get(k);
					}
					else if (diff == minDiff && cConv == minc && jConv < minj){
						minDiff = diff;
						minc = cConv;
						minj = jConv;
						mincString = cPos.get(i);
						minjString = jPos.get(k);
					}
				}
			}
			System.out.println("Case #"+caseNr+": " + mincString + " " + minjString);
		}
	}

	private static List<String> Generate(String j, int length, String soFar) {
		List<String> myInts = new ArrayList<String>();
		if(length == 0){
			myInts.add(soFar);
			return myInts;
		}
		if(j.charAt(j.length()-length) != '?'){
			myInts.addAll(Generate(j, length-1, soFar + j.charAt(j.length()-length)));
		}
		else{
			for(int i = 0; i<= 9; i++){
				myInts.addAll(Generate(j, length-1, soFar + i));
			}
		}
		return myInts;
	}
}
