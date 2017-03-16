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

int ns(int n, int m){
    int total=0;
    while(n%m==0){
        n/=m;
        total++;
    }
    return total;
}

int main()
{
    int a, total, max, maxx;
    fin >> a;
    fin >> a;
    fin >> a;
    fin >> a;
    fin >> a;
    int q[12];
    fout << "Case #1:" << endl;
    for(a=1; a<=8000; a++){
        total=0;
        go(b, 12){
            fin >> q[b];
        }
        max=0;
        go(b, 12){
            if(ns(q[b], 7)>max){
                max=(ns(q[b], 7));
            }
        }
        total+=max;
        go(b, max){
            fout << "7";
        }
        max=0;
        go(b, 12){
            if(ns(q[b], 5)>max){
                max=(ns(q[b], 5));
            }
        }
        total+=max;
        go(b, max){
            fout << "5";
        }
        max=0;
        go(b, 12){
            if(ns(q[b], 2)>max){
                max=(ns(q[b], 2));
            }
        }
        maxx=0;
        go(b, 12){
            if(ns(q[b], 3)>maxx){
                maxx=(ns(q[b], 3));
            }
        }
        total=12-total;


         if(total<=max){
            while(maxx>0){
                fout << "6";
                total--;
                maxx--;
                max--;
            }
            if(max>=2*total){
                go(b, 3*total-max){
                    fout << "4";
                }
                go(b, max-2*total){
                    fout << "8";
                }
                total=0;
            }
            else if(max>=total){
                go(b, 2*total-max){
                    fout << "2";
                }
                go(b, max-total){
                    fout << "4";
                }
                total=0;
            }
        }

        if(total>=max+maxx){
            if(max>maxx){
                go(b, total-maxx){
                    fout << "2";
                }
                go(b, maxx){
                    fout << "3";
                }
            }
            else{
                go(b, max){
                    fout << "2";
                }
                go(b, total-max){
                    fout << "3";
                }
            }
            total=0;
        }

        if(total>0){
            go(b, max){
                fout << "2";
            }
            go(b, total-max){
                fout << "3";
            }
        }


        fout << endl;
    }

}
