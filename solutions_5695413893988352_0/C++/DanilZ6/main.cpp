#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    cin >> t;
    for (int ht=1;ht<=t;ht++)
    {
        string a,b;
        cin >> a >> b;
        string a1=a;
        string b1=b;
        while(a1.length()<3){a1='0'+a1;b1='0'+b1;}
        int res=1000;
        int amin=1000;
        int bmin=1000;
        for (int i=0;i<999;i++)
        {
            if (a1[0]!='?'&&a1[0]-48!=i/100){continue;}
            if (a1[1]!='?'&&a1[1]-48!=(i%100)/10){continue;}
            if (a1[2]!='?'&&a1[2]-48!=i%10){continue;}
            for (int j=0;j<999;j++)
            {
                if (b1[0]!='?'&&b1[0]-48!=j/100){continue;}
                if (b1[1]!='?'&&b1[1]-48!=(j%100)/10){continue;}
                if (b1[2]!='?'&&b1[2]-48!=j%10){continue;}
                if (abs(i-j)<res)
                {
                    res=abs(i-j);
                    amin=i;
                    bmin=j;
                }
                if (abs(i-j)==res&&i<amin)
                {
                    res=abs(i-j);
                    amin=i;
                    bmin=j;
                }
                if (abs(i-j)==res&&i==amin&&j<bmin)
                {
                    res=abs(i-j);
                    amin=i;
                    bmin=j;
                }
            }
        }
        string resa="";
        string resb="";
        //cout << "Case #" << ht << ": " << amin << ' ' << bmin;
        while(amin!=0){resa=(char)(amin%10+48)+resa;amin/=10;}
        while(bmin!=0){resb=(char)(bmin%10+48)+resb;bmin/=10;}
        while (resa.length()<a.length()){resa='0'+resa;}
        while (resb.length()<b.length()){resb='0'+resb;}
        cout << "Case #" << ht << ": " << resa << ' ' << resb;
        cout << endl;
    }
    return 0;
}
