
public class A {
  
  public static int getNumberOfPeopleNeeded(String input) {

    int neededPeople = 0;
    int standingPeople = 0;
    
    for (int i = 0; i < input.length(); i++) {
      int currentPeople = Integer.parseInt(input.charAt(i) + ""); 
      int difference = i - standingPeople;
     
      if (difference > 0) {
        neededPeople += difference;
        standingPeople += difference;
      }
      
      standingPeople += currentPeople;
    }
    
    
    return neededPeople;
  }

}
