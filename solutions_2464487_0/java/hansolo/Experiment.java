
public class Experiment {

	// INPUT
	long r;
	long t;
	// INTERNAL
	long factor;
	boolean paintable;

	// OUTPUT
	long result;
	
	public Experiment(long r, long t) {
		// TODO Auto-generated constructor stub
		this.r =  r;
		this.t =  t;
		factor = r+r+1;
		result = 0;
		paintable=true;
	}

	public long Solve() {
		// TODO Auto-generated method stub
		while(paintable)
		{
			checkBlackCircle();	
			nextBlackCircle();	
		}
		return result;
	}

	private void checkBlackCircle() {
		// TODO Auto-generated method stub
		
		if(t>=factor)
		{
			t-=factor;
			//System.out.println(t);
			result++;	
		}
		else
			paintable = false;
		
	}

	private void nextBlackCircle() {
		// TODO Auto-generated method stub
		factor+=4;
		
	}
	
	
}
