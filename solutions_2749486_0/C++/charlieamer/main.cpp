#include <iostream>
#include <queue>
#include <fstream>
#include <set>
#include <stdlib.h>
using namespace std;

int tren;

void displej(int stat,int uk)
{
    int perc=(double)stat/(double)uk*100.0;
    for (int i=tren;i<perc/10;i++)
        cout << ".";
    tren=perc/10;
}

struct coord
{
    int x,y,dist;
    string put;
    coord(int xx, int yy, int d, string p){x=xx;y=yy;put=p;dist=d;}
    coord(){}
};

#define PROBAJ(x,y,d,p) {if (posjecen.find(make_pair((x),(y)))==posjecen.end()/* && abs(x)<=abs(rx)*10 && abs(y)<=abs(ry)*10*/) {q.push(coord((x),(y),(d),(p)));posjecen.insert(make_pair((x),(y)));}}

int main()
{
    string str;
    getline(cin,str);
    ifstream in(str.c_str());
    //ifstream in("testInput.txt");
    ofstream out("izlaz2.txt");
    int tests;
    in >> tests;
    cout << "working ";
    tren=0;
    for (int t=0;t<tests;t++)
    {
        queue<coord> q;
        set<pair<int,int> > posjecen;
        int rx,ry;
        in >> rx >> ry;
        q.push(coord(0,0,1,""));
        while (!q.empty())
        {
            coord crd=q.front();
            if (crd.x==rx && crd.y==ry)
            {
                out << "Case #" << t+1 << ": " << crd.put << endl;
                break;
            }
            q.pop();
            PROBAJ(crd.x+crd.dist,crd.y,crd.dist+1,crd.put+"E");
            PROBAJ(crd.x-crd.dist,crd.y,crd.dist+1,crd.put+"W");
            PROBAJ(crd.x,crd.y+crd.dist,crd.dist+1,crd.put+"N");
            PROBAJ(crd.x,crd.y-crd.dist,crd.dist+1,crd.put+"S");
        }
        displej(t,tests);
    }
    return 0;
}
