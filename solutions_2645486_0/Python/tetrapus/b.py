import sys
data = open(sys.argv[1]).read().split("\n")

cases = int(data.pop(0))
for case in range(cases):
	print "Case #%d:" % (case + 1),
	energy, regain, activities = map(int, data.pop(0).split())
	values =  map(int, data.pop(0).split())
	values = sorted(values)
	# We can spend a maximum of E energy per activity, but we have E + (r-1)*activities to spend.
	# Spend r on all activities, because we can do that.
	answer = sum(i*regain for i in values)
	# Then we spend the rest on the most valuable activity.
	answer += (energy - regain) * values[-1]
	print answer