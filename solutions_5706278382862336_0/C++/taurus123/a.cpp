#include<iostream>
using namespace std;
int main()
{
    int T;
    long long P,Q;
    cin >> T;
    for(int cas = 1; cas <= T; ++ cas)
    {
        char ch;
        cin >> P >>ch >> Q;
        int res = -1;
        int depth = 0;
        while(depth < 40)
        {
            depth ++;
            P=2*P;
            if(P>= Q)
            {
                if(res == -1)
                    res = depth;
                P = P - Q;
            }
            if(P == 0)
                break;
        }
        if(P == 0 && res != -1)
            cout<<"Case #"<<cas<<": "<<res<<endl;
        else
            cout<<"Case #"<<cas<<": impossible"<<endl;


    }
    return 0;
}
