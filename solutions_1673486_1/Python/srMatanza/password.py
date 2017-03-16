import sys

# Optimization: we know we will never have to backspace more than A/2 chars (easier to just delete all then).

def main():
	fIn = sys.argv[1]

	with open(fIn, 'r') as f:
		T = int(f.readline())

		for t in range(0,T):
			(A,B) = [int(x) for x in f.readline().strip().split(' ')]
			L = [float(x) for x in f.readline().strip().split(' ')]

			m = 2+B # Min is enter plus the length of the whole shebang
			p = 1.0
			for l in range(0,A):
				p *= L[l]
				if l >= 0:
					right = (B-A+1) + (A-l-1)*2
					wrong = (B+1 + ((A-l)*2)+(B-A-2) + 1)
					keystrokes = (p*right) + (1.0-p)*wrong
					#print p,right,wrong,keystrokes
					m = min(keystrokes, m)


			print "Case #%d: %f" % (t+1, m)

if __name__ == '__main__':
	sys.exit(main())
