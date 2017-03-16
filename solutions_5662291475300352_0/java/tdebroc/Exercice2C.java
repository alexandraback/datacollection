import java.util.List;


public class Exercice2C extends Reader {

	@Override
	protected String getFileName() {
		return "C-small-1-attempt2.in";
	}

	@Override
	protected int getNumberOfLinePerCase() {
		return 0;
	}

	@Override
	protected void init(String firstLine) {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void handleCase(List<String> lines) {
		long numberOfLinesPerCase = Long.parseLong(lines.get(0));
		Hicker h1, h2, h3;
		if (numberOfLinesPerCase > 1) {
			h1 = new Hicker(lines.get(1));
			h2 = new Hicker(lines.get(2));
		} else {
			String[] linesSplitted = lines.get(1).split(" ");
			long start = Long.parseLong(linesSplitted[0]);
			long speed = Long.parseLong(linesSplitted[2]);
			
			h1 = new Hicker(start, speed);
			h2 = new Hicker(start, speed + 1);
		}
		
		
		if (h1.speed > h2.speed) {
			h3 = new Hicker(h1.start, h1.minuteForTour);
			h1 = new Hicker(h2.start, h2.minuteForTour);
			h2 = new Hicker(h3.start, h3.minuteForTour);
		}
		
		long remain = 360 - h1.start; 
		double timeToFinish = (double)remain / h1.speed;
		// System.out.println(timeToFinish);
		double distanceH2 = timeToFinish * h2.speed + h2.start;
		double numberLoopH2 = distanceH2 / 360;
		
		
		
		long cross = numberLoopH2 >= 2 ? 1 : 0;
		// System.out.println(cross);
		printResult("" + cross);
	}
	
	
	class Hicker {
		long start;
		long minuteForTour;
		double speed;
		public Hicker(String line) {
			String[] linesSplitted = line.split(" ");
			start = Long.parseLong(linesSplitted[0]);
			minuteForTour = Long.parseLong(linesSplitted[2]);
			speed = (double)360 / (double)minuteForTour;
		}
		public Hicker(long start, long minuteForTour) {
			super();
			this.start = start;
			this.minuteForTour = minuteForTour;
			speed = (double)360 / (double)minuteForTour;
		}
		
	}
}
