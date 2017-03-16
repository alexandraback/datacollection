#include <iostream>

using namespace std;

int calMinStep(int c,int m)
{
    int size;
    int t1,t2;
    int ans;
    int last;
    size = c/m;
    last = c%m;
    t1 = m*size;
    //t2 = c-t1;
    if(last>0)
    {
        ans = size+m;
    }
    else
    {
        ans = size+m-1;
    }
    return ans;
}

int main()
{
    int T,R,C,M;
    int minAns;
    int curCase;
    freopen("D:\\ccpptrain\\codejamround1c2\\A-large.in","r",stdin);
    freopen("D:\\ccpptrain\\codejamround1c2\\testout3.txt","w",stdout);
    cin>>T;
    curCase = 0;
    while(T)
    {
        T--;
        curCase++;
        cin>>R>>C>>M;
        minAns = calMinStep(C,M);
        if(R>1)
        {
            minAns += (R-1)*(C/M);
        }


        cout<<"Case #"<<curCase<<": "<<minAns<<endl;
    }
    return 0;
}
