public class Hiker {
	
	final long timeToTurn;
	final long initPos;
	
	final long timetofinish;
	
	Hiker(long t, long i){
		timeToTurn =t*360;
		initPos = i;
		timetofinish = (360-i)*t;
		System.out.println(timetofinish);
	}


	
	public String toString(){
		return "TimeToFinish : "+timetofinish+" timetoturn : "+timeToTurn+" initPos : "+initPos;
		
	}

	public long crossingWith(long timetofinishtarget) {
		//le cerf double le hiker
		if (timetofinish>timetofinishtarget){
			return 1;
		}
		// le hiker double le cerf
		timetofinishtarget-=timetofinish;
		return timetofinishtarget/timeToTurn;
	}
}
