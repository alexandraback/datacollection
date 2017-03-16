#include<bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define PI 3.14159265359
#define endl '\n'

using namespace std;

int tests,j,p,s,k;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> tests;
	for(int te=1;te<tests+1;te++)
	{
		cin >> j >> p >> s >> k;
		
		if(j==1 && p==1 && s==1)
		{
			cout << "Case #" << te << ": " << 1 << endl << "1 1 1" << endl;
			continue;
		}
		
		if(j==1 && p==1 && s==2)
		{
			if(k == 1)
				cout << "Case #" << te << ": " << 1 << endl << "1 1 1\n";
			else
				cout << "Case #" << te << ": " << 2 << endl << "1 1 1\n1 1 2\n";
			continue;
		}
		
		if(j==1 && p==1 && s==3)
		{
			if(k == 1)
				cout << "Case #" << te << ": " << 1 << endl << "1 1 1\n";
			else if(k == 2)
				cout << "Case #" << te << ": " << 2 << endl << "1 1 1\n1 1 2\n";
			else
				cout << "Case #" << te << ": " << 3 << endl << "1 1 1\n1 1 2\n1 1 3\n";
			continue;
		}
		
		if(j==1 && p==2 && s==2)
		{
			if(k == 1)
				cout << "Case #" << te << ": " << 2 << endl << "1 1 1\n1 2 2\n";
			else
				cout << "Case #" << te << ": " << 4 << endl << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n";
			continue;
		}
		
		if(j==1 && p==2 && s==3)
		{
			if(k == 1)
				cout << "Case #" << te << ": " << 2 << endl << "1 1 1\n1 2 2\n";
			else if(k == 2)
				cout << "Case #" << te << ": " << 4 << endl << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n";
			else
				cout << "Case #" << te << ": " << 6 << endl << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n1 1 3\n1 2 3\n";
			continue;
		}
		
		if(j==1 && p==3 && s==3)
		{
			if(k == 1)
				cout << "Case #" << te << ": " << 3 << endl << "1 1 1\n1 2 2\n1 3 3\n";
			else if(k == 2)
				cout << "Case #" << te << ": " << 6 << endl << "1 1 1\n1 1 2\n1 2 1\n1 2 3\n1 3 2\n1 3 3\n";
			else
				cout << "Case #" << te << ": " << 9 << endl << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n1 1 3\n1 2 3\n1 3 1\n1 3 2\n1 3 3\n";
			continue;
		}
		
		if(j==2 && p==2 && s==2)
		{
			if(k == 1)
				cout << "Case #" << te << ": " << 4 << endl << "1 1 1\n1 2 2\n2 1 2\n2 2 1\n";
			else
				cout << "Case #" << te << ": " << 8 << endl << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n2 1 1\n2 1 2\n2 2 1\n2 2 2\n";
			continue;
		}
		
		if(j==2 && p==2 && s==3)
		{
			if(k == 1)
				cout << "Case #" << te << ": " << 4 << endl << "1 1 1\n1 2 2\n2 1 2\n2 2 1\n";
			else if(k == 2)
				cout << "Case #" << te << ": " << 8 << endl << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n2 1 1\n2 1 2\n2 2 1\n2 2 2\n";
			else
				cout << "Case #" << te << ": " << 12 << endl << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n2 1 1\n2 1 2\n2 2 1\n2 2 2\n1 1 3\n1 2 3\n2 1 3\n2 2 3\n";
			continue;
		}
		
		if(j==2 && p==3 && s==3)
		{
			if(k == 1)
				cout << "Case #" << te << ": " << 6 << endl << "1 1 1\n1 2 2\n1 3 3\n2 1 2\n2 2 3\n2 3 1\n";
			else if(k == 2)
				cout << "Case #" << te << ": " << 12 << endl << "1 1 1\n1 1 2\n1 2 2\n1 2 3\n1 3 1\n1 3 3\n2 1 1\n2 1 2\n2 2 2\n2 2 3\n2 3 1\n2 3 3\n";
			else
				cout << "Case #" << te << ": " << 18 << endl << "1 1 1\n1 1 2\n1 2 2\n1 2 3\n1 3 1\n1 3 3\n2 1 1\n2 1 2\n2 2 2\n2 2 3\n2 3 1\n2 3 3\n1 1 3\n1 2 1\n1 3 2\n2 1 3\n2 2 1\n2 3 2\n";
			continue;
		}
		
		if(j==3 && p==3 && s==3)
		{
			if(k == 1)
				cout << "Case #" << te << ": " << 9 << endl << "1 1 1\n1 2 2\n1 3 3\n2 1 2\n2 2 3\n2 3 1\n3 1 3\n3 2 1\n3 2 2\n";
			else if(k == 2)
				cout << "Case #" << te << ": " << 18 << endl << "1 1 1\n1 1 2\n1 2 2\n1 2 3\n1 3 1\n1 3 3\n2 1 1\n2 1 2\n2 2 2\n2 2 3\n2 3 1\n2 3 3\n3 1 1\n3 1 2\n3 2 2\n3 2 3\n3 3 1\n3 3 3\n";
			else
				cout << "Case #" << te << ": " << 27 << endl << "1 1 1\n1 1 2\n1 2 2\n1 2 3\n1 3 1\n1 3 3\n2 1 1\n2 1 2\n2 2 2\n2 2 3\n2 3 1\n2 3 3\n1 1 3\n1 2 1\n1 3 2\n2 1 3\n2 2 1\n2 3 2\n3 1 1\n3 1 2\n3 1 3\n3 2 1\n3 2 2\n3 2 3\n3 3 1\n3 3 2\n3 3 3\n";
			continue;
		}
		
		cout << "Case #" << te << ": " << endl;
	}
	
	return 0;
}