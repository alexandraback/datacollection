import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

public class A {

	ArrayList<Integer> done = new ArrayList<Integer>();
	
	public void rec (Map<Integer,ArrayList<Integer>> S,int v,ArrayList<Integer> N){
		done.add(v);
		System.out.println("DONE "+done);
		ArrayList<Integer> t = S.get(v);
		//System.out.println("t " +t );
		//System.out.println("N " +N );

		if(t.size()>0){
			for(int i =0;i<t.size();i++){
				if(!done.contains(t.get(i)))
					rec(S,t.get(i),N);
					N.add(t.get(i));
				System.out.println("N "+N);
			}
		}


	}

	public static void main(String[] args){
		String in ="small.txt";
		String out = "output.txt";
		Scanner sc;
		String answers[]=new String[3];
		A a = new A();
		try {
			sc = new Scanner(new File(in));
			sc.useLocale(Locale.FRENCH);
			int T = sc.nextInt();
			answers = new String[T];
			for(int zz =0;zz<T;zz++)
			{
				int N = sc.nextInt();
				Map<Integer,ArrayList<Integer>> S = new HashMap<Integer,ArrayList<Integer>>();
				Map<Integer,ArrayList<Integer>> Inverse = new HashMap<Integer,ArrayList<Integer>>();


				int M [][]= new int[N][N];
				for(int i=0;i<N;i++){
					ArrayList<Integer> inv = new ArrayList<Integer>();
					Inverse.put(i+1,inv);
					for(int j=0;j<N;j++){
						M[i][j]=0;
					}

				}
				for(int i = 0;i<N;i++){
					int tmp=sc.nextInt();
					ArrayList<Integer> t = new ArrayList<Integer>();
					for(int j=0;j<tmp;j++){
						int c = sc.nextInt();
						M[i][c-1] = 1;
						t.add(c);

						//						ArrayList<Integer> invOk = Inverse.get(i+1);
						//
						//						for(int v : invOk){
						//							ArrayList<Integer> e = S.get(v);
						//							e.add(c);
						//							S.put(v,e);
						//						}
						ArrayList<Integer> inv = Inverse.get(c);
						inv.add(i+1);
						Inverse.put(c, inv);

					}
					S.put(i+1, t);
				}

				for(int i =0;i<N;i++){
					ArrayList<Integer> nbOk = new ArrayList<Integer>();
					for(int j=0;j<N;j++){
						if(M[j][i]==1)
							nbOk.add(j+1);
					}
					if(nbOk.size()>=2)
						System.out.println(" Col "+ i +" "+nbOk);
				}
				boolean ok = false;
				for(int i=0;i<N;i++){
					if(ok==false){
						ArrayList<Integer> Na = new ArrayList<Integer>();
						a.rec(S, i+1,Na);
						a.done.clear();
						System.out.println(i+ " " +Na);
						int cmp[] = new int[N];
						for(int j=0;j<N;j++){
							cmp[j]=0;
						}
						for(int j =0;j<Na.size();j++)
							cmp[Na.get(j)-1]++;
						for(int j=0;j<N;j++){
							if(j!=i && cmp[j]>=2)
								ok=true;
						}					}
				}

				System.out.println();



				//System.out.println();

				int z = zz+1;
				if(ok)
					answers[zz]="Case #"+z+": Yes\n";
				else
					answers[zz]="Case #"+z+": No\n";

			}




		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		try
		{
			PrintWriter pw = new PrintWriter(out);
			for(int i=0;i<answers.length;i++)
				pw.println(answers[i]);
			pw.close();	

		}
		catch (Exception e){
			System.out.println(e.toString());
		}



	}


}
