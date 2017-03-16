#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std;
main()
{
int tc;
int num,j,po[11],sum,sum2,touch,left;
float aud[11];
double p3;
char ch;
ifstream f;ofstream f2;
f.open("C:/Turboc3/input.txt");
f2.open("C:/Turboc3/o.txt");
f >> tc;
for(int i=0;i<tc;i++) {
    f >> num;
    sum=0;
    left=num;
    for(j=0;j<num;j++) {
        f >> po[j];
        sum += po[j];
        aud[j]=0;
    }
    sum2=sum;
    back:
    touch=0;
    for(j=0;j<num;j++) {
        if(po[j] > ((sum2+sum)/left)&&(aud[j]==0)){
            aud[j]=-1;
            left--;
            touch=1;
            sum2-=po[j];
        }
    }
    if(touch!=0) goto back;
    //cout<<sum2<<" "<<sum<<" "<<left<<" ";
    for(j=0;j<num;j++) {
        if(aud[j]!=-1) {
            //cout<<sum2<<" "<<sum<<" "<<po[j];
            aud[j]=float(((sum2+sum)/(left*1.0))-po[j])*100.0/(1.0*(sum));
            //cout<<" "<<aud[j]<<"\n";
        }
    }
    for(j=0;j<num;j++) {
        if(aud[j]==-1) aud[j]=0;
    }
    
    f2 << "Case #"<<i+1<<": ";
    for(j=0;j<num;j++) {
        f2<<fixed<<aud[j]<<" ";
    }
    f2<<"\n";
}
f.close();
f2.close();
return 0;
}