#include<bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define rep(i,in1,n) for(i=in1;i<=n;i++)
#define repd(i,in1,n) for(i=in1;i>=n;i--)

#define pf(n) printf("%d ",n);
#define sf(n) scanf("%d",&n)
#define sl(n) scanf("%I64d",&n)
#define nl printf("\n")
#define mem(arr,init) memset(arr,init,sizeof(arr))
#define vi vector<int>
#define vvi vector<vi>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp make_pair
#define ep emplace_back//c++11
#define ii pair<int,int>
#define iii pair<ii,i>
//	freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
using namespace std;


string s1;
string arr[18];
map<char,int> map1;
string ans;

int main()
{
	int i,j,k,t,n,m,a,b,c,x,y,z,cs;
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	
	cin>>t;
	for(cs=1;cs<=t;cs++)
	{
		ans.clear();
		map1.clear();
		cin>>s1;
		n=s1.length();
		for(i=0;i<n;i++)
		{
			map1[s1[i]]++;
		}
		
		while(map1.find('Z')!=map1.end() && map1.find('E')!=map1.end() && map1.find('R')!=map1.end() && map1.find('O')!=map1.end() )
		{
			map1['Z']--; 
			if(map1['Z']<=0)
			map1.erase(map1.find('Z'));
			map1['E']--;
			if(map1['E']<=0)
			map1.erase(map1.find('E'));
			map1['R']--;
			if(map1['R']<=0)
			map1.erase(map1.find('R'));
			map1['O']--;
			if(map1['O']<=0)
			map1.erase(map1.find('O'));
			
			ans+='0';
			
		}
	
		
		while(map1.find('T')!=map1.end() && map1.find('W')!=map1.end() && map1.find('O')!=map1.end()  )
		{
			map1['O']--; 
			if(map1['O']<=0)
			map1.erase(map1.find('O'));
			
			map1['T']--;
			if(map1['T']<=0)
			map1.erase(map1.find('T'));
			
			map1['W']--;
			if(map1['W']<=0)
			map1.erase(map1.find('W'));
			
			ans+='2';
			
		}
		
	
		
		while(map1.find('F')!=map1.end() && map1.find('O')!=map1.end() && map1.find('R')!=map1.end() && map1.find('U')!=map1.end()  )
		{
			map1['F']--; 
			if(map1['F']<=0)
			map1.erase(map1.find('F'));
			
			map1['O']--;
			if(map1['O']<=0)
			map1.erase(map1.find('O'));
			
			map1['R']--;
			if(map1['R']<=0)
			map1.erase(map1.find('R'));
			
			map1['U']--;
			if(map1['U']<=0)
			map1.erase(map1.find('U'));
			
			
			ans+='4';
			
		}
		
		while( map1.find('I')!=map1.end() && map1.find('S')!=map1.end() && map1.find('X')!=map1.end()  )
		{
		
			
			map1['I']--;
			if(map1['I']<=0)
			map1.erase(map1.find('I'));
			
			map1['S']--;
			if(map1['S']<=0)
			map1.erase(map1.find('S'));
			
			map1['X']--;
			if(map1['X']<=0)
			map1.erase(map1.find('X'));
			
			
			ans+='6';
			
		}
			while(map1.find('F')!=map1.end() && map1.find('I')!=map1.end() && map1.find('V')!=map1.end() && map1.find('E')!=map1.end()  )
		{
			map1['F']--; 
			if(map1['F']<=0)
			map1.erase(map1.find('F'));
			
			map1['I']--;
			if(map1['I']<=0)
			map1.erase(map1.find('I'));
			
			map1['V']--;
			if(map1['V']<=0)
			map1.erase(map1.find('V'));
			
			map1['E']--;
			if(map1['E']<=0)
			map1.erase(map1.find('E'));
			
			
			ans+='5';
			
		}
		
		while(map1.find('T')!=map1.end() && map1.find('H')!=map1.end() && map1.find('G')!=map1.end() && map1.find('E')!=map1.end()  && map1.find('I')!=map1.end() )
		{
			map1['H']--; 
			if(map1['H']<=0)
			map1.erase(map1.find('H'));
			
			map1['T']--;
			if(map1['T']<=0)
			map1.erase(map1.find('T'));
			
			map1['G']--;
			if(map1['G']<=0)
			map1.erase(map1.find('G'));
			
			map1['E']--;
			if(map1['E']<=0)
			map1.erase(map1.find('E'));
			
			map1['I']--; 
			if(map1['I']<=0)
			map1.erase(map1.find('I'));
			
			
			ans+='8';
			
		}
		
	while(map1.find('I')!=map1.end()  && map1.find('E')!=map1.end() && map1.find('N')!=map1.end() && map1['N']>=2 )
		{
			
			
			map1['I']--;
			if(map1['I']<=0)
			map1.erase(map1.find('I'));
			
			map1['E']--;
			if(map1['E']<=0)
			map1.erase(map1.find('E'));
			
			map1['N']-=2;
			if(map1['N']<=0)
			map1.erase(map1.find('N'));
			
			
			ans+='9';
			
		}
		while(map1.find('S')!=map1.end() && map1.find('N')!=map1.end() && map1.find('V')!=map1.end() && map1.find('E')!=map1.end() && map1['E']>=2 )
		{
			map1['V']--; 
			if(map1['V']<=0)
			map1.erase(map1.find('V'));
			
			map1['S']--;
			if(map1['S']<=0)
			map1.erase(map1.find('S'));
			
			map1['N']--;
			if(map1['N']<=0)
			map1.erase(map1.find('N'));
			
			map1['E']-=2;
			if(map1['E']<=0)
			map1.erase(map1.find('E'));
			
			
			ans+='7';
			
		}
		while(map1.find('F')!=map1.end() && map1.find('I')!=map1.end() && map1.find('V')!=map1.end() && map1.find('E')!=map1.end()  )
		{
			map1['F']--; 
			if(map1['F']<=0)
			map1.erase(map1.find('F'));
			
			map1['I']--;
			if(map1['I']<=0)
			map1.erase(map1.find('I'));
			
			map1['V']--;
			if(map1['V']<=0)
			map1.erase(map1.find('V'));
			
			map1['E']--;
			if(map1['E']<=0)
			map1.erase(map1.find('E'));
			
			
			ans+='5';
			
		}
		
			while(map1.find('O')!=map1.end() && map1.find('N')!=map1.end() && map1.find('E')!=map1.end()  )
		{
			map1['O']--; 
			if(map1['O']<=0)
			map1.erase(map1.find('O'));
			
			map1['N']--;
			if(map1['N']<=0)
			map1.erase(map1.find('N'));
			
			map1['E']--;
			if(map1['E']<=0)
			map1.erase(map1.find('E'));
			
			ans+='1';
			
		}
			while(map1.find('T')!=map1.end() && map1.find('H')!=map1.end() && map1.find('R')!=map1.end() && map1.find('E')!=map1.end() && map1['E']>=2 )
		{
			map1['H']--; 
			if(map1['H']<=0)
			map1.erase(map1.find('H'));
			
			map1['T']--;
			if(map1['T']<=0)
			map1.erase(map1.find('T'));
			
			map1['R']--;
			if(map1['R']<=0)
			map1.erase(map1.find('R'));
			
			map1['E']-=2;
			if(map1['E']<=0)
			map1.erase(map1.find('E'));
			
			
			ans+='3';
			
		}
		
		bool f1=0;
		tr(map1,it)
		{
			cout<<it->F;
			f1=1;
			
		}
		if(f1)
		nl;
	//	nl;
		sort(ans.begin(),ans.end());
		printf("Case #%d: ",cs);
		cout<<ans;
		nl;
		
		
		
		
	}



	return 0;
}



