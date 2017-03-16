#include<iostream>
#include<fstream>
using namespace std;
int a[11][11][11];
int jp[11][11];
int js[11][11];
int ps[11][11];
int ans[10000][3];
ifstream in("small.txt");
ofstream out("Q3.out");
int main(){
    int t,i,j,p,s,k,soln;
    int i1,i2,i3;
    in>>t;
    for (i=1;i<=t;i++){
        out<<"Case #"<<i<<": ";
        in>>j;
        in>>p;
        in>>s;
        in>>k;
        soln=0;
        for (i1=0;i1<11;i1++)
            for (i2=0;i2<11;i2++){
                jp[i1][i2]=0;
                js[i1][i2]=0;
                ps[i1][i2]=0;
                }
                //for (i3=0;i3<11;i3++)
                //    a[i1][i2][i3]=0;
        for (i1=1;i1<=j;i1++)
            for (i2=1;i2<=p;i2++)
                for (i3=1;i3<=s;i3++){
                    //a[i1][i2][i3]++;
                    //if (a[i1][i2][i3]>k) continue;
                    jp[i1][i2]++;
                    js[i1][i3]++;
                    ps[i2][i3]++;
                    if (jp[i1][i2]>k) {jp[i1][i2]--;js[i1][i3]--;ps[i2][i3]--;continue;}
                    if (js[i1][i3]>k) {jp[i1][i2]--;js[i1][i3]--;ps[i2][i3]--;continue;}
                    if (ps[i2][i3]>k) {jp[i1][i2]--;js[i1][i3]--;ps[i2][i3]--;continue;}
                    ans[soln][0]=i1;
                    ans[soln][1]=i2;
                    ans[soln][2]=i3;
                    soln++;
                }
        out<<soln<<endl;
        for (i1=0;i1<soln;i1++){
            out<<ans[i1][0]<<" "<<ans[i1][1]<<" "<<ans[i1][2]<<endl;
        }
    }
}
