class Attack:
	def __init__(self, day, strength, west, east):
		self.day = day
		self.strength = strength
		self.west = west
		self.east = east
	def __str__(self):
		return '%d: %d, [%d, %d]' % (self.day, self.strength, self.west, self.east)

def parse_attacks(tribes):
	attacks = []
	for t in tribes:
		day, n, west, east, strength, d_days, d_east, d_strength = map(int, t.split())
		for i in range(n):
			attacks.append(Attack(day, strength, west, east))
			day += d_days
			strength += d_strength
			west += d_east
			east += d_east
	attacks.sort(key = lambda a: a.day)
	return attacks

def successful_attacks(attacks):
	successes = 0
	for attack in attacks:
		ranges = [(attack.west, attack.east)]
		prior_attacks = filter(lambda a: a.day < attack.day and a.strength >= attack.strength, attacks)
		for p in prior_attacks:
			new_ranges = []
			for r in ranges:
				w, e = r
				if p.east < w or p.west > e:
					new_ranges.append(r)
				elif p.west < w and p.east < e:
					new_ranges.append((p.east, e))
				elif p.west > w and p.east > e:
					new_ranges.append((w, p.west))
				elif p.west > w and p.east < e:
					new_ranges.append((w, p.west))
					new_ranges.append((p.east, e))
			ranges = new_ranges
		if len(ranges) > 0:
			successes += 1
	return successes

cases = int(raw_input())
for case in range(cases):
	tribes = []
	for i in range(int(raw_input())):
		tribes.append(raw_input())
	attacks = parse_attacks(tribes)
	successes = successful_attacks(attacks)
	print 'Case #%d: %d' % (case + 1, successes)
