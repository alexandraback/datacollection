#!/usr/bin/env python

from collections import defaultdict

def main():
	f = open('input.txt', 'r')



	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		N = int(f.readline().rstrip('\n'))
		tribes = []
		for x in xrange(0, N):
			tribes.append(Tribe(f.readline()))

		gfw = Wall()

		while True:
			today = next_attack_day(tribes)
			# print today
			today_tribes = who_will_attack_today(today, tribes)
			for t in today_tribes:
				gfw.record_attack(t.attack())
			gfw.fix_wall()
			if all([t.next_attack_day is None for t in tribes]):
				break

		print 'Case #{}: {}'.format(T, gfw.success_attack)

def who_will_attack_today(today, tribes):
	return [t for t in tribes if t.next_attack_day == today]

def next_attack_day(tribes):
	return min([t.next_attack_day for t in tribes if t.next_attack_day is not None])

class Wall(object):
	def __init__(self):
		super(Wall, self).__init__()
		self.wall = defaultdict(int)
		self.success_attack = 0

		self.today_attacks = []

	def record_attack(self, one_attack):
		self.today_attacks.append(one_attack)

	def fix_wall(self):
		# print self.today_attacks
		self.success_attack += count_success(self.wall, self.today_attacks)
		for attack in self.today_attacks:
			for w in xrange(attack[0], attack[1]):
				if self.wall[w+0.5] < attack[2]:
					self.wall[w+0.5] = attack[2]
		# print self.wall
		self.today_attacks = []
		
def count_success(wall, attacks):
	count = 0
	for attack in attacks:
		if any([wall[w+0.5] < attack[2] for w in xrange(attack[0], attack[1])]):
			count += 1
	return count

class Tribe(object):
	def __init__(self, arg):
		super(Tribe, self).__init__()
		self.arg = arg
		numbers = map(int, arg.rstrip('\n').split())
		self.d = numbers[0]
		self.n = numbers[1]
		self.w = numbers[2]
		self.e = numbers[3]
		self.s = numbers[4]
		self.delta_d = numbers[5]
		self.delta_p = numbers[6]
		self.delta_s = numbers[7]

		self.count_attacked = 0
		self.next_attack_day = self.d

	def attack(self):
		
		# today's attack status
		ret = (self.w, self.e, self.s)

		self.count_attacked += 1
		if self.count_attacked != self.n:
			self.next_attack_day += self.delta_d
		else:
			self.next_attack_day = None
		self.w += self.delta_p
		self.e += self.delta_p
		self.s += self.delta_s

		return ret
		


if __name__ == '__main__':
	main()