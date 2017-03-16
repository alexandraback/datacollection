#include <iostream>
#include <fstream>

using namespace std;

int iCaseNo = -1;
int i_Op = -1;
int i_A = -1;
int i_N = -1;

int i = 0;

int* p_Mote;

ifstream fin ("C:/Users/SHERMAL/Desktop/A-large.in");
ofstream fout ("C:/Users/SHERMAL/Desktop/out.txt");

void Init();
void ReadInput();
void Print();
void Process(int iOp);
void QuickSort(int arr[], int left, int right);

int main(int argc, char* argv[])
{
	if (fin.is_open())
	{
		Init();

		fin.close();
	}

	fout.close();

    return 0;
}

int iT = 0;

void Init()
{
	
	fin >> iT;

	iCaseNo = 0;

	
	while ( iT > 0 )
	{
		iT--;
		iCaseNo++;

		ReadInput();

		////////////////////////////////
		QuickSort(p_Mote, 0, i_N-1);

		i = 0;
		Process(0);
		///////////////////////////////////////

		Print();
	}
}

void QuickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

  
	while (i <= j) 
	{
			while (arr[i] < pivot)
				i++;

			while (arr[j] > pivot)
				j--;

			if (i <= j) 
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i++;
				j--;
			}
	}

	if (left < j)
		QuickSort(arr, left, j);
	if (i < right)
        QuickSort(arr, i, right);
}

void Process(int iOp)
{
	if ( i_A == 1 )
	{
		return;
	}

	for ( ; i < i_N; i++ )
	{

		if ( p_Mote[i] < i_A )
		{
			i_A = i_A + p_Mote[i];
		}
		else
		{
			if ( i_Op > (iOp + i_N - i) )
			{
				i_Op = (iOp + i_N - i);
			}

			break;
		}
	}

	

	if ( i < i_N )
	{
		

		i_A = 2 * i_A - 1;
		Process(iOp + 1);
	}
	else
	{
		if ( i_Op > iOp )
		{
			i_Op = iOp;
		}
	}
}

void ReadInput()
{
	fin >> i_A;
	fin >> i_N;

	p_Mote = new int[i_N];
	i_Op = i_N;

	for ( int i = 0; i < i_N; i++ )
	{
		fin >> p_Mote[i];
	}
}



void Print()
{
		fout << "Case #" << iCaseNo << ": " << i_Op << endl;
		delete[] p_Mote;
}


