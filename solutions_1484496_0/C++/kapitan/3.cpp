#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    long long T,N,s,X=0,*tab;
    tab=new long long[1048576];
    vector<int> S;
    cin >> T;
    for(int t =0;t<T;t++)
    {
        for(int i =0;i<1048576;i++)
        {
            tab[i]=0;
        }
        S.clear();
        cin >> N;
        for(int i =0;i<N;i++)
        {
            cin >> s;
            S.push_back(s);
        }
        for(int i =0;i<1048576;i++)
        {
            int j=i,a=0;
            while(j!=0)
            {
                if(j%2)
                {
                    tab[i]+=S[a];
                }
                j/=2;
                a++;
            }
        }
        long long l1,l2;
        bool wyjdz=false;
        for(int i =0;i<1048576&&wyjdz==false;i++)
        {
            for(int j =i+1;j<1048576&&wyjdz==false;j++)
            {
                if(tab[i]!=0)
                if(tab[i]==tab[j])
                {
                    l1=i;
                    l2=j;
                    //cout << i << " "<<j<<endl;
                    wyjdz=true;
                }
            }
        }
        cout << "Case #"<<t+1<<":\n";
        int a=0;
        bool pierwszy=true;
        while(l1!=0)
        {
            if(l1%2)
            {
                if(!pierwszy)
                {
                    cout << " ";
                }
                pierwszy=false;
                cout <<S[a];
                l1-=1;
            }


            l1/=2;
            a++;
        }
        cout << endl;
        a=0;
        pierwszy = true;
        while(l2!=0)
        {
            if(l2%2)
            {
                if(!pierwszy)
                {
                    cout << " ";
                }
                pierwszy=false;
                cout <<S[a];
                l2-=1;
            }
            l2/=2;
            a++;
        }
        cout << endl;
    }
    return 0;
}
