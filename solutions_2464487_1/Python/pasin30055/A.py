import math

if __name__ == '__main__':
    tests = int(raw_input().strip())
    for test in xrange(tests):
        r, t = map(int, raw_input().strip().split())
        le = 0
        ri = t + 100
        while le + 1 < ri:
        	mid = (le + ri) / 2
        	# print mid * (2 * r + 2 * mid - 1)
        	if (mid * (2 * r + 2 * mid - 1)) <= t:
        		le = mid
        	else:
        		ri = mid
        print 'Case #' + str(test + 1) + ':', le