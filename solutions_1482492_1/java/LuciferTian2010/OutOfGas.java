import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class OutOfGas {

	private static FileReader freader;
	private static BufferedReader buffreader;
	private static FileWriter fwriter;
	private static BufferedWriter buffwriter;
	
	public static void main(String[] args) throws IOException {
		freader = new FileReader("B-large.in");
		buffreader = new BufferedReader(freader);
		fwriter= new FileWriter("result-large.txt");
		buffwriter = new BufferedWriter(fwriter);
		String str = null;
		int linenum = 0;
		int i=1;
		while((str=buffreader.readLine())!=null){
			if(i==1)
				linenum=Integer.parseInt(str);
			else{
				double dis = Double.parseDouble(str.split(" ")[0]);
				int posNum = Integer.parseInt(str.split(" ")[1]);
				int accNum = Integer.parseInt(str.split(" ")[2]);
				double[] times = new double[posNum];
				double[] dispos = new double[posNum];
				double[] accs = new double[accNum];
				for(int j=0; j<posNum; j++){
					str=buffreader.readLine();
					times[j] = Double.parseDouble(str.split(" ")[0]);
					dispos[j] = Double.parseDouble(str.split(" ")[1]);
					//System.out.println(times[j]+"\t"+dispos[j]);
				}
				str=buffreader.readLine();
				for(int j=0; j<accNum; j++){
					accs[j] = Double.parseDouble(str.split(" ")[j]);
				}
				String finalStr = "Case #"+Integer.toString(i-1)+":\n";
				for(int j=0; j<accNum; j++){
					double minTime = getMinTime(times, dispos, accs[j], dis);
					finalStr+=minTime+"\n";
				}
				System.out.println(finalStr);
				buffwriter.write(finalStr);
			}
			i++;
		}
		buffwriter.close();
		fwriter.close();
		buffreader.close();
		freader.close();

	}
	
	public static double getMinTime(double[] times, double[] dispos, double acc, double totaldis){
		int num = times.length;
		double v = 0f;
		double dis = 0f;
		double totatltime = 0f;
		if(dispos[0]>totaldis){
			totatltime = (double) Math.sqrt(2*totaldis/acc);
			//System.out.println(totatltime);
			return totatltime;
		}
		for(int i =1; i<num; i++){
			//System.out.println(dispos[i]+"\t"+totaldis);
			if(dispos[i]<totaldis){
				double dt = times[i]-times[i-1];
				double calDis = (double) (dis+v*dt+0.5*acc*dt*dt);
				if(calDis>dispos[i]){
					v = (dispos[i]-dispos[i-1])/dt;
					dis = dispos[i];
				}
				else{
					v = v+acc*dt;
					dis = calDis;
				}
				//totatltime =  times[i];
				System.out.println("\t"+v+"\t"+dis);
				
			}
			else{
				double v2 = (dispos[i]-dispos[i-1])/(times[i]-times[i-1]);
				double t2 = times[i-1]+(totaldis-dispos[i-1])/v2;
				double dt = (totaldis-dispos[i-1])/v2;
				double calDis = (double) (dis+v*dt+0.5*acc*dt*dt);
				if(calDis>totaldis){
					v = v2;
					dis = totaldis;
					
				}
				else{
					v = v+acc*dt;
					dis = calDis;
				}
				totatltime =  t2;
				System.out.println(v+"\t"+dis+"\t"+t2);
				
				break;
			}
		}
		if(dis==totaldis){
			return totatltime;
		}
		else{
			double last = totaldis-dis;
			//System.out.println(last);
			double tn = (Math.sqrt(v*v+2*acc*last)-v)/acc;
			//System.out.println(tn);
			return totatltime+tn;
		}
		
	}

}
