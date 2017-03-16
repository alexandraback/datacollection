import java.io.IOException;


public class B extends CodeJammer {

	@Override
	public void process() throws IOException {
		// TODO Auto-generated method stub
		double c = reader.getDouble();
		double f = reader.getDouble();
		double x = reader.getDouble();
		double r = 2; //initial rate
		int farms = (int) ((x*f-r*c)/(c*f)); // number of farms that you should build
		if (farms < 0) farms = 0;
		double cost = 0;
		for (int i=0; i<farms; i++) {
			cost += c / (r + i*f);
		}
		cost += x / (r + farms*f);
		output(cost);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		B b = new B();
		b.run(args);
	}

}
