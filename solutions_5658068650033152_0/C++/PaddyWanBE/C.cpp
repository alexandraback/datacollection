#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
typedef unsigned int uint;
typedef unsigned long ulong;

uint aantal;
uint casei;
void flushLine();
void opl();

int main()
{
    cin >> aantal;
    flushLine();
    for(casei = 1; casei <= aantal; casei++)
	opl();
    return 0;
}

void flushLine()
{
    string str;
    getline(cin, str);
}


void opl()
{
    uint N,M,K;
    cin >> N >> M >> K;
    uint kost=K;
    if(N<= 2 || M <= 2)
	kost = K; 
    else if(K >= N*M-4)
    {//alles moet
	kost=2*(N+M-4) + 4 - (N*M-K);
    }
    else
    {
	for(uint k = 1; k < N-1; k++)
	{
	    if( K >= 2*k)
	    {
		const uint h = static_cast<uint>((K-2*k+1+k)/(2+k));
		//cout << "N: " << N  << " M: " << M<< " K: " << K<< " k: " << k  << " h: " << h << " kost: " << 2*(k+h) << " over: " << 2*(k+h)+k*h << endl;
		//if(2*(k+(h-1))+k*(h-1) >= K )
		    //    cout << "N: " << N  << " M: " << M<< " K: " << K<< " k: " << k  << " h: " << h << " kost: " << 2*(k+h) << " over: " << 2*(k+h)+k*h << endl;
		if(h < M-1)
		{
		    const uint dezeh = h-1;
		    const uint nkost = 2*(k+dezeh);
		    const uint over = 2*(k+dezeh)+k*dezeh;
		    if(over >= K)
		    {
			if(nkost < kost)
			    kost = nkost;
		    }
		    else
		    {
			for(uint i = 1; i < 10; i++)  
			    if(over+i == K)
			    {
				if(nkost+i < kost)
				    kost = nkost+i;
			    }
		    }
		}
		if(h < M-2)
		{
		    const uint nkost = 2*(k+h);
		    if(nkost < kost)
			kost = nkost;
		}
	    }
	}
    }
    cout << "Case #" << casei << ": " << kost << endl;
}

