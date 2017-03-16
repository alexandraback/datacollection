def solve(cur, pos, motes):
	if pos == len(motes):
		return 0
	elif cur > motes[pos]:
		return solve(cur+motes[pos], pos+1, motes)
	elif cur > 1:
		to_grow, new_cur = 0, cur
		while new_cur <= motes[pos]:
			new_cur += new_cur-1
			to_grow += 1

		c1 = to_grow + solve(new_cur+motes[pos], pos+1, motes)
		c2 = len(motes) - pos
		return min(c1, c2)
	else:
		return len(motes)-pos

if __name__ == '__main__':
	T = input()

	for t in range(1, T+1):
		cur, _ = map(int, raw_input().split())
		motes = sorted(map(int, raw_input().split()))

		print 'Case #%d: %d' % (t, solve(cur, 0, motes))
