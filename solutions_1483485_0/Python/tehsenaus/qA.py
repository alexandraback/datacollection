
from jammly import Jam as BaseJam
import math

TEST = \
"""3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""

class Jam(BaseJam):
	r"""
	>>> Jam().runTest(TEST)
	Case #1: our language is impossible to understand
	Case #2: there are twenty six factorial possibilities
	Case #3: so it is okay if you want to just give up
	"""
	
	INITIAL = \
		"""a zooq
		ejp mysljylc kd kxveddknmc re jsicpdrysi
		rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
		de kr kd eoya kw aej tysr re ujdr lkgc jv"""
	PLAIN = \
		"""y qeez
		our language is impossible to understand
		there are twenty six factorial possibilities
		so it is okay if you want to just give up"""
	
	
	def jam(self, line):

		kb = dict(zip(self.INITIAL, self.PLAIN))

		return "".join(map(lambda c: kb[c], line))
	


if __name__ == "__main__":
	Jam.start()
