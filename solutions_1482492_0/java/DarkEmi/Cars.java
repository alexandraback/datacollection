
public class Cars 
{
	double 			dist;
	double[][] 		other;
	double[]		accel;
	int 			N;
	int				A;
	
	public Cars(double homeDist, double[][] otherCar, double[] Aaccel, int nn, int aa) 
	{
		dist = homeDist;
		
		N = nn;
		A = aa;
		other = otherCar;
		accel = Aaccel;
	}

	public String solve()
	{
		Double time = null;
		for (int i = 0; i < A; i++)
		{
			 time = tryForAccel(i, 0, dist, 0, 0);
			 System.out.println("show time : " + time);
		}
		
		return ("" + time);
	}

	private double tryForAccel(int index, int beginCarIndex, double distLeft, 
			double AcurrentSpeed, double currentTime) 
	{
		double currentAccel = accel[index];
		double currentSpeed = AcurrentSpeed;
		double currentPos = 0;
		
		int currentOtherCarCompare = 0;
		
		// dichotomie
		
		boolean collision = false;
		for (int i = beginCarIndex; i < N; i++)
		{
			if (distanceDoneAt(currentSpeed, currentAccel, other[i][0]) >
			other[i][1])
			{
				if (distLeft >= (other[i][1] - other[i - 1][1]))
				{
					double otherCarSpeed = (other[i][1] - other[i - 1][1]) / (other[i][0] - other[i - 1][0]);
					double timeAdded = tryForAccel(index, i + 1, distLeft - other[i][1], otherCarSpeed, currentTime ); 
					return (timeAdded + other[i][0]);
				}
				else
				{
					double otherCarSpeed = (other[i][1] - other[i - 1][1]) / (other[i][0] - other[i - 1][0]);
					if (otherCarSpeed < currentSpeed)
						return (distLeft / otherCarSpeed);
					else
						return getPreciseTimeFor(currentAccel, currentSpeed, distLeft);
				}
			}
		}
		
		if (collision == false)
			return (getPreciseTimeFor(currentAccel, currentSpeed, distLeft));
		else
			return 0;
		
	}

	private double getPreciseTimeFor(double currentAccel,
			double currentSpeed, double distToDo)
	{
		double maxTime = 100000000000000D;
		double minTime = 0;
		
		while ((minTime + 0.00000000001) < maxTime)
		{
			double testDist =  distanceDoneAt(currentSpeed, currentAccel, (maxTime + minTime) * 0.5);
			if (testDist > distToDo)
			{
				maxTime = (maxTime + minTime) * 0.5;
			}
			else
				minTime = (maxTime + minTime) * 0.5;
		}
		
		return minTime;
	}
	
	public double distanceDoneAt(double vo, double currentAccel, double time)
	{
		/*
		 *  v0*t + 0.5*a*t2 
		 */
		return ((vo * time) + (0.5 * currentAccel * time * time));
	}

}
