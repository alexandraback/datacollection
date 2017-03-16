
public class B {

  public static int calculateNumberOfTurns(int[] plates) {

    int low = 0;
    int high = 1000;

    while (low <= high) {
      int mid = (low + high) >>> 1;
      
      boolean canEatForTurn = canEatForTurn(plates, mid);

      if (!canEatForTurn) {
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }

    return low;
  }
  
  private static boolean canEatForTurn(int[] plates, int turnsToFinish) {
    
    for (int i = 0; i < turnsToFinish; i++) {
      boolean canFinish = canEatForTurnAndShift(plates, turnsToFinish, i);
      if (canFinish) {
        return true;
      }
    }
    
    
    return false;
  }
  
  private static boolean canEatForTurnAndShift(int[] plates, int turnsToFinish, int shifts) {
    
    int spentShifts = 0;
    int realTurnsToFinish = turnsToFinish - shifts;
    
    for (int i = 0; i < plates.length; i++) {
      int numShifts = (plates[i] - 1) / realTurnsToFinish;
      spentShifts += numShifts;
      
      if (spentShifts > shifts) {
        return false;
      }
    }
    
    
    return true;
  }

}
