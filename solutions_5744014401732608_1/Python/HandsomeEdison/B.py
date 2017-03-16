	# -*- coding: utf-8 -*-
# @Author: zeyuan.shang
# @Date:   2016-05-08 17:01:08
# @Last Modified by:   zeyuan.shang
# @Last Modified time: 2016-05-08 18:00:08
import sys

if __name__ == "__main__":
	T = input()
	for i in xrange(1, T + 1):
		B, M = map(int, raw_input().split())
		N = 2 ** (B - 2)
		if M > N:
			print 'Case #{}: IMPOSSIBLE'.format(i)
		else:
			print 'Case #{}: POSSIBLE'.format(i)
			res, index = M, 0
			ans = []
			if M == N:
				ans.append(B - 1)
				res -= 1
			while res > 0:
				if res % 2 > 0:
					ans.append(B - 2 - index)
				res /= 2
				index += 1

			for j in xrange(B):
				if j in ans:
					sys.stdout.write('1') 
				else:
					sys.stdout.write('0')
			sys.stdout.write('\n')
			for j in xrange(1, B - 1):
				for k in xrange(0, B):
					if j >= k:
						sys.stdout.write('0')
					else:
						sys.stdout.write('1')
				sys.stdout.write('\n')
			for j in xrange(0, B):
				sys.stdout.write('0')
			sys.stdout.write('\n')