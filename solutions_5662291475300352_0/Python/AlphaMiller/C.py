from __future__ import print_function
import sys
import itertools

def solve():
	# parse input
	N = int(raw_input())
	groups = list(map(int, raw_input().split()) for i in range(N))
	hikers = []
	for group in groups:
		for i in range(group[1]):
			hikers.append([group[0], group[2] + i])
	print(hikers, file=sys.stderr)
	# solve
	smallest_position = min(map(lambda x:x[0], hikers))
	smallest_rpm_speed = 1.0/max(map(lambda x:x[1], filter(lambda x:x[0]==smallest_position, hikers)))
	largest_position = max(map(lambda x:x[0], hikers))
	largest_rpm_speed = 1.0/min(map(lambda x:x[1], filter(lambda x:x[0]==largest_position, hikers)))
	print(smallest_position, smallest_rpm_speed, largest_position, largest_rpm_speed, file=sys.stderr)
	if (360-smallest_position)/360.0/smallest_rpm_speed >= (720-largest_position)/360.0/largest_rpm_speed:
		return 1
	if (360-largest_position)/360.0/largest_rpm_speed >= (720-smallest_position)/360.0/smallest_rpm_speed:
		return 1
	return 0

T = int(raw_input())
for case in xrange(T):
	print(case, file=sys.stderr)
	print("Case #%d: %s"%(case+1, solve()))
