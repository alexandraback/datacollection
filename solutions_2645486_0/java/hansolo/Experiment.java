package partb;


public class Experiment {

	// Input
 	public int E, R, N;
 	public int[] v;
 	
 	// Internal
	private int range;
	private int curE;
	
	// Output
	public int result;
 	
	public Experiment(int E, int R, int N) {
		// TODO Auto-generated constructor stub
		curE = this.E = E;
		this.R = R;
		this.N = N;
		v = new int[N];
		range = (int)Math.ceil(E/R);
		result =0;
	}

	public int Solve() {
		// TODO Auto-generated method stub

		int i;
		for(i = 0; i<N; i++)
		{
			int spendAmt=curE;
			int d;
			for(d=1;d<=range; d++)
			{
				if(i+d < v.length)
					if(v[i]<v[i+d])
					{
						spendAmt = curE +(d*R) -E;
						break;
					}
			}
			if(spendAmt<0)
				spendAmt=0;
			if(spendAmt>E)
				spendAmt=E;
			curE-=spendAmt;
			curE+=R;
			result+= v[i]*spendAmt;
		}
		return result;
	}

}
