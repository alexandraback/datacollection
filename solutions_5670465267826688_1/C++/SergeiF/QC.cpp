#include "QC.h"

bool CQCTaskProcessor::isPossible( const std::string& str, __int64 X )
{
	assert( X >= 1 );

	//	if there are more than 10 chunks, then there are certainly 4 chunks in a row for
	//	either "i", "j", or "k", and 4 chunks in a row == '1' and can be removed
	X = X % 400;
	while( X > 10 + 4 ) {
		X -= 4;
	}

	const int L = str.length();
	
	std::string leftMultiplications;	//	[i] = str[0]*str[1]...*str[i]
	std::string rightMultiplications;	//	[i] = str[i]*str[i+1]*...*str[L-1]

	std::string leftMultiplicationsReversed;	//	[i] = str[i]*...*str[1]*str[0]
	std::string rightMultiplicationsReversed;	//	[i] = str[L-1]*...*str[i+1]*str[i]

	leftMultiplications.resize( L, ' ' );
	char crntValue = '1';
	for( int i = 0; i < L; i++ ) {
		crntValue = mult( crntValue, str[i] );
		leftMultiplications[i] = crntValue;
	}
	leftMultiplicationsReversed.resize( L, ' ' );
	crntValue = '1';
	for( int i = 0; i < L; i++ ) {
		crntValue = mult( str[i], crntValue );
		leftMultiplicationsReversed[i] = crntValue;
	}

	crntValue = '1';
	rightMultiplications.resize( L, ' ' );
	for( int i = L - 1; i >= 0; i-- ) {
		crntValue = mult( str[i], crntValue );
		rightMultiplications[i] = crntValue;
	}

	crntValue = '1';
	rightMultiplicationsReversed.resize( L, ' ' );
	for( int i = L - 1; i >= 0; i-- ) {
		crntValue = mult( crntValue, str[i] );
		rightMultiplicationsReversed[i] = crntValue;
	}

	assert( leftMultiplications[L - 1] == rightMultiplications[0] );
	assert( leftMultiplicationsReversed[L - 1] == rightMultiplicationsReversed[0] );
	assert( mult( leftMultiplications[L - 1], leftMultiplicationsReversed[L - 1] ) == ( L % 2 == 0 ? '1' : 'M' ) );
	assert( mult( rightMultiplicationsReversed[0], rightMultiplications[0] ) == ( L % 2 == 0 ? '1' : 'M' ) );
	const char chunkMultValue = rightMultiplications[0];

	std::vector<int> iPositions;	//	str[0]*...*str[position] == 'i'
	std::vector<int> kPositions;	//	str[position]*...*str[L * X - 1] == 'k'

	crntValue = '1';
	int index = 0;
	for( int x = 0; x < X * L; x++ ) {
		crntValue = mult( crntValue, str[index] );
		if( crntValue == 'i' ) {
			iPositions.push_back( x );
		}
		index++;
		if( index >= L ) {
			index -= L;
		}
	}

	crntValue = '1';
	index = L - 1;
	for( int x = X * L - 1; x >= 0; x-- ) {
		crntValue = mult( str[index], crntValue );
		if( crntValue == 'k' ) {
			kPositions.push_back( x );
		}
		index--;
		if( index < 0 ) {
			index += L;
		}
	}

	if( iPositions.size() == 0 || kPositions.size() == 0 ) {
		return false;
	}

	for( int i = 0; i < (int)iPositions.size(); i++ ) {
		for( int k = 0; k < (int)kPositions.size(); k++ ) {
			if( iPositions[i] + 1 < kPositions[k] ) {
				char valueInBetween = '1';

				const int leftPos = (iPositions[i] + 1) % L;
				const int rightPos = (kPositions[k] - 1) % L;
				const int leftChunkNumber = (iPositions[i] + 1) / L;
				const int rightChunkNumber = (kPositions[k] - 1) / L;
				if( leftChunkNumber == rightChunkNumber ) {
					assert( leftPos <= rightPos );
					valueInBetween = chunkMultValue;
					if( leftPos > 0 ) {
						valueInBetween = mult( leftMultiplicationsReversed[leftPos - 1], valueInBetween );
						if( leftPos % 2 == 1 ) {
							valueInBetween = mult( valueInBetween, 'M' );	// * -1
						}
					}
					if( rightPos < L - 1 ) {
						valueInBetween = mult( valueInBetween, rightMultiplicationsReversed[rightPos + 1] );
						if( (L - 1 - rightPos) % 2 == 1 ) {
							valueInBetween = mult( valueInBetween, 'M' );	// * -1
						}
					}
				} else {
					const int numberOfChunksInBetween = rightChunkNumber - leftChunkNumber - 1;
					valueInBetween = rightMultiplications[leftPos];
					for( int c = 0; c < numberOfChunksInBetween; c++ ) {
						valueInBetween = mult( valueInBetween, chunkMultValue );
					}
					valueInBetween = mult( valueInBetween, leftMultiplications[rightPos] );
				}

				if( valueInBetween == 'j' ) {
					return true;
				}
			}
		}
	}

	return false;
}

