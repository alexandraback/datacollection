import java.util.Scanner;

class q3{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    if(possible(3,3,4))
      return;
    for(int i=1;i<=n;i++){
      int r = in.nextInt();
      int c = in.nextInt();
      int m = in.nextInt();
      System.out.println("Case #"+i+":\n"+q3(r, c, m));
    }
  }
  public static String q3(int r, int c, int m){
    if(possible(Math.min(r,c),Math.max(r,c),m))
      return draw(r,c,m);
    return "impossible";
  }
  public static String drawfull(int r, int c){
     String out = "";
     String row = "";
     for(int i=0;i<c;i++)
       row += "*";
     for(int j=0;j<r;j++)
       out += row+"\n";
     return out.substring(0,out.length()-2)+"c";
  }
  public static String draw(int r, int c, int m){
    //too many exceptions otherwise
    if(r*c-m == 1)
      return drawfull(r,c);

    //arg this is ugly and should be streamlined.
    //would be good to remove possible method and just check at end if all's well.  Would help with verification.

    String out = "";
    int mines = m;
    for(int i=0;i<r-2;i++){
      for(int j=0; j<c-2; j++){
        //if we have the mines and also parity stuff
        if(mines > 0 && !(i == r-3 && j == c-3 && (r*c-m) % 2 == 1)){
          out += "*";
          mines --;
        }
        else out += ".";
      }
      //fill last two cols in pairs
      if(c >= 2){
        //if we have the mines and also parity stuff
        if(mines >= 2 && !(i == r-3 && (r*c-m) % 2 == 1)){
          out += "**";
          mines -= 2;
        }
        else out += "..";
      }
      //else we have a string
      else out += (mines-- > 0 ? "*":".");
      out += "\n";
    }
    //fill last two rows in pairs
    if(r >= 2){
      int nextrow = 0;
      //2nd-to-last row
      for(int j=0; j<c; j++){
	//if we have the mines...
        if(mines-2 >= 0){
          mines -= 2;
          nextrow++;
          out += "*";
        }
        else out += ".";
      }
      out += "\n";
      mines = nextrow;
    }
    //last row...
    for(int j=0; j<c-1; j++){
      if(mines-- > 0)
        out += "*";
      else out += ".";
    }
    //plus "c"!
    out += "c";
    return out;
  }
  public static boolean possible(int r, int c, int m){
    if(m == 0)
      return true;
    if(r < 2 || c < 2)//grid is a string
      return true;
    int empty = r*c-m;
    if(empty == 1)
      return true;
    if(empty == 2)
      return false;
    if(r < 3 || c < 3)//grid is 2xc
      return (empty % 2 == 0);//must have even number of empties
    if(empty >= 8)
      return true;
    return (empty % 2 == 0);
  }
}
