#!/usr/bin/bash

# This is a self compiling file
# Run with `cat file.in | ./$filename [debug|plot] > file.out`

# debug - Show a progress bar and stuff
# plot - Stream performance information to gnuplot

filename=$(echo $0 | sed 's:./::g')
flags="-xc++ -std=gnu++11 -Ofast"
debug="cat"
if [ $filename -nt .$filename ] || [ "$1" != "" ]; then
	if [ "$1" == "debug" ]; then
		debug="sed '1i\#define DEBUG\n#include \"debug.cpp\"'"
		flags="$flags -g"
	elif [ "$1" == "plot" ]; then
		debug="sed '1i\#define DEBUG\n#define DEBUG_PLOT\n#include \"debug.cpp\"'"
		flags="$flags -g"
	fi
	sed -n '/^#include <cstdlib>/,$p' $filename | eval $debug | g++ -o .$filename $flags -
	result=$?
	if [ $result -ne 0 ]; then
		exit $result
	fi
fi

if [ "$1" == "plot" ]; then
	eval ./.$filename 2> >(./stream_plot.py >> /dev/null 2>&1)
	exit $?
fi
exec ./.$filename


#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cstdint>

#include <iostream>
#include <string>
#include <sstream>

#include <map>
#include <vector>
#include <algorithm>
#include <list>


using namespace std;

int main(int argc, char ** argv)
{
	// number of cases
	#ifdef DEBUG
	debug_init(argc, argv);
	#endif //DEBUG
	
	uint nCases;
	cin >> nCases;
	// do cases
	for (uint c = 1; c <= nCases; ++c)
	{
		// get stuff
		
		
		
		uint A; uint N;
		cin >> A; cin >> N;
		
		
		list<uint> motes;
		
		for (uint i = 0; i < N; ++i)
		{
			uint Si;
			cin >> Si;
			if (Si >= A)
			{		
				motes.push_back(Si);
				//cerr << "Can't absorb " << Si << "; now have ("<<A<<") vs "; debug_printlist(motes); cerr << "\n";
			}
			else
			{
				A += Si;
				//cerr << "Preabsorb " << Si << "; now have ("<<A<<") vs "; debug_printlist(motes); cerr << "\n";
			}
		}
		
		//cerr << "START: ("<<A<<") vs "; debug_printlist(motes); cerr << "\n";
		
		uint operations = 0;
		
		uint initial_size = motes.size();
		
		while (motes.size() > 0 && operations < initial_size)
		{
			//cerr << "LOOP #" << operations << ": ("<<A<<") vs "; debug_printlist(motes); cerr << "\n";
			if (A == 1)
			{
				operations = motes.size();
				break;
			}
		
			bool absorbed = false;
			do
			{
				absorbed = false;
				// go through list, absorbing motes
				list<uint>::iterator m = motes.begin();
				while (m != motes.end())
				{
					if (*m < A)
					{
						//cerr << "Absorb " << *m;
						A += *m;
						m = motes.erase(m);
						absorbed = true;
						//cerr << ": ("<<A<<") vs "; debug_printlist(motes); cerr << "\n";
					}
					else
					{
						++m;	
					}
				}
			}
			while (absorbed);
			
			
			if (motes.size() == 1)
			{
				//cerr << "Operation #" << operations+1 << ": Erase " << motes.back() << "\n";
				motes.erase(motes.begin());
				operations += 1;
				
				break;
			}
			
			if (motes.size() > 0)
			{
				//cerr << "Operation #" << operations+1 << ": Add " << A-1 << "\n";
				A += A-1;
				operations += 1;
			}

		}
		
		//cerr << "END: ("<<A<<") vs "; debug_printlist(motes); cerr << "\n";
		//cerr << "Took " << operations << " operations\n";
		
		#ifdef DEBUG_PLOT
		debug_time(c);
		#elif defined DEBUG
		//debug_progress(c, nCases);
		#endif //DEBUG_PLOT
		cout << "Case #" << c << ": " << operations << "\n";
	}
	
	#ifdef DEBUG
	debug_finish();
	#endif //DEBUG
	return 0;	
}