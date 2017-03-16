package oneC;

import java.awt.List;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ProblemA {
	
	public static void main(String[] args) throws IOException {
			BufferedReader br=new BufferedReader(new FileReader(new File("./onec/a-large.in")));
			BufferedWriter bw=new BufferedWriter(new FileWriter(new File("./onec/a-large.out")));
			
			int numOfCase=Integer.parseInt(br.readLine());
			StringBuilder out=new StringBuilder();
			for(int i=1;i<=numOfCase;i++){
				out.append("Case #"+i+": ");
				
				int classNumber=Integer.parseInt(br.readLine());
				ArrayList<ArrayList<Integer>>classDetail=new ArrayList<ArrayList<Integer>>();
				for(int j=0;j<classNumber;j++){
					String[]input=br.readLine().split(" ");
					ArrayList<Integer>parent=new ArrayList<Integer>();
					for(int k=0;k<input.length-1;k++){
						
						parent.add(Integer.parseInt(input[k+1]));
						
					}
					classDetail.add(parent);
				
				}
				boolean found=false;
				
				for(int j=0;j<classDetail.size();j++){
					ArrayList<Integer>path=(ArrayList<Integer>)classDetail.get(j).clone();
					
					int index=0;
					while(index<path.size()){
						
						if(path.get(index)==0){
							index++;
							continue;
						}
						ArrayList<Integer>toAdd=classDetail.get(path.get(index)-1);
						if(toAdd.size()>0){
							for(int l=0;l<toAdd.size();l++){
								if(path.contains(toAdd.get(l)))
									found=true;
								break;
							}
							if(found)
								break;
							path.addAll(toAdd);
						}else
							path.add(0);
						index++;
					}
					
					for(int k=0;k<classDetail.size();k++){
						int count=0;
						
						for(int l=0;l<path.size();l++)
							if(path.get(l)==k+1){
								count++;
								
							}
						
						if(count>1){
							found=true;
							break;
						}
					}
					
					if(found)
						break;
					
				}
				
				out.append(found?"Yes":"No");
				if(i!=numOfCase)
					out.append("\n");
			}
			
			bw.write(out.toString());
			bw.close();
			br.close();

		}
		
	
}
