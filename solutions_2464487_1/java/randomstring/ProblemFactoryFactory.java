import java.util.Scanner;

public class ProblemFactoryFactory {

  public static ProblemFactory produce (String type) {
    switch (type) {
    case "A":
      return new ProblemFactory() {
        @Override public Problem produce(Scanner s) {
          return new ProblemA(s);
        };
      };
    case "B":
      return new ProblemFactory() {
        @Override public Problem produce(Scanner s) {
          return new ProblemB(s);
        };
      };
    case "C":
      return new ProblemFactory() {
        @Override public Problem produce(Scanner s) {
          return new ProblemC(s);
        };
      };
    case "D":
      return new ProblemFactory() {
        @Override public Problem produce(Scanner s) {
          return new ProblemD(s);
        };
      };
    default:
      throw new IllegalArgumentException();
    }
  }

}
