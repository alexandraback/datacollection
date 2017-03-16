#include <iostream>
#include <vector>
#include <deque>

#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

typedef long long ll;

typedef std::pair<ll,ll> mypair;


int main()
{
  int T;
  
  cin>>T;

  for(int i=0; i<T; ++i)
  {
    
    ll A, N;
    
    cin>>A>>N;
    
    vector<ll> motes(N);
    
    for (ll j=0; j<N; ++j) {
      cin>>motes[j];
    }
    
    sort(motes.begin(), motes.end());

    ll count = 0;
    ll max_count = N;
    
    
    if(A==1)
    {
      count = N;
      goto output;
    }
    
    for (ll j=0; j<N; ++j) {
      
      //cout<<"A: "<<A<<" mote: "<<motes[j]<<endl;
      
      if((count + (N-j)) < max_count)
        max_count = count + (N-j);
      
      while (motes[j] >= A)
      {
        A+=(A-1);
        ++count;
      }
      
      A+=motes[j];
      
      if (count >= max_count) {
        count = max_count;
        break;
      }
      
    }
    
    output:
    
    cout<<"Case #"<<i+1<<": "<<count<<endl;
    
  }
  
	return 0;
}
