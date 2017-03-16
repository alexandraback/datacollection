#include<iostream>
#include<cstdio>
#include<vector>

#define MAXX=10000000;
using namespace std;
int n, m, pom1, pom2;
pair<int, int> t[1005];
bool syf=false;
int main()
{
    cin>>n;
    for(int p=1; p<=n; p++)
    {
        syf=false;
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>pom1>>pom2;
            t[i].first=pom1;
            t[i].second=pom2;
        }
        int pula, znalezione, wynik;
        pula=0;
        wynik=0;
        znalezione=0;
        for(int j=0; j<m; j++)
        {
            if(t[j].second<=pula){wynik++; znalezione++;
            pula+=2;

            t[j].first=1000000; t[j].second=1000000;  /*cout<<"biore 2 z "<<j<<" pula "<<pula<<" wynik "<<wynik<<endl;*/j=-1;}
            if(znalezione!=m && j==m-1)
            {
                for(int l=0; l<m; l++)
                {
                     if(t[l].first<=pula){wynik++; pula++;
                     if(t[l].second==1000000)znalezione++;
                     t[l].first=t[l].second; t[l].second=1000000; /*cout<<"biore 1 z "<<l<<" pula "<<pula<<" wynik "<<wynik<<endl;*/ j=-1; break;}
                if(l==m-1)
             {
                 printf("Case #%d: Too Bad\n", p);
                 syf=true;
             }
             }

            }
            if(syf==true)break;
        }

        if(!syf)/*printf("Case #%d: %d", p, wynik);*/cout<<"Case #"<<p<<": "<<wynik<<endl;
    }


}
