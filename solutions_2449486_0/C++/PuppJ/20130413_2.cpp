#include <iostream>
#include <fstream>

using namespace std;

int t,num,m,n,a[150][150],line[150],row[150];
bool breaksign;

int main(){
    ifstream in("B-small-attempt0.in");
    ofstream out("20130413_2.out");
    in>>t;
    for (num=0;num<t;num++){
        out<<"Case #"<<num+1<<": ";
    in>>m>>n;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            in>>a[i][j];
    for (int i=0;i<m;i++){
        line[i]=a[i][0];
        for (int j=1;j<n;j++)
            if (a[i][j]>line[i]) line[i]=a[i][j];
    }
    for (int j=0;j<n;j++){
        row[j]=a[0][j];
        for (int i=0;i<m;i++)
            if (a[i][j]>row[j]) row[j]=a[i][j];
    }
    breaksign=false;
    for (int i=0;i<m;i++){
        if (breaksign) break;
        for (int j=0;j<n;j++)
            if (a[i][j]!=min(line[i],row[j])) {out<<"NO"<<endl; breaksign=true;break;}
    }
    if (!breaksign) out<<"YES"<<endl;
}
    return 0;
}
