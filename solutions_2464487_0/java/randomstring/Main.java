import java.util.Scanner;

public class Main {

  public static void main (String [] arg) {
    if (arg.length != 1) {
      throw new IllegalArgumentException("supply problem type argument");
    }
    ProblemFactory problem_factory = ProblemFactoryFactory.produce(arg[0]);
	  Scanner s = new Scanner(System.in);
	  int n = s.nextInt();
	  for (int i = 0; i < n; ++i) {
	    Problem problem = problem_factory.produce(s);
	    String solution = problem.solve();
	    System.out.println("Case #" + (i + 1) + ": " + solution);
	  }

	}

}
