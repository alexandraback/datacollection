#-*- coding: UTF-8 -*-
import sys
from collections import Counter

temp = ("NINE")

case = int(raw_input())

for CASE in xrange(1, case+1):
	
	print "Case #{}:".format(CASE),

	inp = raw_input()
	cnt = Counter(inp)

	zero = cnt['Z']

	cnt['Z'] -= zero
	cnt['E'] -= zero
	cnt['R'] -= zero
	cnt['O'] -= zero

	six = cnt['X']

	cnt['S'] -= six
	cnt['I'] -= six
	cnt['X'] -= six

	eight = cnt['G']

	cnt['E'] -= eight
	cnt['I'] -= eight
	cnt['G'] -= eight
	cnt['H'] -= eight
	cnt['T'] -= eight

	three = cnt['H']

	cnt['T'] -= three
	cnt['H'] -= three
	cnt['R'] -= three
	cnt['E'] -= three * 2

	two = cnt['W']

	cnt['T'] -= two
	cnt['W'] -= two
	cnt['O'] -= two

	four = cnt['R']

	cnt['F'] -= four
	cnt['O'] -= four
	cnt['U'] -= four
	cnt['R'] -= four

	five = cnt['F']

	cnt['F'] -= five
	cnt['I'] -= five
	cnt['V'] -= five
	cnt['E'] -= five

	seven = cnt['V']

	cnt['S'] -= seven
	cnt['E'] -= seven * 2
	cnt['V'] -= seven
	cnt['N'] -= seven

	one = cnt['O']

	cnt['O'] -= one
	cnt['N'] -= one
	cnt['E'] -= one

	nine = cnt['E']

	ans = '0' * zero + '1' * one + '2' * two + '3' * three + '4' * four + '5' * five + '6' * six + '7' * seven + '8' * eight + '9' * nine
	print ans