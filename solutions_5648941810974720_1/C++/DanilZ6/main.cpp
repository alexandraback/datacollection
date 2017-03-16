#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char,int> s;
int times[11];
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    cin >> t;
    for (int ht=1;ht<=t;ht++)
    {
    s.clear();for (int i=0;i<10;i++){times[i]=0;}
        string h;
        cin >> h;
        for (int i=0;i<h.length();i++)
        {
            s[h[i]]++;
        }

        if (s.find('Z')!=s.end()){int a=s['Z'];times[0]=a;s['E']-=a;s['R']-=a;s['O']-=a;s['Z']-=a;}
        if (s.find('U')!=s.end()){int a=s['U'];times[4]=a;s['F']-=a;s['O']-=a;s['U']-=a;s['R']-=a;}
        if (s.find('W')!=s.end()){int a=s['W'];times[2]=a;s['T']-=a;s['O']-=a;s['W']-=a;}
        if (s.find('X')!=s.end()){int a=s['X'];times[6]=a;s['S']-=a;s['I']-=a;s['X']-=a;}
        if (s.find('G')!=s.end()){int a=s['G'];times[8]=a;s['E']-=a;s['I']-=a;s['G']-=a;s['H']-=a;s['T']-=a;}
        if (s.find('H')!=s.end()&&s['H']!=0){int a=s['H'];times[3]=a;s['T']-=a;s['H']-=a;s['R']-=a;s['E']-=a;s['E']-=a;}
        if (s.find('O')!=s.end()&&s['O']!=0){int a=s['O'];times[1]=a;s['O']-=a;s['N']-=a;s['E']-=a;}
        if (s.find('F')!=s.end()&&s['F']!=0){int a=s['F'];times[5]=a;s['F']-=a;s['I']-=a;s['V']-=a;s['E']-=a;}
        if (s.find('S')!=s.end()&&s['S']!=0){int a=s['S'];times[7]=a;s['S']-=a;s['E']-=a;s['V']-=a;s['E']-=a;s['N']-=a;}
        if (s.find('N')!=s.end()&&s['N']!=0){int a=s['N']/2;times[9]=a;s['N']-=a;s['I']-=a;s['N']-=a;s['E']-=a;}
        cout << "Case #" << ht << ": ";
        for (int i=0;i<10;i++){for (int j=0;j<times[i];j++){cout << i;}}
cout << endl;
    }
    return 0;
}
