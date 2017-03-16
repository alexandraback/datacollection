#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;
#define ll long long 
int main(){

	freopen ("C:/Users/weilu/Downloads/A-small-attempt0.in","r",stdin);
	freopen("test.out", "w", stdout);
//	freopen("test.in", "r", stdin);
	int T;
	cin >> T;

	
	for (int ii = 0; ii < T; ii++)
	{
		ll L;
		ll n;
		string name;
		cin >> name >> n;
		ll length = name.size();
		ll count = 0;
		ll pre = 0;
		ll num = 0;
		for (int i = 0; i < length; i++)
		{
			if(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
				count =0;
			else
				count++;
			if ( count >= n)
			{
				ll start = i - n + 1;
				num += (start - pre + 1) * ( length - i );
				
	//			cout<<" !!"<<i<<"  "<<pre<<" "<< num<<endl;
				pre = start+1 ;
			}
		}	
		cout<< "Case #"<<ii+1<<": "<<num <<endl;
	}
	return 0;
}