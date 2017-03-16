import java.util.*;

class Googlerese{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String jumbled;
    StringTokenizer st;
    int test;
    test = sc.nextInt();
    sc.nextLine();
    for(int i=1;i<=test;i++){
      System.out.print("Case #"+i+": ");
      jumbled = sc.nextLine();

      st = new StringTokenizer(jumbled);
      while(st.hasMoreTokens()){
        jumbled = st.nextToken();
        for(int j=0;j<jumbled.length();j++)
          convert(jumbled.charAt(j));
        System.out.print(" ");
      }
      System.out.println();
      
    }
  }
  public static void convert(char converting){
    char converts = 'a';
    switch(converting){
      case 'a':
        converts = 'y';
        break;
       case 'b':
        converts = 'h';
        break;
         case 'c':
        converts = 'e';
        break;
         case 'd':
        converts = 's';
        break;
         case 'e':
        converts = 'o';
        break;
         case 'f':
        converts = 'c';
        break;
         case 'g':
        converts = 'v';
        break;
         case 'h':
        converts = 'x';
        break;
         case 'i':
        converts = 'd';
        break;
         case 'j':
        converts = 'u';
        break;
         case 'k':
        converts = 'i';
        break;
         case 'l':
        converts = 'g';
        break;
         case 'm':
        converts = 'l';
        break;
         case 'n':
        converts = 'b';
        break;
         case 'o':
        converts = 'k';
        break;
         case 'p':
        converts = 'r';
        break;
         case 'q':
        converts = 'z';
        break;
         case 'r':
        converts = 't';
        break;
         case 's':
        converts = 'n';
        break;
         case 't':
        converts = 'w';
        break;
         case 'u':
        converts = 'j';
        break; 
      case 'v':
        converts = 'p';
        break; 
      case 'w':
        converts = 'f';
        break;
         case 'x':
        converts = 'm';
        break;
         case 'y':
        converts = 'a';
        break;
         case 'z':
        converts = 'q';
        break;
    }
    System.out.print(converts);
  }
}