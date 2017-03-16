#!/usr/bin/python

def readline( f ):
	line = f.readline();
	line = line[:-1]
	return line

def read_integer( f ):
	line = readline( f )
	return int( line )

def read_integer_list( f ):
	line = readline( f )
	integers = line.split( " " )

	for i in range( len( integers ) ):
		integers[i] = int( integers[i] )

	return integers

def read_string( f ):
	return readline( f )

def solve( motes, armin_size ):
	motes.sort()

	removals = 0
	min_changes = -1
	armin_size_initial = armin_size

	if armin_size == 1:
		return len( motes )

	while True:
		changes = removals
		armin_size = armin_size_initial

		for m in motes:
			# add a mote while armin is too small to eat any mote
			while( m >= armin_size ):
				armin_size += ( armin_size - 1 )
				changes += 1

			armin_size += m

		if min_changes < 0 or changes < min_changes:
			min_changes = changes

		if len( motes ) == 0:
			break

		# pop last (biggest) mote
		motes.pop()
		removals += 1

	return min_changes

f = open( "A-large.in" )

test_cases = read_integer( f )

for tc in range( test_cases ):
	bounds = read_integer_list( f )
	
	armin_size = bounds[0]

	motes = read_integer_list( f )
	print( "Case #" + str( tc + 1 ) + ": " + str( solve( motes, armin_size ) ) )