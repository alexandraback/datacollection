import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;


public class Dijkstra {
	private void rwFile(String filename){
		try {
			FileReader fr = new FileReader(filename);
			BufferedReader br = new BufferedReader(fr);
			FileWriter fw = new FileWriter(new File("result2.txt"));
			BufferedWriter bw = new BufferedWriter(fw);
			int count = Integer.parseInt(br.readLine());
//			int m = 0;
			for(int i=1; i<=count; i++){
				int num = Integer.parseInt(br.readLine().split(" ")[1]);
				StringBuffer sb = new StringBuffer();
				String k = br.readLine();
				num = num - (num-9)/4 *4;
				for(int j=0;j<num;j++){
					sb.append(k);
				}
				String reStr = "NO";
				boolean re = isSameD(sb.toString());
				if(re){
//					bw.write(passString(sb.toString())+"\n");
//					m++;
					if(passString(sb.toString()).equals("ijij")){
						reStr = "YES";
					}
				}
				bw.write("Case #"+i+": "+reStr+"\n");
			}
//			System.out.println(m);
			bw.flush();
			bw.close();
			br.close();
			fr.close();
			fw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		catch(IOException e){
			e.printStackTrace();
		}
	}
	
	private String passString(String str){
		String newStr = str.replaceAll("k", "ij");
		String[] element  = new String[]{"i","j","ji","ij"};
		for(int i=0;i<element.length;i++){
			for(int j=0;j<element.length;j++){
				String rm = element[i]+element[j]+element[j]+element[i];
				String rm1 = element[i]+element[i]+element[j]+element[j];
				String rm2 = element[i]+element[i]+element[j]+element[j];
				String rm3 = element[j]+element[i]+element[i]+element[j];
				newStr = newStr.replaceAll(rm, "").replaceAll(rm1, "")
						.replaceAll(rm2, "").replaceAll(rm3, "");
			}
		}
		if(newStr.equals(str)){
			return newStr;
		}
		else{
			return passString(newStr);
		}
	}
	
	private boolean isSameD(String str){
		String result = "";
		Map<String,String> map = new HashMap<String,String>();
		map.put("ii", "-1");
		map.put("ij", "k");
		map.put("ik", "-j");
		map.put("jj", "-1");
		map.put("ji", "-k");
		map.put("jk", "i");
		map.put("ki", "j");
		map.put("kj", "-i");
		map.put("kk", "-1");
		
		char[] chars = str.toCharArray();
		result = chars[0]+"";
		for(int i=1; i<chars.length; i++){
			result = result+chars[i];
			String newResult = null;
			if(result.startsWith("1")){
				newResult = result.substring(1);
			}
			else if(result.startsWith("-1")){
				newResult = result.substring(2);
			}
			else if(result.startsWith("-")){
				String value = map.get(result.substring(1));
				if(value.startsWith("-")){
					newResult = value.substring(1);
				}
				else{
					newResult = "-"+value;
				}
			}
			else{
				newResult = map.get(result);
			}
			if(newResult == null){
				System.out.println();
			}
			result = newResult;
		}
		return result.equals("-1");
	}
	
	
/*	private boolean isSame(String str){
		if(str.length()<3){
			return false;
		}
		else if(str.length() == 3){
			return str.equals("ijk");
		}
		
		Map<String,String> map = new HashMap<String,String>();
		map.put("ii", "-1");
		map.put("ij", "k");
		map.put("ik", "-j");
		map.put("jj", "-1");
		map.put("ji", "-k");
		map.put("jk", "i");
		map.put("ki", "j");
		map.put("kj", "-i");
		map.put("kk", "-1");
		
		char[] chars = str.toCharArray();
		for(int len = 3; len<=chars.length-2; len++){
			for(int i=0; i<=chars.length-len;i++){
				String original = str.substring(i,i+len-1);
				String result = map.get(original);
				char lastCharacter = str.charAt(i+len-1);
				String key = original+lastCharacter;
//				System.out.println(original);
				if(result.equals("-1")){
					map.put(key, "-"+lastCharacter);
				}
				else if(result.equals("1")){
					map.put(key, ""+lastCharacter);
				}
				else if(result.startsWith("-")){
					String temp = result.substring(1)+lastCharacter;
					String value = map.get(temp);
					if(value.startsWith("-")){
						map.put(key, value.substring(1));
					}
					else{
						map.put(key, "-"+value);
					}
				}
				else{
					String temp = result+lastCharacter;
					String value = map.get(temp);
					map.put(key, value);
				}
			}
		}
		
		for(int i=1; i<chars.length-2; i++){
			for(int j=i+1;j<chars.length-1; j++){
				String first = i == 1? str.substring(0,1):map.get(str.substring(0, i));
				if(first.equals("i")){
					String second = j == i+1?str.substring(i,j):map.get(str.substring(i,j));
					if(second.equals("j")){
						String third = str.substring(j);
						if(third.length()>1){
							third = map.get(third);
						}
						if(third.equals("k")){
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	
	*/
	
	
	public static void main(String[] args){
		Dijkstra test = new Dijkstra();
//		test.rwFile("C-small-attempt1.in.txt");
		test.rwFile("C-small-attempt2.in.txt");
//		test.rwFile("test");
	}
}
