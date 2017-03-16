#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main()
{
    int T,I=0,N;
    cin>>T;
    while(T--)
    {
        I++;
        cin>>N;
        float val1[N],val2[N];
        for(int i=0;i<N;i++)
            cin>>val1[i];
        for(int i=0;i<N;i++)
            cin>>val2[i];
        sort(val1,val1+N);
        sort(val2,val2+N);
      //  for(int i=0;i<N;i++)
        //    cout<<val1[i]<<' '<<val2[i]<<endl;
        int start=0,start2=0,end2=N-1,countAns=0;;
        for(int i=0;i<N;i++){
        if(val1[start]<val2[start2])
        {
            end2--;
            start++;
        }
        else{
            countAns++;
            start++;
            start2++;
        }
        }
        int countAns2=0;
        end2=N-1;
        start2=0;
        for(int i=N-1;i>=0;i--)
        {
            if(val1[i]<val2[end2])
            {
                end2--;
                countAns2--;
            }
            else
            {
                start2++;
            }
        }
        countAns2+=N;
        cout<<"Case #"<<I<<": "<<countAns<<' '<<countAns2<<endl;
    }
}
