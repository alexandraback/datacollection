#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX 100
#define test(a) cout << "TEST " << a << endl;
#define go(a,b) for(int a=0; a<b; a++)
#define case(a) fout << "Case #"<< a << ": " <<
using namespace std;
ofstream fout ("output.txt");
ifstream fin ("input.txt");


int t(int n){
    n*=2;
    int blah = ((n+2)*(n+1));
    return (blah/2);
}

int main()
{
    int cases, n, x, y, level;
    fin >> cases;
    for(int a=1; a<=cases; a++){
        fin >> n >> x >> y;
        level = abs(x) + y;
        level/=2;

         if(level>3){
            case(a) "0.0" << endl;
        }
        else if(level==0){
            case(a) "1.0" << endl;
        }
        else if(n>=t(level)){
            case(a) "1.0" << endl;
        }
        else if(n<=t(level-1)){
            case(a) "0.0" << endl;
        }
        else if(level==1){
            n-=1;
            if(y==0){
                if(n>2){
                    case(a) "1.0" << endl;
                }
                if(n==2){
                    case(a) 0.75 << endl;
                }
                if(n==1){
                    case(a) 0.5 << endl;
                }
            }
            if(y==1){
                if(n>3){
                    case(a) "1.0" << endl;
                }
                if(n==3){
                    case(a) 0.5 << endl;
                }
                if(n==2){
                    case(a) 0.25 << endl;
                }
                if(n==1){
                    case(a) "0.0" << endl;
                }
            }
            if(y==2){
                case(a) "0.0" << endl;
            }

        }
        else if(level==2){
            n-=6;
            if(y==0){
                if(n>4){
                   case(a) "1.0" << endl;
                }
                if(n==4){
                    case(a) 0.9375 << endl;
                }
                if(n==3){
                    case(a) 0.875 << endl;
                }
                if(n==2){
                    case(a) 0.75 << endl;
                }
                if(n==1){
                    case(a) 0.5 << endl;
                }
            }
            if(y==1){
                if(n>5){
                   case(a) "1.0" << endl;
                }
                if(n==5){
                    case(a) 0.8125 << endl;
                }
                if(n==4){
                    case(a) 0.625 << endl;
                }
                if(n==3){
                    case(a) 0.5 << endl;
                }
                if(n==2){
                    case(a) 0.25 << endl;
                }
                if(n==1){
                    case(a) "0.0" << endl;
                }
            }
            if(y==2){
                if(n>6){
                   case(a) "1.0" << endl;
                }
                if(n==6){
                    case(a) 0.65625 << endl;
                }
                if(n==5){
                    case(a) 0.5 << endl;
                }
                if(n==4){
                    case(a) 0.3125 << endl;
                }
                if(n==3){
                    case(a) 0.125 << endl;
                }
                if(n<=2){
                    case(a) "0.0" << endl;
                }
            }
            if(y==3){
                if(n>7){
                   case(a) "1.0" << endl;
                }
                if(n==7){
                    case(a) 0.5 << endl;
                }
                if(n==6){
                    case(a) 0.34375 << endl;
                }
                if(n==5){
                    case(a) 0.1875 << endl;
                }
                if(n==4){
                    case(a) 0.0625 << endl;
                }
                if(n<=3){
                    case(a) "0.0" << endl;
                }
            }
            if(y==4){
                if(n>8){
                   case(a) "1.0" << endl;
                }
                else{
                    case(a) "0.0" << endl;
                }
            }

        }
        else if(level==3){
            n-=15;
            if(y==0){
                if(n==5){
                    case(a) 0.96875 << endl;
                }
                if(n==4){
                    case(a) 0.9375 << endl;
                }
                if(n==3){
                    case(a) 0.875 << endl;
                }
                if(n==2){
                    case(a) 0.75 << endl;
                }
                if(n==1){
                    case(a) 0.5 << endl;
                }
            }
            else if(y==1){
                if(n==5){
                    case(a) 0.8125 << endl;
                }
                if(n==4){
                    case(a) 0.625 << endl;
                }
                if(n==3){
                    case(a) 0.5 << endl;
                }
                if(n==2){
                    case(a) 0.25 << endl;
                }
                if(n<=1){
                    case(a) "0.0" << endl;
                }
            }
            else if(y==2){
                if(n==5){
                    case(a) 0.5 << endl;
                }
                if(n==4){
                    case(a) 0.3125 << endl;
                }
                if(n==3){
                    case(a) 0.125 << endl;
                }
                if(n<=2){
                    case(a) "0.0" << endl;
                }
            }
            else if(y==3){
                if(n==5){
                    case(a) 0.1875 << endl;
                }
                if(n==4){
                    case(a) 0.0625 << endl;
                }
                if(n<=3){
                    case(a) "0.0" << endl;
                }
            }
            else if(y==4){
                if(n==5){
                    case(a) 0.03125 << endl;
                }

                if(n<=4){
                    case(a) "0.0" << endl;
                }
            }
            else{
                case(a) "0.0" << endl;
            }
        }
        else{
            case(a) "0.0" << endl;
        }
    }
}
