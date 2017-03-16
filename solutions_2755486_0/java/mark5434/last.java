import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;

class att {
	int d;
	int w,e;
	int s;
}

class compatt implements Comparator<att>{

	@Override
	public int compare(att arg0, att arg1) {
		return arg0.d-arg1.d;
	}
	
}

public class last {

	static att allatt[];
	static int wall[];
	static int nw[];
	
	static void calc(int cid) {
		wall = new int[2000000];
		nw = new int[2000000];
		int lastday=0;
		int succn=0;
		boolean lastsucc =false;
		for (int i=0;i<allatt.length;i++) {
			//System.out.printf("%d %d %d %d%n",allatt[i].d,allatt[i].w,allatt[i].e,allatt[i].s);
			if (allatt[i].d != lastday && lastsucc) {
				for (int ich=0;ich<wall.length;ich++) {
					wall[ich]=nw[ich]>wall[ich]?nw[ich]:wall[ich];
				}
				lastsucc=false;
				nw = new int[2000000];
			}
			boolean succ=false;
			for (int ich=allatt[i].w+1000000;ich<allatt[i].e+1000000;ich++) {
				nw[ich]=allatt[i].s>nw[ich]?allatt[i].s:nw[ich];
				if (allatt[i].s>wall[ich]) {
					succ=true;
					lastsucc=true;
				}
			}
			if (succ) {
				succn++;
			}
			lastday=allatt[i].d;
//			for (int ich=1000000;ich<1000010;ich++) {
//				System.out.printf("%d ",wall[ich]);
//			}
//			System.out.printf("of att %d%n",i);
		}
		System.out.printf("Case #%d: %d%n", cid,succn);
	}
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) {
		try {
			ArrayList<att> attlistall;
			Scanner sc =new Scanner(new File("d:/in"));
			int n = sc.nextInt();
			for (int cid =1;cid<=n;cid++) {
				attlistall =new ArrayList<att>();
				int N=sc.nextInt();
				for (int i=0;i<N;i++) {
					int id=sc.nextInt();
					int in=sc.nextInt();
					int iw=sc.nextInt();
					int ie=sc.nextInt();
					int is=sc.nextInt();
					int idd=sc.nextInt();
					int idp=sc.nextInt();
					int ids=sc.nextInt();
					for (int j=0;j<in;j++) {
						att a =new att();
						a.d=id+j*idd;
						a.e=ie+j*idp;
						a.w=iw+j*idp;
						a.s=is+j*ids;
						attlistall.add(a);
					}
				}
				allatt =new att[attlistall.size()];
				//System.out.println(allatt.length);
				attlistall.toArray(allatt);
				Arrays.sort(allatt,new compatt());
				calc(cid);
				//System.out.println(cid);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
