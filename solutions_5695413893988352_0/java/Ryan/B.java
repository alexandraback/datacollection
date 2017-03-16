import java.util.*;

public class B{
  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    int cases=scanner.nextInt();
    for(int c=1;c<=cases;c++){
      coderBoard=scanner.next();
      coderBoard=new StringBuilder(coderBoard).reverse().toString();
      jammerBoard=scanner.next();
      jammerBoard=new StringBuilder(jammerBoard).reverse().toString();
      State s=solve();
      //State t=bruteSolve();
      /*if(s.getDifference()!=t.getDifference()){
        System.out.println(coderBoard+" "+jammerBoard);
        System.out.println("Case #"+c+": "+s.getCoderScore()+" "+s.getJammerScore());
        System.out.println("Case #"+c+": "+t.getCoderScore()+" "+t.getJammerScore());
        //break;
      }*/
      System.out.println("Case #"+c+": "+s.getCoderScore()+" "+s.getJammerScore());
    }
  }

  private static String coderBoard,jammerBoard;

  private static class State{
    private String coderScore,jammerScore;
    private long difference;
    private boolean bad;

    public State(boolean bad){
      this.bad=bad;
      difference=0;
      coderScore="";
      jammerScore="";
    }

    public State(long difference,String coderScore,String jammerScore){
      this.coderScore=coderScore;
      this.jammerScore=jammerScore;
      this.difference=difference;
      this.bad=false;
    }

    public String getCoderScore(){ return coderScore; }
    public String getJammerScore(){ return jammerScore; }
    public long getDifference(){ return difference; }
    public boolean isBad(){ return bad; }

    public boolean isBetter(State other){
      if(coderScore.compareTo(other.coderScore)!=0)
        return coderScore.compareTo(other.coderScore)<0;
      return jammerScore.compareTo(other.jammerScore)<0;
    }
  }

  private static State solve(){
    State[] states=new State[4];
    for(int i=0;i<4;i++)
      states[i]=new State(false);

    long powerTen=1;
    for(int i=0;i<coderBoard.length();i++){
      states=dp(i,states,powerTen);
      powerTen*=10;
    }

    if(states[0].isBad())
      return states[1];
    if(states[1].isBad())
      return states[0];
    if(-states[0].getDifference() < states[1].getDifference())
      return states[0];
    if(-states[0].getDifference() > states[1].getDifference())
      return states[1];

    if(states[0].isBetter(states[1]))
      return states[0];
    return states[1];
  }

  private static State[] dp(int index,State[] previousStates,long powerTen){
    char coderDigit=coderBoard.charAt(index);
    char jammerDigit=jammerBoard.charAt(index);
    State[] ret=new State[4];
    for(int i=0;i<4;i++)
      ret[i]=new State(true);
    for(int cd=0;cd<10;cd++){
      char newCoderDigit=(char)('0'+cd);
      if(coderDigit!='?' && coderDigit!=newCoderDigit) continue;
      for(int jd=0;jd<10;jd++){
        char newJammerDigit=(char)('0'+jd);
        if(jammerDigit!='?' && jammerDigit!=newJammerDigit) continue;

        long currentDifference=(cd-jd)*powerTen;
        State nextState;
        if(cd>jd){
          nextState=new State(currentDifference+previousStates[2].getDifference(),newCoderDigit+previousStates[2].getCoderScore(),newJammerDigit+previousStates[2].getJammerScore());
          updateStates(ret,nextState);

          nextState=new State(currentDifference+previousStates[3].getDifference(),newCoderDigit+previousStates[3].getCoderScore(),newJammerDigit+previousStates[3].getJammerScore());
          updateStates(ret,nextState);
        }else if(cd==jd){
          if(!previousStates[0].isBad()){
            nextState=new State(previousStates[0].getDifference(),newCoderDigit+previousStates[0].getCoderScore(),newJammerDigit+previousStates[0].getJammerScore());
            updateStates(ret,nextState);
          }

          if(!previousStates[1].isBad()){
            nextState=new State(previousStates[1].getDifference(),newCoderDigit+previousStates[1].getCoderScore(),newJammerDigit+previousStates[1].getJammerScore());
            updateStates(ret,nextState);
          }

          nextState=new State(previousStates[2].getDifference(),newCoderDigit+previousStates[2].getCoderScore(),newJammerDigit+previousStates[2].getJammerScore());
          updateStates(ret,nextState);

          nextState=new State(previousStates[3].getDifference(),newCoderDigit+previousStates[3].getCoderScore(),newJammerDigit+previousStates[3].getJammerScore());
          updateStates(ret,nextState);
        }else if(cd<jd){
          nextState=new State(currentDifference+previousStates[2].getDifference(),newCoderDigit+previousStates[2].getCoderScore(),newJammerDigit+previousStates[2].getJammerScore());
          updateStates(ret,nextState);

          nextState=new State(currentDifference+previousStates[3].getDifference(),newCoderDigit+previousStates[3].getCoderScore(),newJammerDigit+previousStates[3].getJammerScore());
          updateStates(ret,nextState);
        }
      }
    }
    //for(int i=0;i<ret.length;i++) System.out.println(index+": "+i+": "+ret[i].getDifference()+", "+ret[i].getCoderScore()+" to "+ret[i].getJammerScore());
    return ret;
  }

  private static void updateStates(State[] result,State currentState){
    if(currentState.getDifference()<=0){
      if(result[0].isBad())
        result[0]=currentState;
      else if(currentState.getDifference()>result[0].getDifference())
        result[0]=currentState;
      else if(currentState.getDifference()==result[0].getDifference() && currentState.isBetter(result[0]))
        result[0]=currentState;
    }

    if(currentState.getDifference()>=0){
      if(result[1].isBad())
        result[1]=currentState;
      else if(currentState.getDifference()<result[1].getDifference())
        result[1]=currentState;
      else if(currentState.getDifference()==result[1].getDifference() && currentState.isBetter(result[1]))
        result[1]=currentState;
    }

    if(result[2].isBad())
        result[2]=currentState;
    else if(currentState.getDifference()<result[2].getDifference())
      result[2]=currentState;
    else if(currentState.getDifference()==result[2].getDifference() && currentState.isBetter(result[2]))
      result[2]=currentState;

    if(result[3].isBad())
      result[3]=currentState;
    else if(currentState.getDifference()>result[3].getDifference())
      result[3]=currentState;
    else if(currentState.getDifference()==result[3].getDifference() && currentState.isBetter(result[3]))
      result[3]=currentState;
  }

  private static boolean matches(int score,String board){
    for(int i=0;i<board.length();i++){
      int digit=score%10;
      score/=10;
      if(board.charAt(i)=='?') continue;
      if(board.charAt(i)!='0'+digit)
        return false;
    }

    for(int i=board.length();i<3;i++){
      int digit=score%10;
      score/=10;
      if(digit!=0)
        return false;
    }

    return true;
  }

  private static State bruteSolve(){
    State bestState=new State(true);
    for(int cs=0;cs<1000;cs++)
      if(matches(cs,coderBoard))
        for(int js=0;js<1000;js++)
          if(matches(js,jammerBoard)){
            long difference=cs-js;
            State currentState=new State(difference,""+cs,""+js);
            if(bestState.isBad())
              bestState=currentState;
            else if(Math.abs(difference)<Math.abs(bestState.getDifference()))
              bestState=currentState;
            else if(Math.abs(difference)==Math.abs(bestState.getDifference()) && currentState.isBetter(bestState))
              bestState=currentState;
          }
    return bestState;
  }
}
