import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;


public class RankAndFile {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileInputStream fstream = new FileInputStream("B-small-attempt0.in");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

		String strLine;

		//Read File Line By Line
		int count = -1;
		int index = -1;
		int n = -1;
		ArrayList<Integer> lines = null;
		while ((strLine = br.readLine()) != null)   {
		  // Print the content on the console
			if(count==-1){
				count++;
				continue;
			}
			String[] entries = strLine.split(" ");
			if(entries.length<2){
				index++;
				n = Integer.parseInt(entries[0]);
				if(lines!=null){
					System.out.println("Case #" + index + ": " + helper(lines));
				}
				lines = new ArrayList<Integer>();
			}else{
				for(int i=0;i<entries.length;i++){
					lines.add(Integer.parseInt(entries[i]));
				}
			}
			//System.out.println("Case #" + count + ": " + helper("ZXCASDQWEIOEWQRKDJSKLFJJDKSFJKDJFKJDKFJKDSJKFJDSALKJFLKJADSLKFJKLSDAJKFJKLSDJFKLJSDLKJFKLLKDSAJFLKDJSAKLFJKLDASJFKLJDSAKLFJKL"));
		  }
		if(lines!=null&&lines.size()>0){
			index++;
			System.out.println("Case #" + index + ": " + helper(lines));
		}
		//Close the input stream
		br.close();
	}

	private static String helper(ArrayList<Integer> lines){
		Map<Integer,Integer> count = new HashMap<Integer,Integer>();
		ArrayList<Integer> result = new ArrayList<Integer>();
		for(Integer i: lines){
			if(count.containsKey(i)){
				count.put(i, count.get(i)+1);
			}else{
				count.put(i, 1);
			}
		}
		for(Integer i: count.keySet()){
			if(count.get(i)%2==1){
				result.add(i);
			}
		}
		Collections.sort(result);
		StringBuilder sb = new StringBuilder();
		for(Integer i: result){
			sb.append(i);
			sb.append(" ");
		}
		return sb.toString().trim();
	}
}
