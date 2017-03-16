#include<iostream>
#include<string>

#define Xadd "WE"
#define Xsub "EW"
#define Yadd "SN"
#define Ysub "NS"

using namespace std;

string stepX(int x)
{
    int i;
    string s;
    if(x>=0)
    {
        for(i=0;i<x;i++)
            s += Xadd;
    }
    else
    {
        x = -x;
        for(i=0;i<x;i++)
            s += Xsub;
    }


    return s;
}


string stepY(int y)
{
    int i;
    string s;
    if(y>=0)
    {
        for(i=0;i<y;i++)
            s += Yadd;
    }
    else
    {
        y = -y;
        for(i=0;i<y;i++)
            s += Ysub;
    }


    return s;
}

int main()
{
    int tt,T,x,y,i,n;
    string str;


    cin >> T;
    for(tt=1;tt<=T;tt++)
    {
        str.clear();
        cin >> x >> y;

        str += stepX(x);
        str += stepY(y);

        cout << "Case #" << tt << ": " << str << endl;
    }

    return 0;
}
