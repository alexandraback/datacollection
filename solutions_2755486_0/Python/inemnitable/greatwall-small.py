from collections import defaultdict

t = int(raw_input())
for case in xrange(t):
	num_tribes = int(raw_input())
	tribes = []
	for i in xrange(num_tribes):
		tribes.append([int(x) for x in raw_input().split()])
	wall = defaultdict(lambda: 0)
	day = 0
	days = max(tribe[0] + (tribe[1]-1) * tribe[5] for tribe in tribes)
	successful_attacks = 0
	while day <= days:
		attack_queue = []
		for tribe in tribes:
			if tribe[0] == day:
				attack_queue.append(tribe[2:5])
				tribe[1] -= 1
				if tribe[1] > 0:
					tribe[0] += tribe[5]
					tribe[2] += tribe[6]
					tribe[3] += tribe[6]
					tribe[4] += tribe[7]
		wall_queue = defaultdict(lambda: 0)
		for attack in attack_queue:
			success = False
			for x in xrange(attack[0], attack[1]):
				if attack[2] > wall[x]:
					success = True
					wall_queue[x] = max(wall_queue[x], attack[2])
			if success:
				successful_attacks += 1
			#print "day %i pos %i-%i wall %i height %i" % (day, attack[0], attack[1], wall[attack[0]], attack[2])
		for k, v in wall_queue.iteritems():
			wall[k] = v
		day += 1
	print "Case #%i: %i" % (case + 1, successful_attacks)
