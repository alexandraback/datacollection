#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	//srand(time(NULL));
	for(int I=1;I<=T;I++)
	{
		cout << "Case #" << I << ": ";
		int ult1 = 1,ult2=1;
		int n;
		cin >> n;
		int contmax = 0;
		vector<pair<string,string> > vs(n);
		pair<string,string> ps;
		pair<int,int> p,p1,p2;
		vector<pair<int,int> > v(n);
		
		//map<string,int> m1,m2;
		for(int i=0;i<n;i++)
		{
			string s1,s2;
			cin >> s1 >> s2;
			/*if(!m1[s1])
				m1[s1] = ult1,ult1++;
			if(!m2[s2])
				m2[s2] = ult2,ult2++;
			p.first = m1[s1];
			p.second = m2[s2];*/
			//v[i] = p;
			ps.first = s1;
			ps.second = s2;
			//st.insert(p);
			vs[i]= ps;
		}
		for(int ii=0;ii<100;ii++)
		{
			int cont = 0;
			ult1 = ult2 = 1;
			map<string,int> m1,m2;
			set<pair<int,int> >st;
			random_shuffle(vs.begin(),vs.end());
			for(int i=0;i<n;i++)
			{
				string s1=vs[i].first,s2=vs[i].second;
				//cin >> s1 >> s2;
				if(!m1[s1])
					m1[s1] = ult1,ult1++;
				if(!m2[s2])
					m2[s2] = ult2,ult2++;
				p.first = m1[s1];
				p.second = m2[s2];
				//v[i] = p;
				ps.first = s1;
				ps.second = s2;
				st.insert(p);
				//vs[i]= ps;
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==j)
						continue;
					p.first = p.second = i;
					p1.first = p1.second= j;
					p2.first = i;
					p2.second = j;
					if(st.find(p)!=st.end() && st.find(p1)!=st.end() && st.find(p2)!=st.end())
						cont++,st.erase(p2);
				}
			}/*
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==j)
						continue;
					p.first = i;
					p.second = j;
					p1.first = j;
					p1.second = j;
					p2.first = j;
					p2.second = i;
					if(st.find(p)!=st.end() && st.find(p1)!=st.end() && st.find(p2)!=st.end())
						cont++,st.erase(p1);
				}
			}*/
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					for(int k=0;k<n;k++)
					{
						for(int l=0;l<n;l++)
						{
							if((i==k) || (j==l))
								continue;
							p.first = i;
							p.second = j;
							p1.first = k;
							p1.second = j;
							p2.first = k;
							p2.second = l;
							if(st.find(p)!=st.end() && st.find(p1)!=st.end() && st.find(p2)!=st.end())
								cont++,st.erase(p1);
						}
					}
				}
			}
			contmax = max(cont,contmax);
		}
		
		cout << contmax << endl;
	}
}
