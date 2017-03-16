import sys

T = int(sys.stdin.readline().strip())

source = '''
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
'''

target = '''
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
'''

def build_map():
	source_lines = source.strip().split('\n')
	target_lines = target.strip().split('\n')
	charmap = {' ': ' '}
	for i in range(len(source_lines)):
		for j in range(len(source_lines[i])):
			charmap[source_lines[i][j]] = target_lines[i][j]
	
	missing = ''
	for c in list('abcdefghijklmnopqrstuvwxyz'):
		if c not in charmap:
			missing = c
			break
	charmap['z'] = missing
	charmap[missing] = 'z'

	return charmap

charmap = build_map()
#for k in sorted(charmap):
#	print(k, charmap[k])

def translate(line):
	translated = []
	for c in line:
		translated.append(charmap[c])
	return ''.join(translated)

for t in range(T):
	line = sys.stdin.readline().strip()
	print('Case #{0}: {1}'.format(t + 1, translate(line)))
