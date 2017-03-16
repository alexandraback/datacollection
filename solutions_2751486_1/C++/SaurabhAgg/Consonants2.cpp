#include<iostream>
#include<cstring>
using namespace std;

int locations[1000010][2];
int numLocations;

char L[1000010];
char starts[1000010];

int n;
int length;

bool isVowel(char c)
{
    switch (c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        {
            return true;
        }
        default:
        {
            return false;
        }
    }
}

void findLocations()
{
	int numCons = 0;
	for(int i = 0; i < length; i++)
		starts[i] = '0';
	starts[length] = '\0';
	for(int i = 0; i < length; i++)
	{
		if(!isVowel(L[i]))
			numCons++;
		else
			numCons = 0;
		if(numCons >= n)
			starts[i - n + 1] = '1';
	}
}

int main()
{
	int cases;
	cin >> cases;
	
	for(int t = 1; t <= cases; t++)
	{
		cin >> L >> n;
		length = strlen(L);
		findLocations();
		//cout << starts << endl;
		/*
		for(int i = 0; i < numLocations; i++)
		{
			cout << locations[i][0] << " " << locations[i][1] << endl;
		}
		*/
		
		long long ans = 0;
		
		int last1 = 0;
		for(int i = 0; i < length; i++)
		{
			if(starts[i] == '1')
			{
				//cout << "i = " << i << endl;
				ans += ((i - last1 + 1) * (length - i - n + 1));
				last1 = i + 1;
			}
		}
		
		cout << "Case #" << t << ": " << ans << endl;
	}
}
