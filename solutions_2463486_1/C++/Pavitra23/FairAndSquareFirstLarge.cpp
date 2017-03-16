#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<cstdint>

using namespace std;

///////////////NEXT HIGHER PALINDROME//////////////////

static int countDigits(unsigned long long int n)
{
	int c = 0;

	for(c=0; n > 0; c++, n /= 10)
		;
	return c;
}

static unsigned long long int makeMultiple(int what, int power)
{
	unsigned long long int c;

	for(c=1; power > 0; (c *= what), power--)
		;
	return c;
}

static unsigned long long int
	smallestPlalindromeLargerThanInteger(unsigned long long int n)
{
	n++;
	int c = countDigits(n);
	unsigned long long int mstens = makeMultiple(10, c-1);
	unsigned long long int lstens = 10;
	while(mstens >= lstens)
	{
		unsigned long long int postPart = n%lstens;
		if((n/mstens)%10 < (n%lstens)/(lstens/10))
		{
			unsigned long long int rem = (n/mstens)%10;
			n /= lstens;
			n++;
			n = n*lstens + rem*(lstens/10) + postPart%(lstens/10);
		}
		else if((n/mstens)%10 > (n%lstens)/(lstens/10))
		{
			unsigned long long int rem = (n/mstens)%10;
			n = n/lstens;
			n = n*lstens + rem*(lstens/10) + postPart%(lstens/10);
			mstens /= 10;
			lstens *= 10;
		}
		else
		{
			mstens /= 10;
			lstens *= 10;
		}
	}
	return n;
}

///////////////////////////////////////////////////////

#define TEST_CASES_FIRSTLARGE 10000
const  unsigned long long int F_S_FIRSTLARGE = 100000000000000;

unsigned long long int FairAndSqNumbers[1000]; //magic number hard coded...
int count;

class inRange
{
public:
	unsigned long long int A;
	unsigned long long int B;
	long noOfFSNumbers;
};

inRange FSNUMS[TEST_CASES_FIRSTLARGE];

bool isPalindrome(unsigned long long int x) {
  if (x < 0) return false;
  unsigned long long int divisor = 1;
  while (x / divisor >= 10) {
    divisor *= 10;
  }       
  while (x != 0) {
    unsigned long long int l = x / divisor;
    unsigned long long int r = x % 10;
    if (l != r) return false;
    x = (x % divisor) / 10;
    divisor /= 100;
  }
  return true;
}

void fairAndSquareSmall(int tcases)
{
	for(int i = 0; i < tcases; i++)
	{
		for(int j = 0; j< count; j++)
		{
			if((FairAndSqNumbers[j] >= FSNUMS[i].A) && (FairAndSqNumbers[j] <= FSNUMS[i].B))
				FSNUMS[i].noOfFSNumbers++;
			else if(FairAndSqNumbers[j] > FSNUMS[i].B)
				break;
		}
	}
}

void printFairAndSqCount(FILE *ofp, int tCases)
{
	assert(ofp);
	for(int i =0; i <tCases; i++)
		fprintf(ofp, "Case #%d: %d\n", i+1, FSNUMS[i].noOfFSNumbers);
	return;
}

void preprocessing()
{
	unsigned long long int upperLimit = (int)floor(sqrt((double)F_S_FIRSTLARGE));
	unsigned long long int i = 0;
	count = 0;

	for( i = 1; i <= upperLimit; 
		i = smallestPlalindromeLargerThanInteger(i))
	{
		if(isPalindrome(i*i) && ((i*i) <= F_S_FIRSTLARGE))
			FairAndSqNumbers[count++] = i*i;
	}
}

int main()
{
	char *inFile = "C://InputOutput//FairAndSquare//C-large-1.in";
	char *outFile = "C://InputOutput//FairAndSquare//sampleOutput.txt";
	
	FILE *ifp = fopen(inFile, "r");
	FILE *ofp = fopen(outFile, "w");
	assert(ifp);
	assert(ofp);

	int tcases=0;

	fscanf(ifp, "%d\n", &tcases);
	preprocessing();
	for(int i = 0; i < tcases; i++)
	{
		fscanf(ifp, "%llu %llu\n", &(FSNUMS[i].A), &(FSNUMS[i].B));
		FSNUMS[i].noOfFSNumbers = 0;
	}

	fairAndSquareSmall(tcases);
	printFairAndSqCount(ofp, tcases);

	return 0;
}