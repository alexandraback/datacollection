"""
GCJ 2013
url http://code.google.com/codejam/contest/2270488/dashboard#s=p1
"""
import sys

def possible(lawn):
	lines_max, cols_max = maximums(lawn)
	for i, line in enumerate(lawn):
		for j, cell in enumerate(line):
			if cell != lines_max[i] and cell != cols_max[j]:
				return 'NO'
	return 'YES'

def maximums(lawn):
	lines_max = {}
	cols_max = {}
	for i, line in enumerate(lawn):
		lines_max[i] = max(line)
		for j, cell in enumerate(line):
			cols_max[j] = max(cols_max.setdefault(j, 0), cell)
	return lines_max, cols_max



def boardPrint(board):
  """ displays the board (for debug only)
  """
  for line in board:
    print ("".join(str(i) for i in line))
  print()

def process(f, output):
    nb_of_cases = int(f.readline().rstrip());
    for n in range(1, nb_of_cases + 1):
        print('Case', n)

        N, M = (int(i) for i in f.readline().rstrip().split())
        lawn = []
        for i in range(N):
        	lawn.append([int(i) for i in f.readline().rstrip().split()])
        boardPrint(lawn)
        answer = possible(lawn)

        print('Answer:', answer)
        output.write('Case #{0}: {1}\n'.format(n, answer))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("missing argument input_file")
        sys.exit(2)
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[1] + '.out', 'w+')
    process(input_file, output_file)
