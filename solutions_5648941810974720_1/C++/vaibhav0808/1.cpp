#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	
	int t;
	cin >>  t;
	
	
	int freq[26];
	int f[10];
	
	for(int tst=1;tst<=t;tst++)
	{
		cout << "Case #" << tst  << ": " ;
		
		char s[2005];
		cin >> s;
		
		memset(f,0,sizeof(f));
	    memset(freq,0,sizeof(freq));
	    
		int n = strlen(s);
		for(int i=0;i<n;i++)
		{
			freq[s[i]-'A']++;
		} 
	    
	    for(int i=0;i<freq['X'-'A'];i++)
	    {
	    	f[6]++;
	    	freq['I'-'A']--;
	    	freq['S'-'A']--;
		}
		for(int i=0;i<freq['W'-'A'];i++)
	    {
	    	f[2]++;
	    	freq['T'-'A']--;
	    	freq['O'-'A']--;
		}
        for(int i=0;i<freq['U'-'A'];i++)
	    {
	    	f[4]++;
	    	freq['O'-'A']--;
	    	freq['F'-'A']--;
	    	freq['R'-'A']--;	
		}
		for(int i=0;i<freq['G'-'A'];i++)
	    {
	    	f[8]++;
	    	freq['E'-'A']--;
	    	freq['I'-'A']--;
	    	freq['H'-'A']--;	
	         freq['T'-'A']--;
		}
		for(int i=0;i<freq['Z'-'A'];i++)
	    {
	    	f[0]++;
	    	//freq['Z'-'A']--;
	    	freq['E'-'A']--;
	    	freq['R'-'A']--;	
	         freq['O'-'A']--;
		}
	    for(int i=0;i<freq['F'-'A'];i++)
	    {
	    	f[5]++;
	    	//freq['Z'-'A']--;
	    	freq['I'-'A']--;
	    	freq['V'-'A']--;	
	         freq['E'-'A']--;
		}
		for(int i=0;i<freq['T'-'A'];i++)
	    {
	    	f[3]++;
	    	//freq['Z'-'A']--;
	    	freq['H'-'A']--;
	    	freq['R'-'A']--;	
	        freq['E'-'A']--;
	        freq['E'-'A']--;
		}
		for(int i=0;i<freq['V'-'A'];i++)
	    {
	    	f[7]++;
	    	freq['E'-'A']--;
	    	freq['E'-'A']--;
	    	freq['N'-'A']--;	
		}
		for(int i=0;i<freq['O'-'A'];i++)
	    {
	    	f[1]++;
	    	freq['N'-'A']--;
	    	freq['E'-'A']--;
	    	//freq['R'-'A']--;	
		}
	  	
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<f[i];j++)
			{
				cout << i ;
			}
		}
		cout << endl;
	}
	return 0;
}


