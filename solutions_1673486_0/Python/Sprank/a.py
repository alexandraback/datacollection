def expected_keystrokes(A, B, ps):
	correct_so_far = [None] * (A + 1)
	correct_so_far[0] = 1
	n = 1
	for p in ps:
		correct_so_far[n] = p * correct_so_far[n - 1]
		n += 1

	best_so_far = 300000
	backtrack = 1
	for _ in xrange(A): # A - 1 should work.
		good = correct_so_far[A - backtrack]
		bad = 1 - good
		current = good * (backtrack + B - A + backtrack + 1) + bad * (backtrack + B - A + backtrack + 1 + B + 1)
		backtrack += 1
		best_so_far = min((current, best_so_far))

	lache_pas_la_patate = correct_so_far[A] * (B - A + 1) + (1 - correct_so_far[A]) * (B - A + 1 + B + 1)
	give_up = B + 2
	return min((lache_pas_la_patate, best_so_far, give_up))

T = int(raw_input())
for x in xrange(1, T + 1):
	[A, B] = map(int, raw_input().split(' '))
	ps = map(float, raw_input().split(' '))
	y = expected_keystrokes(A, B, ps)
	print("Case #%d: %f" % (x, y))
