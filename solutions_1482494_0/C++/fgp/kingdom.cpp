#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Level
{
	public:
		int s1, s2, c2;
		Level(int a, int b) { s1 = a; s2=b; c2=0; }
};

bool func2(Level * a, Level * b)
{
	return (a->s2 > b->s2);
}

bool func1(Level * a, Level * b)
{
	if(a->s1==b->s1) return a->s2<b->s2;
	return (a->s1 > b->s1);
}

int main()
{
	vector<Level *> lvs1;
	vector<Level *> lvs2;

	int t,i,j=0,n;
	int a,b;
	int sts;
	
	cin >> t;
	for(i=0; i<t; i++)
	{
		lvs1.erase(lvs1.begin(), lvs1.end());
		lvs2.erase(lvs2.begin(), lvs2.end());
		cin >> n;
		sts=0;
		int cnt = 0;
		Level * c;
		j=0;
		for(j=0;j<n;j++)
		{
			cin >> a;
			cin >> b;			
			c = new Level(a,b);
			lvs1.push_back(c);
			lvs2.push_back(c);
		}		
		
		sort(lvs1.begin(), lvs1.end(), func1);
		sort(lvs2.begin(), lvs2.end(), func2);
		
		cout << "Case #" << (i+1) << ": ";
		
		bool ss;
		
		while(lvs1.size())
		{
			if(lvs2.back()->s2 > sts)
			{
				if(lvs1.back()->s1 > sts)
				{
					cout << "Too Bad" << endl;
					break;
				}
				else
				{
					lvs1.back()->c2=1;
					sts++;
					cnt++;
				}
			}
			else
			{
				sts+=2;
				Level *aux = lvs2.back();
				sts-=aux->c2; 
				int rm=0;				
				while(lvs1[rm]!=aux)
					rm++;				
				lvs1.erase(lvs1.begin()+rm);
				lvs2.erase(lvs2.end()-1);
				cnt++;
				if(lvs1.size()==0)
					cout << cnt << endl;
			}
		}
		
		
			
	}
	
	
	return 0;
}
		
		
