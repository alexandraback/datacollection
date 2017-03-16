#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    #ifdef CODEBLOCKS
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CODEBLOCKS


//    cout << "Hello world!" << endl;
    int t;
    scanf("%d",&t);

    for(int ti=1;ti<=t;ti++)
    {
        int x,r,c;

        cin>>x>>r>>c;
        cout<<"Case #"<<ti<<": ";
        if(x>=7)
        {
            cout<<"RICHARD"<<endl;
        }
        else if(x==1)
        {
            cout<<"GABRIEL"<<endl;
        }
        else
        {
            if(min(r,c)>=x-1&&(r*c)%x==0)cout<<"GABRIEL"<<endl;
            else cout<<"RICHARD"<<endl;
        }
    }
    return 0;
}
