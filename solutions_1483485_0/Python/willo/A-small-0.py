from operator import itemgetter, attrgetter
import itertools
import os, logging

FILE = 'A-small-0'

def runner():
	#path = os.path.join(os.path.dirname(__file__), 'input', '%s.in' % FILE)
	path = os.path.join(os.path.dirname(__file__), '%s.in' % FILE)
	f = open(path, 'r')
	
	path = os.path.join(os.path.dirname(__file__), '%s.out' % FILE)
	r = open(path, 'w')
	
	for n, test_case in enumerate(f.readlines()[1:]):
#		if n % 2 == 1:

		result = encode(test_case.strip())

#		if result == None: result = 'NO'
		s = 'Case #%r: %s\n' % (n + 1, result)
		print s
		r.write(s)
	
	f.close()
	r.close()
	

def unencode(l):
    for t in l:
        for n, c in enumerate(t[0]):
            if c != ' ':
                MAP[t[1][n]] = c

#MAP = {}
#unencode([('ejp mysljylc kd kxveddknmc re jsicpdrysi', 'our language is impossible to understand'), ('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', 'there are twenty six factorial possibilities'), ('de kr kd eoya kw aej tysr re ujdr lkgc jv', 'so it is okay if you want to just give up'), ('y qee', 'a zoo')])

MAP = {'a': 'y', 'c': 'f', 'b': 'n', 'e': 'c', 'd': 'i', 'g': 'l', 'f': 'w', 'i': 'k', 'h': 'b', 'k': 'o', 'j': 'u', 'm': 'x', 'l': 'm', 'o': 'e', 'n': 's', 'p': 'v', 's': 'd', 'r': 'p', 'u': 'j', 't': 'r', 'w': 't', 'v': 'g', 'y': 'a', 'x': 'h', 'z': 'q'}
MAP['q'] = 'z'
MAP[' '] = ' '

UNMAP = {v: k for k, v in MAP.items()}

def encode(s):
    '''
    >>> encode('a zoo')
    'y qee'
    '''
    r = ''
    for c in s:
        r += UNMAP[c]

    return r


    

if __name__ == "__main__":
	#import doctest
	#doctest.testmod()
	runner()

