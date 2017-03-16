from cjlib.input import *
from cjlib.runner import TaskRunner, DummyRunner, MPQRunner
import logging

logging.basicConfig(level=logging.DEBUG)

class Tribe:
	def __init__(self, p, id):
		self.id = id
		self.first = p[0]
		self.no = p[1]
		self.range = [p[2], p[3]]
		self.strength = p[4]
		self.next = p[5]
		self.next_d = p[6]
		self.next_s = p[7]
	def __iter__(self):
		day = self.first
		dist = self.range
		s = self.strength
		for cnt in range(self.no):
			yield {
				'r': dist,
				's': s,
				'd': day
			}
			day += self.next
			dist = [x + self.next_d for x in dist]
			s += self.next_s
	def atk_day(self, day):
		if day < self.first:
			return False
		if (day - self.first)%self.next != 0:
			#print "Tribe %d: Left %d days"%(self.id, (day - self.first)%self.next)
			return False
		attackCnt = (day - self.first)/self.next
		if attackCnt+1 > self.no:
			return False
		return {
			'r': [x + (self.next_d*attackCnt) for x in self.range],
			's': self.strength + (self.next_s * attackCnt),
			'd': day
		}
	def last_attack(self):
		return self.first + (self.next*(self.no-1))
	def min_x(self):
		return min(self.range[0], self.range[0] + (self.next_d*(self.no-1)))
	def max_x(self):
		return max(self.range[1], self.range[1] + (self.next_d*(self.no-1)))

class Wall:
	def __init__(self, mn, mx):
		self.wall = [0]*(mx-mn+1)
		self.start = mn
		self.q = []
	def pos(self, x):
		# start -5 req -3
		return self.wall[x - self.start]
	def set(self, x, v):
		self.wall[x-self.start] = v
	def queue_rebuild(self, r, s):
		self.q.append([r, s])
	def do_rebuild(self):
		for x in self.q:
			for r in range(x[0][0], x[0][1]):
				if self.pos(r) < x[1]:
					self.set(r, x[1])
			#print "rebuild ", x
		#print "wall now ", self.wall
		self.q = []

def process(case):
	case = [[int(y) for y in x.split(" ")] for x in case]
	tribes = []
	last_atk = 0
	min_wall = 9999999999999
	max_wall = -999999999999
	for i,x in enumerate(case):
		t = Tribe(x, i+1)
		tribes.append(t)
		last_atk = max(t.last_attack(), last_atk)
		min_wall = min(t.min_x(), min_wall)
		max_wall = max(t.max_x(), max_wall)
	wall = Wall(min_wall, max_wall)
	atk_suc = 0
	for day in range(last_atk+1):
		for t in tribes:
			atk = t.atk_day(day)
			if atk:
				#print "D%d: Tribe %d attacking %s strength %d"%(day, t.id, atk['r'], atk['s'])
				for x in range(atk['r'][0], atk['r'][1]):
					if wall.pos(x) < atk['s']:
						#print "D%d: Tribe %d broke height %d pos %d stength %d"%(day, t.id, wall.pos(x), x, atk['s'])
						atk_suc += 1
						wall.queue_rebuild(atk['r'], atk['s'])
						break
		#print "="*60
		wall.do_rebuild()
	return atk_suc

get("""2
2
0 3 0 2 10 2 3 -2
10 3 2 3 8 7 2 0
3
1 1 0 5 10 2 8 0
0 3 0 1 7 1 2 2
3 3 0 5 1 1 4 0""")

r = TaskRunner(process, MPQRunner, processCnt=8)
#r = TaskRunner(process, DummyRunner)

while neof():
	r.add(block())

r.run(True)