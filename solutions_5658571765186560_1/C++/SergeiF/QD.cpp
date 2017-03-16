#include "QD.h"

bool CQDTaskProcessor::doesNastyOminoExist( int X, int R, int C )
{
	const int W = max( R, C );
	const int H = min( R, C );

	if( (R * C) % X != 0 ) {
		//	can never fill the grid with X-ominoes
		return true;
	}
	if( W < X || H < ( (X + 1) / 2 ) ) {
		//	there's an omino that does not fit
		return true;
	}
	if( X >= 7 ) {
		//	there's an omino with the hole
		return true;
	}

	if( X == 1 ) {
		return false;
	} else if( X == 2 ) {
		return false;	//	area is proprotional to 2, due to checks above; either H or W is prop to 2 => always possible to fill
	} else if( X == 3 ) {
		return false;
	} else if( X == 4 ) {
		if( H == 2 ) {
			return true;
		}
	} else if( X == 5 ) {
		return false;
	} else if( X == 6 ) {
		if( H == 3 ) {
			return true;
		}
	}

	return false;
}

///////////////////////////////////
