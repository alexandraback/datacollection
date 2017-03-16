#!/usr/bin/env python3

def quaternion_mul(a, b):
	if a[1] == "1":
		options = {"1": "+1", "i": "+i", "j": "+j", "k": "+k"} 
	elif a[1] == "i":
		options = {"1": "+i", "i": "-1", "j": "+k", "k": "-j"} 
	elif a[1] == "j":
		options = {"1": "+j", "i": "-k", "j": "-1", "k": "+i"} 
	elif a[1] == "k":
		options = {"1": "+k", "i": "+j", "j": "-i", "k": "-1"} 
	
	r = options[b[1]]
	if a[0] != b[0]:
		if r[0] == "+":
			r = "-" + r[1]
		else:
			r = "+" + r[1]
	return r

for case in range(int(input())):
	l, x = [int(i) for i in input().split()]
	s = [ ("+" + i) for i in input().strip()]

	# possible i * j * k must be -1
	r = "+1"
	for c in s * (x % 4):
		r = quaternion_mul(r, c)
	if r != "-1":
		ans = "NO"
	else:	
		# extend s to include its period
		# 4 repeats equal +1
		# offset 1 period for overlapping at the crossing point
		if x < 4:
			extended_s = s * (x % 4)
		else:
			extended_s = s * (4 + (x % 4))	
		# can be i
		i_stop = -1
		r = "+1"
		for i in range(len(extended_s)):
			r = quaternion_mul(r, extended_s[i])
			if r == "+i":
				i_stop = i
				break
		# not found +i
		if i_stop == -1:
			ans = "NO"
		else:
			# can be k
			k_start = len(extended_s) + 1
			r = "+1"
			for k in range(len(extended_s) - 1, 0, -1):
				r = quaternion_mul(extended_s[k], r)
				if r == "+k":
					k_start = k
					break
			# not found +k
			if k_start == len(extended_s) + 1:
				ans = "NO"
			else:
				# others can be +j because our first r condition results in -1
				exact_k_start = k_start + ((x * l) - len(extended_s))
				if i_stop < exact_k_start:
					ans = "YES"
				else:
					ans = "NO"
	print('Case #{}: {}'.format(case + 1, ans))
