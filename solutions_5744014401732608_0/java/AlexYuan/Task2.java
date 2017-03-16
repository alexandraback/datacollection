package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;


//class status{
//	boolean in;
//	boolean out;
//}
public class Task2 {
	private static BufferedReader br = null;
	private static BufferedWriter bw = null;
	private static boolean find = false;
	
	public static void dfs(int bIndex, boolean[] s, int bLen, List<String> sub, int total,StringBuilder sb){
		if(bIndex == bLen && sub.size()+1 == total){
			sb.deleteCharAt(sb.length()-1);
			sub.add(sb.toString());
			find = true;
			return;
		}
		if(bIndex == bLen){
			sb.deleteCharAt(sb.length()-1);
			sub.add(sb.toString());
			return ;
		}
		for(int i =1;i<=bLen;i++){
			if(i == bIndex) continue;
			if(!s[i]){
				String ori = sb.toString();
				sb.append(bIndex+"-"+i+"-");
				s[i] = true;
				dfs(i, s, bLen, sub, total, sb);
				if(find){
					return;
				}else{
					s[i] = false;
					sb = new StringBuilder(ori);
				}
			}
		}
		s[bIndex] = false;
	}
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		bw = new BufferedWriter(new FileWriter("result.txt"));
		int size = Integer.parseInt(br.readLine());
		String line = "";
		int index = 0;
		while((line = br.readLine())!= null ){
			index++;
			find = false;
			String[] info = line.split(" ");
			int bLen = Integer.parseInt(info[0]);
			int[][] matrix = new int[bLen][bLen];
			int total = Integer.parseInt(info[1]);
//			status[] status = new status[bLen+1];
//			for(int i = 0 ; i<status.length;i++)
//				status[i] = new status();
			boolean[] status = new boolean[bLen+1];
			List<String> sub = new ArrayList<String>();
			status[1] = true;
			dfs(1, status, bLen, sub, total, new StringBuilder());
			for(String str: sub){
				String[] strs = str.split("-");
				for(int i = 0;i<strs.length;i+=2){
					int row = Integer.parseInt(strs[i])-1;
					int col = Integer.parseInt(strs[i+1])-1;
					matrix[row][col] = 1;
				}
			}
			if(find){
				bw.write("Case #"+index+": POSSIBLE");
				bw.newLine();
				System.out.println("Case #"+index+": POSSIBLE");
				for(int[] i:matrix){
					for(int j : i){
						System.out.print(j);
						bw.write(j+"");
					}
					bw.newLine();
					System.out.println();
				}
			}else{
				bw.write("Case #"+index+": IMPOSSIBLE");
				bw.newLine();
				System.out.println("Case #"+index+": IMPOSSIBLE");
			}
		}
		if(bw != null){
			bw.close();			
		}
		if(br != null){
			br.close();
		}
	}
}
