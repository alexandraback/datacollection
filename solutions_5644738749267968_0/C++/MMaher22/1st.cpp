#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    ifstream cin ("D-small-attempt0.in");
    ofstream cout ("clocks.out");
    int n;
    cin>>n;
    for(int counter=1;counter<=n;counter++)
    {
        int i,j,no;
        cin>>no;
        double x[no],y[no];
        for(i=0;i<no;i++)
        {
            cin>>x[i];
        }
        sort(&x[0],&x[no]);
        for(i=0;i<no;i++)
        {
            cin>>y[i];
        }
        sort(&y[0],&y[no]);
        int optimal = 0 , decieve = 0 ;

        j=0;
        for(i=0;i<no;i++)
        {
            if(x[i]>y[j])
            {
                j++;
                decieve++;
            }
        }
        int index=0;
        for(i=0;i<no;i++)
        {
            for(j=index;j<no;j++)
            {
                if(y[j]>x[i])
                {
                    optimal++;
                    index=j+1;
                    break;
                }
            }
        }
        cout<<"Case #"<<counter<<": ";
        cout<<decieve<<" "<<no-optimal<<endl;
    }
return 0;
}
