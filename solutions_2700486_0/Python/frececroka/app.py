#!/usr/bin/python

from math import *

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

def within( stage, x, y ):
	d = abs( x ) + abs( y )
	return d <= ( stage - 1 ) * 2

def binomialCoefficient( n, k ):
	if k < 0 or k > n:
		return 0
	if k > n - k: # take advantage of symmetry
		k = n - k
	c = 1
	for i in range(1,k+1):
		c = c * (n - (k - i))
		c = c // i
	return c

def stage_height( stage ):
	return 2 * ( stage - 1 )

f = open( "B-small.in" )

test_cases = read_integer( f )

for tc in range( test_cases ):
	bounds = read_integer_list( f )

	diamonds = bounds[0]
	x = bounds[1]
	y = bounds[2]

	stages = floor( ( sqrt( 1 + 8 * diamonds ) + 1 ) / 4 )
	overflow = diamonds - stages * ( 2 * stages - 1 )
	
	if within( stages, x, y ):
		# point is within the completely filled triangle
		print( "Case #" + str( tc + 1 ) + ": 1.0" )
	elif within( stages + 1, x, y ) and y != stage_height( stages + 1 ):
		k = y + 1
		p = 0.0

		while k <= overflow:
			p += binomialCoefficient( overflow, k ) * pow( 0.5, overflow )
			k += 1

		print( "Case #" + str( tc + 1 ) + ": " + str( p ) + "" )
	else:
		# point is somewhere else
		print( "Case #" + str( tc + 1 ) + ": 0.0" )