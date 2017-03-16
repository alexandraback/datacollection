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
#include<string.h>
#include<fstream>
int ab(int a)
{
	if(a<0)
	return -1*a;
	return a;
}

using namespace std;

vector< vector<int> > attack(676068);
vector< vector<int> > attack1(676068);
vector< vector<int> > attack2(676068);
vector< vector<int> > attack3(676068);

int h[1200][1200];
		vector< vector<int> > v(12);
int main()
{

   /* freopen ("A-small_1.in", "rt", stdin);
    freopen ("output_trial.txt", "wt", stdout);
    ifstream f;
    f.open ("A-small_1.in");
    ofstream ff;
    ff.open ("output_trial.txt");*/
    int t;
    cin>>t;
    int g=0;
    while(t--)
    {
		attack.clear();
		v.clear();

        g++;

		cout<<"Case #"<<g<<": ";
		int n;
		cin>>n;
		
		
		memset(h,0,sizeof(h));
		int suc=0;
		int f=0;
		int gg=n;
		while(gg--)
		{

			int kk=8;
			while(kk--)
			{
				int temp;
				cin>>temp;
				v[f].push_back(temp);
			}
			f++;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=v[i][1];j++)
			{
				//cout<<"yes\n";
				int s=v[i][0];
				if(j>1)
				{
					s+=(j-1)*v[i][5];
				}
				int stren=v[i][4]+(j-1)*v[i][7];
				
				attack[s].push_back(i);
				attack1[s].push_back(stren);
				int e=500+v[i][3],w=500+v[i][2];
				if(j>1)
				{
					e+=(j-1)*v[i][6];
					w+=(j-1)*v[i][6];
				}
				cout<<i<<" "<<s<<" "<<stren<<" "<<w<<" "<<e<<endl;
				attack2[s].push_back(e);
				attack3[s].push_back(w);

				
			}
		}
		//cout<<attack.size()<<endl;
		//cout<<attack[0].size()<<endl;
		for(int i=0;i<676068;i++)
		{
			
			for(int j=0;j<attack[i].size();j++)
			{
                int flag=0;
				//cout<<"yes\n";
				for(int k=attack3[i][j];k<attack2[i][j];k++)
				{
					if(h[k][k+1]<attack1[i][j])
					{
						if(flag==0)
						{
							suc++;
							flag=1;
							cout<<i<<" "<<j<<endl;
						}
						h[k][k+1]=attack1[i][j];
					}
				}
			}
		}




		cout<<suc<<endl;

			

	}
	return 0;
}
