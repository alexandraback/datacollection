import sys

f = sys.stdin

def readline():
	l = f.readline().strip()
	return l

class Game:
	def __init__(self, R, C, M):
		self.M = M
		self.R = R
		self.C = C
		self.matrix = []
		self.spot_checked = 0
		self.spot_count = R * C
		row = []
		for i in range(0, C):
			row.append("-")
		for i in range(0, R):
			self.matrix.append(row[:])

	def check_spot(self, x, y):
		if x < 0 or x >= self.C:
			return False
		if y < 0 or y >= self.R:
			return False
		self.spot_checked += 1
		return True

	def set_spot(self, x, y, c):
		if self.check_spot(x, y):
			if self.matrix[y][x] != "-":
				print x, y
				raise Exception("")
			self.matrix[y][x] = c

	def is_mine(self, x, y):
		if x < 0 or x >= self.C:
			return False
		if y < 0 or y >= self.R:
			return False

		return self.matrix[y][x] == "*"

	def is_uncheck(self, x, y):
		if x < 0 or x >= self.C:
			return False
		if y < 0 or y >= self.R:
			return False

		return self.matrix[y][x] == "-"

	def get_nearby(self, x, y):
		points = [(x-1, y-1), (x-1, y), (x-1, y+1),
				  (x, y-1),             (x, y+1),
				  (x+1, y-1), (x+1, y),(x+1, y+1)]

		for x, y in points:
			if x >= 0 and x < self.C and y >= 0 or y < self.R:
				yield x, y
		return

	def get_mines(self, x, y):
		mines = 0

		for x, y in self.get_nearby(x, y):
			if self.is_mine(x, y):
				mines += 1
		
		return mines

	def place_mine(self):
		if self.M == 0:
			return

		if self.M == 1:
			self.set_spot(0, 0,  "*")
			return

		x = 0
		y = 0
		y_span = self.R
		x_span = self.C
		mine_left = self.M

		while (mine_left >= y_span or mine_left >= x_span) and x_span > 1 and y_span > 1:
			if x_span < y_span:
				for i in range(self.C - x_span, self.C):
					self.set_spot(i, self.R - y_span,  "*")
					mine_left -= 1
				y_span -= 1
			else:
				for i in range(self.R - y_span, self.R):
					self.set_spot(self.C - x_span, i, "*")
					mine_left -= 1
				x_span -= 1

		start_x = self.C - x_span
		start_y = self.R - y_span
		x = start_x
		y = start_y

		if mine_left == 0:
			return

		if mine_left == 1:
			self.set_spot(x, y, "*")
			return

		while mine_left > 1:
			mine_left -= 1
			if x_span >= y_span:
				self.set_spot(x, y, "*")
				x += 1
			else:
				self.set_spot(x, y, "*")
				y += 1

		if x + 1 == self.C or y + 1 == self.R or (self.C - x > 2 and self.R - y > 2):
			self.set_spot(x, y, "*")
		else:
			if x_span > y_span:
				if start_x + 1 < self.C and start_y < self.R:
					self.set_spot(start_x + 1, start_y, "*")
				else:
					self.set_spot(x, y, "*")
			else:
				if start_y + 1 < self.R:
					self.set_spot(start_x, start_y + 1, "*")
				else:
					self.set_spot(x, y, "*")

	def walk(self):
		x = 0
		y = 0
		while y < self.R:
			yield x, y
			x += 1
			if x == self.C:
				x = 0
				y += 1
		return 

	def expand(self, x, y):
		for x, y in self.get_nearby(x, y):
			if not self.is_uncheck(x, y):
				continue
			self.set_spot(x, y, ".")
			mines = self.get_mines(x, y)
			if mines == 0:
				self.expand(x, y)

	def click(self):
		x, y, can_expand = self.find_click()
		self.set_spot(x, y, "c")

		if can_expand:
			self.expand(x, y)

		return

	def find_click(self):
		safe_x = -1
		safe_y = -1
		for x, y in self.walk():
			if self.is_mine(x, y):
				continue

			safe_x = x
			safe_y = y
			if self.get_mines(x, y) == 0:
				return x, y, True

		return safe_x, safe_y, False

	def draw(self):
		print
		print
		answer = []
		for row in self.matrix:
			answer.append("".join(row))

		print "\n".join(answer)

	def get_result(self):
		answer = []
		if self.spot_checked < self.spot_count:
			return "Impossible"
		# 	answer.append("Impossible")
		# else:
		# 	return ""


		for row in self.matrix:
			answer.append("".join(row))

		return "\n".join(answer)

def read_game(game_num):
	R, C, M = map(int, readline().split(" "))

	game = Game(R, C, M)
	game.place_mine()
	game.click()
	answer = game.get_result()
	mines = 0
	for x, y in game.walk():
		if game.is_mine(x, y):
			mines += 1

	if mines != M:
		game.draw()
		print R, C, M
		raise Exception("Mine Error")

	print "Case #%d:\n%s" % (game_num, answer)

def main():
	game_count = int(f.readline())
	for i in range(1, game_count + 1):
		read_game(i)

main()