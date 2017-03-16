#!/usr/bin/env python3

def solve(N):
	letters = [0] * 26
	result = ''
	for letter in N:
		letters[ord(letter) - 65] += 1

	count = letters[ord('G') - 65]
	result += '8' * count
	for letter in "EIGHT":
		letters[ord(letter) - 65] -= count

	count = letters[ord('U') - 65]
	result += '4' * count
	for letter in "FOUR":
		letters[ord(letter) - 65] -= count

	count = letters[ord('W') - 65]
	result += '2' * count
	for letter in "TWO":
		letters[ord(letter) - 65] -= count

	count = letters[ord('X') - 65]
	result += '6' * count
	for letter in "SIX":
		letters[ord(letter) - 65] -= count
	
	count = letters[ord('Z') - 65]
	result += '0' * count
	for letter in "ZERO":
		letters[ord(letter) - 65] -= count
	
	count = letters[ord('F') - 65]
	result += '5' * count
	for letter in "FIVE":
		letters[ord(letter) - 65] -= count
	
	count = letters[ord('H') - 65]
	result += '3' * count
	for letter in "THREE":
		letters[ord(letter) - 65] -= count
	
	count = letters[ord('O') - 65]
	result += '1' * count
	for letter in "ONE":
		letters[ord(letter) - 65] -= count

	count = letters[ord('S') - 65]
	result += '7' * count
	for letter in "SEVEN":
		letters[ord(letter) - 65] -= count
	
	count = letters[ord('I') - 65]
	result += '9' * count
	for letter in "NINE":
		letters[ord(letter) - 65] -= count
	
	return ''.join(sorted(result))
	

for case in range(1, int(input()) + 1):
	print('Case #', case, ': ', solve(input()), sep = '')