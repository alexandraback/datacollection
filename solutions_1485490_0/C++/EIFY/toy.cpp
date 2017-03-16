#include <iostream>
#include <deque>

#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

typedef long long ll;

typedef std::pair<ll,ll> mypair;


ll recur(deque<mypair> box,
          deque<mypair> toy)
{
    if(box.empty() || toy.empty()) return 0;
    
    if(box[0].second == toy[0].second)
    {
        ll add;
        
        if(box[0].first > toy[0].first)
        {
            add = toy[0].first;
            
            toy.pop_front();
            
            box[0].first -= add;
        }
        else if(box[0].first == toy[0].first)
        {
            add = toy[0].first;
            
            toy.pop_front();
            box.pop_front();
        
        }
        else
        {
            add = box[0].first;
            
            box.pop_front();
            
            toy[0].first -= add;
        }
        
        return add + recur(box, toy);
    
    }
    else
    {
        deque<mypair> b = box;
        deque<mypair> t = toy;
        
        box.pop_front();
        toy.pop_front();
        
        return max(recur(b, toy), recur(box, t));
    
    }


}

int main()
{
    ll T, N, M;
    
    cin>>T;
    
     
    for(int i=0; i<T; ++i)
    {
    
        cin>>N>>M;
        
        deque<mypair> box;
        deque<mypair> toy;
        
        for(ll j=0; j<N; ++j)
        {
            ll a, A;
            
            cin>>a>>A;
            
            mypair p;
            
            p.first = a;
            p.second = A;
            
            box.push_back(p);
        
        }
        
        
        for(ll j=0; j<M; ++j)
        {
            ll a, A;
            
            cin>>a>>A;
            
            mypair p;
            
            p.first = a;
            p.second = A;
            
            toy.push_back(p);
            
        }
    
        cout<<"Case #"<<i+1<<": "<<recur(box, toy)<<endl;
        
    }
	return 0;
}
