#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long solve();
long need_to_add(long mote, long size);


vector<long> motes;
vector<long> need_add;

int main()
{
    long T;
    cin >> T;
    for(long i=1; i<=T; ++i)
    {
	cout << "Case #" << i << ": " << solve() << endl;
    }
    
    return 0;
}


long solve()
{
    long A, N;
    cin >> A >> N;

    motes.clear();
    motes.resize(N);

    need_add.clear();
    need_add.resize(N);

    for(long i=0; i<N; ++i)
    {
	cin >> motes[i];
    }
    
    if(A == 1)
    {
	return N;
    }

    sort(motes.begin(), motes.end());

    need_add[0] = 0;
    long size = A;
    for(long i=0; i<N; ++i)
    {
	if(i>0) {
	    need_add[i] = need_add[i-1];
	}
	if(size > motes[i])
	{
	    size += motes[i];
	}
	else
	{	    
	    size = need_to_add(i,size) + motes[i];
	}
    }

    long min = need_add[N-1];
    for(long i=0; i<N; ++i)
    {
	if(need_add[N-i-1] + i < min)
	{
	    min = need_add[N-i-1] + i;
	}
    }

    if(min > N)
    {
	return N;
    }

    return min;
}


long need_to_add(long mote, long size)
{
    long j=0;
    while(size <= motes[mote])
    {
	size += size-1;
	j++;
    }
    
    need_add[mote] += j;

    return size;
}
