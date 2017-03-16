import java.util.Scanner;
/**
 * Write a description of class cEasy here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class cEasy
{
   public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for(int z = 1; z <= cases; z++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int s = sc.nextInt();
            System.out.println("Case #" + z + ": "+ans(a, b, s));
        }
    }
   public static int ans(int a, int b, int stones){
       int ans;
       if(a == 1 || b == 1){
           return stones;          
        }
       else if(a*b == 4){
           if(stones > 4){
               return stones - 1;
            }
            return stones;
        }
       else if(a*b == 6){
           if(stones > 7){
               return stones-2;
            } else if(stones > 4){
                return stones-1;
            } else{
                return stones;
            }
        }
       else if(a*b == 8){
           if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones;
            
        }
       else if(a * b == 10){
           if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones;
        }
        else if(a*b == 12&&(a == 2 || b == 2)){
            if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones;
        }
        else if(a*b == 14&&(a == 2 || b == 2)){
             if(stones > 19){
               return stones - 6;
            }
           else if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones;
        } else if(a*b == 16&&(a==2 || b == 2)){
            if(stones > 22){
                return stones -7;
            }
            if(stones > 19){
               return stones - 6;
            }
           else if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones; 
        } else if(a*b == 18 && (a==2 || b == 2)){
            if (stones > 25){
               return stones -8 ;
            }
            if(stones > 22){
                return stones -7;
            }
            if(stones > 19){
               return stones - 6;
            }
           else if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones; 
        } else if(a*b == 20 &&(a==2 || b == 2)){
             if (stones > 25){
               return stones -8 ;
            }
            if(stones > 22){
                return stones -7;
            }
            if(stones > 19){
               return stones - 6;
            }
           else if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones; 
        }
       else if(a*b == 9){
           if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones;
        }
       else if(a*b == 12){
           if(stones > 19){
               return stones - 6;
            }
           else if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones;
        } else if(a*b == 15){
            if (stones > 25){
               return stones -8 ;
            }
            if(stones > 22){
                return stones -7;
            }
            if(stones > 19){
               return stones - 6;
            }
           else if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones; 
        }
        else if(a*b == 18){
            if(stones > 31){
             return stones -10;
            }
          if(stones > 28){
                return stones -9;
            }
            if (stones > 25){
               return stones -8 ;
            }
            if(stones > 22){
                return stones -7;
            }
            if(stones > 19){
               return stones - 6;
            }
           else if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones; 
        }
        else if(a*b == 16){
            if(stones > 28){
                return stones -9;
            }
            if (stones > 25){
               return stones -8 ;
            }
            if(stones > 22){
                return stones -7;
            }
            if(stones > 19){
               return stones - 6;
            }
           else if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones; 
        }
       else {
         if(stones > 37){
             return stones -12;
            }
         if(stones > 34){
             return stones -11;
            }
         if(stones > 31){
             return stones -10;
            }
          if(stones > 28){
                return stones -9;
            }
            if (stones > 25){
               return stones -8 ;
            }
            if(stones > 22){
                return stones -7;
            }
            if(stones > 19){
               return stones - 6;
            }
           else if(stones > 16){
               return stones -5;
            }
           else if(stones > 13){
               return stones -4;
            } else if(stones > 10){
               return stones-3;
            } else if(stones > 7){
                return stones -2;
            } else if(stones >4 ){return stones -1;} else return stones; 
        }
    }
}