///////////////////////////////////

//	chars may be 'i', 'j', 'k', '1', 
//	or negater values, encoded as 'I', 'J', 'K', 'M'
char CQCTaskProcessor::mult( char a, char b ) const
{
	assert( a == '1' || a == 'i' || a == 'j' || a == 'k' ||
		a == 'M' || a == 'I' || a == 'J' || a == 'K' );
	assert( b == '1' || b == 'i' || b == 'j' || b == 'k' ||
		b == 'M' || b == 'I' || b == 'J' || b == 'K' );

	char modA;
	char modB;
	const int signA = splitSign( a, modA );
	const int signB = splitSign( b, modB );

	char result;
	if( modA == '1' ) {
		result = modB;
	} else if( modB == '1' ) {
		result = modA;
	} else if( modA == 'i' ) {
		if( modB == 'i' ) {
			result = 'M';
		} else if( modB == 'j' ) {
			result = 'k';
		} else if( modB == 'k' ) {
			result = 'J';
		}
	} else if( modA == 'j' ) {
		if( modB == 'i' ) {
			result = 'K';
		} else if( modB == 'j' ) {
			result = 'M';
		} else if( modB == 'k' ) {
			result = 'i';
		}
	} else if( modA == 'k' ) {
		if( modB == 'i' ) {
			result = 'j';
		} else if( modB == 'j' ) {
			result = 'I';
		} else if( modB == 'k' ) {
			result = 'M';
		}
	}

	return addSign( result, signA * signB );
}

int CQCTaskProcessor::splitSign( char a, char& modA ) const
{
	if( a == '1' || a == 'i' || a == 'j' || a == 'k' ) {
		modA = a;
		return 1;
	} else if( a == 'M' ) {
		modA = '1';
		return -1;
	} else if( a == 'I' ) {
		modA = 'i';
		return -1;
	} else if( a == 'J' ) {
		modA = 'j';
		return -1;
	} else if( a == 'K' ) {
		modA = 'k';
		return -1;
	} else {
		assert( false );
	}
	return 1;
}

char CQCTaskProcessor::addSign( char a, int sign ) const
{
	char result;

	if( sign == 1 ) {
		result = a;
		return result;
	}

	if( a == '1' ) {
		result = 'M';
	} else if( a == 'i' ) {
		result = 'I';
	} else if( a == 'j' ) {
		result = 'J';
	} else if( a == 'k' ) {
		result = 'K';
	} else if( a == 'M' ) {
		result = '1';
	} else if( a == 'I' ) {
		result = 'i';
	} else if( a == 'J' ) {
		result = 'j';
	} else if( a == 'K' ) {
		result = 'k';
	} else {
		assert( false );
	}

	return result;
}