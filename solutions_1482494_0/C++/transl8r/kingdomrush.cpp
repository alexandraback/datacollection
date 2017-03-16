#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    int t;
    int i,n;
    int c = 0;
	    int x,y;
	    pair<int,int> p;
    scanf("%d", &t);
	int stars = 0, moves = 0;
	int flag=0;
	int cur;
	int lvl[1000];
    while(t--)
    {
    vector<pair<int,int> > a, b;
	stars = 0;
	moves = 0;
	flag = 0;
	c++;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
	    scanf("%d%d", &x, &y);
	    p.first = x;
	    p.second = i;
	    a.push_back(p);
	    p.first = y;
	    b.push_back(p);
	}
		
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
//	for(int j = 0; j < a.size(); j++)
//	    cout<<" "<<a[j].first;

	memset(lvl, 0, sizeof(int)*1000);
	while(stars != 2*n)
	{
	    while(lvl[a.back().second] == 2)
		a.pop_back();
	    cur = stars;

//	    cout<<"move"<<moves<<" :b"<<b.back().first<<" ,a"<<a.back().first<<" stars"<<stars<<endl;
	    if(b.back().first <= stars)
	    {
		stars += 2 - lvl[b.back().second];
		lvl[b.back().second] = 2;
		b.pop_back();
		moves++;
	    }
	    else if(a.back().first <= stars)
	    {
		stars += lvl[a.back().second]==1?0:1;
		lvl[a.back().second] = 1;
		a.pop_back();
		moves++;
	    }


	    if(cur == stars)
	    {
		flag = 1;
		break;
	    }
	}
	if(flag)
	    printf("Case #%d: Too Bad\n",c);
	else
	    printf("Case #%d: %d\n", c, moves);
	while(a.size() > 0)
	    a.pop_back();
	while(b.size() > 0)
	    b.pop_back();
    }
    return 0;
}
