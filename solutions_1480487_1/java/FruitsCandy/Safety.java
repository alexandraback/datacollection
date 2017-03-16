import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Safety extends CodeJamIO {
	public static void main(String[] args){
		CodeJamIO as=new Safety("A-large.in","out.txt");
		as.read();
		as.solve();
		as.write();
	}
	
	public Safety(String file_in, String file_out) {
		super(file_in, file_out);
	}

	public void solve() {
		int case_num=getInt();
		for(int count=0;count<case_num;count++){
			int cons=getInt();
			List<Integer> points=getInts();
			List<Integer> points2=new ArrayList<Integer>();
			int tot=0;
			for(Integer i:points){
				tot+=i;
				points2.add(i);
			}
			Collections.sort(points2);
			int water=0;
			double cut=2*(tot+0.0)/cons;
			int bottom=points2.get(0);
			for(int count2=1;count2<cons;count2++){
				int prev=points2.get(count2-1);
				int cur=points2.get(count2);
				int adder=count2*(cur-prev);
				water+=adder;
				if(water>tot){
					cut=cur-((water-tot+0.0)/count2);
					break;
				}
			}
			List<Double> needs=new ArrayList<Double>();
			for(Integer i:points){
				if(cut<i){
					needs.add(0.0);
				}else{
					needs.add(100*(cut-i)/tot);
				}
			}
			String line="";
			for(Double d:needs){
				line+=(" "+d);
			}
			line=line.substring(1);
			addResult(line);
		}

	}

}
