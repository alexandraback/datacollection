#! /usr/bin/env python3
'''
' Title:	
' Author:	Cheng-Shih, Wong
' Date:		
'''

t = int(input())

for ti in range(1,t+1):
	s = input()
	ans = s[0]

	for c in s[1:]:
		if ord(c)>=ord(ans[0]):
			ans = c+ans
		else:
			ans = ans+c
		
	print( 'Case #{0}: {1}'.format(ti,ans) )
