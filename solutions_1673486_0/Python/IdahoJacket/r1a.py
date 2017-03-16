import sys

numCases = input()
for case in range( 1, numCases + 1 ):
	(typed, total ) = raw_input().split();
	typed = int(typed)
	total = int(total)
	pctStrs = raw_input().split()
	pcts = []
	for num in pctStrs:
		pcts.append( float( num ) )

	finish = [];
	finish.append( pcts[0] );

	for i in range( 1, typed ):
		finish.append( pcts[i] * finish[i-1] )

	remaining = total - typed

	enter = total + 2

	odds = []
	odds.append( enter )

	for i in range( 0, typed ):
		ifCorrect = finish[ typed - i - 1 ] * ( i + i + remaining + 1 )
		ifWrong = ( 1 - finish[ typed - i - 1 ]) * ( i + i + remaining + 1 + total + 1 );
		odds.append( ifCorrect + ifWrong )

	odds.sort()


	print 'Case #' + str( case ) + ': ' + str( odds[0] )
