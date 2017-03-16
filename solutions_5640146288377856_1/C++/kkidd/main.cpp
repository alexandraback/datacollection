#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream f2("flargeout.out");
    int T;
    cin>>T;
    int R,C,W;
    int N;
    int y;
    for(int i=0;i<T;++i)
    {
        cin>>R>>C>>W;
        N=C/W;
        if(C==N*W)
        {
            y=N*R+(W-1);
        }
        else
        {
            y=N*R+W;
        }
        f2<<"Case #"<<i+1<<": "<<y<<endl;
    }
    return 0;
}
