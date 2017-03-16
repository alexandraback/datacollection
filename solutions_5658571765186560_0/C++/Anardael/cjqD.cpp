#include <fstream>
#include <string>
#include <map>
using namespace std;

int main(){
    int t;
    ifstream f("input.txt");
    ofstream w("output.txt");
    f>>t;
    for (int tests=0;tests<t;tests++)
    {
        int X,R,C;
        f>>X>>R>>C;
        if (X>=7&&min(R,C)>=3)
        {
            w<<"Case #"<<(tests+1)<<": "<<"RICHARD"<<endl;
            continue;
        }
        if (X>=4&&min(R,C)<=2)
        {
            w<<"Case #"<<(tests+1)<<": "<<"RICHARD"<<endl;
            continue;
        }
        if (X>=5&&min(R,C)<=3)
        {
            w<<"Case #"<<(tests+1)<<": "<<"RICHARD"<<endl;
            continue;
        }
        if (R*C%X){
            w<<"Case #"<<(tests+1)<<": "<<"RICHARD"<<endl;
            continue;
        }
        if (X>max(R,C)||X/2>min(R,C)||(X%2==1&&(X+1)/2>min(R,C)))
        {
            w<<"Case #"<<(tests+1)<<": "<<"RICHARD"<<endl;
            continue;
        }
        if (X==1)
        {
            w<<"Case #"<<(tests+1)<<": "<<"GABRIEL"<<endl;
            continue;
        }
        if (X==2&&R*C%2==0)
        {
            w<<"Case #"<<(tests+1)<<": "<<"GABRIEL"<<endl;
            continue;
        }

        w<<"Case #"<<(tests+1)<<": "<<"GABRIEL"<<endl;
    }
    f.close();
    w.close();


    return 0;
}

