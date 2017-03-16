#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
using namespace std;

#define _for(i,x,n) for(int i=x;i<n;i++)
#define _ifor(i,x,n) for(int i=(n);i>=x;i++)
#define _forv(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

#define _dv(var) cout<<"L"<<__LINE__<<": "<<#var<<": "<<var<<endl;
#define _dav(v) cout<<"L"<<__LINE__<<": "<<#v<<": "; dav((v).begin(),(v).end());
template<typename it> void dav(it i,it f)
	{ cout<<"[ "; while(i!=f) cout<<*(i++)	<<" "; cout<<"]"<<endl; }
#define _ln cout<<"_ln: "<<__LINE__<<endl;


int main(){
    int T;
    cin>>T;
    _for(tt,1,T+1){
        int N,a,b;
        cin>>N;
        pair<int,int> levels[N];
        _for(i,0,N){
            cin>>a>>b;
            levels[i]=make_pair(a,b);
        }

        //sort
        int order2rating[N];
        int order1rating[N];
        _for(i,0,N){
            order2rating[i]=i;
            order1rating[i]=i;
        }
        _for(i,0,N)
            _for(j,i+1,N){
                if(levels[order1rating[i]].first > levels[order1rating[j]].first){
                    int aux=order1rating[j];
                    order1rating[j]=order1rating[i];
                    order1rating[i]=aux;
                }
                if(levels[order2rating[i]].second > levels[order2rating[j]].second){
                    int aux=order2rating[j];
                    order2rating[j]=order2rating[i];
                    order2rating[i]=aux;
                }
            }

        //bool completed2rating[N];
        //bool completed2rating[N];
        int stars=0,times=0,j=0;
        _for(i,0,N){
            if(stars < levels[order2rating[i]].second){
                //if he has completed any level with rating 2
                if(i>0){
                    times += levels[order2rating[i]].second-stars;
                    stars = levels[order2rating[i]].second;
                }
                else{
                    //if he has completed any level with rating 1
                    if(j>0){
                        times += levels[order2rating[i]].second-stars;
                        stars = levels[order2rating[i]].second;
                    }
                    else{
                        //try to complete levels with rating 1 to achieve rating 2
                        while(stars<levels[order2rating[i]].second && j<N){
                            if(stars >= levels[order1rating[j]].first){
                                times += levels[order2rating[i]].second-stars;
                                stars = levels[order2rating[i]].second;
                                j++;
                            }
                            else
                                break;
                        }
                    }
                }
            }

            //if he can complete level with rating 2
            if(stars >= levels[order2rating[i]].second){
                stars += 2;
                times++;
            }
            //he can't complete all levels with rating 2
            else{
                times=-1;
                break;
            }
        }

        if(times==-1)
            cout<<"Case #"<<tt<<": Too Bad"<<endl;
        else
            cout<<"Case #"<<tt<<": "<<times<<endl;
    }
    return 0;
}
