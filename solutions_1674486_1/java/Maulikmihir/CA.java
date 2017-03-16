import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class CA {



	public static void main(String args[]){
		
		try{
		
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			String strTmp = br.readLine();
			BufferedWriter bw = new BufferedWriter(new FileWriter( new File("output.txt"),false));
			
			
			int inputSize = Integer.parseInt(strTmp);
			
			for(int i=0;i<inputSize;i++  ){

				// processing inputline
				strTmp = br.readLine();
				int N = Integer.parseInt(strTmp);
				String result = "No" ;
				
				ArrayList<ArrayList<Integer>> classList = new ArrayList<ArrayList<Integer>>();
				
				for(int j=0;j<N ; j++){
					strTmp = br.readLine();
					String[] cls = strTmp.split(" ");
					
					ArrayList<Integer> tmp = new ArrayList<Integer>();
					int totCls = Integer.parseInt(cls[0]);
					for(int k=0;k<totCls;k++){
						tmp.add( Integer.parseInt(cls[k+1]) );
					}
					
					classList.add( new ArrayList(tmp));
				}
				
				// find the loop
				boolean isBreak = false;
				
				for( int j=0 ; j< classList.size();j++){	
					
					ArrayList<Integer> tmp = new ArrayList<Integer>( classList.get(j)  );
					
					for(Integer a : classList.get(j)){
						
						ArrayList<Integer> sub = classList.get(a-1);
						
						do{
						    ArrayList<Integer> newlyAdded = new ArrayList<Integer>();
							for( Integer b:sub ){
								
								if( tmp.contains(b) ){
									result = "Yes";
									isBreak = true;
									break;
								}else{
									tmp.add(b);
									newlyAdded.add(b);
								}
								
							}
							sub = new ArrayList<Integer>();
							
							for(Integer c:newlyAdded){
								sub.addAll(classList.get(c-1));
							}
							
							if(isBreak){
								break;
							}
							
						}while( sub.size()>0 );	
						
						if(isBreak){
							break;
						}
					}
					
					if(isBreak){
						break;
					}
				}
				
				
				
				
				// produce output
                System.out.println("Case #"+(i+1)+": " + result );			
				bw.write("Case #"+(i+1)+": " + result);
				bw.newLine();
			}
			
			bw.close();
			br.close();
		
		
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
	


}
