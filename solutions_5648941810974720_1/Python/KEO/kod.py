#-*- coding: UTF-8 -*-
from collections import Counter

import sys
temp = ("NINE")

case = int(raw_input())
for t in xrange(1, case+1):
	print "Case #{}:".format(t),

	text = raw_input()
	counter = Counter(text)

	zero = counter['Z']

	counter['Z'] -= zero
	counter['E'] -= zero
	counter['R'] -= zero
	counter['O'] -= zero

	six = counter['X']

	counter['S'] -= six
	counter['I'] -= six
	counter['X'] -= six

	eight = counter['G']

	counter['E'] -= eight
	counter['I'] -= eight
	counter['G'] -= eight
	counter['H'] -= eight
	counter['T'] -= eight

	three = counter['H']

	counter['T'] -= three
	counter['H'] -= three
	counter['R'] -= three
	counter['E'] -= three * 2

	two = counter['W']

	counter['T'] -= two
	counter['W'] -= two
	counter['O'] -= two

	four = counter['R']

	counter['F'] -= four
	counter['O'] -= four
	counter['U'] -= four
	counter['R'] -= four

	five = counter['F']

	counter['F'] -= five
	counter['I'] -= five
	counter['V'] -= five
	counter['E'] -= five

	seven = counter['V']

	counter['S'] -= seven
	counter['E'] -= seven * 2
	counter['V'] -= seven
	counter['N'] -= seven

	one = counter['O']

	counter['O'] -= one
	counter['N'] -= one
	counter['E'] -= one

	nine = counter['E']

	ans = '0' * zero + '1' * one + '2' * two + '3' * three + '4' * four + '5' * five + '6' * six + '7' * seven + '8' * eight + '9' * nine
	print ans
