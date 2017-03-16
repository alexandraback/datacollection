import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.util.*;

//DancingGooglers.java
//Completes the Dancing with Googlers problem for Google Code Jam 2012
//By Jack Thakar
//Coded in Java using Eclipse 3.7
public class EqualSums {
	public static void main(String[] args){
		String input = readFile("C-small-attempt1.in");
		String[] lines = input.split(System.lineSeparator());
		String output = "";
		for(int i=1;i<lines.length;i++){
			Case c = (new EqualSums()).new Case(lines[i]);
			output+="Case #"+i+":\n";
			output+=c.getSolution();
			if(i<lines.length-1) output+=System.lineSeparator();
		}
		writeFile("C-small-attempt1.out",output);
	}
	class Case{
		private List<Long> list;
		public Case(String line){
			String[] splits = line.split(" ");
			list = new ArrayList<Long>();
			for(int i=1;i<splits.length;i++){
				list.add(Long.parseLong(splits[i]));
			}
		}
		public String getSolution(){
			List<Long[]> list2p = new ArrayList<Long[]>();
			List<Long> list2 = new ArrayList<Long>();
			for(int i=0;i<list.size()-1;i++){
				for(int j=i+1;j<list.size();j++){
					if(list.contains(list.get(i)+list.get(j))){
						String rS = list.get(list.indexOf(list.get(i)+list.get(j))).toString();
						rS+="\n";
						rS+=list.get(i)+" "+list.get(j);
						return rS;
					}
					if(list2.contains(list.get(i)+list.get(j))){
						Long[] l = list2p.get(list2.indexOf(list.get(i)+list.get(j)));
						String rS = l[0]+" "+l[1];
						rS+="\n";
						rS+=list.get(i)+" "+list.get(j);
						return rS;
					}
					list2p.add(new Long[] {list.get(i),list.get(j)});
					list2.add(list.get(i)+list.get(j));
				}
			}
			List<Long[]> list3p = new ArrayList<Long[]>();
			List<Long> list3 = new ArrayList<Long>();
			for(int i=0;i<list.size()-2;i++){
				for(int j=i+1;j<list.size()-1;j++){
					for(int k=j+1;k<list.size();k++){
						if(list.contains(list.get(i)+list.get(j)+list.get(k))){
							String rS = list.get(list.indexOf(list.get(i)+list.get(j)+list.get(k))).toString();
							rS+="\n";
							rS+=list.get(i)+" "+list.get(j)+" "+list.get(k);
							return rS;
						}
						if(list2.contains(list.get(i)+list.get(j)+list.get(k))){
							Long[] l = list2p.get(list2.indexOf(list.get(i)+list.get(j)+list.get(k)));
							String rS = l[0]+" "+l[1];
							rS+="\n";
							rS+=list.get(i)+" "+list.get(j)+" "+list.get(k);
							return rS;
						}
						if(list3.contains(list.get(i)+list.get(j)+list.get(k))){
							Long[] l = list3p.get(list3.indexOf(list.get(i)+list.get(j)+list.get(k)));
							String rS = l[0]+" "+l[1]+" "+l[2];
							rS+="\n";
							rS+=list.get(i)+" "+list.get(j)+" "+list.get(k);
							return rS;
						}
						list3p.add(new Long[] {list.get(i),list.get(j),list.get(k)});
						list3.add(list.get(i)+list.get(j)+list.get(k));
					}
				}
			}
			List<Long[]> list4p = new ArrayList<Long[]>();
			List<Long> list4 = new ArrayList<Long>();
			for(int i=0;i<list.size()-3;i++){
				for(int j=i+1;j<list.size()-2;j++){
					for(int k=j+1;k<list.size()-1;k++){
						for(int m=k+1;m<list.size();m++){
							if(list.contains(list.get(i)+list.get(j)+list.get(k)+list.get(m))){
								String rS = list.get(list.indexOf(list.get(i)+list.get(j)+list.get(k))).toString();
								rS+="\n";
								rS+=list.get(i)+" "+list.get(j)+" "+list.get(k)+" "+list.get(m);
								return rS;
							}
							if(list2.contains(list.get(i)+list.get(j)+list.get(k)+list.get(m))){
								Long[] l = list2p.get(list2.indexOf(list.get(i)+list.get(j)+list.get(k)));
								String rS = l[0]+" "+l[1];
								rS+="\n";
								rS+=list.get(i)+" "+list.get(j)+" "+list.get(k)+" "+list.get(m);
								return rS;
							}
							if(list3.contains(list.get(i)+list.get(j)+list.get(k)+list.get(m))){
								Long[] l = list3p.get(list3.indexOf(list.get(i)+list.get(j)+list.get(k)));
								String rS = l[0]+" "+l[1]+" "+l[2];
								rS+="\n";
								rS+=list.get(i)+" "+list.get(j)+" "+list.get(k)+" "+list.get(m);
								return rS;
							}
							if(list4.contains(list.get(i)+list.get(j)+list.get(k)+list.get(m))){
								Long[] l = list4p.get(list4.indexOf(list.get(i)+list.get(j)+list.get(k)));
								String rS = l[0]+" "+l[1]+" "+l[2]+" "+l[3];
								rS+="\n";
								rS+=list.get(i)+" "+list.get(j)+" "+list.get(k)+" "+list.get(m);
								return rS;
							}
							list4p.add(new Long[] {list.get(i),list.get(j),list.get(k),list.get(m)});
							list4.add(list.get(i)+list.get(j)+list.get(k)+list.get(m));
						}
					}
				}
			}
			return "Impossible";
		}
	}

	private static String readFile(String name){
		File file = new File("input"+File.separator+name);
		Charset charset = Charset.forName("ASCII");
		String text = "";
		try (BufferedReader reader = Files.newBufferedReader(file.toPath(), charset)) {
			String line = null;
			while ((line = reader.readLine()) != null) {
				text+=line+System.lineSeparator();
			}
		} catch (IOException e) {
		}
		return text;
	}
	private static void writeFile(String name, String data){
		File file = new File("output"+File.separator+name);
		Charset charset = Charset.forName("ASCII");
		try (BufferedWriter writer = Files.newBufferedWriter(file.toPath(), charset)) {
			writer.write(data, 0, data.length());
		} catch (IOException e) {
		}
	}
}
