#include <iostream>
#include <fstream>
#include <cstdlib>
#include<string>
#include<vector>
#include<cmath>
#include <sstream>
#include <bitset>

using namespace std;



#define lp(i,n) for(i=0; i<n ; i++)
#define lp1(i,n) for(i=0; i<n ; i++)
#define lpI(i,a,b) for(i = a; )

#define lp(i,n) for (i=0; i<n; i++)
#define lp1(i,n) for (i=1; i<=n; i++)
#define lpi(i,a,b) for (i=a; i<=b; i++)
#define lpr(i,n) for (i=(n)-1; i>=0; i--)
#define lpr1(i,n) for (i=n; i>0; i--)
#define lpri(i,a,b) for (i=b; i>=a; i--)
#define lop(i, n)  for(int i=0; i<n ; i++)
#define lop1(i, n)  for(int i=1; i<n ; i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define ull unsigned long long 


char ctemp;
ull temp = 0;

string stemp;

string word = "";

int N= 0;

int h[1000][1000];

int max = 0;

int track[10000] = { 0 } ;

int ans[100];
int pos = 0;

int pri[100] = { 0 };

int num;

void bubble_sort(int arr[], int size) {
	bool not_sorted = true;
	int j = 1, tmp;

	while (not_sorted) {
		not_sorted = false;
		j++;
		for (int i = 0; i < size - j; i++) {
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				not_sorted = true;

			}//end of if
		
		}//end of for loop
	}//end of while loop
}//end of bubble_sort


void docase()
{

	cin >> N;
	
	lop(k, (2 * N ) - 1)
		{
			lop(c, N)
			{
				cin >> num;	// h[k][c];
				track [ num ] = track[num] + 1;
			
				if (max < num)
				{
					max = num;
				}
				// cout << num << "  " << max << endl;
			}

		}
	int w = 1;
	lp(w, max  + 1)
	{
		if (track[w] % 2 == 1)
		{
		//	cout << track[w] << endl;
			ans[pos] = w;
		//	cout << ans[pos] << endl;
			pos++;
		}
	}
	w = 1;
	lp(w, max + 1)
	{
		track[w] = 0;
	}
	


	
}

















































int main()
{
	int cases = 0;
	freopen("a.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> cases;
	

	for (int i = 0; i < cases; i++)
	{
				
		cout << "Case #" << i + 1 << ": ";
		docase();


		bubble_sort(ans, pos - 1);

		lop(z, pos)
		{
			cout << ans[z] << " ";
		}
		pos = 0;
		max = 0;
		cout << endl;


	}

	



	return 0;
}
