#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve(x):
	x.sort(reverse=True)
	m = r = x[0] # MAX
	for v in range(1, m+1): #v=仮の最大値（全値をv以下にするために必要なステップ数を算出したい）
		s = 0
		for z in x:
			if z <= v: # すでに最大値以下の値は無視
				break
			# zをv以下にするために必要なステップ数を算出し
			# 総合ステップ数へ加算
			s += z / v
			if z % v == 0:
				s -= 1
		if s + v < r: #総合ステップ数 + 仮の最大値 = 朝食を終らせれる時間
			r = s + v
	return r

for i in range(int(raw_input())):
	a = raw_input()
	b = raw_input().split()
	x = []
	for n in b:
		x.append(int(n))
	print 'Case #' + str(i+1) + ": " + str(solve(x))
