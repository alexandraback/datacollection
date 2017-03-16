import math
class Vec2d:
	def __init__(self, *args):
		if len(args) == 2:
			x, y = args
		elif len(args) == 1:
			x, y = args[0]
		self.x = x + 0.
		self.y = y + 0.
	def __add__(self, v):
		return Vec2d(self.x + v.x, self.y + v.y)

	def __sub__(self, v):
		return Vec2d(self.x - v.x, self.y - v.y)

	def dot(self, v):
		return self.x * v.x + self.y * v.y

	def kdot(self, t):
		return Vec2d(t*self.x, t*self.y)

	def __repr__(self):
		return '(%.2f,%.2f)' % (self.x, self.y)

	def length(self):
		return (self.x ** 2 + self.y ** 2) ** 0.5

	def __mul__(self, v):
		if isinstance(v, Vec2d):
			return self.dot(v)
		else:
			return self.kdot(v)

	def __rmul__(self, v):
		if isinstance(v, Vec2d):
			return self.dot(v)
		else:
			return self.kdot(v)

	def __hash__(self):
		return int(math.atan2(self.y, self.x) * 1000000)

	def normalized(self):
		l = self.length()
		if l > 1e-8:
			return self.kdot(1/l)
		else:
			return Vec2d(0, 0)

	def __eq__(self, v):
		return (self - v).length() < 1e-8

	def perp(self):
		return Vec2d(-self.y, self.x)

