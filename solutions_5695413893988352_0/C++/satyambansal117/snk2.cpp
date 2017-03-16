#include<bits/stdc++.h>
#define intMAX 1123456789LL
#define MAX intMAX * intMAX
#define F first
#define S second
#define mp make_pair
#define ll long long
#define pb push_back
#define pv(v,b,a) v.insert(v.begin()+b,a)
#define all(c) c.begin(),c.end()
#define sf(a) scanf("%d",&a);
#define sl(a) scanf("%lld",&a);
#define MAXCR 1000000000
#define mem(arr,a) memset(arr, a, sizeof arr)
#define er(vec,a,b) vec.erase(vec.begin() + a, vec.begin() + b+1)
#define traverse(a) for()
#define pii pair<int ,int>
#define mod 1000000007
#define LIM 100
using namespace std;
/*
list as pop_front();push_front(ELEMENT);
list as pop_front();push_back(ELEMENT);
to see first element stack=q.front()
to see last element queue=q.back()
*/
//str.insert(6,str3,3,4); to insert 4 words from str3 starting from 3rd position(0 based indexing) to str from 6th position (0 based indexing)
//str.find("live");//finds first occurance of string and returns its 0 based indes
//string str1=str.substr (a,n);//a=0 based start index,n=length of words//if length not given substring till end is formed
//auto bound_=upper_bound (v.begin(), v.end(), 20); //Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
//auto bound_=lower_bound (v.begin(), v.end(), 20);//Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
//bool ans=binary_search();//Returns true if any element in the range [first,last) is equivalent to val, and false otherwise.
/*
//for(???<???>:iterator itr;itr!=???.end();itr++) or for(auto &tt : t.edges)
map<double,LL>my;
map<double,LL>:: iterator it;
for(it=my.begin();it!=my.end();it++)
*/
//getline(cin,s,'\n');  to get input terminating at'\n';excluding '\n'
//(a/b)%m = ((a%m)(b^(m-2)%m))%m.
//(a^b)%m=
//vector<ll>v(size,default val);
//reverse(all(s))//to reverse some vector or string;
//cin.eof() //checks for end of file return true when cin takes input as end of file
//cin.peek()//Returns the next character in the input sequence, without extracting it:
string S1,S2,ans1,ans2;
ll min__;
ll tonum(string s)
{
	ll a=0,len=s.length(),i=0;
	while(i<len)
	{//printf("a");
		a=a*10+s[i]-48;
		i++;
	}
	return a;
}
bool min_(string s1,string s2)
{
//	printf("((%lld %lld))",tonum(s2),tonum(s1));
	ll a=abs(tonum(s2)-tonum(s1));
	if(a<min__)
	{
		min__=a;
		ans1=s1;
		ans2=s2;
		return true;
	}
	else if(a==min__&&s1<ans1)
	{
		min__=a;
		ans1=s1;
		return true;
	}
	else if(a==min__&&s1==ans1&&s2<ans2)
	{
		min__=a;
		ans2=s1;
		return true;
	}
	return false;
}
void chk(string s1,string s2,ll len,ll i,ll j)
{
	
//	printf("((%lld %lld))",len,j);
	if(i==len&&j==len)
	{
//		cout<<endl<<s1<<"..."<<s2<<endl;
		min_(s1,s2);
		return ;
	}
	ll k;
	if(i<len)
	{//printf("a");
		if(S1[i]=='?')
		{
			for(k=0;k<=9;k++)
			{
				
				s1[i]=(char)(k+48);
//				cout<<s1<<" "<<s2<<" ";
				chk(s1,s2,len,i+1,j);
			}
		}
		else
		{
			chk(s1,s2,len,i+1,j);
		}
	}
	if(j<len)
	{
		if(S2[j]=='?')
		{
			for(k=0;k<=9;k++)
			{
				s2[j]=(char)(k+48);
				chk(s1,s2,len,i,j+1);
			}
		}
		else
		{
			chk(s1,s2,len,i,j+1);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ll t,i,len;
	string s1,s2;
	sl(t)
	for(i=1;i<=t;i++)
	{
		min__=99999999999;
		cin>>s1;
		cin>>s2;
		S1=s1;
		S2=s2;
		len=s1.length();
		chk(s1,s2,len,0,0);
		printf("Case #%lld:  ",i);
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
