#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <limits.h>
#include <iterator>

using namespace std;

typedef int ttyp;
#define fors(bg,en) for(int i=bg;i<en;i++)
#define forso(j,bg,en) for(int j=bg;j<en;j++)
#define forz(n) for(int i=0;i<n;i++)
#define forzo(j,n) for(int j=0;j<n;j++)
#define forsz(v) for(int i=0;i<v.size();i++)
#define forszo(j,v) for(int j=0;j<v.size();j++)
#define MP make_pair
#define sz(v) v.size()

#define REDU 1325000000000LL
#define MAXN 3000010
#define TMAXN 9000010

int n,vix;
set<long long> tempset;
set<long long>::iterator it;
struct node{
    int bg, en;
}vinp[MAXN];

struct inpnode{
    long long bg, en;
    long long stgh;
    long long day;
};
vector <inpnode> sinp;

struct segt{
    int bgix,enix;
    long long bg, en;
    long long stgh;

}vsegt[TMAXN];

struct inpnode_comp{
    bool operator()(inpnode const & a, inpnode const & b) const {
        //return true if a is lower than b
        if (a.day!=b.day) return a.day < b.day;
        return a.stgh < b.stgh;
    }
};
struct inpnode_compa{
    bool operator()(inpnode const & a, inpnode const & b) const {
        //return true if a is lower than b
        if (a.bg!=b.bg) return a.bg < b.bg;
        return a.en < b.en;
    }
};

void build(int ix, int vbgix, int venix){
    if(vbgix==venix){
        vsegt[ix].bgix=ix;
        vsegt[ix].enix=ix;
        vsegt[ix].bg=vinp[vbgix].bg;
        vsegt[ix].en=vinp[vbgix].en;
        vsegt[ix].stgh=0;
        return;
    }
    int mid=(vbgix+venix)/2,lix=ix*2,rix=ix*2+1;
    build(lix,vbgix,mid);
    build(rix,mid+1,venix);
    vsegt[ix].bgix=vbgix;
    vsegt[ix].enix=venix;
    vsegt[ix].bg =vsegt[lix].bg;
    vsegt[ix].en=vsegt[rix].en;
    vsegt[ix].stgh=0;
    return;
}
bool getit(int ix, int bg, int en, long long instgh){
    if(bg>vsegt[ix].en || en<vsegt[ix].bg)return 0;
    if(bg<vsegt[ix].bg && en>=vsegt[ix].en){
        if(vsegt[ix].stgh < instgh){
            vsegt[ix].stgh = instgh;
            return true;
        }
        return false;
    }
    if(vsegt[ix].bgix==vsegt[ix].enix){
        if(vsegt[ix].stgh < instgh){
            vsegt[ix].stgh = instgh;
            return true;
        }
        return false;
    }
    int lix=ix*2,rix=ix*2+1;
    bool ret=false;
    if(vsegt[lix].stgh<vsegt[ix].stgh)vsegt[lix].stgh=vsegt[ix].stgh;
    if(vsegt[rix].stgh<vsegt[ix].stgh)vsegt[rix].stgh=vsegt[ix].stgh;
	if(bg<=vsegt[lix].en)
		if(getit(lix,bg,en,instgh)) ret=true;
	if(en>=vsegt[rix].bg)
		if(getit(rix,bg,en,instgh)) ret=true;
    return ret;
}


void doit(){
    int n, nodeinx=0,ret=0;
    long long bday, natt, bwest, beast, bstgh, diffday, diffdist, diffstgh;
    inpnode tempinpnode;
    sinp.clear();
    cin>>n;
    forz(n){
        cin>>bday>>natt>>bwest>>beast;
        cin>>bstgh>>diffday>>diffdist>>diffstgh;
        tempinpnode.bg = bwest;
        tempinpnode.en = beast-1;
        tempinpnode.day = bday;
        tempinpnode.stgh = bstgh;
        forz(natt){
            sinp.push_back(tempinpnode);
            tempset.insert(tempinpnode.bg);
            tempset.insert(tempinpnode.en);
            tempinpnode.bg+=diffdist;
            tempinpnode.en+=diffdist;
            tempinpnode.day+=diffday;
            tempinpnode.stgh+=diffstgh;
        }
    }
    sort(sinp.begin(),sinp.end(),inpnode_comp());
    beast=0;bwest=0;
    for(it=tempset.begin();it!=tempset.end();it++){
        if(it==tempset.begin())beast=(*it);
        else{
            vinp[nodeinx].bg=beast;
            vinp[nodeinx++].en = beast;
            bwest=(*it);
            beast++;
            if(beast<bwest){
                vinp[nodeinx].bg=beast;
                vinp[nodeinx++].en = bwest-1;
                vinp[nodeinx].bg=bwest;
                vinp[nodeinx++].en = bwest;
                beast=bwest+1;
            }
            else if (beast==bwest){
                vinp[nodeinx].bg=bwest;
                vinp[nodeinx++].en = bwest;
                beast=bwest+1;
            }
        }
    }
    build(1,0,nodeinx-1);
    for(int i=0;i<sinp.size();i++){
        if(getit(1, sinp[i].bg, sinp[i].en, sinp[i].stgh))ret++;
//        cout<<"bg en stgh day ret "<<sinp[i].bg<<" "<<sinp[i].en<<" "<<sinp[i].stgh<<" "<<sinp[i].day<<" "<<ret<<endl;
    }

    cout<<ret<<endl;
    return;
}
int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cout<<"Case #"<<i<<": ";
        doit();
    }
    return 0;
}
