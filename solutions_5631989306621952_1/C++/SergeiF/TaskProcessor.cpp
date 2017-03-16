#include "TaskProcessor.h"

std::string CTaskProcessor::findLastWord( const std::string& str )
{
	const int len = str.length();
	assert( len > 0 );

	std::string result = "";
	result = result + str[0];
	char maxChar = str[0];
	for( int i = 1; i < len; i++ ) {
		if( str[i] >= maxChar ) {
			maxChar = str[i];
			result = str[i] + result;
		} else {
			result = result + str[i];
		}
	}

	return result;
}
