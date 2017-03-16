import java.util.*;
import java.io.*;
public class C {

	boolean[] unique={false,false,true,true,true};
	/**************************************/
	void run(String inputfile){
	try{
		Scanner s;
		File file=new File("output.txt");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
		if(inputfile.equals("test")) s=new Scanner(System.in);
		else s=new Scanner(new FileInputStream(new File(inputfile)));
		int cases=s.nextInt();
		for(int X=0;X<cases;X++){
			pw.println("Case #"+(X+1)+": ");
	/**************************************/
			int r=s.nextInt();
			int n=s.nextInt();
			int m=s.nextInt();
			int k=s.nextInt();
			while(r>0){
				int[] eo=new int[2];
				int[] appeard=new int[m];
				int[] gt=new int[m];
				int[] input=new int[k];
				int twotwice=0;
				for(int i=0;i<k;i++){
					int tmp=s.nextInt();
					int[] count=new int[m];
					int tg=2;
					int counttotal=0;
					while(tmp!=1){
						if(tmp%tg==0){
							tmp/=tg;
							count[tg-1]++;
							counttotal++;
						}else tg++;
					}
					if(counttotal>n){
						count[1]-=2;
						count[3]++;
					}
					for(int j=1;j<m;j++){
						appeard[j]+=count[j];
						gt[j]=(gt[j]<count[j])?count[j]:gt[j];
					}
					if(count[1]!=0) eo[count[1]%2]++;
				}
				int gtcount=0;

				for(int i=1;i<m;i++){
					if(unique[i]) gtcount+=gt[i];
					else{
						if(eo[1]>0){
							gtcount++;
							appeard[1]=eo[1];
						}
						else if(eo[0]>0&&gt[3]==0){
							gt[3]++;
							appeard[3]+=eo[0];
							appeard[1]-=2*eo[0];
							gt[1]-=2;
							gtcount++;
						}
					}
				}
				int tp=(eo[1]>0)?1:0;
				while(gtcount<n&&n-gtcount<gt[1]-tp){
					gt[3]++;
					appeard[3]+=eo[0];
					appeard[1]-=2*eo[0];
					gt[1]-=2;
					gtcount++;
				}
				gt[1]=tp;
				while(gtcount<n){
					double max=0.0;
					int ind=1;
					for(int i=1;i<m;i++){
						double exp=(double)(appeard[i]*2)/(double)k-(double)gt[i];
						if(exp>=max){
							max=exp;
							ind=i;
						}
					}
					gt[ind]++;
					gtcount++;
				}
				int lcount=n;
				for(int i=1;i<m;i++){
					while(gt[i]>0){
						pw.print(i+1);
						gt[i]--;
						lcount--;
					}
				}
				while(lcount>0){
					pw.print(2);
					lcount--;
				}
				pw.print("\n");
				r--;
			}
			
	/**************************************/
		}
		pw.close();
	}catch(IOException e){
		System.out.println(e);
		System.exit(0);
	}}
	/**************************************/

	
	boolean isP(String tg){
		int a=0;
		int b=tg.length()-1;
		while(a<b){
			if(tg.charAt(a)!=tg.charAt(b)) return false;
			a++;
			b--;
		}
		return true;
	}
	
	
	public static void main(String[] args){
		
		new C().run(args[0]);
	}
}
