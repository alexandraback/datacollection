	# -*- coding: utf-8 -*-
# @Author: zeyuan.shang
# @Date:   2016-05-08 17:01:08
# @Last Modified by:   zeyuan.shang
# @Last Modified time: 2016-05-08 19:25:51
import sys

def solve(J, P, S, K):
	ans = []
	jp, js, ps = {}, {}, {}
	jps = set()
	for j in xrange(1, J + 1):
		for p in xrange(1, P + 1):
			for ss in xrange(1, S + 1):
				s = ss # (j + p - 2 + ss) % S + 1
				if (j, p, s) in jps:
					continue
				elif jp.get((j, p), 0) >= K:
					continue
				elif js.get((j, s), 0) >= K:
					continue
				elif ps.get((p, s), 0) >= K:
					continue
				ans.append((j, p, s))
				jps.add((j, p, s))
				jp[(j, p)] = jp.get((j, p), 0) + 1
				js[(j, s)] = js.get((j, s), 0) + 1
				ps[(p, s)] = ps.get((p, s), 0) + 1

	return ans

if __name__ == "__main__":
	T = input()
	for i in xrange(1, T + 1):
		J, P, S, K = map(int, raw_input().split())
		all_ans = []
		all_ans.append(solve(J, P, S, K))
		all_ans.append(solve(J, S, P, K))
		all_ans.append(solve(P, J, S, K))
		all_ans.append(solve(P, S, J, K))
		all_ans.append(solve(S, P, J, K))
		all_ans.append(solve(S, J, P, K))
		ans = []
		for a in all_ans:
			if len(a) > len(ans):
				ans = a
		print 'Case #{}: {}'.format(i, len(ans))
		for j, p, s in ans:
			print j, p, s