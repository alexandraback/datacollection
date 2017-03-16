#include<iostream>
#include<cstdio>

using namespace std;
double a, dr, trz, akt, makks;
int n, m, g;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
      //  cout<<"Tu"<<endl;
        akt=0;
        cin>>m>>g;
        makks=g+2;
        dr=1;
        for(int j=1; j<m; j++){
        cin>>a;
        dr=(double)dr*a;
        trz=(double)1-dr;
        akt=(double)dr*(m-j+m-j+g-m+1)+(double)trz*(m-j+m-j+g-m+1+g+1);
         makks=min(makks, akt);
       //  cout<<"akt "<<akt<<endl;
       //  cout<<"I tu\n";
        }
        cin>>a;
        dr=(double)dr*a;
        trz=(double)1-dr;
        akt=(double)dr*(g-m+1)+(double)trz*(g-m+1+g+1);
         //cout<<"akt "<<akt<<endl;
         makks=min(makks, akt);
         printf("Case #%d: %.6f\n", i, makks);

    }
}
