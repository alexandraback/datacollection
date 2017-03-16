#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int * start;
int * end;
int *  arrows;


int tester(vector<int> *value, int position){
    int temp;

    for(int count = 0 ; arrows[position] > count ; count++){
	temp	= *(start+ position * 1000 + count);
	value->push_back(temp);
	tester(value, temp);
    }
}

int main(int argc, char **argv){
    ifstream inFile;
    ofstream outFile;

    int count;
    int count2;
    int count3;
    int count4;
    int count5;

    int temp;

    int numberOfDia;
    int numberOfInput;
    int numberOfArrow;

    vector<int> * list;

    vector<int>::iterator it;

    int * histo;
    int * startPointer;
    int numbers[3];

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    if(!inFile.is_open()){
	return EXIT_FAILURE;
    }

    inFile >> numberOfInput;

    start   = new int[1000 * 1000];
    end	    = new int[1000 * 1000];
    arrows  = new int[1000];

    for(count = 0 ; numberOfInput > count; count++){
	memset(start, 0x00, 1000 * 1000 * sizeof(int));
	memset(end, 0x00, 1000 * 1000 * sizeof(int));
	memset(arrows, 0x00, 1000 * sizeof(int));

	inFile >> numberOfDia;

	startPointer	= start;

	for(count2 = 0 ; numberOfDia > count2 ; count2++){
	    inFile >> numberOfArrow;

	    arrows[count2]  = numberOfArrow;

	    for(count3 = 0 ; numberOfArrow > count3 ; count3++){
		inFile >> temp;

		startPointer[count3]	= (temp-1);
	    }

	    startPointer    += 1000;
	}

	for(count2 = 0 ; numberOfDia > count2 ; count2++){
	    if(1 < arrows[count2]){
		list	= new vector<int>[arrows[count2]];
		for(count3 = 0 ; arrows[count2] > count3 ; count3++){
		    (list + count3)->push_back(*(start+count2 * 1000 + count3));
		    tester((list + count3), *(start+count2 * 1000 + count3));
		}
		for(count3 = 0 ; arrows[count2] > count3 ; count3++){
		    sort((list + count3)->begin(), (list + count3)->end());
		}
		for(count3 = 0 ; (arrows[count2] - 1) > count3 ; count3++){
		    for(count4 = 0 ; (list+count3)->size() > count4 ; count4++){
			for(count5 = count3 + 1 ; arrows[count2] > count5 ; count5++){
			    it = find((list+count5)->begin(), (list+count5)->end(), (list+count3)->at(count4));
			    if(it != (list+count5)->end()){
				goto ROOF_END;
			    }
			}
		    }

		}
		delete [] list;

	    }
	}

	if(false){
ROOF_END :
	    outFile << "Case #" << count+1 << ": " << "Yes" << endl;
	}else{
	    outFile << "Case #" << count+1 << ": " << "No" << endl;
	}
    }
    outFile.close();
    inFile.close();

    return EXIT_FAILURE;
}






