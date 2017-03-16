import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;


public class Dijkstra {
	public static void main(String args[]){
		
		try {
			BufferedReader br = new BufferedReader(new FileReader("input0.in"));
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
			Map<String,String> m = new HashMap<String,String>();
			m.put("11","1");
			m.put("1i","i");
			m.put("1j","j");
			m.put("1k","k");
			
			m.put("i1","i");
			m.put("ii","-1");
			m.put("ij","k");
			m.put("ik","-j");
			
			m.put("j1","j");
			m.put("ji","-k");
			m.put("jj","-1");
			m.put("jk","i");
			
			m.put("k1","k");
			m.put("ki","j");
			m.put("kj","-i");
			m.put("kk","-1");
			
			int test = Integer.parseInt(br.readLine());
			int testcase= 1;
			while(test>= testcase)
			{
				String r[]= br.readLine().split(" ");
				int len = Integer.parseInt(r[0]);
				int rep = Integer.parseInt(r[1]);
				
				String str = br.readLine();
				String s=str;
				
				if(str.length() ==1){
					//System.out.println("Case #"+testcase+": NO");
					bw.write("Case #"+testcase+": NO");
					testcase++;
					if(testcase<=test){
						bw.write("\n");
					}
					continue;
				}
				
				for(int i=1;i<rep;i++){
					str+=s;
				}
				//System.out.println(str);
				if(str.length()<=2){
					//System.out.println("Case #"+testcase+": NO");
					bw.write("Case #"+testcase+": NO");
					if(testcase<=test){
						bw.write("\n");
					}
					testcase++;
					continue;
				}
				char arr[]= str.toCharArray();
				int counter_i =0,counter_j =0, counter_k =0;
				
				for(int i=0;i<str.length();){
					
					String temp = arr[i]+"";
					//System.out.println(temp);
					
					while(true && i<str.length()){
						boolean neg = false;
						if(temp.equals("i")){
							counter_i++;
							i++;
							break;
						}
						if(temp.charAt(0)=='-'){
							neg = true;
							temp = temp.charAt(1)+"";
						}
						//System.out.println(i);
						if(i+1 >=str.length()){
							break;
						}
						temp = m.get(temp+arr[i+1]+"");
						//System.out.println(temp);
						if(temp.charAt(0)=='-' && neg){
							neg = false;
							temp = temp.charAt(1)+"";
						}
						
						if(neg){
							temp="-"+temp;
						}
						i++;
					}
					if(i+1 >str.length()){
						break;
					}
					temp = arr[i]+"";
					//System.out.println(temp+ " "+ i);
					
					while(true && i<str.length()){
						boolean neg = false;
						if(temp.equals("j")){
							counter_j++;
							i++;
							break;
						}
						if(temp.charAt(0)=='-'){
							neg = true;
							temp = temp.charAt(1)+"";
						}
					//	System.out.println("---"+i);
						if(i+1 >=str.length()){
							break;
						}
						temp = m.get(temp+arr[i+1]+"");
						//System.out.println(temp);
						if(temp.charAt(0)=='-' && neg){
							neg = false;
							temp = temp.charAt(1)+"";
						}
						
						if(neg){
							temp="-"+temp;
						}
						i++;
					}
					if(i+1 >str.length()){
						break;
					}
					temp = arr[i]+"";
					
					//System.out.println("dfaf");
					while(true && i<str.length()){
						boolean neg = false;
						if(temp.equals("k")){
							counter_k++;
							i++;
							break;
						}
						if(temp.charAt(0)=='-'){
							neg = true;
							temp = temp.charAt(1)+"";
						}
						if(i+1 >=str.length()){
							break;
						}
						temp = m.get(temp+arr[i+1]+"");
						//System.out.println(temp);
						if(temp.charAt(0)=='-' && neg){
							neg = false;
							temp = temp.charAt(1)+"";
						}
						
						if(neg){
							temp="-"+temp;
						}
						i++;
					}
				}
				
				if(counter_i==1 && counter_j==1 && counter_k==1){
					//System.out.println("sab available");
					//System.out.println("Case #"+testcase+": YES");
					bw.write("Case #"+testcase+": YES");
					
				}
				else{
					//System.out.println("Case #"+testcase+": NO");
					bw.write("Case #"+testcase+": NO");
					
				}
				//System.out.println("Case #"+testcase+":"+count);
				//bw.write("Case #"+testcase+": "+count);
				if(testcase<=test){
					bw.write("\n");
				}
				testcase++;
//				if(testcase<=test){
//					bw.write("\n");
//				}
			}
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
