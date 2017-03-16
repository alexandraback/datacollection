#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

// Radix sort comparator for 32-bit two's complement integers
class radix_test
{
    const int bit; // bit position [0..31] to examine
public:
    radix_test(int offset) : bit(offset) {} // constructor
 
    bool operator()(int value) const // function call operator
    {
        if (bit == 31) // sign bit
            return value < 0; // negative int to left partition
        else
            return !(value & (1 << bit)); // 0 bit to left partition
    }
};

void solve(double n[1000], double nc[1000], double k[1000], int r[2], int N);
int s_naomi(double n[1000], double k[1000], int N);
int s_ken(double n[1000], double k[1000], int N);
void rsort(double* a, int s, int e);
void quicksort(double* input, int p, int r);
int partition(double* input, int p, int r);
int binSearch(double arr[], int len, double what);
void pa(double a[], int n);
void print(int result[2], int r);

int main()
{
    int n;
    int N;
    double naomi[1000];
    double naomi_c[1000];
    double ken[1000];
    int result[2] = {0,0};
    
    cin >> n;

    for (int j = 0; j < n; j++)
    {
        cin >> N;
        
        for (int i = 0; i < N; ++i)
        {
        	cin >> naomi[i];
        	naomi_c[i] = naomi[i];
        }

        for (int i = 0; i < N; ++i)
        {
        	cin >> ken[i];
        }

        solve(naomi,naomi_c,ken,result,N);
        print(result, j+1);
    }

    return 0;
}

void solve(double n[1000], double nc[1000], double k[1000], int r[2], int N)
{
	/*cout << "start\n";*/

	quicksort(n,0,N-1);
	quicksort(nc,0,N-1);
	quicksort(k,0,N-1);
	/*cout << "middle\n";*/

	r[0] = s_naomi(n,k,N);
	r[1] = s_ken(nc,k,N);
	/*cout << "end\n";*/
}

int s_naomi(double n[1000], double k[1000], int N)
{
	/*cout << "naomi\n";*/
	int result=0;

	for (int i = 0; i < N; ++i)
	{
		int r = binSearch(n,N,k[i]);
		if(r==-1) result++;
		else
		{
			n[r] = 0;
			rsort(n,0,r);
		}
	}

	return N-result;
}

int s_ken(double n[1000], double k[1000], int N)
{
	int result=0;

	for (int i = 0; i < N; ++i)
	{
/*		cout << i << "th loop\n";
		pa(k,N);
		pa(n,N);
		cout << n[i] << endl;*/
		int r = binSearch(k,N,n[i]);
		if(r==-1) result++;
		else
		{
			k[r] = 0;
			rsort(k,0,r);
		}
	}

	return result;
}

void rsort(double* a, int s, int e)
{
	double temp=a[e];
	for (int i = e; i>0 ; i--)
	{
		a[i] = a[i-1];
	}
	a[0] = temp;
}

void quicksort(double* input, int p, int r)
{
    if ( p < r )
    {
        int j = partition(input, p, r);        
        quicksort(input, p, j-1);
        quicksort(input, j+1, r);
    }
}

int partition(double* input, int p, int r)
{
    double pivot = input[r];

    while ( p < r )
    {
        while ( input[p] < pivot )
            p++;

        while ( input[r] > pivot )
            r--;

        if ( input[p] == input[r] )
            p++;
        else if ( p < r )
        {
            double tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }

    return r;
}

int binSearch(double arr[], int len, double what)
{
  int low = 0;
  int high = len - 1;
  while (low <= high) {
  	/*cout << low << " " << high << "binsearch\n";*/
    int mid = (low + high) / 2;
    if (arr[mid] > what &&  mid > 0 && arr[mid-1] < what)
    	return mid;
    else if(arr[mid] > what && mid == 0)
    	return mid;
    else if (arr[mid] > what)
      high = mid - 1;
  	else if (arr[mid] < what && mid < high && arr[mid+1] > what)
  		return mid+1;
    else if (arr[mid] < what)
      low = mid + 1;
  }
  return -1; // indicate not found 
}

void pa(double a[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}

void print(int result[2], int r)
{
    cout << "Case #" << r << ": " << result[0] << " " << result[1] << endl;
}