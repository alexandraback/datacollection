


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>

using namespace std;

#define c_1 ('1' - '0')
#define c_i ('i' - '0')
#define c_j ('j' - '0')
#define c_k ('k' - '0')

char mulChar_ca[60][60];
int mulSign_ia[602][60];
char mulAnsChar_c;
int mulAnsSign_i;

int main( void )
{
	fstream inputfile_fsp;
	fstream outputfile_fsp;
	
	long tcases_l;
	long noOfChars_l;
	long noOfRepetitions_l;
	long noOfOriginalRepetitions_l;
	string readPattern_sz;
	string fullPattern_sz;
	
	char charBeingSearched_ca[5] = { 'i', 'j', 'k' };
	int charNumber_i = 0;
	
	int ifound_i = 0;
	int jfound_i = 0;
	int kfound_i = 0;
	int RemainsFine_i = 0;
	
	char mulAnsTempChar_c;

	int leftOverFine_i = 0;
	char leftOverChar_c;
	int leftOverSign_i;
	
	memset( mulChar_ca, 0, sizeof(mulChar_ca) );
	memset( mulSign_ia, 0, sizeof(mulSign_ia) );
	
	mulChar_ca[c_1][c_1] = '1';
	mulChar_ca[c_1][c_i] = 'i';
	mulChar_ca[c_1][c_j] = 'j';
	mulChar_ca[c_1][c_k] = 'k';
	mulChar_ca[c_i][c_1] = 'i';
	mulChar_ca[c_i][c_i] = '1'; // -
	mulChar_ca[c_i][c_j] = 'k';
	mulChar_ca[c_i][c_k] = 'j'; // -
	mulChar_ca[c_j][c_1] = 'j';
	mulChar_ca[c_j][c_i] = 'k'; // -
	mulChar_ca[c_j][c_j] = '1'; // -
	mulChar_ca[c_j][c_k] = 'i';
	mulChar_ca[c_k][c_1] = 'k';
	mulChar_ca[c_k][c_i] = 'j';
	mulChar_ca[c_k][c_j] = 'i'; // -
	mulChar_ca[c_k][c_k] = '1'; // -
	
	mulSign_ia[c_1][c_1] = 1;
	mulSign_ia[c_1][c_i] = 1;
	mulSign_ia[c_1][c_j] = 1;
	mulSign_ia[c_1][c_k] = 1;
	mulSign_ia[c_i][c_1] = 1;
	mulSign_ia[c_i][c_i] = -1; // -
	mulSign_ia[c_i][c_j] = 1;
	mulSign_ia[c_i][c_k] = -1; // -
	mulSign_ia[c_j][c_1] = 1;
	mulSign_ia[c_j][c_i] = -1; // -
	mulSign_ia[c_j][c_j] = -1; // -
	mulSign_ia[c_j][c_k] = 1;
	mulSign_ia[c_k][c_1] = 1;
	mulSign_ia[c_k][c_i] = 1;
	mulSign_ia[c_k][c_j] = -1; // -
	mulSign_ia[c_k][c_k] = -1; // -	
	
	
	inputfile_fsp.open( "C-large.in", ios::in );
	outputfile_fsp.open( "C-large.out", ios::out );
	
// 	inputfile_fsp.open( "testinput.in", ios::in );
// 	outputfile_fsp.open( "testoutput.out", ios::out );
	
// 	inputfile_fsp.open( "infile.txt", ios::in );
// 	outputfile_fsp.open( "outfile.txt", ios::out );
	
	inputfile_fsp >> tcases_l;
	
	for( int i = 0; i < tcases_l; i++ )
	{
		inputfile_fsp >> noOfChars_l >> noOfRepetitions_l;
		inputfile_fsp >> readPattern_sz;
		
		fullPattern_sz= "";
		ifound_i = 0;
		jfound_i = 0;
		kfound_i = 0;
		RemainsFine_i = 0;
		leftOverFine_i = 0;
		
		//cout << "Number of chars: " << noOfChars_l << " | Repetitions: " << noOfRepetitions_l << " | readPattern_sz : " << readPattern_sz << endl;
		
		noOfOriginalRepetitions_l = noOfRepetitions_l;
		
		if( noOfRepetitions_l > 12 )
		{
			noOfRepetitions_l = 12;
		}
		else
		{
			// Do nothing
		}
		
		for( long j = 0; j < noOfRepetitions_l; j++ )
		{
			fullPattern_sz = fullPattern_sz + readPattern_sz;
		}
		
		//cout << "Full pattern = " << fullPattern_sz << endl;
		
		long k = 0;
		mulAnsChar_c = fullPattern_sz[k];
		k++;
		
		//cout << "First char from the full pattern : " <<  mulAnsChar_c << endl;
		
		mulAnsSign_i = 1;
		if( mulAnsChar_c == 'i')
		{
			ifound_i = 1;
			
			//cout << "Found i in one shot, k value: " << k <<  endl; // arv test code
		}
		while( (k < (noOfRepetitions_l*noOfChars_l)) && (ifound_i == 0) )
		{
			//cout << "Before Char compute, k value = " << k << endl; // arv test code
			//cout << "Previous char : " << mulAnsChar_c << " | Computed char : " << mulAnsTempChar_c << endl;
			
			mulAnsTempChar_c = mulChar_ca[ mulAnsChar_c-'0' ][ fullPattern_sz[k] - '0' ];
			
			//cout << "After Char compute" << endl; // arv test code
			
			mulAnsSign_i = mulAnsSign_i * mulSign_ia[ mulAnsChar_c-'0' ][ fullPattern_sz[k] - '0' ];
			
			//cout << "After sign compute" << endl; // arv test code
			
			mulAnsChar_c = mulAnsTempChar_c;
		
			if( (mulAnsChar_c == 'i') && (mulAnsSign_i == 1) )
			{
				ifound_i = 1;
				
				//cout << "Found i finally, k value: " << k <<  endl; // arv test code
			}
			k++;
		}
		
		//cout << "Check for i over" << endl << endl; // arv test code
		

		// ***************************** J *****************************
		if( k < (noOfRepetitions_l*noOfChars_l) )
		{
			mulAnsChar_c = fullPattern_sz[k];
			k++;
			mulAnsSign_i = 1;
			if( mulAnsChar_c == 'j')
			{
				jfound_i = 1;
				
				//cout << "Found j in one shot, k value: " << k <<  endl; // arv test code
			}
		}
		else
		{
			cout << "Overflow before j start" << endl;
		}
		while( (k < (noOfRepetitions_l*noOfChars_l)) && (jfound_i == 0) )
		{
		
			mulAnsTempChar_c = mulChar_ca[ mulAnsChar_c-'0' ][ fullPattern_sz[k] - '0' ];
			mulAnsSign_i = mulAnsSign_i * mulSign_ia[ mulAnsChar_c-'0' ][ fullPattern_sz[k] - '0' ];
			
			mulAnsChar_c = mulAnsTempChar_c;
			
			if( (mulAnsChar_c == 'j') && (mulAnsSign_i == 1) )
			{
				jfound_i = 1;
				
				//cout << "Found j finally, k value: " << k <<  endl; // arv test code
			}
			k++;
		}
		
		//cout << "Check for j over" << endl << endl; // arv test code
		
		
		// ***************************** K *****************************
		if( k < (noOfRepetitions_l*noOfChars_l) )
		{
			mulAnsChar_c = fullPattern_sz[k];
			k++;
			mulAnsSign_i = 1;
			if( mulAnsChar_c == 'k')
			{
				kfound_i = 1;
				
				//cout << "Found K in one shot, k index value: " << k <<  endl; // arv test code
			}
		}
		else
		{
			cout << "Overflow before K start" << endl;
		}
		while( (k < (noOfRepetitions_l*noOfChars_l)) && (kfound_i == 0) )
		{
			//cout << "Before Char compute" << endl; // arv test code
			
			mulAnsTempChar_c = mulChar_ca[ mulAnsChar_c-'0' ][ fullPattern_sz[k] - '0' ];
			
			//cout << "After Char compute" << endl; // arv test code
			
			//cout << "Char value: " << mulAnsChar_c << " | Read pattern: " << fullPattern_sz[k] << " | k value: " << k << endl;
			//cout << "Total peak char numbers: " << noOfRepetitions_l*noOfChars_l << endl;
			
			mulAnsSign_i = mulAnsSign_i * mulSign_ia[ mulAnsChar_c-'0' ][ fullPattern_sz[k] - '0' ];
			
			//cout << "After sign compute" << endl; // arv test code
			
			mulAnsChar_c = mulAnsTempChar_c;
			
			if( (mulAnsChar_c == 'k') && (mulAnsSign_i == 1) )
			{
				kfound_i = 1;
				
				//cout << "Found k finally, k value: " << k <<  endl; // arv test code
			}
			k++;
		}
		
		//cout << "Check for k over" << endl << endl; // arv test code
		
		cout << "k value before the remain check, k = " << k << endl;
		

		if( noOfOriginalRepetitions_l > 12 ) 
		{
			long leftOverPatterns_l = (noOfOriginalRepetitions_l - 12)%4;
			string leftOverPattern_sz = "";
			for( int p = 0; p < leftOverPatterns_l; p++ )
			{
				leftOverPattern_sz = leftOverPattern_sz + readPattern_sz;
			}
			int t = 0;
			leftOverChar_c = leftOverPattern_sz[t];
			t++;
			leftOverSign_i = 1;
			
			while( t < (noOfChars_l*leftOverPatterns_l) )
			{
				char leftOverTempChar_c;
				
				leftOverTempChar_c = mulChar_ca[ leftOverChar_c-'0' ][ leftOverPattern_sz[t] - '0' ];
				leftOverSign_i = leftOverSign_i * mulSign_ia[ leftOverChar_c-'0' ][ leftOverPattern_sz[t] - '0' ];
				
				leftOverChar_c = leftOverTempChar_c;
				
				t++;
			}
			if( ( 	(leftOverChar_c == '1') && (leftOverSign_i == 1) ) || 
				(leftOverPatterns_l == 0) )
			{
				leftOverFine_i = 1;
				cout << "Finally left over is fine" << endl;
			}
		}
		else
		{
			cout << "Left over is just fine because < 12" << endl;
			leftOverFine_i = 1;
		}
		
		
		
		if( k == (noOfRepetitions_l*noOfChars_l) )
		{
			RemainsFine_i = 1;
		}
		else
		{
			mulAnsChar_c = fullPattern_sz[k];
			k++;
			mulAnsSign_i = 1;
			
			// Check the reamaining part
			while( (k < (noOfRepetitions_l*noOfChars_l)) )
			{
				char mulAnsTempChar_c;
				
				mulAnsTempChar_c = mulChar_ca[ mulAnsChar_c-'0' ][ fullPattern_sz[k] - '0' ];
				mulAnsSign_i = mulAnsSign_i * mulSign_ia[ mulAnsChar_c-'0' ][ fullPattern_sz[k] - '0' ];
				
				mulAnsChar_c = mulAnsTempChar_c;
				
				k++;
			}
			if( (mulAnsChar_c == '1') && (mulAnsSign_i == 1) )
			{
				RemainsFine_i = 1;
			}
		}
		
		int mulOneMoreSign_i = 1;
		
		if( (leftOverFine_i == 0) && (RemainsFine_i == 0) )
		{
			char mulOneMoreTempChar_c;
			
			mulOneMoreTempChar_c = mulChar_ca[ mulAnsChar_c-'0' ][ leftOverChar_c - '0' ];
			mulOneMoreSign_i = mulAnsSign_i * leftOverSign_i * mulSign_ia[ mulAnsChar_c-'0' ][ leftOverChar_c - '0' ];
			
			char mulOneMoreChar_c = mulOneMoreTempChar_c;
			
			if( (mulOneMoreChar_c == '1') && (mulOneMoreSign_i == 1) )
			{
				RemainsFine_i = 1;
				leftOverFine_i = 1;
				cout << "Both are fine" << endl;
			}
		}
		
		cout << "ifound_i: " << ifound_i << " | jfound_i: " << jfound_i << " | kfound_i: " << kfound_i << " | RemainsFine_i: " << RemainsFine_i << " | leftOverFine_i: " << leftOverFine_i << endl; 
		
		if( (ifound_i == 1) && (jfound_i == 1) && (kfound_i == 1) && (RemainsFine_i == 1) && (leftOverFine_i == 1))
		{
			cout <<  "Case #" << i+1 << ": YES" << endl;
			outputfile_fsp <<  "Case #" << i+1 << ": YES" << endl;
		}
		else
		{
			cout <<  "Case #" << i+1 << ": NO" << endl;
			outputfile_fsp <<  "Case #" << i+1 << ": NO" << endl;
		}
		cout << endl << endl;
	}
}


void fn_multiply( int sign1_i, char c1_c, int sign2_i, char c2_c, int* ansSign_i, char* ansChar_c )
{
	*ansChar_c = mulChar_ca[c1_c - '0'][c2_c - '0'];
	*ansSign_i = mulSign_ia[c1_c - '0'][c2_c - '0'];
}