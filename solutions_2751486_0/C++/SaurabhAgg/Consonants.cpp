#include<iostream>
#include<cstring>
using namespace std;

int locations[1000010][2];
int numLocations;

char L[1000010];
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
	numLocations = 0;
	for(int i = 0; i < length; i++)
	{
		bool found = true;
		int j;
		for(j = i; (j < length) && ((j - i) < n); j++)
		{
			if(isVowel(L[j]))
			{
				found = false;
				break;
			}
		}
		if((j - i) < n)
			found = false;
		if(found)
		{
			locations[numLocations][0] = i;
			locations[numLocations][1] = j;
			numLocations++;
		}
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
		
		/*
		for(int i = 0; i < numLocations; i++)
		{
			cout << locations[i][0] << " " << locations[i][1] << endl;
		}
		*/
		
		long long ans = 0;
		
		for(int numPats = 0; numPats < numLocations; numPats++)
		{
			//cout << "numPats = " << numPats << endl;
			for(int startPat = 0; (startPat + numPats) < numLocations; startPat++)
			{
				//cout << "startPat = " << startPat << endl;
				int left = 0;
				if(startPat != 0)
					left = locations[startPat - 1][0] + 1;
				left = locations[startPat][0]- left;
				//cout << "left = " << left << endl;
				
				int right = length;
				//cout << right << endl;
				if((startPat + numPats) != (numLocations - 1))
					right = locations[startPat + numPats + 1][1] - 1;
				//cout << right << endl;
				right = right - locations[startPat + numPats][1];
				//cout << "right = " << right << endl;
				
				//cout << endl;
				ans += ((left + 1) * (right + 1));
			}
		}
		
		cout << "Case #" << t << ": " << ans << endl;
	}
}
