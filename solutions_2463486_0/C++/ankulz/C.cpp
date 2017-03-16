#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <vector>
using namespace std;

string toString (long long n)
{
	string num;
	while(n)
	{
		num += (n%10) + '0';
		n /= 10;
	}
	reverse(num.begin(), num.end());
	return num;
}

vector <long long> list;

bool IsPalindrome(string a)
{
	string b = a;
	reverse(b.begin(), b.end());
	if (a==b && a.size() < 16)
	{
		list.push_back(atoi(a.c_str()));
	}
	return a==b;
}

// Generate all numbers containing only 1,0,2 of max length 14
// Concatenate the numbers at their end to get palindromes of max length 28
// Get square of this number and check if square is also palindrome

string mult(string n1, char x)
{
	int i = n1.size()-1;
	int m = x-48;
	int tmp,carry=0;
	string ret;

	while(i>0)
	{
		tmp = (n1[i]-48)*m+carry;
		if(tmp>=10)
		{
			carry = tmp/10;
			tmp = tmp%10;
			ret+=tmp+48;
		}else
		{
			carry = 0;
			ret+=tmp+48;
		}

		i--;
	}
	tmp = (n1[i]-48)*m+carry;

	if(tmp>=10)
	{
		while(tmp)
		{
			int j = tmp%10;
			ret+=j+48;
			tmp = tmp/10;
		}	
	}else
	{
		ret+=tmp+48;
	}

	reverse(ret.begin(),ret.end());

	return ret;
}

string zero_rem(string s)
{
	if(s[0]==48&& s.size()>1)
	{
		int i=1;
		while(s[i]==48)
		{
			i++;
			if(i==s.size())
			{
				i--;
				break;
			}	
		}
		s=s.substr(i);
	}

	return s;
}

string add(string n1, string n2)
{
	int i = n1.size()-1;
	int j = n2.size()-1;
	int tmp,carry=0;
	string sum;

	while(i>=0&&j>=0){
		tmp = (n1[i]-48)+(n2[j]-48)+carry;
		if(tmp>=10){
			tmp=tmp%10;
			sum+=tmp+48;
			carry=1;
		}else{
			sum+=tmp+48;
			carry=0;
		}
		i--;
		j--;
	}

	if(i==-1){
		while(j>=0){
			tmp = (n2[j]-48)+carry;
			if(tmp>=10){
				tmp=tmp%10;
				sum+=tmp+48;
				carry=1;
			}else{
				sum+=tmp+48;
				carry=0;
			}
			j--;
		}
	}else{
		while(i>=0){
			tmp = (n1[i]-48)+carry;
			if(tmp>=10){
				tmp=tmp%10;
				sum+=tmp+48;
				carry=1;
			}else{
				sum+=tmp+48;
				carry=0;
			}
			i--;
		}
	}
	if(carry==1){
		sum+=49;
	}
	reverse(sum.begin(),sum.end());

	return sum;
}

string multiply(string n1, string n2)
{
	vector <string> v,t;
	string res;
	for(int i=n2.size()-1; i>=0; i--)
	{ 
		res = mult(n1,n2[i]);
		res = zero_rem(res);
		v.push_back(res);
	}
	t=v;
	int i = t.size()-1;
	int j = 1;
	res = t[0];
	while(i--)
	{
		int k = j;
		while(k--)
		{
			t[j]+=48;
		}
		res = add(res,t[j]);
		j++;
	}
	res = zero_rem(res);
	return res;
}

bool IsSquareFair (string a)
{
	long long n = atoi(a.c_str());
	return IsPalindrome(multiply(a,a));
}

main()
{
	/*for (long long i = 1; i <= 10000000; i++)
	{
		if (IsPalindrome(i) && IsPalindrome(i*i))
		{
			cout << i << " ---> " << i*i << "\n";
		}
	}*/

	queue <string> q;
	q.push("1");
	q.push("2");
	queue <string> rq;
	rq.push("1");
	rq.push("2");
	while (!q.empty())
	{
		string str = q.front();
		string rstr = rq.front();
		q.pop();
		rq.pop();
		if (str.size() > 7)
		{
			continue;
		}
		string a = str + rstr;
		IsSquareFair(a);
		a = str + "0" + rstr;
		IsSquareFair(a);
		a = str + "1" + rstr;
		IsSquareFair(a);
		if (str[0] == '1')
		{
			a = str + "2" + rstr;
			IsSquareFair(a);
		}
		q.push(str+"0");
		rq.push("0"+rstr);
		if (str[0] == '1')
		{
			q.push(str+"1");
			rq.push("1"+rstr);
		}
	}
	list.push_back(1);
	list.push_back(4);
	list.push_back(9);
	sort(list.begin(),list.end());
	int T;
	cin >> T;

	for (int in = 1; in <= T; in++)
	{
		cout << "Case #" << in << ": ";
		long long A,B;
		int ans = 0;
		cin >> A >> B;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i] >= A && list[i] <= B)
			{
				ans++;
			}
		}
		cout << ans << "\n";
	}
}